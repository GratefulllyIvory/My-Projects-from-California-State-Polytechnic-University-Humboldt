/*---
    CS 112 Fall 2020 - Assignment 4 SOLUTION
    C++ Base Classes and Derived Classes

    David C. Tuttle
    Last Modified: 13 Nov 2020
---*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "PlayingCard.h"

using namespace std;

// Helper functions (CAN be methods, buy we'll avoid redefining this way!)

string rankToString(int cardRank) {
    if (cardRank < 1 || cardRank > 13)
        return rankNames[0];
    else
        return rankNames[cardRank];
}

string suitToString(char cardSuit) {
    switch(cardSuit) {
        case 'H':
        case 'h':
            return "Hearts";
        case 'D':
        case 'd':
            return "Diamonds";
        case 'C':
        case 'c':
            return "Clubs";
        case 'S':
        case 's':
            return "Spades";
        default:
            return "*ERROR*";
    }  
}

// CONSTRUCTORS

PlayingCard::PlayingCard() {
    rank = 1;    // Default rank is Ace
    suit = 'S';  // Default suit is Spades
}

PlayingCard::PlayingCard(int cardRank, char cardSuit) {
    // Validity checking for passed values
    if (cardRank < 1 || cardRank > 13) {
        cout << "*** Invalid rank passed, set to Ace      ***" << endl;
        rank = 1;
    }
    else
        rank = cardRank;
    
    switch(cardSuit) {
        case 'H':
        case 'h':
            suit = 'H';
            break;
        case 'D':
        case 'd':
            suit = 'D';
            break;
        case 'C':
        case 'c':
            suit = 'C';
            break;
        case 'S':
        case 's':
            suit = 'S';
            break;
        default:
            cout << "*** Invalid suit passed, set to Spades   ***" << endl;
            suit = 'S';
    }
}

// ACCESSORS

int PlayingCard::getRank() {
    return rank;
}

char PlayingCard::getSuit() {
    return suit;
}

// MUTATORS

void PlayingCard::setRank(int newRank) {
    if (newRank < 1 || newRank > 13)
        cout << "*** Invalid rank passed, rank unchanged   ***" << endl;
    else
        rank = newRank;   
}

void PlayingCard::setSuit(char newSuit) {
    
    switch(newSuit) {
        case 'H':
        case 'h':
            suit = 'H';
            break;
        case 'D':
        case 'd':
            suit = 'D';
            break;
        case 'C':
        case 'c':
            suit = 'C';
            break;
        case 'S':
        case 's':
            suit = 'S';
            break;
        default:
            cout << "*** Invalid suit passed, suit unchanged   ***" << endl;
    }
    
}

// OTHER METHODS

void PlayingCard::printCard() {
    cout << rankToString(rank) << " of " << suitToString(suit) << endl;
}

string PlayingCard::cardToString() {
    return rankToString(rank) + " of " + suitToString(suit);
}

