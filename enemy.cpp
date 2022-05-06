#include <iostream>
#include <cmath>
using namespace std;
#include "interface.h"
#include "enemy.h"
#include "time.h"
#include "stdlib.h"

enemy::enemy(int stage){
    //get a random number from 0 to 5 and make stats random
    int a = zero_to_five();
    this -> atk = (100 + 10 * a) * stage - 50 ;
    this -> def = (30 + 3 * a) * stage - 10;
    this -> hp = (750 + 100 * a)* stage - 400;
    this -> gold = (30 + 4 * a) * stage;
    this -> exp = (30 + 5 * a ) * stage;
    this -> original_hp = this -> hp;
}