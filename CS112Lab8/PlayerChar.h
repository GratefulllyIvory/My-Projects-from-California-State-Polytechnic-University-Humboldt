//Daniel Desforges and Henry Morgan Lab 8 Fall 2020 CS112
#ifndef PLAYERCHAR_H
#define PLAYERCHAR_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

class PlayerChar {

struct PlayerType{
 int strength;
 double agility;
 string role;
};

PlayerType const stdPlayer[5] = {{700, 2.5, "Ogre"}, {300, 5.5, "Sprite"},
 {400, 4.5, "Elf"}, {600, 3.0, "Valkyrie"}, {500, 3.5, "Magician"}};

public:
//Constructors
set_str_agil(string new_name, string new_role);

create_Ogre(string new_name);

ogre_Fred();

//Accessor
string getName();

int getStrength();

double getAgility();

string getRole();

//Mutator
increaseStrength(int pump);

increaseAgility(double boost);

//Other Methods
print_player_info();

private:
    
    string name;
    int strength;
    double agility;
    string role;

};
#endif /* PLAYERCHAR_H */

