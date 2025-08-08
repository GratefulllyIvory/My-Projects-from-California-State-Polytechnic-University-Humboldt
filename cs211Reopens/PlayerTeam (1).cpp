// CS 211 Spring 2021 – Week 03 Lab
// Anthony Shucraft and Daniel Desforges


/*=====
 PlayerTeam
    implementation of the constructors and methods for
    a class representing a team of PlayerChars

    last modified: 2021-02-02
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

PlayerTeam::PlayerTeam(string name) {
    team_name = name;
    team_array = new PlayerChar[TEAM_SIZE];
    for (int i = 0; i < TEAM_SIZE; ++i) {
        team_array[i] = PlayerChar();
    }
}

PlayerTeam::PlayerTeam() {
    team_name = DEFAULT_TEAM_NAME;
    team_array = new PlayerChar[TEAM_SIZE];
    for (int i = 0; i < TEAM_SIZE; ++i) {
        team_array[i] = PlayerChar();
    }
}


// implement PlayerTeam's destructor 
PlayerTeam::~PlayerTeam() {
    delete [] team_array;
}

//=====
// implement PlayerTeam's accessors
string PlayerTeam::getTeamName() const {
    return team_name;
}

//=====
// implement PlayerTeam's mutators
void PlayerTeam::setPlayer(int arrPosition) {
    team_array[arrPosition] = PlayerChar();
}

void PlayerTeam::setPlayer(string name, string role, int arrPosition) {
    team_array[arrPosition] = PlayerChar(name, role);
}

void PlayerTeam::setPlayer(string name, int strength, double agility, string role, int arrPosition) {
    team_array[arrPosition] = PlayerChar(name, strength, agility, role);

}

void PlayerTeam::resetPlayer(int arrPosition) {
    team_array[arrPosition] = PlayerChar();
}
void PlayerTeam::setTeamName(string newName) {
    team_name = newName;
}

//Othor methods

void PlayerTeam::printTeamPlayer(int arrPosition) {
    team_array[arrPosition].printPlayer();
}




