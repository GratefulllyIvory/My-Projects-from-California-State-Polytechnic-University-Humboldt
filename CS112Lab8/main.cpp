//Daniel Desforges and Henry Morgan Lab 8 Fall 2020 CS112
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include "PlayerChar.h"
using namespace std;


int main() {
    
    PlayerChar Player1;
    
    Player1.set_str_agil("Nancy", "Valkyrie");
    Player1.create_Ogre("Michael");
    Player1.ogre_Fred();
    Player1.getAgility();
    Player1.getStrength();
    Player1.getName();
    Player1.getRole();
    Player1.increaseAgility(6);
    Player1.increaseStrength(4);
    Player1.print_player_info();
    

    return 0;
} 

