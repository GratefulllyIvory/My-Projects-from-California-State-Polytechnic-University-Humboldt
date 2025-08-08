/*=====
 PlayerChar
    implementation of the constructors and methods for
    a class representing a simple character in a role-playing game;
    has a name, strength, agility, role, and calculated health points

    Daniel Desforges and Anthony Shucraft Fall 2020 Week 3
=====*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <valarray>
#include "PlayerChar.h"
using namespace std;

// implement PlayerChar's constructors 

PlayerChar::PlayerChar(string playerName, int playerStrength, 
                       double playerAgility, string playerType) {
    name = playerName;
    strength = playerStrength;
    agility = playerAgility;
    type = playerType;
    hp = strength * agility;
}

PlayerChar::PlayerChar(string playerName, string playerType) {
    name = playerName;
    strength = DEFAULT_STRENGTH;
    agility = DEFAULT_AGILITY;
    type = playerType;
    hp = strength * agility;
}

PlayerChar::PlayerChar() {
    name = DEFAULT_NAME;
    strength = DEFAULT_STRENGTH;
    agility = DEFAULT_AGILITY;
    type = DEFAULT_TYPE;
    hp = strength * agility;
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


//=====
// implement PlayerChar's mutators

void PlayerChar::setName(string newName) {
    name = newName;
}

void PlayerChar::setStrength(double newStrength) {
    strength = max(min(newStrength, MAX_STRENGTH), 0.0);
}

void PlayerChar::setAgility(double newAgility) {
    agility = max(min(newAgility, MAX_AGILITY), 0.0);
}

void PlayerChar::setType(string newType) {
    type = newType;
}

void PlayerChar::setHP(double newHP) {
    // Minimum value of HP of 0.0 is now enforced in this method
    hp = max(newHP, 0.0);
}

/****************************************************************/
void PlayerChar::restoreHealth(){
    hp=strength*agility;
}
/****************************************************************/

//=====
// implement PlayerChar's other methods

// method: printPlayer: void -> void
// purpose: expects nothing, has the side-effect of
//     printing to the screen the current data fields of the
//     calling PlayerChar instance, and returns nothing
//     (Every class definition should have such a method :-)

void PlayerChar::printPlayer() const {
    cout << "PlayerChar name:       " << name  << endl
         << "           strength:   " << strength  << endl
         << "           agility:    " << agility  << endl
         << "           type:       " << type << endl
         << "           current HP: " << hp << endl;
}

// method: battle: PlayerChar -> void
// purpose: expects a PlayerChar, returns nothing
// side effects: calculates damage to calling PlayerChar
//          and argument PlayerChar
//          reduces HP value of both PlayerChar objects
//          prints to the screen a battle result

void PlayerChar::battle(PlayerChar& opponent) {
    // Announce Battle
    cout << "*** BATTLE: " << this->getName()
         << " vs " << opponent.getName() << " *** " << endl;
            
    // If either PlayerChar has no remaining HP, return now
    if (this->getHP() <= 0.0) {
        cout << "   " << this->getName() << " has already fainted"
             << " -- no battle!" << endl;
        return;
    }
    if (opponent.getHP() <= 0.0) {
        cout << "   " << opponent.getName() << " has already fainted"
             << " -- no battle!" << endl;
        return;
    }
    
    // Print states of PlayerChars before battle
    cout << "Before battle:  " 
         << this->getName() << " has " << this->getHP() << " HP, "
         << opponent.getName() << " has " << opponent.getHP() << " HP "
         << endl;;
    
    // Battle! Calculate damage (remember damage to print later)
    double damage1 = opponent.getHP() * randPct();
    double damage2 = this->getHP() * randPct();
    
    // Set new values of HP (method will ensure HP stays >= 0)
    this->setHP(this->getHP() - damage1);
    opponent.setHP(opponent.getHP() - damage2);
    
    // Announce results
    cout << "*** BATTLE ***! "
         << this->getName() << " suffers " << damage1 << " damage, "
         << opponent.getName() << " suffers " << damage2 << " damage" << endl;

    if (this->getHP() <= 0.0)
        cout << this->getName() << " faints!" << endl << endl;
    if (opponent.getHP() <= 0.0)
        cout << opponent.getName() << " faints!" << endl << endl;
    
    if (this->getHP() > opponent.getHP())
        cout << "*** " << this->getName() << " wins! ***" << endl << endl;
    
    else if (opponent.getHP() > this->getHP())
        cout << "*** " << opponent.getName() << " wins! ***" << endl << endl;
    
    else
        cout << "*** It's a tie! How did that happen?? ***" << endl;

}   

// randPct: void -> double
// purpose: expects nothing
// returns a value from 0.01 to 1.00 in increments
// of 0.01 -- for use in battles between PlayerChars

double randPct() {
    double return_val;
    return_val = (rand() % 100 + 1) * 0.01;
    return return_val;
}

