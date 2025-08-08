/*=====
 PlayerTeam
    implementation of the constructors and methods for
    a class representing a team of PlayerChars

    Daniel Desforges and Anthony Shucraft Fall 2020 Week 3
=====*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include "PlayerTeam.h"
#include "PlayerChar.h"
using namespace std;

// implement PlayerTeam's constructors 
PlayerTeam::PlayerTeam(string name){
    team_name = name;
    team_array = new PlayerTeam[TEAM_SIZE];
}

// implement PlayerTeam's destructor 
PlayerTeam::PlayerTeam(){
   delete PlayerTeam; 
}

//=====
// implement PlayerTeam's accessors
void PlayerTeam::setTeamName(){
    return 0;
}
void PlayerTeam

//=====
// implement PlayerTeam's mutators
