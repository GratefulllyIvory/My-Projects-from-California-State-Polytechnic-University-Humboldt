/*=====
 Daniel Desforges and Anthony Shucraft Fall 2020 Week 3
=====*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include "PlayerChar.h"
#include "PlayerTeam.h"
using namespace std;

int main() {
   cout << boolalpha;
   
   // To appropriately "seed" the random number generator, we call
   // the srand function once at the beginning of execution.
   // UPDATE THIS CODE AS NEEDED TO RUN CORRECTLY ON YOUR IDE!
   
   srand(time(NULL));

    /**********************************************************/
    // This block of code runs a 1-on-1 battle
    
    PlayerChar fred;
    fred.printPlayer();
    PlayerChar ariel("Ariel", "Sprite");
    ariel.printPlayer();

    // In this particular test, we have Fred and Ariel battle
    // until one has no more health points (and has "fainted")
    
    while (fred.getHP() > 0.0 && ariel.getHP() > 0.0)
        fred.battle(ariel);
    
    /**********************************************************/
    // This block of code tests the restoreHealth method

    // Restore the health of the PlayerChar objects
    // and print the player stats to confirm
    
    fred.restoreHealth();
    fred.printPlayer();
// 
    ariel.restoreHealth();
    ariel.printPlayer();


    /**********************************************************/
    // This block of code tests the PlayerTeam class

    // THIS CODE TESTS METHODS OF THE PlayerTeam CLASS
   
    PlayerTeam *team_1 = new PlayerTeam();
    PlayerTeam *team_2 = new PlayerTeam("Team 2");
   
    cout << "TEAM 1: " << team_1->getTeamName() << endl;
    cout << "TEAM 2: " << team_2->getTeamName() << endl;
    
    team_2->setTeamName("The Other Team");
    cout << "TEAM 2: " << team_2->getTeamName() << endl;
    
    team_1->setPlayer("Ariel", 100, 2.0, "Sprite", 0);
    team_2->setPlayer("Barney", 1000, 10.0, "Dinosaur", 4);
    
    team_1->printTeamPlayer(0);
    team_2->printTeamPlayer(4);
    
    team_1->resetPlayer(0);
    team_1->printTeamPlayer(0);    

   return EXIT_SUCCESS;
}

