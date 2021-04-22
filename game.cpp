/*
background:
interstellar times, players use helmet and get infected, stuck in the nightmare
player need to escape from the nightmare before the dawn
who did not escape before the dawn will die in reality
*/


#include <iostream>

using namespace std;

void fightguardian(bool weapon, int hp){
	
}

int main() {
	
	/*
	player is playing inside the helmet, the sight went white, then inside a tower
	moonlight lean in, the electrical voice starts:
	"
	dear player, welcome to nightmare!
	the counting down is 4 hours
	remember to stay away from the guardians, escape from the tower and head towards the east.
	escape the nightmare before the dawn which is crossing the river!
	the conseqquence of failing to escape is that you will sleep forever in reality.
	try to wake up and good luck!
	"
	*/
	
	bool flag = true;
	while (flag = true){
		int hp = 5; // for fighting with the guardian
		// the primitive hp is 5
		// when hp >= 5, player can beat the guardian
		
		const double halfhour = 0.5;
		double countdown = 0.0; // totally 4 h, every choice 30 min
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
			countdown += halfhour;
			// nothing happened, but wait half an hour
		}
		else if (a == 'B'){
			// nothing is outside the door
		}
		else if (a == 'C'){
			hp -= 1;
			fightguardian();
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
				fightguardian();
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
			fightguardian();
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
