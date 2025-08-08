// CS 112 Fall 2020 - Week 09 Lab
// Skyler Kona and Anthony Shucraft and Daniel Desforges (We got 3! Yay!)

/*---
    CS 112 Fall 2020 - Week 09 Lab
    C++ Classes and Methods

    David C. Tuttle
    Last Modified: 22 Oct 2020
---*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "PlayerChar.h"
#include "PlayerTeam.h"

using namespace std;

// CONSTRUCTORS

// PlayerTeam: string int -> void
// Expects a team name, and an int for team's size
// Returns nothing
// Side effect: sets teamName to passed string value
//              sets teamSize to passed int value
//              DYNAMICALLY ALLOCATES an array of PlayerChar
//              objects of the correct size, and points the
//              teamArray pointer to that array

/*** Place code for constructor method here ***/

PlayerTeam::PlayerTeam(string name, int size){
    teamName = name;
    teamSize = size;
    teamArray = new PlayerChar[teamSize];
}

// PlayerTeam: void -> void
// Expects a team name, and an int for team's size
// Returns nothing
// Side effect: sets teamName to DEFAULT_TEAM_NAME
//              sets teamSize to DEAFULT_TEAM_SIZE
//              DYNAMICALLY ALLOCATES an array of PlayerChar
//              objects of the correct size, and points the
//              teamArray pointer to that array

/*** Place code for constructor method here ***/

PlayerTeam::PlayerTeam(){
    teamName = DEFAULT_TEAM_NAME;
    teamSize = DEFAULT_TEAM_SIZE;
    teamArray = new PlayerChar[teamSize];
}

// PlayerTeam: const PlayerTeam& -> void
// Expects a PlayerTeam object
// Returns nothing
// Side effect: Sets teamName to "Copy of " + teamName of
//              passed PlayerTeam object
//              Sets teamSize to teamSize of passed object
//              DYNAMICALLY ALLOCATES an array of PlayerChar
//              objects of the correct size, and copes each
//              PlayerChar from the passed PlayerTeam's array
//              to the new array

/*** Place code for copy constructor method here ***/

PlayerTeam::PlayerTeam(const PlayerTeam& a_team){
    teamName = a_team.getTeamName();
    teamSize = a_team.getTeamSize();
    teamArray = new PlayerChar[teamSize];
}

// DESTRUCTOR METHOD

/*** Place code for destructor method here ***/

PlayerTeam::~PlayerTeam(){
    cout << "Divided array by zero" << endl;
//    delete teamArray;
    // remember us? we were the one with the deletion issue
}

// ACCESSORS

// getTeamName: void -> string
// Expects nothing
// Returns the PlayerTeam's name

string PlayerTeam::getTeamName() const {
    return teamName;
}
PlayerChar PlayerTeam::getPlayer(int playernum) const{
    return teamArray[playernum];
}

// getTeamSize: void -> int
// Expects nothing
// Returns the PlayerTeam's size

int PlayerTeam::getTeamSize() const {
    return teamSize;
}

// MUTATORS

// setPlayer: PlayerChar& const, int -> void
// Expects a PlayerChar and an index in the PlayerTeam array
// Returns nothing
// Side effect: Copies the PlayerChar info into the PlayerTeam
//              teamArray at that index

void PlayerTeam::setPlayer(const PlayerChar& a_player, int index) {
    if (index < 0 || index >= teamSize) {
        cout << "*** Player not set - index out of bounds!" << endl;
        return;
    }
    teamArray[index].setName(a_player.getName());
    teamArray[index].setStrength(a_player.getStrength());
    teamArray[index].setAgility(a_player.getAgility());
    teamArray[index].setRole(a_player.getRole());
}

// OPERATOR OVERLOADING METHODS

/*** Place code for == operator method here ***/

bool PlayerTeam::operator ==(PlayerTeam& rhs){
    bool stillequal = (teamSize == rhs.getTeamSize());
    for (int i = 0; i < teamSize; i++){
        if (teamArray[i].getRole() != rhs.teamArray[i].getRole()){
            stillequal = false;
        }
    }
}

// OTHER METHODS

// printTeam: void -> void
// Expects nothing (PlayerTeam is an implicit argument)
// Returns nothing
// Side effects:  Prints to the screen the team info

PlayerTeam::printTeam() const {
    
    cout << "*** TEAM INFORMATION ***" << endl
         << "TEAM NAME IS     " << teamName << endl;
    for (int i=0; i<teamSize; i++)
        teamArray[i].printPlayer();

}