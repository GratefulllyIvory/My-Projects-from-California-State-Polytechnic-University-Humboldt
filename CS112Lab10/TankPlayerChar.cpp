// CS 112 Fall 2020 – Week 10 Lab
// <Sergio Monterroso> and <Daniel Desforges>
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "PlayerChar.h"
#include "TankPlayerChar.h"

//Constructors
TankPlayerChar::TankPlayerChar(string init_name, string init_role)
{
    setName(init_name);
    setRole(init_role);
    aggro = (getStrength() / 2);
    stamina = (getStrength() * getAgility() * 2);
}

TankPlayerChar::TankPlayerChar(string init_name)
{
    setName(init_name);
    aggro = (getStrength() / 2);
    stamina = (getStrength() * getAgility() * 2);
}

TankPlayerChar::TankPlayerChar()
{
    aggro = (getStrength() / 2);
    stamina = (getStrength() * getAgility() * 2);
}

//Accessors
int TankPlayerChar::getAggro()
{
    return aggro;
}

double TankPlayerChar::getStamina()
{
    return stamina;
}

//Mutators
TankPlayerChar::setAggro(int init_aggro)
{
    aggro = init_aggro;
}

TankPlayerChar::setStamina(double init_stamina)
{
    stamina = init_stamina;
}

//Methods
TankPlayerChar::printPlayer()
{
    cout << "***  TANK CHARACTER INFORMATION ***" << endl
         << "NAME IS     " << getName() << endl
         << "STRENGTH IS " << getStrength() << endl
         << "AGILITY IS  " << getAgility() << endl
         << "ROLE IS     " << getRole() << endl
         << "AGRRO IS    " << aggro << endl
         << "STAMINA IS  " << stamina << endl;   
}

bool TankPlayerChar::operator ==(const TankPlayerChar& rhs)
{
    bool nameEqual = (getName() == rhs.getName());
    bool strengthEqual = (getStrength() == rhs.getStrength());
    bool agilityEqual =
         (abs(getAgility() - rhs.getAgility()) < 0.01 );
    bool roleEqual = (getRole() == rhs.getRole());
    bool aggroEqual = (aggro == rhs.aggro);
    bool staminaEqual = (stamina == rhs.stamina);
    
    return (nameEqual && strengthEqual &&
            agilityEqual && roleEqual);
}