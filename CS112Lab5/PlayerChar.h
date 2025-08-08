// Daniel Desforges and Morgan Plants
// CS112 Lab 5 Fall 2020
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>

using namespace std;

#ifndef PLAYERCHAR_H
#define PLAYERCHAR_H

// PlayerChar will be built from the idea from last
// lecture that introduced the CharSheet struct

// struct CharSheet
// {
//    string name;
//    int    strength;
//    double agility;
//    string role;    
// };

class PlayerChar {
public:
    // Headers for constructors
    
    PlayerChar(string init_name, int init_strength,
                       double init_agility, string init_role);
    
    PlayerChar(string init_name, string init_role);
    
    PlayerChar();
    
    PlayerChar(const PlayerChar& existing_char);
    
    // Headers for accessors
    
    string get_name() const;
    
    int get_strength() const;
    
    double get_agility() const;
    
    string get_role() const;
    
    
    // Headers for mutators
    
    set_name(string new_name);
    
    set_strength(int new_strength);
    
    set_agility(double new_agility);
    
    set_role(string new_role);
    
    increase_strength(int increase_pump);
    
    agility_boost(int agility_up);
    
    reset_strength();
    
    // Headers for other functions
    
    print_player_info();
    
    
private:
    // member variables, data members, data fields
    // Those all mean the same thing
    
    string name;
    int strength;
    double agility;
    string role;
    int originalstrength;
    
    
    
};

#endif /* PLAYERCHAR_H */
