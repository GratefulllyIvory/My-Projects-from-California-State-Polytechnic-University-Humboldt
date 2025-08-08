//Daniel Desforges Cs112 Fall 2020t Modified: 22 Oct 2020


#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "PlayerChar.h"
#include "PlayerTeam.h"
#include <vector>

using namespace std;

int main() {
    cout << boolalpha;
    
    cout << "*** CREATING PLAYERCHARS *** " << endl;
    
    // Let's create PlayerChars for our PlayerTeams
    
    PlayerChar *fred = new PlayerChar();
    PlayerChar *wilma = new PlayerChar("Wilma", "Elf");
    PlayerChar *barney = new PlayerChar("Barney", "Magician");
    PlayerChar *betty = new PlayerChar("Betty", "Valkyrie");
        
    cout << "*** TESTING THE PLAYERTEAM METHODS *** " << endl;
    
    // TESTING FIRST CONSTRUCTOR
    PlayerTeam *team_1 = new PlayerTeam("TEAM 1", 2);
    team_1->setPlayer(*fred, 0);
    team_1->setPlayer(*barney, 1);
    team_1->printTeam();
    cout << endl;
    
    // TESTING SECOND CONSTRUCTOR
    PlayerTeam *team_2 = new PlayerTeam();
    team_2->setPlayer(*fred, 0);
    team_2->setPlayer(*wilma, 1);
    team_2->setPlayer(*barney, 2);
    team_2->printTeam();
    
    // TESTING COPY CONSTRUCTOR
    PlayerTeam *team_3 = new PlayerTeam(*team_1);
    team_3->printTeam();
    
    // TESTING DESRUCTOR
    PlayerTeam *team_4 = new PlayerTeam("TEAM 4",1);
    team_4->setPlayer(*betty, 0);
    team_4->printTeam();
    
    delete team_4;
    
    // TESTING == OPERATOR METHOD
    
    cout << "TEAM 1 SHOULD *NOT* EQUAL TEAM2" << endl;
    if (*team_1 == *team_2)
        cout << "TEAM 1 EQUALS TEAM 2!" << endl;
    else
        cout << "TEAM 1 DOES NOT EQUAL TEAM 2!" << endl;
    
    cout << "TEAM 1 SHOULD EQUAL TEAM3" << endl;
    if (*team_1 == *team_3)
        cout << "TEAM 1 EQUALS TEAM 3!" << endl;
    else
        cout << "TEAM 1 DOES NOT EQUAL TEAM 3!" << endl;
    
    return EXIT_SUCCESS;
}
