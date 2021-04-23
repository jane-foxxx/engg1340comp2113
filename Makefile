flag = -pedantic-errors -std=c++11
gcd.o: gcd.cpp gcd.h
	g++ $(flag) -c $<
lcm.o: lcm.cpp lcm.h gcd.h
	g++ $(flag) -c $<
calc.o: calc.cpp lcm.h gcd.h
	g++ $(flag) -c $<

calc: gcd.o lcm.o calc.o
	g++ $(flag) $^ -o $@
clean:
	rm -f gcd.o lcm.o calc.o calc.tgz calc
.PHONY: clean
