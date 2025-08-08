/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BridgeCard.h
 * Author: David
 *
 * Created on November 13, 2020, 1:50 PM
 */

#ifndef BRIDGECARD_H
#define BRIDGECARD_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "PlayingCard.h"

using namespace std;

// Declarations of data types and constants

// Definition of class BridgeCard

class BridgeCard: public PlayingCard {
public:

    // Headers for constructors
    
    BridgeCard();  // Default is Ace of Spades, trump=false
    
    BridgeCard(int cardRank, char cardSuit, char trumpSuit);
                   // Note that last parameter isn't a bool!
    BridgeCard(int cardRank, char cardSuit);  // default trump=false
    
    // Headers for accessors
    
    bool getTrump();
    
    // Headers for mutators
    
    void setTrump(char trumpSuit);  // Note parameter isn't a bool!
    
    // Headers for other functions
    
    void printCard();
    string cardToString();
    
private:
    // member variables, data members, data fields
    // (Those all mean the same thing)
    
    bool isTrumpSuit;
    
    // Private methods
    
};


#endif /* BRIDGECARD_H */

