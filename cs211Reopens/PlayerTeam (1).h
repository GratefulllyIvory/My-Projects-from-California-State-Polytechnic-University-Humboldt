// CS 211 Spring 2021 – Week 03 Lab
// Anthony Shucraft and Daniel Desforges

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlayerTeam.h
 * Author: David C. Tuttle
 *
 * Modified on February 2, 2021
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
    PlayerTeam(string name);
    PlayerTeam();
    ~PlayerTeam();
    string getTeamName() const;
    void setTeamName(string newName);
    void setPlayer(int arrPosition);
    void setPlayer(string name, string role, int arrPosition);
    void setPlayer(string, int strength, double agility, string  role, int arrPosition);
    void resetPlayer(int arrPosition);
    void printTeamPlayer(int arrPosition);
    private: 
        string team_name;
        PlayerChar *team_array;

};   // DO NOT FORGET the SEMICOLON!!!!!!!!

#endif /* PLAYERTEAM_H */

