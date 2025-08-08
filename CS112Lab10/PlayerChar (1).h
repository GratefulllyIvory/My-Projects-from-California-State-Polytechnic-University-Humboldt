/* 
 * File:   PlayerChar.h
 * Author: David
 *
 * Created on October 28, 2020
 */

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

struct PlayerType {
    int strength;
    double agility;
    string role;
};

const int NUM_TYPES = 5;

// Definition of class PlayerChar

class PlayerChar {
public:

    const PlayerType stdPlayer[NUM_TYPES] = {
        {700, 2.5, "Ogre"}, {300, 5.5, "Sprite"},
        {400, 4.5, "Elf"},  {600, 3.0, "Valkyrie"},
        {500, 3.5, "Magician"} };

    // Headers for constructors
    
    PlayerChar(string init_name, string init_role);
    
    PlayerChar(string init_name);
    
    PlayerChar();
    
    // Headers for accessors
    
    string getName() const;
    int getStrength() const;
    double getAgility() const;
    string getRole() const;
    
    // Headers for mutators
    
    void setName(string);
    void setStrength(int);
    void setAgility(double);
    void setRole(string);
    
    // Headers for operator methods
    
    bool operator ==(const PlayerChar& rhs);
    
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

