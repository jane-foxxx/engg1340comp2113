#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#define HEART   "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"

//#include "caesar.h"

using namespace std;

int caesar(){
    cout << DIAMOND << " ************************************************************************************************************* " << DIAMOND << endl;
	cout << "  *  Now you finally found the door with the help of the light, and you found a line engraved on the door———— *" << endl;
	cout << "  *  Only the person who addresses this cipher can open the door.                                             *" << endl;
	cout << "  *  The is one sample left by last person who opened the door successfully:                                  *" << endl;
	cout << DIAMOND << " ************************************************************************************************************* " << DIAMOND << endl;
	cout << "--------------SAMPLE---------------" << endl;
	cout << "|  >>> Key number is -3           |" << endl;
	cout << "|  >>> Encrypted sentence:        |" << endl;
	cout << "|  --> Hbbm cfdeqfkd ql tfk!      |" << endl;
	cout << "|  >>> Decrypted password:        |" << endl;
	cout << "|  --> Keeping fight to win!      |" << endl;
	cout << "-----------------------------------" << endl;
	cout << ">>> Now please use your wise to solve this cipher question!" << endl;
	// set random key number 
	srand((unsigned)time(NULL)); 
	int a = -100;
	int b = 100;
	int key = (rand() % (b-a+1))+ a;
	
	string input = "ENGG1340!";
	string data = "abcdefghijklmnopqrstuvwxyz";
	string data_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	cout << ">>> Key number = "<< key << endl;
	
	string output = "";
	//Encrypt
	string::size_type position;
	string::size_type position1;
	if (key >= 0){
		for (int i = 0; i < input.size(); i++){
			position = data.find(input[i]);
			position1 = data_upper.find(input[i]);
			if (position != data.npos || position1 != data_upper.npos){
				//Encrypt Uppercase letters
				if (isupper(input[i])){
					output += char(int(input[i] + key - 65) % 26 + 65);
				}
				//Encrypt Lowercase letters
				else{
					output += char(int(input[i] + key -97) % 26 + 97);
				}
			}
			else{
				output += input[i];
			}
		}
	}
	else{
		for (int i = 0; i < input.size(); i++){
			position = data.find(input[i]);
			position1 = data_upper.find(input[i]);
			if (position != data.npos || position1 != data_upper.npos){
				//Encrypt Upper letters
				if (isupper(input[i])){
					if (int(key % 26 + input[i]) < 65){
						output += char(int(key % 26 + 26 + input[i]));
					}
					else{
						output += char(int(key % 26 + input[i])); 
					}
				}
				//Encrypt Lowercase letters
				else{
					if (int(key % 26 + input[i]) < 96){
						output += char(int(key % 26 + 26 + input[i]));
					}
					else{
						output += char(int(key % 26 + input[i])); 
					}
				}
			}
			else{
				output += input[i];
			}
		}
	}
	cout << ">>> Encrypted sentence is " << output << endl;
	cout << "--> Please input your decrypted password: ";
	
	//Decrypt
	string input1 = output;
	string output1;
	string::size_type position_d;
	string::size_type position1_d;
	if (key < 0){
		for (int i = 0; i < input1.size(); i++){
			position_d = data.find(input1[i]);
			position1_d = data_upper.find(input1[i]);
			if (position_d != data.npos || position1_d != data_upper.npos){
				//Decrypt Uppercase letters
				if (isupper(input1[i])){
					output1 += char(int(input1[i] - key - 65) % 26 + 65);
				}
				// Decrypt Lowercase letters
				else{
					output1 += char(int(input1[i] - key - 97) % 26 + 97);
				}
			}
			else{
				output1 += input1[i];
			}
		}
	}
	else{
		for (int i = 0; i < input1.size(); i++){
			position_d = data.find(input1[i]);
			position1_d = data_upper.find(input1[i]);
			if (position_d != data.npos || position1_d != data_upper.npos){
				//Decrypt Upper letters
				if (isupper(input1[i])){
					if (int(-key % 26 + input1[i]) < 65){
						output1 += char(int(-key % 26 + 26 + input1[i]));
					}
					else{
						output1 += char(int(-key % 26 + input1[i])); 
					}
				}
				// Decrypt Lowercase letters
				else{
					if (int(-key % 26 + input1[i]) < 96){
						output1 += char(int(-key % 26 + 26 + input1[i]));
					}
					else{
						output1 += char(int(-key % 26 + input1[i])); 
					}
				}
			}
			else{
				output1 += input1[i];
			}
		}
	}
	string user_input;
	cin >> user_input;
	int times = 1;
	while (true){
		if (user_input == output1){
			cout << "Congratulation! You pass it!" << endl;
			return times;
			break;
		}
		cout << "OMG! Not the correct answer~" << endl;
		cout << "There are " << 3 - times << " more chances." << endl;
		cout << "Try again: ";
		cin >> user_input;
		if(times == 2){
			if (user_input == output1){
				cout << "Congratulation! You pass it!" << endl;
				return 3;
				break;
			}
			cout << "Three times all wrong" << endl;
			return 4;
			break;
		}
		times += 1;
	}
}

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

//Time triger
bool check_countdown(int countdown){
    if (countdown > 70){
        return false;
    }
	return true;
}

//print the death reason for each death
void print_death_reason(int hp,int countdown, bool weapon){
	//hp <= 0
	if(hp <= 0){
		cout << "You die because of no health point." << endl;
	}
	//player is defeated by the guardian
	else if(fightguardian(weapon, hp) == false){
		cout << "You are defeated by the guardian because you do not have weapon or your health point is lower than 6" << endl;
	}
	//countdown > 70
	else if (countdown > 70){
		cout << "You fail to escape from NIGHTMARE BEFORE the dawn!" << endl;
	}
}

//print the current states of the player so that the player can make more choice
void print_current_value(int hp,int countdown, bool weapon){
    cout << endl;
    cout << "-------Current Condition-------" << endl;
	//hp
	cout << "|       health point: " << hp <<"       |" << endl;
	//count down
	cout << "|       time left: " << (70-countdown) << " min     |" << endl;
	//weapon
	if(weapon == true){
		cout << "|       weapon: stick         |" << endl;
	}
	else if (weapon == false){
		cout << "|       weapon: none          |" << endl;
	}
	cout << "-------------------------------" << endl;
}

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

//print death announce for failure in the game
void print_death(){
	cout << "THANK YOU FOR YOUR CONTRIBUTION TO NIGHTMARE" << endl;
	cout << "WE WISH YOU GOOD HELL :)" << endl;
}


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

