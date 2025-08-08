// Daniel Desforges and Morgan Plants
// CS112 Lab 5 Fall 2020

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "PlayerChar.h"

using namespace std;

int main()
{
    cout << boolalpha;
    
    // INTRO TO C++ CLASSES
    // Classes have struct features, and a LOT more!
    // Intro to Object-Oriented Programming (OOP)
    
    // Today's goals: Show you a C++ Class, write 
    //    some functions for the Class (which are
    //    called Methods), and create instantiations
    //    (declaration) of an instance of a class
    //    which we call an Object
    
    // History of structs and classes
    // In the C language, there were only structs
    // In the C++ language, Object-Oriented features
    // were added to the old C language
    // and structs (while still existing) evolved
    // into classes
   
    // Classes feature control of access to the data
    // members, known as "information hiding"
    // Reasons to do so include data validation
    
    // VOCABULARY
    // Member Variables or Data Fields that the
    //   class will contain (just like a struct)
    // Member Functions or METHODS that can retrieve,
    //   mutate, or perform other actions with the
    //   member variables
    // An OBJECT is an instance of a class
    // Certain Types of Methods:
    //   CONSTRUCTOR - Create instance of a class (object)
    //   ACCESSOR (or "getter") to get the value of
    //      a member variable
    //   MUTATOR (or "setter") to set the value of
    //      a member variable
    // 
    // The PUBLIC part of the Class definition is 
    // what users are allowed to access -- some
    // data members may be PUBLIC, and methods that
    // users call are also PUBLIC
    //
    // The PRIVATE part of the Class definition is
    // what users are NOT allowed to access directly
    
    // See PlayerChar.h for the public method headers
    // and private data fields
    
    // See PlayerChar.cpp for the methods
    
    // Declaration of an object of type PlayerChar
    
    PlayerChar david_player;
    
    
    david_player.set_name("David");
    david_player.set_strength(9001);
    david_player.set_agility(7.10);
    david_player.set_role("Mage");
    david_player.increase_strength(100);
    david_player.reset_strength();
    david_player.agility_boost(100);
    
    //redundant player to show increase strength execution
   PlayerChar daniel_player;
   
   daniel_player.set_name("Daniel");
   daniel_player.set_strength(700);
   daniel_player.increase_strength(520);
   
   PlayerChar copy_char(david_player);
    // Call to a PlayerChar method
    
    david_player.print_player_info();
    cout << "" << endl;
    daniel_player.print_player_info();
    cout << "" << endl;
    copy_char.print_player_info();
    
    return EXIT_SUCCESS;
}