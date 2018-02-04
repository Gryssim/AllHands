CXXFLAGS = -g -Iinclude -std=c++11
LDFLAGS = -lSDL2 -lSDL2_image
#$(CXX) predefined to be g++

all : bin/app

#tmp/class.o src/class.cpp include/class.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

tmp/main.o src/proto.cpp #include/class.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

bin/app : tmp/main.o #tmp/class.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

