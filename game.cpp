#include <iostream>

using namespace std;

//print the death reason for each death
void print_death_reason(int hp,int countdown, bool weapon){
	//hp <= 0
	if(hp <= 0){
		cout << "You died because of no health point." << endl;
	}
	//player is defeated by the guardian
	if(fightguardian(weapon, hp) == false){
		cout << "You were defeated by the guardian because you do not have weapon or your health point is lower than 5" << endl;
	}
	//countdown > 70
	if (coutdown >70){
		cout << "You failed to escape from NIGHTMARE BEFORE the dawn!" << endl;
	}
}

//print the current states of the player so that the player can make more choice
void print_current_value(int hp,int countdown, bool weapon){
	//hp
	cout << "health point: " << hp << endl;
	//count down
	cout << "time left: " << (70-countdown) << "min" << endl;
	//weapon
	if(weapon == true){
		cout << "you do have a stick in your bag" << endl;
	}
	else if (weapon == false){
		cout << "it seems that you cannot defeat the guardian" << endl;
	}
}

//print death announce for failure in the game
void print_death(){
	cout << "THANK YOU FOR YOUR CONTRIBUTION TO NIGHTMARE" << endl;
	cout << "WE WISH YOU GOOD HELL :)" << endl;
}

//the action of fighting with the guardian
//true means the player defeat the guardian and survive, and health point will decrease by 3
//false means the player is defeated and die
bool fightguardian(bool weapon, int &hp){
	if(hp >= 5 && weapon == true){
		hp -= 3;
		return true;
	}
	hp = 0;
	return false;
}

int main() {
	
	//background explanation
	cout << "INTERSTELLAR LOG UPDATE:" << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << "Time: A.D. 2049" << endl;
	cout << "Infection Reason: Virtual reality is infected" << endl;
	cout << "Current Situation: Stuck in the NIGHTMARE" << endl;
	cout << "Analysis: Death in NIGHTMARE directly causes death in reality" << endl;
	cout << "Suggestion: YOU need to escape before the dawn (in 70 MINUTES)" << endl;
	cout << "Remember to stay away from the guardian!"
	cout << "-------------------------------------------------------------" << endl;

	//story telling and game instruction
	cout << "Current Situation Update: " << endl;
	cout << "The sight suddenly goes white." << endl;
	cout << "After few seconds, you can see and find that you are in a room with some moonlight leaning in." << endl;
	/*
	the electrical voice starts:
	Dear player, welcome to NIGHTMARE! The simple instruction is to run towards east and cross the river which is the boundary of the nightmare space before the dawn coming... Otherwise you will fall into eternal sleep in reality. Please try to stay away from the guardians because as soon as you fail to defeat him, you will lost in your dream too. Besides, remember to use the props you found through the game correctly. They can help you escape from NIGHTMARE successfully. There are 120 minutes before the dawn coming. Try to wake up and good luck!
	*/
	
	//the game starts!
	bool flag = true;
	while (flag == true){
		int hp = 5; // for fighting with the guardian
		// the primitive hp is 5
		// when hp >= 5, player can beat the guardian
		
		int countdown = 0; // totally 120 minutes, 1 unit of countdown = 5 minutes
		//death reset the time back to zero
		
		bool weapon = false;
		
		print_current_value(hp, countdown, weapon);
		
		//level 1
		cout << "A bread is on the table in front of you, and the door near the table is squeezing." << endl;
		cout << "CHOOSE----------" << endl;
		cout << "A. wait and see" << endl;
		cout << "B. open the door" << endl;
		cout << "C. use table to block the door" << endl;
		cout << "please input your choice: ";
		
		char a;
		cin >> a;
		if (a == 'A'){
			countdown += 10;
			cout << "Nothing happened at all! But you wasted 10 minutes :(" << endl;
		}
		else if (a == 'B'){
			countdown += 5;
			cout << "Nothing is outside the door~" << endl;
		}
		else if (a == 'C'){
			hp -= 1;
			if(fightguardian(weapon, hp) == flase){
				cout << "The sound of moving the table invokes the guardian, and you are beaten by him and locked in the room until the dawn came." << endl;
				cout << "YOU DIED!!!" << endl;
				print_death_reason(hp, countdown, weapon);
				cout << "Do you want to re-enter NIGHTMARE or just die :)" << endl;
				cout << "CHOOSE----------" << endl;
				cout << "A. try again" << endl;
				cout << "B. exit" << endl;
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
		
		//level 2
		/*
		cout <<  "chill and go back for the bread" << endl;
		cout << "CHOOSE----------" << endl;
		cout << "A. eat the bread and leave the room" << endl;
		cout << "B. just leave the room" << endl;
		*/
		char b;
		cin >> b;
		if (b == 'A'){
			hp += 1;
		}
		else if (b == 'B'){
			hp = hp;
		}
		
		/*
		cout << "there is another closing door and a staircase" << endl;
		cout << "CHOOSE----------" << endl;
		cout << "A. go to the thrid floor" << endl;
		cout << "B. go to the ground floor" << endl;
		cout << "C. try to open the closing door" << endl;
		*/
		
		char c;
		cin >> c;
		if (c == 'A'){
			//useless room
			//with stick
			weapon = true;
		}
		else if (c == 'B'){
			//nothing in ground floor
			hp -= 1;
			/*
			cout << "there is another closing door and a staircase" << endl;
			cout << "CHOOSE----------" << endl;
			cout << "A. go to the thrid floor" << endl;
			cout << "C. try to open the closing door" << endl;
			*/
			char c1;
			cin >> c1;
			if (c1 == 'A'){
				//useless room
				//with stick
				weapon = true;
			}
			else if(c == 'C'){
				fightguardian(weapon, hp);
				// guardain
				/* 
				cout << "did not wake up, you die! do you want to re-enter the nightmare?" << endl;
				cout << "CHOOSE----------" << endl;
				cout << "A. try again" << endl;
				cout << "B. exit" << endl;
				*/
				
				char die;
				cin >> die;
				if (die == 'A'){
					continue;
				}
				else if (die == 'B'){
					//sayonala
					flag = false;
					break;
				}
			}
		}
		else if(c == 'C'){
			fightguardian(weapon, hp);
			// guardain
			/* 
			cout << "did not wake up, you die! do you want to re-enter the nightmare?" << endl;
			cout << "CHOOSE----------" << endl;
			cout << "A. try again" << endl;
			cout << "B. exit" << endl;
			*/
			
			char die;
			cin >> die;
			if (die == 'A'){
				continue;
			}
			else if (die == 'B'){
				//sayonala
				flag = false;
				break;
			}
		}
		
		
		
		
	}//while end
	
	
	
	
}//main end
