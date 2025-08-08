/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlayerChar.h
 * Author: David
 *
 * Created on September 24, 2020, 11:27 AM
 */

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
    
    // Headers for accessors
    
    string get_name() const;
    
    // Headers for mutators
    
    set_name(string new_name);
    
    // Headers for other functions
    
    print_player_info();
    
    
private:
    // member variables, data members, data fields
    // Those all mean the same thing
    
    string name;
    int strength;
    double agility;
    string role;
    
};

#endif /* PLAYERCHAR_H */

