/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlayingCard.h
 * Author: David
 *
 * Created on November 13, 2020, 1:43 PM
 */

#ifndef PLAYINGCARD_H
#define PLAYINGCARD_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>

using namespace std;

// Declarations of data types and constants

const string rankNames[14] = {"ERROR", "Ace  ", "Two  ", "Three", "Four ",
                              "Five ", "Six  ", "Seven", "Eight", "Nine ",
                              "Ten  ", "Jack ", "Queen", "King "};

// Declarations of helper functions

string rankToString(int cardRank);
string suitToString(char cardSuit);

// Definition of class PlayingCard

class PlayingCard {
public:
    // Headers for constructors
    
    PlayingCard();           // Will default to Ace of Spades
    
    PlayingCard(int cardRank, char cardSuit);

    // Headers for accessors
    
    int getRank();
    char getSuit();
    
    // Headers for mutators
    
    void setRank(int newRank);
    void setSuit(char newSuit);
    
    // Headers for other functions
    
    void printCard();
    string cardToString();

    
protected:
    // member variables, data members, data fields
    // (Those all mean the same thing)
    
    int rank;   // 1=Ace, 11=Jack, 12=Queen, 13=King
    char suit;  //'H', 'D', 'C', or 'S'
    
    // Private methods
};

#endif /* PLAYINGCARD_H */

