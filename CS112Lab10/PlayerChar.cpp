/*---
    CS 112 Fall 2020 - Week 10 Lab
    C++ Derived Classes

    David C. Tuttle
    Last Modified: 28 Oct 2020
---*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
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
    for (int i=0; i<NUM_TYPES; i++) {
        if (init_role == stdPlayer[i].role) {
            strength = stdPlayer[i].strength;
            agility = stdPlayer[i].agility;
            role = stdPlayer[i].role;
        }
    }
    
    // If no match was found in stdPlayer array
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

// OPERATOR METHODS

bool PlayerChar::operator ==(const PlayerChar& rhs) {
    bool nameEqual = (name == rhs.getName());
    bool strengthEqual = (strength == rhs.getStrength());
    bool agilityEqual =
         (abs(agility - rhs.getAgility()) < 0.01 );
    bool roleEqual = (role == rhs.getRole());
    
    return (nameEqual && strengthEqual &&
            agilityEqual && roleEqual);
}


// OTHER FUNCTIONS

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
