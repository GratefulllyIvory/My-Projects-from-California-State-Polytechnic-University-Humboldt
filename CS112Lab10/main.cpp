/*---    CS 112 Fall 2020 - Week 10 Lab    C++ Derived Classes    David C. Tuttle    Last Modified: 28 Oct 2020---*/
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "PlayerChar.h"

using namespace std;
int main() {   
    
cout << boolalpha;   
cout << "*** CREATING PLAYERCHARS *** " << endl;  
// Let's create PlayerChars for our PlayerTeams   
PlayerChar *fred = new PlayerChar();   
PlayerChar *wilma = new PlayerChar("Wilma", "Elf");  
PlayerChar *barney = new PlayerChar("Barney", "Magician");
PlayerChar *betty = new PlayerChar("Betty", "Valkyrie"); 
PlayerChar *fred2 = new PlayerChar(*fred);  
cout << "*** CREATING TANKPLAYERCHARS *** " << endl;  
// Create TankPlayerChars here   
// Write statements to test the methods you wrote for  
// the derived TankPlayerChar class  

return EXIT_SUCCESS;
}