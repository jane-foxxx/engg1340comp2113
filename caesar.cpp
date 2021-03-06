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

int caesar(){
    	cout << DIAMOND << " ************************************************************************************************************* " << DIAMOND << endl;
	cout << "  *  Now you finally found the door with the help of the light, and you found a line engraved on the door———— *" << endl;
	cout << "  *  Only the person who addresses this cipher can open the door.                                             *" << endl;
	cout << "  *  The is one sample left by last person who opened the door successfully:                                  *" << endl;
	cout << DIAMOND << " ************************************************************************************************************* " << DIAMOND << endl;
	cout << "--------------SAMPLE---------------" << endl;
	cout << "|  >>> Key number is -3           |" << endl;
	cout << "|  >>> Encrypted sentence:        |" << endl;
	cout << "|  --> Hbbm cfdeqfkd ql tfk!2021  |" << endl;
	cout << "|  >>> Decrypted password:        |" << endl;
	cout << "|  --> Keeping fight to win!2021  |" << endl;
	cout << "-----------------------------------" << endl;
	cout << "*** You have 3 chances to solve this cipher question." << endl;
	cout << "*** Each chance will take 5 minutes." << endl;
	cout << "*** Now please use your wise to get the correct password as soon as possible!" << endl;
	// set random key number 
	srand((unsigned)time(NULL)); 
	int a = -100;
	int b = 100;
	int key = (rand() % (b-a+1))+ a;
	
	string input = "ENGG1340!";
	string data = "abcdefghijklmnopqrstuvwxyz";
	string data_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	cout << "----------------Question-----------------" << endl;
	cout << "|   >>> Key number = " << setfill( ' ' ) << setw(3) << key << "                |" << endl;
	
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
	cout << "|   >>> Encrypted sentence is " << output << " |" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "---> Please input your decrypted password: ";
	
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
		cout << "---> Try again: ";
		cin >> user_input;
		if(times == 2){
			if (user_input == output1){
				cout << "Congratulation! You pass it!" << endl;
				return 3;
				break;
			}
			cout << "Three times all wrong" << endl;
			cout << "The door is locked forever...You cannot leave here forever..." << endl;
			return 4;
			break;
		}
		times += 1;
	}
}
