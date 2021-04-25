# engg1340comp2113

Group No.149 

Group Members: Wang Xinyi (3035767750); Huang Xiaoquan (3035812311)

# Description:
In the Great Interstellar Era, players in a virtual reality game world were attacked by an unknown virus while using a holographic simulation helmet to play the game. They fail to exit the virtual reality game and are stuck in one new space named the nightmare game.  Players need to follow the guidelines provided in the game to escape the boundary of this nightmare game before the dawn of the nightmare game. Players who fail to escape before the specified time will fall into death in the real world.

# Game Rule:
When the nightmare game starts, there are fifty minutes before dawn coming. Each choice made by the player in the nightmare game will spend several minutes. 

The initial physical energy value of each player is 5 units. If the physical energy value is lower than 6 or the player does not have weapon, the player will be defeated by the guardian and lose the game. 

During the game, the player will get useful props in the room, thus deciding how to use the props will be one of the critical factors in successfully escaping the nightmare game.

Apart from that, the player also needs to pass one chanllege--Caesar cipher, this is a kind of substitution cipher. Instead of using a substitution table, the alphabets are rotated by a number (a key). For example, if the key is 3, plaintext alphabet a would become d, and plaintext alphabet z would become c. The player is required to decrypt one sentence according to the given information to escape the tower and there are 3 chances to deduce the password.

# 1-5 coding requirements:

1. Generation of random game sets or events

2. Data structures for storing game status

3. Dynamic memory management

4. File input/output (e.g., for loading/saving game status)

5. Program codes in multiple files

6. Proper indentation and naming styles

7. In-code documentation

# Features to implement:
Some features implemented to fulfill the 1-5 coding requirements

1. Generation of random game sets or event

   1. use srand() and rand() for initializing the random number generator for key integer in the Caesar cipher

2. Data structures for storing game status

   1. Initializing one struct to store information of the player

   2. Initializing the int variables of time and physical energy under the struct 

   3. Initializing the one string vector for storing tools founded under the struct

   4. Initializing the string variable for the sentence that needed to decrypt

3. Dynamic memory management

   1. User the string vector to store props founded through the game

4. File input/output 

   1. input.txt contains the random input factors.
   There are three example:
      i. sample_input1.txt
      ii. sample_input2.txt
      iii. sample_input3.txt

   2. output.txt contains the results of the random input factors.
   There are three example:
      i. sample_output1.txt
      ii. sample_output2.txt
      iii. sample_output3.txt
   
   3. The game is based on the response from the player.

5. Program codes in multiple files

   1. Makefile
   
   2. function.h
   
   3. main.cpp
   
   4. print_death_reason.cpp
   
   5. print_death.cpp
   
   6. print_current_value.cpp
   
   7. ask_death.cpp
   
   8. caesar.cpp
   
   9. fightguardian.cpp
   
   10. check_countdown.cpp

# Compilation and execution instructions:

$make game

./game

with the two sentence, the code can be executed and you can play the game!
