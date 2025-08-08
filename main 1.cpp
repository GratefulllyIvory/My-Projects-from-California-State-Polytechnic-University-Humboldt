//---------------------------------------------------------------
// File: bag_play.cpp
// Name: <Jacob Rojeski> and <Daniel Desforges> Spring 2021
//
// Purpose: playing around with the class Bag
//--------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include "Bag.h"
using namespace std;

int main() {
    // declarations
    Bag bag1;
    Bag bag2(100);

    cout << boolalpha;
    cout << endl;
    cout << "Baby-Testing class Bag..." << endl;
    cout << endl;

    // verify the constructors and test the accessors/observers
    //        at the same time
    cout << "VERIFYING CONSTRUCTORS/ACCESSORS/OBSERVERS:" << endl;
    cout << endl;
    cout << "true means test passed, false means test failed:" << endl;
    cout << "-------------------------------------------" << endl;

    cout << (bag1.get_size() == 0) << endl;
    cout << (bag2.get_size() == 0) << endl;

    cout << (bag1.get_count(3) == 0) << endl;

    cout << (bag1.get_capacity() == 30) << endl;
    cout << (bag2.get_capacity() == 100) << endl;

    // verifying the modifiers

    cout << endl;
    cout << "VERIFYING MODIFIERS:" << endl;
    cout << endl;
    cout << "true means test passed, false means test failed:" << endl;
    cout << "-------------------------------------------" << endl;

    bag1.insert(3);
    bag1.insert(3);
    bag1.insert(4);
    bag1.insert(4);
    bag1.insert(4);

    cout << (bag1.get_size() == 5) << endl;
    cout << (bag1.get_count(3) == 2) << endl;
    cout << (bag1.get_count(4) == 3) << endl;

    bag1.erase(4);
    bag1.erase_one(3);

    cout << (bag1.get_size() == 1) << endl;
    cout << (bag1.get_count(3) == 1) << endl;
    cout << (bag1.get_count(4) == 0) << endl;

    bag1.reserve(1000);

    cout << (bag1.get_capacity() == 1000) << endl;
    cout << (bag1.get_size() == 1) << endl;
    cout << (bag1.get_count(3) == 1) << endl;
    cout << (bag1.get_count(4) == 0) << endl;

    // other methods/operators tests -- can use same basic approach as
    //        for functions, except they can be included in this same
    //        testing function.

    return EXIT_SUCCESS;
}


