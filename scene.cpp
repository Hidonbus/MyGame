#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "scene.h"


void looping_scenes(int onoff)
{
    while (onoff){
        switch (onoff){
            case 1:
            onoff = map();
            break;
            case 2:
            onoff = fight();
            break;
            case 3:
            onoff = shop();
            break;
            default :
            cout << "invalid, chose another option: "<< endl;
            cin >> onoff;
        }
    }
}
int fight (){
     int temp;
    cout << "you are now in fight!" <<endl << "next step: ";
    cin >> temp;
    return temp;
}
int shop(){
     int temp;
    cout << "you are now in shop!" <<endl << "next step: ";
    cin >> temp;
    return temp;
}
//void character_interface();
int map(){
    int temp;
    cout << "you are now in map!" <<endl << "next step: ";
    cin >> temp;
    return temp;
    
}
void end(){
    cout <<"thank you for playing!" << endl;
}