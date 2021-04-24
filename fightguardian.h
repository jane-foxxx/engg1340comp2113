#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#define HEART   "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"

using namespace std;

//the action of fighting with the guardian
//true means the player defeat the guardian and survive, and health point will decrease by 3
//false means the player is defeated and die
bool fightguardian(bool weapon, int &hp){
	if(hp > 5 && weapon == true){
	    hp -= 3;
		return true;
	}
	return false;
}
