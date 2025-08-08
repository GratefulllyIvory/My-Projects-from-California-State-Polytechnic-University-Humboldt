
/*---
 Daniel Desforges CS112 Fall 2020 Assignment 3
---*/

#ifndef PLAYERCHAR_H
#define PLAYERCHAR_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>

using namespace std;

// Declarations of data types and constants
class PlayerChar {
    
struct PlayerType {
    int strength;
    double agility;
    string role;
};

const int NUM_TYPES = 6;

// Definition of class PlayerChar

public:

    const PlayerType stdPlayer[NUM_TYPES] = {
        {700, 2.5, "Ogre"}, {300, 5.5, "Sprite"},
        {400, 4.5, "Elf"},  {600, 3.0, "Valkyrie"},
        {500, 3.5, "Magician"}, {650, 2.7, "Dwarf" } };

    //Constructors
    set_str_agil(string new_name, string new_role);

    create_Ogre(string new_name);

    ogre_Fred();
    
    
    // Headers for accessors
    //Accessor
    string getName();

    int getStrength();

    double getAgility();

    string getRole();

    
    // Headers for mutators
    
    void setName(string);
    void setStrength(int);
    void setAgility(double);
    void setRole(string);
    
    increaseStrength(int pump);
    
    increaseAgility(double boost);
    
    // Headers for other functions
    
    void printPlayer() const;
    
private:
    // member variables, data members, data fields
    // (Those all mean the same thing)
    
    string name;
    int strength;
    double agility;
    string role;
    
};

#endif /* PLAYERCHAR_H */
