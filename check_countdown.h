#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#define HEART   "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"

using namespace std;

//Time triger
bool check_countdown(int countdown){
	if (countdown > 70){
		return false;
	}
	return true;
}
