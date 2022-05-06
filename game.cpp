#ifndef GAME_CPP
#define GAME_CPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
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
#include "saveload.h"
#include "game.h"

int opening(){
    //border() = print border
    border();
    print( "Welcome to our game!");
    cout << "1: Start from the beginning" << endl ;
    cout << "2: Continue" << endl;
    cout << "3: Instructions" << endl;
    cout << "4: End game" << endl;
    border();
    //get command
    int choice = get_int_command();
    //rmb to change!!
    while (choice < 0 && choice > 4)
    {
        cout << "Invalid command!" << endl;
        choice = get_int_command();
    }
    return choice; 
}
//make a new character
character* new_start(){
    character* hero = new character;
    cout << "HAVE FUN!!" << endl;
    hero -> my_sword -> set(1);
    hero -> my_armour -> set(1);
    hero -> my_small_potion -> count = 1;
    return hero;
}
void instruction(){
    border();
    cout << "Your objective is to beat the final boss" << endl;
    cout << "To do this, defeat enemies from the battle ground to gain gold and exp!" << endl;
    cout << "You can upgrade your items and buy potions that regenerate half of your max health from the shop" << endl;
    cout << "(Sword increases attack and armour increases defense" << endl;
    cout << "Exp allows you to level up and improve your base stats (typical huh...)" << endl;
    cout << "That's it! Enjoy the game!" << endl;
    border();
    cout << "r: Return" << endl;
    string input = get_char_command();
    if (input == "r"){
        return;
    }
    else {
        cout << "BUT WHY......" << endl;
    }
}
//the whole flow of the game
void game(){

    int choice{0};
    character* hero;
    while (choice != 4){
        choice = opening();
        switch (choice)
        {   
            case 4:
            break;
            case 3:
            instruction();
            break;
            case 2: 
            hero = load_hero();
            play_game(hero);
            save_hero(hero);
            delete hero;
            break;
            case 1:
            hero = new_start();
            play_game(hero);
            save_hero(hero);
            delete hero;
            break;
        }
        
    }
    print ("THANK YOU FOR PLAYING !");
}
//this is what happens after the interface
void play_game(character* hero){
    string input {" "};
    while (input != "e"){
        border();
        cout << "a: Enter battle ground" << endl;
        cout << "b: Fight the final boss" << endl;
        cout << "c: View hero stats" << endl;
        cout << "d: Enter shop" << endl;
        cout << "e: Exit to menu (automatic save)" << endl;
        border();
        input = get_char_command();
        //rmb to change!
        while (input != "a" && input != "b" && input != "c" && input != "d" && input != "e"){
            cout << "Invalid command!" << endl;
            input = get_char_command();
        }
        if (input == "a"){
            border();
            cout << "1: Enter stage 1 (recommended level: 1-6)" << endl;
            cout << "2: Enter stage 2 (recommended level: 7-12)" << endl;
            cout << "3: Enter stage 3 (recommended level: 13-18" << endl;
            cout << "4: Enter special stage" << endl;
            cout << "5: Return" << endl;
            border();
            //rmb to change!
            int stage = get_int_command();
            while (stage < 0 && stage > 5){
                cout << "Invalid command!" << endl;
                stage = get_int_command();
            }
            if (stage != 5){
                battle(hero,stage);
            }
        }
        else if (input == "b"){
           int yesno = boss_battle(hero);
           if (yesno == 1){
               cout << "Thank you for playing our game." << endl;
               cout << "Now that you have beaten the game, you can continue leveling up your character" << endl;
               cout << "Try and challenge the special stage as well!" << endl;
               border();
               return;
           }
        }
        else if (input == "c"){
            hero -> show_stat();
            cout << "r: Return" << endl;
            string input = get_char_command();
            if (input == "r"){
            }
            else {
                cout << "but why......" << endl;
            }
        }
        else if (input == "d"){
            shop(hero);
        }
        else if (input == "e"){
        }
    }    
}






#endif