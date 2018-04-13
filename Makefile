CXXFLAGS = -g -Iinclude -std=c++11
LDFLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
#$(CXX) predefined to be g++

all : bin/app

#tmp/class.o src/class.cpp include/class.h
#	$(CXX) $(CXXFLAGS) -c -o $@ $<

tmp/Vector2.o : src/Vector2.cpp include/Vector2.h
	$(CXX) $(CXXFLAGS) -c -o $@ $< 

tmp/Texture.o : src/Texture.cpp include/Texture.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

tmp/Game.o : src/Game.cpp include/Game.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

tmp/GameWindow.o : src/GameWindow.cpp include/GameWindow.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

tmp/Hand.o : src/Hand.cpp include/Hand.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

tmp/Crew.o : src/Crew.cpp include/Crew.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

tmp/Ship.o : src/Ship.cpp include/Ship.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

tmp/World.o : src/World.cpp include/World.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

tmp/ShipTile.o : src/ShipTile.cpp include/ShipTile.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

tmp/Camera.o : src/Camera.cpp include/Camera.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

tmp/Button.o : src/Button.cpp include/Button.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

tmp/main.o : src/main.cpp include/Vector2.h include/Texture.h \
 include/Game.h include/GameWindow.h include/Hand.h include/Crew.h include/Ship.h \
 include/Button.h include/World.h include/ShipTile.h include/Camera.h #include/class.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

bin/app : tmp/main.o tmp/Vector2.o tmp/Texture.o \
 tmp/Game.o tmp/GameWindow.o tmp/Hand.o tmp/Crew.o tmp/Ship.o \
 tmp/Button.o tmp/World.o tmp/ShipTile.o tmp/Camera.o#tmp/class.o 
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean :
	rm -f tmp/*
	rm -f bin/*
