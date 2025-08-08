/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlayerChar.h
 * Author: David
 *
 * Created on October 16, 2020, 9:27 AM
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

const int NUM_TYPES = 6;

// Definition of class PlayerChar

class PlayerChar {
public:

    const PlayerType stdPlayer[NUM_TYPES] = {
        {700, 2.5, "Ogre"}, {300, 5.5, "Sprite"},
        {400, 4.5, "Elf"},  {600, 3.0, "Valkyrie"},
        {500, 3.5, "Magician"}, {650, 2.7, "Dwarf"} };

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
    
    increaseStrength(int pct_increase);
    increaseAgility(int pct_increase);
    void setName(string new_name);
    
    // Headers for other functions
    
    printPlayer() const;
    
private:
    // member variables, data members, data fields
    // (Those all mean the same thing)
    
    string name;
    int strength;
    double agility;
    string role;
    double hp;
    
    // Private methods
    void updateHP();
    void updateHP(int hpChange);
    
    void restoreHP();
    
};

#endif /* PLAYERCHAR_H */

