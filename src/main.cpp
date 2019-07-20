/*
 * Copyright (c) 2014 Rafael Vega <rvega@elsoftwarehamuerto.org>
 *
 * BSD Simplified License.
 * For information on usage and redistribution, and for a DISCLAIMER OF ALL
 * WARRANTIES, see the file, "LICENSE.txt," in this distribution.
 *
 * See https://github.com/libpd/libpd for documentation
 *
 */
#include <iostream> 
#include <unistd.h>
#include <stdlib.h>

#include "PdBase.hpp"
#include "RtAudio.h"

extern "C" {

	void comport_setup(void);

	void packOSC_setup(void);
	void unpackOSC_setup(void);
	void routeOSC_setup(void);

	void slipdec_setup(void);
	void slipenc_setup(void);

}

RtAudio audio;
pd::PdBase lpd;

int audioCallback(void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames, double streamTime, RtAudioStreamStatus status, void *userData)
{
	int ticks = nBufferFrames / 64;

	lpd.processFloat(ticks, (float *)inputBuffer, (float*)outputBuffer);

	return 0;
}

void init(char *pd_file, char *pd_dir)
{
	unsigned int sampleRate = 44100;
	unsigned int bufferFrames = 128;

	// init pd
	if (!lpd.init(0, 2, sampleRate)) {
		std::cerr << "Could not init pd" << std::endl;
		exit(1);
	}

	comport_setup();

	packOSC_setup();
	unpackOSC_setup();
	routeOSC_setup();

	slipdec_setup();
	slipenc_setup();

	// send DSP 1 message to pd
	lpd.computeAudio(true);

	// load the patch
	pd::Patch patch = lpd.openPatch(pd_file, pd_dir);

	// use the RtAudio API to connect to the default audio device
	if (audio.getDeviceCount() == 0) {
		std::cerr << "ERROR: no available sound devices." << std::endl;
		exit(1);
	}

	RtAudio::StreamParameters parameters;
	parameters.deviceId = audio.getDefaultOutputDevice();
	parameters.nChannels = 2;

	RtAudio::StreamOptions options;
	options.streamName = "libpd rtaudio test";
	options.flags = RTAUDIO_SCHEDULE_REALTIME;
	if (audio.getCurrentApi() != RtAudio::MACOSX_CORE) {
		options.flags |= RTAUDIO_MINIMIZE_LATENCY; // CoreAudio doesn't seem to like this
	}
	try {
		audio.openStream(&parameters, NULL, RTAUDIO_FLOAT32, sampleRate, &bufferFrames, &audioCallback, NULL, &options);
		audio.startStream();
	}
	catch (RtAudioError& e) {
		std::cerr << e.getMessage() << std::endl;
		exit(1);
	}
}


int main (int argc, char *argv[])
{
	if (argc != 3) {
		std::cerr << "ERROR: invalid arguments" << std::endl;
	}

	init(argv[1], argv[2]);

	while (1) {
		usleep(100);
	}

	return 0;
}
