/*
 *Daniel Desforges and Anthony Shucraft Fall 2020 Week 3
 */
#include "PlayerChar.h" 

#ifndef PLAYERTEAM_H
#define PLAYERTEAM_H

// CONSTANT DECLARATIONS

// TEAM_NAME is the default name for a PlayerTeam
const string DEFAULT_TEAM_NAME = "Team of Players";

// TEAM_SIZE sets the number of PlayerChars on a team
// Use this constant in allocating PlayerTeam arrays!
const int TEAM_SIZE = 5;

class PlayerTeam {
    public:


    private: 
        string team_name;
        PlayerChar *team_array;

};   // DO NOT FORGET the SEMICOLON!!!!!!!!

#endif /* PLAYERTEAM_H */

