
/*---
 Daniel Desforges CS112 Fall 2020 Assignment 3
---*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "PlayerChar.h"

using namespace std;


//Constructors
PlayerChar::set_str_agil(string new_name, string new_role)
{
    int i;
    if(new_role == stdPlayer[i].role)
    {
        strength = stdPlayer[i].strength;
        agility = stdPlayer[i].agility;
        role= stdPlayer[i].role;
    }
    else{
        stdPlayer[1];
    }
    return 0;
}

PlayerChar::create_Ogre(string new_name)
{
   stdPlayer[1];
   return 0;
   
}

PlayerChar::ogre_Fred()
{
    name = "Fred";
    strength = 700;
    agility = 2.5;
    role = "Ogre";
    return 0;
}
//Accessor
string PlayerChar::getName() 
{
    return name;
}

int PlayerChar::getStrength()
{
   return strength;
}
double PlayerChar::getAgility()
{
    return agility;
}
string PlayerChar::getRole() 
{
   return role;
}

//Mutator
void PlayerChar:: setName(string newName) {
   name = newName;
}
void PlayerChar::setStrength(int newStrength) {
    strength = newStrength;
}
void PlayerChar::setAgility(double newAgility) {
    agility = newAgility;
}
void PlayerChar::setRole(string newRole) {
    role = newRole;
}

PlayerChar::increaseStrength(int pump)
{
    if(strength <= 2*strength){
    while(pump<10)
    {
        if(pump >= 0){
            strength += strength* pump/100;
        }
        else {
            strength -=strength *pump/100;
        }
    }
}
    return 0;
}


PlayerChar::increaseAgility(double boost)
{
    if(agility <= 2*agility){
    while(boost<10)
    {
        if(boost >= 0){
            agility += agility* boost/100;
        }
        else {
            agility -= agility *boost/100;
        }
}
}
    return 0;
    
}
 

//Other Methods
PlayerChar::printPlayer(){
cout << "NAME IS " << name << endl
         << "STRENGTH IS " << strength << endl
         << "AGILITY IS " << agility << endl
         << "ROLE IS " << role << endl;

} 