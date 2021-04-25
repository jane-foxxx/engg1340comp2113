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


//Time triger
bool check_countdown(int countdown){
    if (countdown > 50){
        return false;
    }
    else{
	    return true;
    }
}
