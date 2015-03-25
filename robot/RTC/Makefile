CC     = gcc
LDFLAGS= `pkg-config choreonoid openrtm-aist --libs --cflags` -shared -fPIC
CFLAGS = -Wall
LIBS   =
SRCS   = $(wildcard *.cpp)
MOTIONS = $(wildcard *.yaml)
TARGET = $(SRCS:.cpp=.so)
DESTDIR = /usr/local
INSTALL = cp -p

.PHONY: clean

all: $(TARGET)

RobotTorqueControllerRTC.so : RobotTorqueControllerRTC.cpp
	$(CC) $(CFLAGS) -o $@ RobotTorqueControllerRTC.cpp $(LDFLAGS)

RobotControllerRTC.so : RobotControllerRTC.cpp
	$(CC) $(CFLAGS) -o $@ RobotControllerRTC.cpp $(LDFLAGS)

clean:
	rm -rf $(OBJS) $(TARGET)

install:
	$(INSTALL) $(TARGET) $(DESTDIR)/lib/choreonoid-1.5/rtc
	$(INSTALL) $(MOTIONS) $(DESTDIR)/share/choreonoid-1.5/motion
