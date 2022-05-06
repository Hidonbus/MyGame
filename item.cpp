#include <iostream>
#include <cmath>
#include <string>
using namespace std;
#include "interface.h"
#include "item.h"

void item :: show(){
    cout <<this -> name << "-";
    cout << " Level :" << this -> level;
    cout << " Value :" << this -> value << endl;
}

sword :: sword (){
}

sword :: sword (string name, int stage){
    this -> value = stage  * 10;
    this -> name = name;
}
void sword :: upgrade (){
    this -> value +=20;
    this -> level +=1;
    cout << "Upgraded to level " << this -> level << "!" << endl;
    cout << "Sword atk: " << this -> value << endl;
}
void sword :: set (int lv){
    this -> value = 10 + 20 * (level -1);
    this -> level = lv;
}
armour :: armour (){
}

armour :: armour (string name, int stage){
    this -> value = stage  * 5;
    this -> name = name;
}
void armour :: upgrade (){
    this -> value +=10;
    this -> level +=1;
    cout << "Upgraded to level " << this -> level << "!" << endl;
    cout << "Armour def: " << this -> value << endl;
}
void armour :: set(int lv){
    this -> value = 5 + 10 * (lv-1);
    this -> level = lv;
}
potion :: potion (){
}

potion :: potion (string name, int stage){
    this -> value = stage  * 50;
    this -> name = name;
}
//add number of constructor
void potion :: add_count(int num){
    this ->count +=num;
    cout << "You now have " << this -> count << " potions" << endl; 
}
void potion :: show_count(){
    cout << "No. of potions: " << this -> count << endl; 
}