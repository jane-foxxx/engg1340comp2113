flag = -pedantic-errors -std=c++11

nightmare.o: nightmare.cpp caesar.h fightguardian.h print_death_reason.h check_countdown.h print_current_value.h ask_death.h print_death.h
	g++ $(flag) -c nightmare.cpp
	
game: nightmare.o
	g++ $(flag) nightmare.o -o game
