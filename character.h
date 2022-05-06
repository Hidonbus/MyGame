#ifndef CHARACTER_H
#define CHARACTER_H


#include "item.h"

class character{
    //double level_up_constant {1.33};
    
    int experience_list[19]{0,280,380,480,580,680,780,980,1080,1180,1280,1380,1480,1580,1680,1780,1880,1980,99999};
    public:
    //CHARACTER STAT
    int atk, def, hp, level, gold, exp;
    void level_up();
    void add_gold(int gold);
    //return 1 if level up
    int increase_exp(int exp_add);
    void show_stat();
    int show_hp();
    int increased_hp();
    //CONSTRUCTOR
    character();
    character(int lv);
    void set_gold(int amount);
    void set_exp(int amount);
    //ITEMS
    sword* my_sword;
    armour* my_armour;
    potion* my_small_potion;
   
    void add_potion(int x);
    void show_items();
    void level_up_sword();
    void level_up_armour();
};


#endif