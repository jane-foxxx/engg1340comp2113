#ifndef FUNCTION_H 
#define FUNCTION_H

void print_death_reason(int hp,int countdown, bool weapon);

void print_death();

void print_current_value(int hp,int countdown, bool weapon);

bool fightguardian(bool weapon, int &hp, int &countdown);

bool check_countdown(int countdown);

void ask_death(int hp, int countdown, bool weapon);

int caesar();

#endif
