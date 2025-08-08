// CS 211 Spring 2021 - Week 02 Lab SOLUTION

/*=====
 PlayerChar
    implementation of the constructors and methods for
    a class representing a simple character in a role-playing game;
    has a name, strength, agility, and role 

    last modified: 26 Jan 2021 - SOLUTION
=====*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include "PlayerChar.h"
using namespace std;

//=====
// implement PlayerChar's constructors

const string DEFAULT_NAME = "Fred";
const int DEFAULT_STRENGTH = 250;
const double DEFAULT_AGILITY = 5.0;
const string DEFAULT_ROLE = "Ogre";

PlayerChar::PlayerChar(string a_name, int a_strength, 
                       double an_agility, string a_type) {
    name = a_name;
    strength = a_strength;
    agility = an_agility;
    type = a_type;
}

// WRITE CODE FOR OTHER CONSTRUCTOR(S) HERE!


//=====
// implement PlayerChar's accessors

string PlayerChar::getName() const {
    return name;
}

int PlayerChar::getStrength() const {
    return strength;
}

double PlayerChar::getAgility() const {
    return agility;
}

string PlayerChar::getType() const {
    return type;
}

// WRITE CODE FOR OTHER ACCESSOR METHOD(S) HERE!


//=====
// implement PlayerChar's mutators

void PlayerChar::setName(string new_name) {
    name = new_name;
}

void PlayerChar::setType(string new_type) {
    type = new_type;
}

// WRITE CODE FOR OTHER MUTATOR METHOD(S) HERE!

//=====
// implement PlayerChar's other methods

// method: printPlayerChar: void -> void
// purpose: expects nothing, has the side-effect of
//     printing to the screen the current data fields of the
//     calling PlayerChar instance, and returns nothing

void PlayerChar::printPlayerChar() const {
    cout << "PlayerChar name:       " << name  << endl
         << "           strength:   " << strength  << endl
         << "           agility:    " << agility  << endl
         << "           type:       " << type << endl;
}

// method: battle: PlayerChar -> void
// purpose: expects a PlayerChar, returns nothing
// side effects: calculates damage to each PlayerChar
//          reduces HP value of each PlayerChar
//          prints to the screen results of the battle

// WRITE CODE FOR BATTLE METHOD HERE!  Replace the supplied stub code

//void PlayerChar::battle(PlayerChar& opponent) {
//
//}   

// randPct: void -> double
// purpose: expects nothing
// returns a value from 0.01 to 1.00 in increments
// of 0.01 -- for use in battles between PlayerChars

double randPct()
{
    double return_val;
    return_val = (rand() % 100 + 1) * 0.01;
    return return_val;
}

    