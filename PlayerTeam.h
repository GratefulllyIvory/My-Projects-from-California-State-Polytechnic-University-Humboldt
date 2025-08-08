//Daniel Desforges Cs112 Fall 2020

#ifndef PLAYERTEAM_H
#define PLAYERTEAM_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include <vector>

using namespace std;

// Declarations of data types and constants

const string DEFAULT_TEAM_NAME = "MY TEAM";
const int DEFAULT_TEAM_SIZE = 3;

// Definition of class PlayerChar

class PlayerTeam {
public:

    // Place Headers for Constructors here
    
    PlayerTeam(string, int);
    PlayerTeam();
    PlayerTeam(const PlayerTeam&);

    // Place Header for Destructor here

    ~PlayerTeam();

    // Headers for accessors
    
    string getTeamName() const;
    int getTeamSize() const;
    
    // Headers for mutators
    addPlayer(PlayerChar& new_player);
    
    deletePlayer(int index_to_delete);
    
    void setPlayer(const PlayerChar& a_player, int index);
    //Change Team Name Header
    void setTeamName(const PlayerTeam& a_team);
    // Headers for other functions
    
    void printTeam() const;
    bool operator ==(const PlayerTeam& rhs);
    
    
private:
    
    // The name of the PlayerTeam
    string teamName;
    
    // The number of the players in the PlayerTeam
    int teamSize;
    
    // A PlayerChar Vector
    vector<PlayerChar> *teamVector;
    
    //Player Team Vector?
    //vector<PlayerTeam> *teamVector;
};

#endif /* PLAYERTEAM_H */

