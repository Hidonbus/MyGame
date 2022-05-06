#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;
#include "interface.h"
#include "item.h"
#include "character.h"
#include "shop.h"


int show_shop(character* hero){
    border();
    cout << "You have " << hero -> gold << " gold" << endl;
    cout << "1: Upgrade sword  COST: " << hero -> my_sword -> level * 100 << endl;
    cout << "2: Upgrade armour COST: " << hero -> my_armour -> level * 100 << endl;
    cout << "3: Buy potions  COST: 50" <<  endl;
    cout << "4: Return" << endl;
    border();
    int command;
    command = get_int_command();
    while (command < 0 || command > 4){
        cout << "Invalid command" << endl;
        command = get_int_command();
    }
    return command;
}
//this is what happens when buying items
void shopping(character* hero, int command){
    int cost;
    if (command == 1){
        cost = hero -> my_sword -> level * 100;
        if (hero -> gold < cost){
            cout << "Insufficient gold!" << endl;
            return;
        }
        else{
            cout << "Upgrading sword ... " << endl;
            hero -> level_up_sword();
            hero -> gold -= cost;
            cout << "Remaining gold: " << hero -> gold << endl;
            }
    }
    if (command == 2){
        cost = hero -> my_armour -> level * 100;
        if (hero -> gold < cost){
            cout << "Insufficient gold!" << endl;
            return;
        }
        else{
            cout << "Upgrading armour ... " << endl;
            hero -> level_up_armour();
            hero -> gold -= cost;
            cout << "Remaining gold: " << hero -> gold << endl;
            }
    }
    if (command == 3){
        int input;
        int number_of_potions;
        cout <<"How many potions do you want to buy?" << endl;
        input = get_int_command();
        number_of_potions = input;
        cost = number_of_potions * 50;
        if (hero -> gold < cost){
            cout << "Insufficient gold!" << endl;
            return;
        }
        else {
            cout << "Adding potion..." << endl; 
            hero ->add_potion(number_of_potions);
            hero -> gold -= cost;
            cout << "Remaining gold: " << hero -> gold << endl;
        }
    }
}
void shop(character* hero){
    border();
    cout << "Welcome to the shop!" << endl;
    string yes_no {"y"};
    int command;
    while (yes_no == "y")
    {   
        command = show_shop(hero);
        if (command == 4){
            return;
        }
        shopping(hero, command);
        cout << "Continue? (y/n)" << endl;
        yes_no = get_char_command();
        while (yes_no != "y" && yes_no != "n"){
            cout << "Invalid command" << endl;
            yes_no = get_char_command();
        }
    }

}