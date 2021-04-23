flag = -pedantic-errors -std=c++11

nightmare.o: nightmare.cpp caesar.h
	g++ $(flag) -c nightmare.cpp
	
game: nightmare.o
	g++ $(flag) nightmare.o -o game
