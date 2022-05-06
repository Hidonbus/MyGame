#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;
#include "interface.h"
#include "item.h"
#include "character.h"

sword long_sword("sword", 1);
armour cloth_armour("armour",1);
potion small_potion("potion", 1);
character::character():atk(100),def(30),hp(550),level(1),gold(200),exp(0){
    this->my_sword = &long_sword;
    this -> my_armour = &cloth_armour;
    this-> my_small_potion = &small_potion;
}
character :: character(int lv){
    this -> level = lv;
    this -> atk = 100 + 20* (lv - 1);
    this -> hp = 550 + 80 * (lv -1);
    this -> def = 30 + 5 * (lv-1);
    this->my_sword = &long_sword;
    this -> my_armour = &cloth_armour;
    this-> my_small_potion = &small_potion;
}
void character :: set_gold(int amount){
     this -> gold = amount;
}
void character :: set_exp(int amount){
    this -> exp = amount;
}


void character :: level_up(){
    this -> level += 1;
    this -> atk += 20 ;
    this -> hp += 80;
    this -> def += 5;
    cout << "Level up!" << endl;
    cout << "You are now level "<< this-> level << endl;
}
void character :: add_gold(int gold_add){
    this -> gold += gold_add;
    cout << gold_add << " gold added" << endl;
    cout << "You now have " << this->gold << " gold" << endl; 
}
int character :: increase_exp(int exp_add){
    int tmp = 0;
    this-> exp += exp_add;
    //resetting exp points after level up
    if (this->exp >= this -> experience_list[this -> level])
    {
        this -> exp -= this -> experience_list[this -> level];
        this -> level_up();
        tmp = 1;
        
    }
    cout << "Exp needed for level up: " << (this -> experience_list[this -> level]) - (this-> exp) << endl;
    return tmp;
}
void character :: show_stat(){
    border();
    print( "Level: " + to_string(this -> level )
    ,"Exp: " + to_string(this -> exp) + " / " + to_string(this -> experience_list[this -> level]));
    print("Hp: "  + to_string(this -> hp));
    print( "Def: " + to_string(this -> def) + " + " + to_string(this -> my_armour -> value), 
    "Atk: " +  to_string(this -> atk ) + " + " + to_string(this -> my_sword -> value));
    print("Gold: " + to_string(this -> gold),"Potions: " + to_string(this -> my_small_potion ->count));
    print("Sword Lv." + to_string(this -> my_sword ->level), "Armour Lv." + to_string(this -> my_armour -> level));
    border();
}
int character :: show_hp(){
    return this -> hp;
}
//rmb to change this when you change level up stats
int character :: increased_hp(){
    return 80;
}
/*
void character :: chg_sword(sword weapon){
    this -> equipment[0] = &weapon;
    cout << "sword changed" << endl;
};
void character :: chg_armour(armour cloth){
    this -> equipment[1] = &cloth;
};
void character :: potion_set_up(potion small_large){
    this -> equipment[2] = &small_large;
    }
*/
void character :: add_potion(int x){
    this -> my_small_potion -> add_count(x);
    }

void character :: show_items(){
    this -> my_sword -> show();
    this -> my_armour -> show();
    this -> my_small_potion -> show_count();
}
void character :: level_up_sword(){
    this ->my_sword -> upgrade();
}
void character :: level_up_armour(){
    this -> my_armour -> upgrade();
}