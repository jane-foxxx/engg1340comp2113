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

//print the death reason for each death
void print_death_reason(int hp,int countdown, bool weapon){
	//hp <= 0
	if(hp <= 0){
		cout << "You die because of no health point." << endl;
	}
	//player is defeated by the guardian
	else if(fightguardian(weapon, hp, countdown) == false){
		cout << "You are defeated by the guardian because you do not have weapon or your health point is lower than 6" << endl;
	}
	//countdown > 50
	else if (countdown > 50){
		cout << "You fail to escape from NIGHTMARE BEFORE the dawn!" << endl;
	}
}

