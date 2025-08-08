// Daniel Desforges and Morgan Plants
// CS112 Lab 5 Fall 2020
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
    originalstrength = strength;
}

// We can OVERLOAD the CONSTRUCTOR
// In other words, we can write constructor function
// (method) definitions that use different types of args

PlayerChar::PlayerChar(string init_name, string init_role) {
    name = init_name;
    strength = 500;
    agility = 3.4;
    role = init_role;
    originalstrength = strength;
    
}

PlayerChar::PlayerChar() {
    name = "Fred";
    strength = 500;
    agility = 3.4;
    role = "Ogre";
    originalstrength = strength;
}
PlayerChar::PlayerChar(const PlayerChar& existing_char){
    name = "Copy of:" + existing_char.name; 
    strength = existing_char.strength;
    agility = existing_char.agility;
    role = existing_char.role;
    originalstrength = existing_char.originalstrength;
}

// ACCESSORS

// get_name: void -> string
// Expects a PlayerChar (as an implicit argument)
// Return the PlayerChar's name

string PlayerChar::get_name() const {
    return name;
}

int PlayerChar::get_strength() const{
    return strength;
}

double PlayerChar::get_agility() const{
    return agility;
}

string PlayerChar::get_role() const{
    return role; 
}

// MUTATORS

// set_name: string -> void
// Expects a string (PlayerChar is an implicit argument)
// Returns nothing
// Side effect: Mutate value of name

PlayerChar::set_name(string new_name) {
    name = new_name;
}

PlayerChar::set_strength(int new_strength){
    strength = new_strength;
}

PlayerChar::set_agility(double new_agility){
    agility = new_agility;
}

PlayerChar::set_role(string new_role){
    role = new_role;
}

PlayerChar::increase_strength(int increase_pump){
    strength += increase_pump;
}

PlayerChar::reset_strength(){
    strength = originalstrength;
}

PlayerChar::agility_boost(int agility_up){
    agility += agility * agility_up/100;
    
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