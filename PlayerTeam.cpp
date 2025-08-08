//Daniel Desforges Cs112 Fall 2020

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include <valarray>
#include <vector>
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

PlayerTeam::PlayerTeam(string name, int size) {
    if (size <= 0) {
        cout << "*** ILLEGAL SIZE FOR TEAM! ***" << endl;
        return;
    }
    teamName = name;
    teamSize = size;
    teamVector;
    //new vector<PlayerType> teamVector;  
}

// PlayerTeam: void -> void
// Expects a team name, and an int for team's size
// Returns nothing
// Side effect: sets teamName to DEFAULT_TEAM_NAME
//              sets teamSize to DEAFULT_TEAM_SIZE
//              DYNAMICALLY ALLOCATES an array of PlayerChar
//              objects of the correct size, and points the
//              teamArray pointer to that array

PlayerTeam::PlayerTeam() {
    teamName = DEFAULT_TEAM_NAME;
    teamSize = DEFAULT_TEAM_SIZE;
    teamVector;
    //new vector<PlayerChar> teamVector; 
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

PlayerTeam::PlayerTeam(const PlayerTeam& a_team) {
    
    teamName = "Copy of " + a_team.getTeamName();
    //teamSize = a_team.getTeamSize();
    teamVector;
   // new vector<PlayerChar> teamVector; 
    for (int i=0; i< teamVector.size(); i++) {
        // Sigh, I can't just use this one assignment statement
        // because my compiler tells me the default copy constructor
        // isn't availble for PlayerChar - "would not be well-formed"
        // teamArray[i] = a_team.teamArray[i];
        
        // So instead, I'm forced to use the PlayerChar methods
        teamVector[i].setName(a_team.teamVector[i].getName());
        teamVector[i].setStrength(a_team.teamVector[i].getStrength());
        teamVector[i].setAgility(a_team.teamVector[i].getAgility());
        teamVector[i].setRole(a_team.teamVector[i].getRole());
    }
}

// DESTRUCTOR METHOD

PlayerTeam::~PlayerTeam() {
    delete teamVector;
}

// ACCESSORS

// getTeamName: void -> string
// Expects nothing
// Returns the PlayerTeam's name

string PlayerTeam::getTeamName() const {
    return teamName;
}

// getTeamSize: void -> int
// Expects nothing
// Returns the PlayerTeam's size

int PlayerTeam::getTeamSize() const {
    return teamVector.size();
}

// MUTATORS
PlayerTeam::addPlayer(PlayerChar& new_player){
    teamVector->push_back(new_player);
}
PlayerTeam::deletePlayer(int index_to_delete){
    teamVector->pop_back(index_to_delete);
}
PlayerTeam::setTeamName(const PlayerTeam& a_team){
    a_team = teamName;
}
// setPlayer: PlayerChar& const, int -> void
// Expects a PlayerChar and an index in the PlayerTeam array
// Returns nothing
// Side effect: Copies the PlayerChar info into the PlayerTeam
//              teamArray at that index

void PlayerTeam::setPlayer(const PlayerChar& a_player, int index) {
    if (index < 0 || index >= teamVector.size()) {
        cout << "*** Player not set - index " << index 
             << " out of bounds!" << endl;
        return;
    }
    teamVector[index].setName(a_player.getName());
    teamVector[index].setStrength(a_player.getStrength());
    teamVector[index].setAgility(a_player.getAgility());
    teamVector[index].setRole(a_player.getRole());
}

// OPERATOR OVERLOADING METHODS

bool PlayerTeam::operator ==(const PlayerTeam& rhs) {
    // If teams aren't the same size, they can't be equal!
    if (teamVector.getPower() - rhs.getPower() <= 100)
        return true;
    else
        return false;
   
    }
    
    // If we get to this point, then all values match, and they're equal
    return true;
}
// OTHER METHODS

// printTeam: void -> void
// Expects nothing (PlayerTeam is an implicit argument)
// Returns nothing
// Side effects:  Prints to the screen the team info

void PlayerTeam::printTeam() const {
    
    cout << "*** TEAM INFORMATION ***" << endl
         << "TEAM NAME IS     " << teamName << endl;
    for (int i=0; i<teamVector.size(); i++)
        teamVector[i].printPlayer();
    return;
}