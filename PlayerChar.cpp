/*---
    CS 112 Fall 2020 - Assignment 05
    Using C++ Vectors

    David C. Tuttle
    Last Modified: 22 Oct 2020
---*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include <vector>
#include "PlayerChar.h"

using namespace std;

// CONSTRUCTORS

// PlayerChar: string int double string -> void
// Expects a name, a strength, an agility, and a role
// Returns nothing
// Side effect: creates an instance of a PlayerChar

PlayerChar::PlayerChar(string init_name, string init_role) {
    name = init_name;
    strength = 0;
    // Search stdPlayer array for role
    for (int i=0; i<stdPlayer.size(); i++) {
        if (init_role == stdPlayer[i].role) {
            strength = stdPlayer[i].strength;
            agility = stdPlayer[i].agility;
            role = stdPlayer[i].role;
        }
    }
    
    // If no role match was found in stdPlayer array, make it an Ogre
    if (strength == 0) {
            strength = stdPlayer[0].strength;
            agility = stdPlayer[0].agility;
            role = stdPlayer[0].role;
    }
}

PlayerChar::PlayerChar(string init_name) {
    name = init_name;
    strength = stdPlayer[0].strength;
    agility = stdPlayer[0].agility;
    role = stdPlayer[0].role;
}

PlayerChar::PlayerChar() {
    name = "Fred";
    strength = stdPlayer[0].strength;
    agility = stdPlayer[0].agility;
    role = stdPlayer[0].role;
}

// COPY CONSTRUCTOR NOT PROVIDED!  But if it were,
// it would look like this:

//PlayerChar::PlayerChar(const PlayerChar& a_char) {
//    
//}

// ACCESSORS

// get_name: void -> string
// Expects a PlayerChar (as an implicit argument)
// Return the PlayerChar's name

string PlayerChar::getName() const {
    return name;
}

int PlayerChar::getStrength() const {
    return strength;
}

double PlayerChar::getAgility() const {
    return agility;
}

string PlayerChar::getRole() const {
    return role;
}
// MUTATORS

void PlayerChar::setName(string newName) {
    name = newName;
}
void PlayerChar::setStrength(int newStrength) {
    strength = newStrength;
}
void PlayerChar::setAgility(double newAgility) {
    agility = newAgility;
}
void PlayerChar::setRole(string newRole) {
    role = newRole;
};

void PlayerChar::increaseStrength(int pct_increase) {
    // Check if pct_increase is within limits
    if (abs(pct_increase) > 10) {
        cout << "*** Strength change out of range ***"
             << endl;
        return;
    }
    // Calculate new strength
    int newStrength =
        strength * (1.0 + (pct_increase / 100.0));

    // Determine max strength allowed
    int maxStrength = strength;
    for (int i=0; i<NUM_TYPES; i++) {
        if (role == stdPlayer[i].role)
            maxStrength = stdPlayer[i].strength * 2;
    }
    
    if (strength >= maxStrength)
        cout << "Maximum strength attained - value " <<
                "not changed" << endl;
    
    // Set strength to lower of the two values
    strength = min(newStrength, maxStrength);
}

void PlayerChar::increaseAgility(int pct_increase) {
    // Check if pct_increase is within limits
    if (abs(pct_increase) > 10) {
        cout << "*** Agility change out of range ***"
             << endl;
        return;
    }
    // Calculate new agility
    double newAgility =
        agility * (1.0 + (pct_increase / 100.0));

    // Determine max agility allowed
    double maxAgility = agility;
    for (int i=0; i<NUM_TYPES; i++) {
        if (role == stdPlayer[i].role)
            maxAgility = stdPlayer[i].agility * 2;
    }
    
    if (agility >= maxAgility)
        cout << "Maximum agility attained - value " <<
                "not changed" << endl;
    
    // Set strength to lower of the two values
    agility = min(newAgility, maxAgility);
}

// OTHER FUNCTIONS

//Copy Constructor
PlayerChar::copyChar(const PlayerChar& a_player) {
    a_player = stdPlayer;
}
PlayerChar::getPower(){
    for(int i= 0; i< teamVector.size(); i++){
        teamPower += teamVector.power; 
    }
    return teamPower;
}   
// printPlayer: void -> void
// Expects nothing (PlayerChar is an implicit argument)
// Returns nothing
// Side effects:  Prints to the screen the data member
//     values of the PlayerChar

void PlayerChar::printPlayer() const {
    
    cout << "*** CHARACTER INFORMATION ***" << endl
         << "NAME IS     " << name << endl
         << "STRENGTH IS " << strength << endl
         << "AGILITY IS  " << agility << endl
         << "ROLE IS     " << role << endl;
}

