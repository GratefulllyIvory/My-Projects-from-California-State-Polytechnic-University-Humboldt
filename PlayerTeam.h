// CS 112 Fall 2020 - Week 09 Lab
// Skyler Kona and Anthony Shucraft and Daniel Desforges (We got 3! Yay!)

/*
 * CS 112 Fall 2020 - Week 09 Lab
 *     C++ Classes and Methods
 */

/* 
 * File:   PlayerTeam.h
 * Author: David
 *
 * Created on October 22, 2020, 11:11 PM
 */

#ifndef PLAYERTEAM_H
#define PLAYERTEAM_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>

using namespace std;

// Declarations of data types and constants

const string DEFAULT_TEAM_NAME = "MY TEAM";
const int DEFAULT_TEAM_SIZE = 3;

// Definition of class PlayerChar

class PlayerTeam {
public:

    // Place Headers for Constructors here
    
    PlayerTeam(string name, int size);
    PlayerTeam();
    PlayerTeam(const PlayerTeam& a_team);

    // Place Header for Destructor here

    ~PlayerTeam();
    
    // Headers for accessors
    
    string getTeamName() const;
    int getTeamSize() const;
    PlayerChar getPlayer(int playernum) const;
    
    // Headers for mutators
    
    void setPlayer(const PlayerChar& a_player, int index);
    
    // Headers for other functions
    
    printTeam() const;

    // Place header for == operator method here
    
    bool operator ==(PlayerTeam& rhs);
    
private:
    
    // The name of the PlayerTeam
    string teamName;
    
    // The number of the players in the PlayerTeam
    int teamSize;
    
    // A pointer to the PlayerChar array
    // It only needs to be a pointer to an individual PlayerChar
    // You can still use an index on it, like this:  teamArray[i]
    PlayerChar *teamArray;   
};

#endif /* PLAYERTEAM_H */

