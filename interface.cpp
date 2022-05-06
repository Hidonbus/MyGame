#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <stdlib.h>
using namespace std;

#include "interface.h"


void border(){
    cout << setw(65) << setfill('*') << ' '<<endl;
}
void print(string a){
    cout << setw(48/2+ a.size()/2 ) << setfill(' ') << a << endl;; 
}
void print( string a, string b){
    cout << setw(48/3 + a.size()/2 ) << setfill(' ') <<a << setw(48/3 + b.size()/2 - a.size()/2  ) << b << endl;
}
//not fixed
void print( string a, string b, string c){
    cout << setw(48/4) << setfill(' ') << a <<setw(60/4) << b << setw(60/4) << c << endl;
}
int get_int_command(){
    string command;
    int check{1};
    do{
        check = 1;
        cout <<"Please insert your choice: ";
        cin >> command;
        for (int i=0; i < command.size(); ++i)
        {
            if (isdigit(command[i]) == false){
                check = 0;
            }
        }
        if (check == 0){
            cout << "Invalid command!" << endl;
        }
    }while (check == 0);

        return atoi(command.c_str());
}
string get_char_command(){
    string input;
    cout << "Please insert your choice: " ;
    cin >> input;
    return input;
}
int zero_to_five(){
    srand(time(0));
    return rand()%6;
}