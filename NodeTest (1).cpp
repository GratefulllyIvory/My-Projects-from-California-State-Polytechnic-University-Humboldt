
/*-------
  Signature: main: void -> int

  Purpose: testing program for the class Node

  Examples: when run, the following should be printed
      to the screen:

testing class Node - true means test passed:
--------------------------------------------
testing constructors and getters:
true
true
true
true
true
true
true
true

testing setters:
true
true
true

walking through little 4-node proto-list:
-----------------------------------------
next is pointing to node w/data: 100
next is pointing to node w/data: 200
next is pointing to node w/data: 300
next is pointing to node w/data: 400

  written by: Sharon Tuttle 
  modified by: David C. Tuttle
  modified by: <Daniel Desforges>
  last modified: 01 Feb 2021
--------*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <fstream>
#include "Node.h"

using namespace std;

int main() {
    cout << boolalpha << endl;

    // calling all 4 Node constructors
	Node newNode5;
    Node newNode4(&newNode5);
    Node newNode3(&newNode4);
    Node newNode2(200);
    Node newNode1(100, &newNode2);

    cout << "testing class Node - true means test passed:" << endl;
    cout << "--------------------------------------------" << endl; 

    // testing constructors and accessors

    cout << "testing constructors and getters:" << endl; 
	
	cout << (newNode5.getData() ==500) <<endl;
    cout << (newNode4.getData() == 0) << endl;
    cout << (newNode3.getData() == 0) << endl;
    cout << (newNode2.getData() == 200) << endl;
    cout << (newNode1.getData() == 100) <<  endl;

    cout << (newNode5.getLink() == NULL)
	cout << (newNode4.getLink() == &newNode5) << endl;
    cout << (newNode3.getLink() == &newNode4) << endl;
    cout << (newNode2.getLink() == NULL) << endl;
    cout << (newNode1.getLink() == &newNode2) << endl;

    // testing setters

    cout << endl;
    cout << "testing setters:" << endl;
	
    newNode4.setData(400);
    cout << (newNode4.getData() == 400) << endl;
    
    newNode3.setData(300);
    cout << (newNode3.getData() == 300) << endl;

    newNode2.setLink(&newNode3);
    cout << (newNode2.getLink() == &newNode3) << endl;

    // just for fun: "walk" through little proto-list

    cout << endl;
    cout << "Walking through little proto-list:" << endl;
    cout << "----------------------------------" << endl;

    Node *next;

    next = &newNode1;

    while (next != NULL) {
        cout << "next is pointing to node w/data: " 
                  << next->getData() << endl;
        next = next->getLink();
    }

    cout << endl;
    return EXIT_SUCCESS;
}
