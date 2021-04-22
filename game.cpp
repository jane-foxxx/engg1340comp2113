#include <iostream>

using namespace std;

//print the death reason for each death
void print_death_reason(int hp,int countdown, bool weapon){
	//hp <= 0
	
	//player is defeated by the guardian
	cout << "The guardian beat you since your physical energy is not enough" << endl;
	
	//countdown > 70
	
}

//print the current states of the player so that the player can make more choice
void print_current_value(int hp,int countdown, bool weapon){
	//hp
	cout << "health point is " << hp << endl;
	//count down
	
	//weapon
	
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
	cout << "Suggestion: YOU need to escape before the dawn" << endl;
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
		
		/*
		a bread is on the table in front of you, and the door near the table is squeezing
		CHOOSE----------
		A. wait and see
		B. open the door
		C. use table to block the door
		*/
		
		char a;
		cin >> a;
		if (a == 'A'){
			countdown += 1;
			// nothing happened, but wait half an hour
		}
		else if (a == 'B'){
			// nothing is outside the door
		}
		else if (a == 'C'){
			hp -= 1;
			fightguardian(weapon, hp);
			// the sound of moving the table calls the guadian, you are beaten by him and trapped by him until the dawn came.
			/* 
			did not wake up, you die! do you want to re-enter the nightmare?
			CHOOSE----------
			A. try again
			B. exit
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
		
		/*
		chill and go back for the bread
		CHOOSE----------
		A. eat the bread and leave the room
		B. just leave the room
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
		there is another closing door and a staircase
		CHOOSE----------
		A. go to the thrid floor
		B. go to the ground floor
		C. try to open the closing door
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
			there is another closing door and a staircase
			CHOOSE----------
			A. go to the thrid floor
			C. try to open the closing door
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
				did not wake up, you die! do you want to re-enter the nightmare?
				CHOOSE----------
				A. try again
				B. exit
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
			did not wake up, you die! do you want to re-enter the nightmare?
			CHOOSE----------
			A. try again
			B. exit
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
