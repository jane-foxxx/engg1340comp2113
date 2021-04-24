#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#define HEART   "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"

using namespace std;

//ask the player if play again
void ask_death(int hp, int countdown, bool weapon){
	print_death_reason(hp, countdown, weapon);
	cout << endl;
	cout << "        ******************************        " << endl;
	cout << "              **** YOU DIED! ****             " << endl;
	cout << ">>> Do you want to re-enter NIGHTMARE or just die ?  :)" << endl;
	cout << ">>> YOU CHOOSE TO----------" << endl;
	cout << "   A. Try again" << endl;
	cout << "   B. Exit" << endl;
	cout << ">>> Please input your choice: ";
}
