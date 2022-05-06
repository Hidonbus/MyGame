#ifndef SAVELOAD_CPP
#define SAVELOAD_CPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

//including things
#include "interface.h"
#include "scene.h"
#include "item.h"
#include "variable.h"
#include "character.h"
#include "enemy.h"
#include "battle.h"
#include "shop.h"
#include "game.h"

//put information into txt file
void save_hero (character* hero){
    ofstream save_file;
    save_file.open("save.txt");
    save_file << hero -> level << endl << hero -> gold << endl 
                << hero -> exp << endl;
    save_file << hero -> my_sword -> level 
                << endl << hero -> my_armour -> level << endl <<
                hero -> my_small_potion ->count;
    if (save_file.fail()){
        cout << "Error in file opening!" << endl;
        exit(1);
    }
    cout << "saved!" << endl;
}

//read from the txt and create character
character* load_hero(){
    cout << "loading......" << endl;
    ifstream(load_file);
    load_file.open("save.txt");
    int x;
    load_file >> x;
    character* hero = new character (x);
    load_file >> x;
    hero -> set_gold(x);
    load_file >> x;
    hero -> set_exp(x);
    load_file >> x;
    hero -> my_sword -> set(x);
    load_file >> x;
    hero -> my_armour -> set(x);
    load_file >> x;
    hero -> my_small_potion ->count = x;
    
    return hero;

}


#endif