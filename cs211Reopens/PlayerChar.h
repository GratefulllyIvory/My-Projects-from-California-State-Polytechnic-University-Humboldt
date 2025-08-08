
/*=====
    a class representing a simple character in a role-playing game;
    has a name, strength, agility, type, abnd health points

    last modified: 2021-02-02
=====*/

#ifndef PLAYERCHAR_H
#define PLAYERCHAR_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;

// CONSTANT DECLARATIONS

// DEFAULT_NAME is the default name a PlayerChar will get if not specified
const string DEFAULT_NAME = "Fred";

// DEFAULT_STRENGTH is the default initial strength of a PlayerChar
const double DEFAULT_STRENGTH = 400.0;

// DEFAULT_AGILITY is the default initial agility of a PlayerChar
const double DEFAULT_AGILITY = 5.0;

// DEFAULT_TYPE is the default type of character of a PlayerChar
const string DEFAULT_TYPE = "Ogre";

// MAX_STRENGTH is the maximum strength permitted for any PlayerChar
const double MAX_STRENGTH = 500.0;

// MAX_AGILITY is the maximum agility permitted for any PlayerChar
const double MAX_AGILITY = 50.0;

// rand_pct: void -> double
// purpose: expects nothing
// returns a value from 0.01 to 1.00 in increments
// of 0.01 -- for use in PlayerChar battles

double randPct();

class PlayerChar {
    public:

        // constructors

        PlayerChar(string playerName, int playerStrengfth,
                   double playerAgility, string playerType);
        PlayerChar(string playerName, string playerType);
        PlayerChar();

        // accessors

        string getName() const;
        int getStrength() const;
        double getAgility() const;
        string getType() const;
        double getHP() const;
    
        // mutators
        //
        // (here, a programmer can ONLY change a player character's
        //     name and type and HP directly)

        void setName(string newName);
        void setStrength(double newStrength);
        void setAgility(double newAgility);       
        void setType(string newType);
        void setHP(double newHP);

        // other methods

        // method: printPlayer: void -> void
        // purpose: expects nothing, has the side-effect of
        //     printing to the screen the current data fields of the
        //     calling PlayerChar instance, and returns nothing

        void printPlayer() const;
        
        // method: battle: PlayerChar -> void
        // purpose: expects a PlayerChar, returns nothing
        // side effects: calculates damage to each PlayerChar
        //          reduces HP value of each PlayerChar
        //          prints to the screen results of the battle

        void battle(PlayerChar& opponent);

    private: 
        string name;
        int    strength;
        double agility;
        string type;
        double hp;
     
};   // DO NOT FORGET the SEMICOLON!!!!!!!!

#endif
