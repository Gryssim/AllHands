CXXFLAGS = -g -Iinclude -std=c++11
LDFLAGS = -lSDL2 -lSDL2_image
#$(CXX) predefined to be g++

all : bin/app

#tmp/class.o src/class.cpp include/class.h
#	$(CXX) $(CXXFLAGS) -c -o $@ $<

tmp/Texture.o : src/Texture.cpp include/Texture.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

tmp/GameWindow.o : src/GameWindow.cpp include/GameWindow.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

tmp/main.o : src/main.cpp include/Texture.h include/GameWindow.h #include/class.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

bin/app : tmp/main.o tmp/Texture.o tmp/GameWindow.o #tmp/class.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

