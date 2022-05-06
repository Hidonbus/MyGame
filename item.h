#ifndef ITEM_H
#define ITEM_H

//base
class item {
    public:
    int level{1};
    string name {" "};
    int value {0};
    const int scaling_constant {2};
    //constructor
    
    //function
    void show();
    void virtual add_count(int num){};
};

//inherited class 1
class sword : public item{
    public:
    sword();
    sword(string name, int stage);
    void upgrade();
    void set(int lv);
};
class armour : public item{
    public:
    armour();
    armour(string name, int stage);
    void upgrade();
    void set(int lv);
};
class potion : public item{
    public:
    int count{1};
    potion();
    potion(string name, int stage);
    void add_count(int num);
    void show_count();
};
#endif