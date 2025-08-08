// CS 112 Fall 2020 – Week 10 Lab
// <Sergio Monterroso> and <Daniel Desforges>
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TankPlayerChar.h
 * Author: Sergio
 *
 * Created on October 30, 2020, 11:13 AM
 */

#ifndef TANKPLAYERCHAR_H
#define TANKPLAYERCHAR_H

#include <string>
#include <cstdlib> 
using namespace std;

class TankPlayerChar: public PlayerChar
{
    private:
        int aggro;
        double stamina;
    public:
        //Constructors
        TankPlayerChar(string name, string role);
        TankPlayerChar(string name);
        TankPlayerChar();
        //Accessors
        int getAggro();
        double getStamina();
        //Mutators
        setAggro(int init_aggro);
        setStamina(double init_stamina);
        //Methods
        printPlayer();
        bool operator ==(const TankPlayerChar& rhs);
};

#endif /* TANKPLAYERCHAR_H */

