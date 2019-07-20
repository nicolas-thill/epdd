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
    -I./src

LIBS = -lasound -pthread

SOURCES_C = ../lib/pd-comport/comport.c

SOURCES_CXX = main.cpp PdObject.cpp RtAudio.cpp

TARGET = pdtest

.PHONY: clean

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS) $(DEFS) $(INCS)

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CFLAGS) $(CXXFLAGS) $(DEFS) $(INCS)

$(TARGET): ${SOURCES_C:.c=.o} ${SOURCES_CXX:.cpp=.o}
	g++ -o $(TARGET) $^ $(LDFLAGS) $(LIBPD) $(LIBS)

clean:
	rm -f *.o $(TARGET)
