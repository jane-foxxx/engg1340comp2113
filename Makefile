flag = -pedantic-errors -std=c++11
fightguardian.o: fightguardian.cpp function.h
	g++ $(flag) -c $<
print_death.o: print_death.cpp function.h
	g++ $(flag) -c $<
check_countdown.o: check_countdown.cpp function.h
	g++ $(flag) -c $<
print_current_value.o: print_current_value.cpp function.h
	g++ $(flag) -c $<
caesar.o: caesar.cpp function.h
	g++ $(flag) -c $<
print_death_reason.o: print_death_reason.cpp function.h
	g++ $(flag) -c $<
ask_death.o: ask_death.cpp function.h
	g++ $(flag) -c $<
main.o: main.cpp function.h  
	g++ $(flag) -c $<
game: main.o fightguardian.o print_death.o check_countdown.o print_current_value.o print_death_reason.o ask_death.o caesar.o
	g++ $(flag) $^ -o game
