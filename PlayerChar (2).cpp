/*---
    CS 112 Fall 2020 - Week 08 Lab SOLUTION
    C++ Classes and Methods

    David C. Tuttle
    Last Modified: 16 Oct 2020
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
            hp = strength * agility;
        }
    }
    
    // If no match was found in stdPlayer array
    if (strength == 0) {
            strength = stdPlayer[0].strength;
            agility = stdPlayer[0].agility;
            role = stdPlayer[0].role;
            hp = strength * agility;
    }
}

PlayerChar::PlayerChar(string init_name) {
    name = init_name;
    strength = stdPlayer[0].strength;
    agility = stdPlayer[0].agility;
    role = stdPlayer[0].role;
    hp = strength * agility;
}

PlayerChar::PlayerChar() {
    name = "Fred";
    strength = stdPlayer[0].strength;
    agility = stdPlayer[0].agility;
    role = stdPlayer[0].role;
    hp = strength * agility;
}

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

PlayerChar::increaseStrength(int pct_increase) {
    int strength_change = 0;
    int maxStrength = 0;

    // Check if pct_increase is within limits
    if (abs(pct_increase) > 10)
        cout << "*** Strength change limited to 10% ***" << endl;        
    
    // Calculate amount of change in strength
    // (automatically truncating to int)
    if (pct_increase > 10.0)
        strength_change = strength * 1.1;
    else if (pct_increase < -10.0)
        strength_change = strength * 0.9;
    else
        strength_change = strength * (pct_increase / 100.0);

    // Calculate new strength 
    int newStrength = strength + strength_change;

    // Determine is new strength is above max strength allowed
    for (int i=0; i<NUM_TYPES; i++) {
        if (role == stdPlayer[i].role)
            maxStrength = stdPlayer[i].strength * 2;
    }
    
    if (newStrength >= maxStrength)
        cout << "Maximum strength attained" << endl;
        
    // Set strength to lower of the two values
    strength = min(newStrength, maxStrength);

    // Update HP
    updateHP();
}

PlayerChar::increaseAgility(int pct_increase) {
    double agility_change = 0.0;
    double maxAgility = 0.0;

    // Check if pct_increase is within limits
    if (abs(pct_increase) > 10)
        cout << "*** Agility change limited to 10% ***" << endl;

    // Calculate amount of change in agility
    if (pct_increase > 10.0)
        agility_change = agility * 1.1;
    else if (pct_increase < -10.0)
        agility_change = agility * 0.9;
    else
        agility_change = agility * (pct_increase / 100.0);

    // Calculate new agility to test for limits
    double newAgility = agility + agility_change;

    // Determine max agility allowed
    for (int i=0; i<NUM_TYPES; i++) {
        if (role == stdPlayer[i].role)
            maxAgility = stdPlayer[i].agility * 2.0;
    }
    
    if (newAgility >= maxAgility)
        cout << "Maximum agility attained" << endl;
    
    // Set agility to lower of the two values
    agility = min(newAgility, maxAgility);

    // Update HP
    updateHP();
}

void PlayerChar::setName(string new_name) {
    name = new_name;
}
  
void PlayerChar::updateHP() {
    hp = min(hp, strength * agility);
}

void PlayerChar::updateHP(int hpChange) {
    // calculate maxHP once to save on computation!
    double maxHP = strength * agility;
    if (hp + hpChange > maxHP) {
        hp = maxHP;
        return;
    }
    if (hp + hpChange < 0.0) {
        hp = 0.0;
        return;
    }
    hp += hpChange;
}

void PlayerChar::restoreHP() {
    hp = strength * agility;
}

// OTHER FUNCTIONS

// printPlayer: void -> void
// Expects nothing (PlayerChar is an implicit argument)
// Returns nothing
// Side effects:  Prints to the screen the data member
//     values of the PlayerChar

PlayerChar::printPlayer() const {
    
    cout << "*** CHARACTER INFORMATION ***" << endl
         << "NAME IS     " << name << endl
         << "STRENGTH IS " << strength << endl
         << "AGILITY IS  " << agility << endl
         << "ROLE IS     " << role << endl;
}