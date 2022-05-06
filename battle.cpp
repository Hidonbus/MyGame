#include <iostream>
#include <cmath>
#include <string>
using namespace std;

#include "character.h"
#include "enemy.h"
#include "interface.h"
#include "battle.h"
void battle_interface(character* hero, int temp_hp, enemy& villain)
{   
    border();
    print("ENEMY");
    print ("Hp " + to_string(villain.hp) + "/" + to_string(villain.original_hp));
    cout << endl << endl;
    print ("Hp " + to_string(temp_hp) + "/" + to_string(hero -> hp) );
    print("HERO Lv." + to_string(hero->level));
    print("Atk: " + to_string(hero -> atk + hero -> my_sword -> value), "Def :" + to_string(hero -> def + hero -> my_armour -> value));
    print ("Gold :" + to_string(hero -> gold), "No. of potions :" + to_string(hero -> my_small_potion ->count));
    border();
}

void battle(character* hero, int stage){
    //creates a copy so that when the character dies he gets nth back
    character copy = *hero;
    int temp_hp = hero -> show_hp();
    // who_died = 0 when hero dies and 1 when enemy dies
    int who_died = 2;
    char yesno = 'y', command;
    
    //the player decides if he wants to fight another enemy
    while (yesno == 'y')
    {
        //creates new enemy 
        enemy villain(stage);
        cout << "battle start!" << endl;
        while (villain.hp > 0 && temp_hp > 0)
        {
            battle_interface(hero, temp_hp, villain);
            cout << "Attack (a) | Use potion (d) " << endl << "your command :";
            cin >> command;
            while (command != 'a' && command != 'd')
            {
                cout << "invalid command" << endl << "your command :";
                cin >> command;
            }
            //battle command
            if (command == 'a')
            {
                who_died = hero_attack(hero, temp_hp, villain);
                if (who_died != 1){
                    who_died = villain_attack(hero, temp_hp, villain);
                }
            }    
            if (command == 'd'){
                hero_regen(hero, temp_hp, villain);
                who_died = villain_attack(hero, temp_hp, villain);
            }

            //check if anyone is dead
            check_if_dead(hero, villain, temp_hp, yesno, who_died, copy);
            
        }   
    }
}
//hero attacks and check if enemy is dead
int hero_attack(character* hero,int& temp_hp, enemy& villain)
{
    int damage;
    border();
    cout << "attack initiated!" << endl;
    damage = (hero -> atk) + (hero -> my_sword -> value) - villain.def;
    damage = (damage < 0)? 0 : damage;
    cout << "you dealt " << damage << " damage to you enemy" << endl;
    villain.hp -= damage;
    villain.hp = (villain.hp < 0)? 0 : villain.hp;
    cout << "enemy remaining health: " << villain.hp << endl;
    if (villain.hp == 0)
    {
        return 1;
    }
    else{
    return 2;
    }
}    
//enemy attacks and see if hero is dead
int villain_attack(character* hero,int& temp_hp, enemy& villain)
{
    {   
        int damage;
        damage = villain.atk - (hero -> def) - (hero -> my_armour ->value);
        damage = (damage < 0)? 0 : damage;
        cout << "enemy dealt " << damage << " damage to you" << endl;
        temp_hp -= damage;
        temp_hp  = (temp_hp < 0)? 0 : temp_hp;
        cout << "hero remaining health: " << temp_hp << endl;
        if (temp_hp == 0)
        {
            return 0;
        }
    }
    return 2;
}
//if someone died, ask for decision, else continue fighting
void check_if_dead(character* hero, enemy& villain, int& temp_hp, char& yesno, int& who_died, character copy)
{
    if (who_died == 0)
        {
            *hero = copy;
            yesno = 'n';
            border();
            cout << "you were defeated......." <<endl;
            cout << "you gained nothing from this journey" << endl;
            border();
        } 
    if (who_died == 1) 
    {   border();
        cout << "enemy fainted!"<< endl;
        hero -> add_gold(villain.gold);
        int if_level_up = hero -> increase_exp(villain.exp);
        temp_hp = (if_level_up == 1)? temp_hp + hero -> increased_hp() : temp_hp;
        border();
        cout << "continue fighting? (y/n): " ;
        cin >> yesno;
        while (yesno != 'y' && yesno != 'n')
        {
            cout << "invalid command!" << endl << "continue fighting? (y/n): ";
            cin >> yesno;
        }
            who_died = 2;
        }
    }
//hero uses potion
void hero_regen(character*hero, int&temp_hp, enemy& villain){
    if (hero -> my_small_potion -> count > 0){
        temp_hp += (hero -> hp /2);
        temp_hp = (temp_hp > hero -> hp)? hero -> hp : temp_hp;
        hero -> my_small_potion -> count --;
        cout << "hp regenerated back to " << temp_hp << endl;
    }
    else{
        cout << "you wanted to use potions but there is no more left!" << endl;
    }
}

//this is the same as the battle function. The only difference is that there is no loop, so only 1 boss.
int boss_battle (character*hero){
    //creates a copy so that when the character dies he gets nth back
    character copy = *hero;
    int temp_hp = hero -> show_hp();
    // who_died = 0 when hero dies and 1 when enemy dies
    int who_died = 2;
    char command;
    enemy villain(4);
    cout << "Boss battle start!" << endl;
    while (villain.hp > 0 && temp_hp > 0)
    {
        battle_interface(hero, temp_hp, villain);
        cout << "Attack (a) | Use potion (d) " << endl << "your command :";
        cin >> command;
        while (command != 'a' && command != 'd')
        {
            cout << "invalid command" << endl << "your command :";
            cin >> command;
        }
        //battle command
        if (command == 'a')
        {
            who_died = hero_attack(hero, temp_hp, villain);
            if (who_died != 1){
                who_died = villain_attack(hero, temp_hp, villain);
            }
        }    
        if (command == 'd'){
            hero_regen(hero, temp_hp, villain);
            who_died = villain_attack(hero, temp_hp, villain);
        }
        if (who_died == 0)
        {
            *hero = copy;
            border();
            cout << "you were defeated......." <<endl;
            cout << "you gained nothing from this journey" << endl;
            border();
        } 
        if (who_died == 1) 
        {   border();
            cout << "boss fainted!"<< endl;
            hero -> add_gold(villain.gold);
            int if_level_up = hero -> increase_exp(villain.exp);
            temp_hp = (if_level_up == 1)? temp_hp + hero -> increased_hp() : temp_hp;
            border();
            border();
            cout << "Congratulations! You have won the game!" << endl;
            border();
            return 1;
        }
    }
        return 0;
}