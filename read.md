# engg1340comp2113

Group No.149 

Group Members: Wang Xinyi (3035767750); Huang Xiaoquan (3035812311)

# Description:
In the Great Interstellar Era, players in a virtual reality game world were attacked by an unknown virus while using a holographic simulation helmet to play the game. They fail to exit the virtual reality game and are stuck in one new space named the nightmare game.  Players need to follow the guidelines to escape the boundary of this nightmare game before the dawn of the nightmare game. Players who fail to escape before the specified time will fall into death in the real world.

# Game Rule:
When the nightmare game starts, there are forty minutes before dawn coming. Each choice made by the player in the nightmare game will take 5 minutes. 

The initial physical energy value of each player is 5 units. If the physical energy value is lower than 5, the player cannot win the battle with the guard. 

During the game, the player will get useful props in the room, thus deciding how to use the props will be one of the critical factors in successfully escaping the game.

Apart from that, the player also need to pass one chanllege--Caesar cipher, the player is required to decrypt one sentence according to the given information to escape the tower. The player has 3 chances to solve this cipher.

# 1-5 coding requirements:

Generation of random game sets or events

Data structures for storing game status

Dynamic memory management

File input/output (e.g., for loading/saving game status)

Program codes in multiple files

Proper indentation and naming styles

In-code documentation

# Features to implement:
Some features implemented fulfill the coding requirements

1.Generation of random game sets or event

  1. use srand() and rand() for initializing the random number generator for key integer in the Caesar ciper
  
2.Data structures for storing game status:

  1.Initializing one struct to store information of the player

  2.Initializing the int variables of time and physical energy under the struct 

  3.Initializing the one string vector for storing tools founded under the struct

  4.Initializing the string variable for the sentence that needed to decrypt

3.Dynamic memory management


   1.User the string vector to store props founded through the game

4.File input/output 

  1.input.txt contains the random input factors

  2.output.txt contains the results of the random input factors.

5.Program codes in multiple files

  1.head.cpp

  2.main.cpp

  3.waiting for implementing...

# Compilation and execution instructions:
