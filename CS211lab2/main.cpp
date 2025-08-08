/*=====
    a small main "exercising" the parts of class PlayerChar

    last modified: 2021-01-26
=====*/
// Daniel Desforges and Karen Vargas Cs211 Spring 2021 lab2
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include "PlayerChar.h"
using namespace std;

int main()
{
    cout << boolalpha;
    srand(time(NULL));

    // Sample test code for trying out PlayerChar constructors

    PlayerChar angie("Angie", 450, 2.2, "Angel");

    // trying out accessors AND seeing if 4-argument constructor
    // set angie as expected

    cout << endl;
    cout << "Angie's initial info: " << endl;
    cout << angie.getName() << " " << angie.getStrength()
         << " " << angie.getAgility() << " " << angie.getType()
         << endl;

    // trying out other-method print_player_char

    cout << endl;
    cout << "Calling printPlayerChar: " << endl;
    angie.printPlayerChar();
    cout << endl;

    // BATTLE CODE!
    
    cout << "*** LET'S BATTLE! ***" << endl;
    
    PlayerChar fred;  // By default, he's Fred the Ogre
    fred.printPlayerChar();
    PlayerChar ariel("Ariel", "Sprite");
    ariel.printPlayerChar();
    cout << endl;

    while (fred.getHP() > 0 && ariel.getHP() > 0)
        fred.battle(ariel);
       
    return EXIT_SUCCESS;
}