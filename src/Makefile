LIBPD_DIR = ../lib/libpd
LIBPD = $(LIBPD_DIR)/libs/libpd.so
#LIBPD = -L $(LIBPD_DIR)/libs -lpd

CFLAGS = -O3

CXXFLAGS = -std=c++11

DEFS=  -DLIBPD_USE_STD_MUTEX -D__LINUX_ALSA__

INCS= \
    -I$(LIBPD_DIR)/pure-data/src \
    -I$(LIBPD_DIR)/libpd_wrapper \
    -I$(LIBPD_DIR)/libpd_wrapper/util \
    -I$(LIBPD_DIR)/cpp \
    -I./src \
    -I../lib/pd-mrpeach/osc

LIBS = -lasound -pthread

SOURCES_C = ../lib/pd-comport/comport.c \
    ../lib/pd-mrpeach/osc/packOSC.c \
    ../lib/pd-mrpeach/osc/unpackOSC.c \
    ../lib/pd-mrpeach/osc/routeOSC.c \
    ../lib/pd-mrpeach/slip/slipdec.c \
    ../lib/pd-mrpeach/slip/slipenc.c \

SOURCES_CXX = main.cpp RtAudio.cpp

TARGET = epdd

.PHONY: clean

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS) $(DEFS) $(INCS)

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CFLAGS) $(CXXFLAGS) $(DEFS) $(INCS)

$(TARGET): ${SOURCES_C:.c=.o} ${SOURCES_CXX:.cpp=.o}
	g++ -o $(TARGET) $^ $(LDFLAGS) $(LIBPD) $(LIBS)

clean:
	rm -f *.o $(TARGET)
