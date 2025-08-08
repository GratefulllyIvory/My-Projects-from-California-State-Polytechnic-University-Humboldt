

/*=====
 PlayerChar
    implementation of the constructors and methods for
    a class representing a simple character in a role-playing game;
    has a name, strength, agility, and role 

=====*/
// Daniel Desforges and Karen Vargas CS211 Spring 2021 lab2
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
PlayerChar::PlayerChar(string a_name, string a_type) {
    name = a_name;
    type = a_type;
    strength = DEFAULT_STRENGTH;
    agility = DEFAULT_AGILITY;
    hp = strength*agility;
    
}
PlayerChar::PlayerChar() {
    name = DEFAULT_NAME;
    strength = DEFAULT_STRENGTH;
    agility = DEFAULT_AGILITY;
    type = DEFAULT_ROLE;
    hp = strength*agility;
}

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
double PlayerChar::getHP() const {
    return hp;
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

void PlayerChar::setHP(double new_hp){
    hp = new_hp;
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

void PlayerChar::battle(PlayerChar& player_2) {
    double  p1, p2;
    
    p1 = randPct();
    p2 = randPct();
    
    double dmg1, dmg2;
    dmg1 = p1 * hp;
    dmg2 = (p2 * player_2.getHP());
    // calc damage
    double nwH1;
    double nwH2;
    
    cout << endl;
    cout << "the Fight Begins" << endl;
    
    nwH1 = hp - dmg2;
    if(nwH1 <0){
        nwH1 = 0;
    } 
    cout << name << "does" << dmg1 << "damage"<< endl;
    cout <<player_2.getName() << "does" << dmg2 << "damage" <<endl;
    nwH2 = (player_2.getHP() - dmg1);
    if(nwH2 < 0){
        nwH2 = 0;
    }
    hp = nwH1;
    player_2.setHP(nwH2);
    if(nwH1> nwH2){
        cout<< name << "Wins"<< endl;
    }
    if(nwH2 > nwH1){
        cout<< player_2.getName() << "Wins" << endl;
    }
    if(nwH1 = nwH2){
        cout << "It was a tie" << endl;
    }
// randPct: void -> double
// purpose: expects nothing
// returns a value from 0.01 to 1.00 in increments
// of 0.01 -- for use in battles between PlayerChars
}
double randPct()
{
    double return_val;
    return_val = (rand() % 100 + 1) * 0.01;
    return return_val;
}
