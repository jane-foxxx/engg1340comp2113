#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#define HEART   "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"

#include "function.h"

using namespace std;

//print the current states of the player so that the player can make more choice
void print_current_value(int hp, int countdown, bool weapon){
    cout << endl;
    cout << "-------Current Condition-------" << endl;
	//hp
	cout << "|       health point: " << hp <<"       |" << endl;
	//count down
	cout << "|       time left: " << (50 - countdown) << " min     |" << endl;
	//weapon
	if(weapon == true){
		cout << "|       weapon: stick         |" << endl;
	}
	else if (weapon == false){
		cout << "|       weapon: none          |" << endl;
	}
	cout << "-------------------------------" << endl;
}

