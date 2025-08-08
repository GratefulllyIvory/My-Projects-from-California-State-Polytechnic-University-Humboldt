/*---
    CS 112 Fall 2020 - Assignment 04 SOLUTION
    C++ Classes and Derived Classes

    David C. Tuttle
    Last Modified: 13 Nov 2020
---*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "BridgeCard.h"

using namespace std;

// CONSTRUCTORS

BridgeCard::BridgeCard(): PlayingCard() {
    isTrumpSuit = false;  // No trump
}

BridgeCard::BridgeCard(int cardRank, char cardSuit, char trumpSuit): 
            PlayingCard(cardRank, cardSuit) {
    switch(trumpSuit) {
        case 'H':
        case 'h':
        case 'D':
        case 'd':
        case 'C':
        case 'c':
        case 'S':
        case 's':
        case 'N':
        case 'n':
            isTrumpSuit = (suit == toupper(trumpSuit));
            break;
        default:
            cout << "*** Invalid trump suit - trump not set   ***" << endl;
            isTrumpSuit = false;
    }
}

BridgeCard::BridgeCard(int cardRank, char cardSuit): 
            PlayingCard(cardRank, cardSuit) {
    isTrumpSuit = false;
}
// ACCESSORS

bool BridgeCard::getTrump() {
    return isTrumpSuit;
}

// MUTATORS

void BridgeCard::setTrump(char trumpSuit) {
    switch(trumpSuit) {
        case 'H':
        case 'h':
        case 'D':
        case 'd':
        case 'C':
        case 'c':
        case 'S':
        case 's':
        case 'N':
        case 'n':
            isTrumpSuit = (suit == toupper(trumpSuit));
            break;
        default:
            cout << "*** Invalid trump suit - trump not set   ***" << endl;
    }
}

// OTHER METHODS

void BridgeCard::printCard() {
    cout << rankToString(rank) << " of " << suitToString(suit);
    if (isTrumpSuit)
        cout << "*";
    else
        cout << " ";
    cout << endl;
}

string BridgeCard::cardToString() {
    string output_string;
    output_string = rankToString(rank) + " of " + suitToString(suit);
    if (isTrumpSuit)
        output_string += "*";
    else
        output_string += " ";
    return output_string;
}

