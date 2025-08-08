//Daniel Desforges Cs112 Fall 2020 

#ifndef PLAYERCHAR_H
#define PLAYERCHAR_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include <vector>

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
    
    
    vector<PlayerType> (stdPlayer) = {
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
    void increaseStrength(int pct_increase);
    void increaseAgility(int pct_increase);
    
    // Headers for other functions
    double getPower();
    void printPlayer() const;
    // copy constructor
    copyChar(const PlayerChar& a_player);
private:
    // member variables, data members, data fields
    // (Those all mean the same thing)
    
    string name;
    int strength;
    double agility;
    string role;
    double power= strength*agility;
    double teamPower;
    
    
};

#endif /* PLAYERCHAR_H */

