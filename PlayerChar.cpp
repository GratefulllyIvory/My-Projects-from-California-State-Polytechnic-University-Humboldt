/*---
    CS 112 Fall 2020 - Week 05 Lecture 2
    C++ Classes and Methods

    David C. Tuttle
    Last Modified: 24 Sep 2020
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

PlayerChar::PlayerChar(string init_name, int init_strength,
                       double init_agility, string init_role) {
    name = init_name;
    strength = init_strength;
    agility = init_agility;
    role = init_role;
}

// We can OVERLOAD the CONSTRUCTOR
// In other words, we can write constructor function
// (method) definitions that use different types of args

PlayerChar::PlayerChar(string init_name, string init_role) {
    name = init_name;
    strength = 500;
    agility = 3.4;
    role = init_role;
}

PlayerChar::PlayerChar() {
    name = "Fred";
    strength = 500;
    agility = 3.4;
    role = "Ogre";
}

// ACCESSORS

// get_name: void -> string
// Expects a PlayerChar (as an implicit argument)
// Return the PlayerChar's name

string PlayerChar::get_name() const {
    return name;
}

// MUTATORS

// set_name: string -> void
// Expects a string (PlayerChar is an implicit argument)
// Returns nothing
// Side effect: Mutate value of name

PlayerChar::set_name(string new_name) {
    name = new_name;
}

// OTHER FUNCTIONS

// print_player_info: void -> void
// Expects nothing (PlayerChar is an implicit argument)
// Returns nothing
// Side effects:  Prints to the screen the data member
//     values of the PlayerChar

PlayerChar::print_player_info() {
    
    cout << "NAME IS " << name << endl
         << "STRENGTH IS " << strength << endl
         << "AGILITY IS " << agility << endl
         << "ROLE IS " << role << endl;
}