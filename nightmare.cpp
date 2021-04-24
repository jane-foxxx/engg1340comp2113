#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#define HEART   "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"

#include "caesar.h"
#include "fightguardian.h"
#include "print_death_reason.h"
#include "check_countdown.h"
#include "print_current_value.h"
#include "ask_death.h"
#include "print_death.h"

using namespace std;

int main() {
	
	//background explanation
	cout << "      ***************INTERSTELLAR LOG UPDATE***************" << endl;
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "|                        Time: A.D. 2049                                 |" << endl;
	cout << "|	Infection Reason: Virtual reality is infected                    |" << endl;
	cout << "|	Current Situation: Stuck in the NIGHTMARE                        |" << endl;
	cout << "|	Analysis: Death in NIGHTMARE directly causes death in reality    |" << endl;
	cout << "|	Suggestion: YOU need to escape before the dawn (in 70 MINUTES)   |" << endl;
	cout << "|	Remember to stay away from the guardian!                         |" << endl;
	cout << "--------------------------------------------------------------------------" << endl;
	cout << endl;
	
	//story telling and game instruction
	cout << "      ***************Current Situation Update***************" << endl;
	cout << "-------------------------------------------------------------------------------------------------" << endl;
	cout << "|                      Time: A.D. 2049                                                          |" << endl;
	cout << "| The sight suddenly goes white.                                                                |" << endl;
	cout << "| Current Situation: Stuck in the NIGHTMARE                                                     |" << endl;
	cout << "| After few seconds, you can see and find that you are in a room with some moonlight leaning in.|" << endl;
	cout << "-------------------------------------------------------------------------------------------------" << endl;
	cout << endl;
	
	//the game starts!
	bool flag = true;
	while (flag == true){
		int hp = 5; // for fighting with the guardian
		// the primitive hp is 5
		// when hp >= 5, player can beat the guardian
		
		int countdown = 0; // totally 70 minutes, 1 unit of countdown = 1 minutes
		//death reset the time back to zero
		
		bool weapon = false;
		
		vector<string>props;
		
		print_current_value(hp, countdown, weapon);
		//level 1
		cout << ">>> One bread is on the table in front of you, and the door near the table is squeezing." << endl;
		cout << ">>> CHOOSE----------" << endl;
		cout << "   A. Wait and see" << endl;
		cout << "   B. Open the door" << endl;
		cout << "   C. Use table to block the door" << endl;
		cout << ">>> Please input your choice: ";
		
		char a;
		cin >> a;
		if (a == 'A'){
			countdown += 10;
			cout << "--- Nothing happened at all! But you wasted 10 minutes :(" << endl;
		}
		else if (a == 'B'){
			countdown += 5;
			cout << "--- Nothing is outside the door~" << endl;
		}
		else if (a == 'C'){
			hp -= 1;
			if(fightguardian(weapon, hp) == false){
				cout << "--- The sound of moving the table invokes the guardian, and you are beaten by him and locked in the room until the dawn came." << endl;
				ask_death(hp, countdown, weapon);
				char die;
				cin >> die;
				if (die == 'A'){
					continue;
				}
				else if (die == 'B'){
					flag = false;
					print_death();
					break;
				}
			}
		}
		
		print_current_value(hp, countdown, weapon);
		//level 2
		cout << ">>> So you calm down and back to the table." << endl;
		cout << ">>> NOW YOU CHOOSE TO------------------" << endl;
		cout << "  A. Eat the bread and leave the room" << endl;
		cout << "  B. Just leave the room" << endl;
		cout << ">>> Please input your choice: ";
		char b;
		cin >> b;
		if (b == 'A'){
			hp += 1;
			countdown += 10;
			cout << "--- Yummy~" << endl;
		}
		else if (b == 'B'){
			countdown += 5;
			cout << "--- Why don't you eat the bread?" << endl;
		}
		
		print_current_value(hp, countdown, weapon);
		//level 3
		cout << ">>> There is another closing door and staircases." << endl;
		cout << ">>> You find that this room seems to have three floors." << endl;
		cout << ">>> SO YOU CHOOSE----------" << endl;
		cout << "  A. Go to the third floor" << endl;
		cout << "  B. Go to the ground floor" << endl;
		cout << "  C. Try to open the closing door" << endl;
		cout << ">>> Please input your choice: ";
		char c;
		cin >> c;
		if (c == 'A'){
			countdown += 5;
			cout << ">>>There is an empty room with only one stick lying on the ground." << endl;
			cout << ">>>You pick up the stick." << endl;
			weapon = true;
		}
		else if (c == 'B'){
			countdown += 5;
			cout << ">>> There is nothing on the ground floor, but you wasted 5 minutes.  :(" << endl;
			print_current_value(hp, countdown, weapon);
			cout << ">>> Please choose again:" << endl;
			cout << ">>> YOU CHOOSE TO----------" << endl;
			cout << "   A. Go to the third floor" << endl;
			cout << "   C. Try to open the closing door" << endl;
			cout << ">>> Please input your choice: ";
			char c1;
			cin >> c1;
			if (c1 == 'A'){
				countdown += 5;
				cout << "--- There is an empty room with only one stick lying on the ground." << endl;
				cout << "--- You pick up the stick and return to the second floor" << endl;
				weapon = true;
			}
			else if(c == 'C'){
				if(fightguardian(weapon, hp) == false){
					cout << "--- You open the door and the guardian is inside if it. And you are defeated by the guardian." << endl;
					ask_death(hp, countdown, weapon);
					char die;
					cin >> die;
					if (die == 'A'){
						continue;
					}
					else if (die == 'B'){
						flag = false;
						print_death();
						break;
					}
				}
			}
		}
		else if(c == 'C'){
			if(fightguardian(weapon, hp) == false){
				cout << "--- You open the door, but the guardian is inside the room!" << endl;
				cout << "--- Unfortunately, you are defeated by the guardian..." << endl;
				ask_death(hp, countdown, weapon);
				char die;
				cin >> die;
				if (die == 'A'){
					continue;
				}
				else if (die == 'B'){
					flag = false;
					print_death();
					break;
				}
			}
		}
	

		print_current_value(hp, countdown, weapon);
		//level 4
		cout << ">>> Wow! You hear a sound of footsteps in the room with the door slightly closed" << endl;
		cout << ">>> Guardian is inside the room!" << endl;
		cout << ">>> YOU CHOOSE TO-------------------" << endl;
		cout << "   A. Challenge the guardian" << endl;
		cout << "   B. Go back to the ground floor" << endl;
		cout << ">>> Please input your choice: ";
		char d;
		cin >> d;
		if (d == 'B'){
			cout << "--- It is all dark! You can see nothing!" << endl;
			cout << "--- So you change your mind and decide to challenge the guardian." << endl;
			if(fightguardian(weapon, hp) == false){
				cout << "--- However, you are defeated by the guardian." << endl;
				ask_death(hp, countdown, weapon);
				char die;
				cin >> die;
				if (die == 'A'){
					continue;
				}
				else if (die == 'B'){
					flag = false;
					print_death();
					break;
				}
			}
			else if(fightguardian(weapon, hp) == true){
				countdown += 10;
				cout << "--- You win!!! You are inevitable!" << endl;
			}
		}
		else if (d == 'A'){
			if(fightguardian(weapon, hp) == false){
				cout << "--- You are defeated by the guardian." << endl;
				ask_death(hp, countdown, weapon);
				char die;
				cin >> die;
				if (die == 'A'){
					continue;
				}
				else if (die == 'B'){
					flag = false;
					print_death();
					break;
				}
			}
			else if(fightguardian(weapon, hp) == true){
				hp -= 3;
				countdown += 10;
				cout << "--- You win!!! You are inevitable!" << endl;
			}
		}
       
		print_current_value(hp, countdown, weapon);
		//level 5
		cout << ">>> Congratulation! You beat the guardian with the stick!" << endl;
		cout << ">>> You go into the guardian's room and find a few things." << endl;
		cout << ">>> There are a lamp, a can of ham, a stick and a compass." << endl;
		cout << ">>> Now you have to choose 3 items out of 4, since your bag is not big enough." << endl;
		cout << ">>> FINALLY YOU CHOOSE------------" << endl;
		cout << "   A. The lamp" << endl;
		cout << "   B. The can of ham" << endl;
		cout << "   C. The stick" << endl;
		cout << "   D. The compass" << endl;
		cout << ">>> Please input your choice: ";
		char e1, e2, e3;
		cin >> e1;
		cin >> e2;
		cin >> e3;
		if(e1 == 'A' or e2 == 'A' or e3 == 'A'){
			props.push_back("lamp");
		}
		if(e1 == 'B' or e2 == 'B' or e3 == 'B'){
			props.push_back("ham");
		}
		if(e1 == 'C' or e2 == 'C' or e3 == 'C'){
			props.push_back("stick");
		}
		if(e1 == 'D' or e2 == 'D' or e3 == 'D'){
			props.push_back("compass");
		}
		countdown += 5;
		int k = 0;
		for(int i = 0; i < props.size(); i++){
			if(props[i] == "stick"){
				k = 1;
			}
		}
		if(k == 0){
			weapon = false;
		}
		
		print_current_value(hp, countdown, weapon);
		//level 6
		bool temp = false;
		for(int i = 0; i < props.size(); i++){
			if (props[i] == "lamp"){
				temp = true;
			}
		}
		if(temp == false){
			cout << ">>> Without the lamp, you are lost in NIGHTMARE :(" << endl;
			countdown += 100;
			cout << endl;
        	cout << "        ******************************        " << endl;
        	cout << "              **** YOU DIED! ****             " << endl;
        	cout << ">>> Do you want to re-enter NIGHTMARE or just die :)" << endl;
        	cout << ">>> YOU CHOOSE TO--------" << endl;
        	cout << "   A. Try again" << endl;
        	cout << "   B. Exit" << endl;
        	cout << ">>> Please input your choice: ";
			char die;
			cin >> die;
			if (die == 'A'){
				continue;
			}
			else if (die == 'B'){
				flag = false;
				print_death();
				break;
			}
		}
		cout << "--- You take the lamp and go to the ground floor." << endl;
		cout << "--- There is a door, but it requires one correct password to open it." << endl;
		int cc = caesar();
		if (cc <= 3){
			countdown += cc * 5;
		}
		else {
			countdown += 100;
			ask_death(hp, countdown, weapon);
			char die;
			cin >> die;
			if (die == 'A'){
				continue;
			}
			else if (die == 'B'){
				flag = false;
				print_death();
				break;
			}
		}
		
		print_current_value(hp, countdown, weapon);
		//level 7
		bool temp1 = false;
		for(int i = 0; i < props.size(); i++){
			if (props[i] == "compass"){
				temp1 = true;
			}
		}
		if(temp1 == false){
			cout << ">>> However, without the compass, you are lost in NIGHTMARE and died in the reality :(" << endl;
        	cout << ">>> Do you want to re-enter NIGHTMARE or just die :)" << endl;
        	cout << ">>> YOU CHOOSE TO---------" << endl;
        	cout << "   A. Try again" << endl;
        	cout << "   B. Exit" << endl;
        	cout << ">>> Please input your choice: ";
			countdown += 100;
			char die;
			cin >> die;
			if (die == 'A'){
				continue;
			}
			else if (die == 'B'){
				flag = false;
				print_death();
				break;
			}
		}
		cout << "--- With the compass, you find the way out and stop in front of a river." << endl;
		bool temp2 = false;
		for(int i = 0; i < props.size(); i++){
			if (props[i] == "ham"){
				temp2 = true;
				countdown += 20;
			}
		}
		if(temp2 == false){
			cout << ">>> You drown when you are swimming across the river!" << endl;
			cout << ">>> Tip: hp must be higher than 3 to cross the river." << endl;
			ask_death(hp, countdown, weapon);
			char die;
			cin >> die;
			if (die == 'A'){
				continue;
			}
			else if (die == 'B'){
				flag = false;
				print_death();
				break;
			}
		}
		if (check_countdown(countdown) == false){
			cout << ">>> The Dawn is coming, you fail to escape." << endl;
			cout << ">>> Do you want to re-enter NIGHTMARE or just die :)" << endl;
			cout << ">>> YOU CHOOSE TO--------" << endl;
			cout << "   A. Try again" << endl;
			cout << "   B. Exit" << endl;
        	cout << ">>> Please input your choice: ";
			char die;
			cin >> die;
			if (die == 'A'){
				continue;
			}
			else if (die == 'B'){
				flag = false;
				print_death();
				break;
			}}
		cout << "--- You eat the ham and swim across the river successfully!" << endl;
		cout << "   " << HEART << " Welcome back to the reality! " << HEART << endl;
		break;	
			
	}//while end
	
}//main end
