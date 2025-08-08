/*---
    CS 112 Fall 2020 - Week 12 Lecture 1
    C++ Abstract Methods, and Vectors

    David C. Tuttle
    Last Modified: 10 Nov 2020
---*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include <vector>

using namespace std;

int main() {
    cout << boolalpha;
    
    // First, a discussion of ABSTRACT CLASSES, also called INTERFACES
    
    // An ABSTRACT CLASS will describe behavior that a C++ class promises
    // to deliver, without the abstract class coding it itself.
    
    // Suppose a base class has a method defined, and a derived class then
    // redefines that method, using the same number and type of arguments.
    
    // This naturally introduces the possibility that a base class might
    // be written to have a method it does not supply at all, but instead
    // relies of derived classes to provide the "redefined" method.
    
    // This leads to the concept of an ABSTRACT CLASS, which says that
    // a derived class will provide method(s) that match the headers in
    // the abstract class, but the abstract class does not provide code
    // (for SOME of the methods - the abstract class MAY have actual code
    // for other methods.)
    
    // Think of it as a set of specifications, a guarantee that a derived
    // class will provide a particular method meeting the specifications.
    
    // Programming languages like Java and Python do NOT offer multiple
    // inheritance like C++ does.  So what does Java offer in place of
    // multiple inheritance?  Java offers INTERFACES that mimic the
    // properties of a base class but do not officialy pass inheritance
    // to a derived class, other than the guarantee that an interface
    // provides.
    
    // ABSTRACT CLASS EXAMPLE
    
//    class Box {
//    public:
//        // Only a virtual function that expects to be redefined
//        virtual double getVolume() = 0.0;
//        
//    private:
//        double length;
//        double width;
//        double height;
//    };
    
    // NO constructors are specified in an abstract class
    // It's not possible to say "new Box()"
    
    // Another example of an ABSTRACT class
    
//    class Shape {
//    public:
//        // NOTICE THE LACK OF CONSTRUCTORS HERE!
//        virtual int getArea() = 0;  // ABSTRACT method, subclass is
//                                    // obligated to provide code
//
//        // In this example, we actually have 2 mutator methods with code
//        void setWidth(int w) {
//            width = w;
//        }
//        void setHeight(int h) {
//            height = h;
//        }
//        
//    protected:
//        int width;
//        int height;
//  
//    };
//    
//    // Two derived classes that inherit the abstract class
//    // (and thus are required to define getArea() as seen in Shape)
//
//    class Rectangle: public Shape {
//    public:
//        int getArea() {
//            return width * height;
//        }
//    };
//    
//    class Triangle: public Shape {
//        int getArea() {
//            return (width * height / 2);
//        }
//    };
    
    // And now for something completely different...
    
    // VECTORS in C++ - an implementation of array-like objects that
    // have additional features, the most prominent of which is being
    // dynamically variable in size (introduced in 2003)
    
    // Recall that arrays require passing two arguments to a function/method
    // one is the array and the other is its size - YUCK!
      
    // In order to demonstrate VECTORS, a C++ object-based implementation
    // of an array-like "data structure", or "abstract data type"
    
    cout << "*** DEMONSTRATION OF VECTORS ***" << endl;

    // First, let's set up a traditional array   
    
    const int DECLARED_SIZE = 5;
    int myArray[DECLARED_SIZE];
    int next = 0;
    int index = 0;

    cout << "Enter up to " << DECLARED_SIZE
            << " integers and use 99999 when finished" << endl;

    cin >> next;
    while (next != 99999 and index < DECLARED_SIZE) {
        myArray[index] = next;
        index++;
        cin >> next;
    }

    int numberUsed = index;
    
    cout << "The values entered into the array are: ";
    for (int i=0; i<numberUsed; i++)
        cout << myArray[i] << " ";
    cout << endl;
    
    // Now let's have fun with VECTORS!
    
    vector<int> myVector;
    
    // This declaration creates a "generic" integer vector
    // with size 0 and capacity 0
    // Size and capacity are different!  Size is how many elements
    // the vector currently stores, and capacity is the number of
    // items the vector has room for (though it will expand automatically
    // should the need arise, usually by doubling capacity)
    
    cout << "The vector's capacity is " << myVector.capacity() << endl;
    cout << "The vector's current size is " << myVector.size() << endl;
    
    // The push_back method adds a new element to the "end" of the vector
    
    for (int i=0; i<numberUsed; i++) {
        myVector.push_back(myArray[i] * 7);
    }

    cout << "The vector's capacity is " << myVector.capacity() << endl;
    cout << "The vector's current size is " << myVector.size() << endl;
    
    for (int i=0; i<numberUsed; i++)
        cout << myVector[i] << " ";
    cout << endl;
    
    // Let's add more elements to the vector, and see its capacity increase
    // again!
    
    for (int i=numberUsed; i<numberUsed + 3; i++)
        myVector.push_back(7 * i);
    cout << endl;

    cout << "The vector's capacity is " << myVector.capacity() << endl;
    cout << "The vector's current size is " << myVector.size() << endl;
    
    for (int i=0; i<myVector.size(); i++)
        cout << myVector[i] << " ";
    cout << endl;

    // The pop_back method removes an item from the end of the vector
    
    cout << "Let's remove three items from the vector: ";
    for (int i=0; i<3; i++)
        myVector.pop_back();
    cout << endl;

    cout << "The vector's capacity is " << myVector.capacity() << endl;
    cout << "The vector's current size is " << myVector.size() << endl;
    
    for (int i=0; i<myVector.size(); i++)
        cout << myVector[i] << " ";
    cout << endl;
    
    // myVector.front()  returns the 1st element in the vector
    // myVector.at(n)    returns the element at the nth index
    // myVector[n]       also represents the nth index of the vector
    // myVector.back()   returns the last element in the vector
    // myVector.insert(i,n)  insert value n at the ith position
    //                       (shifts the values after it one position over)
    // myVector.clear()  emptys the vector
    
    cout << "at(2) returns " << myVector.at(2) << " and index 2 is "
            << myVector[2] << endl;

    // Constructors!
    
    vector<int> *newVectorPtr = new vector<int>;

    // This copies the entire vector's values into *newVectorPtr
    *newVectorPtr = myVector;
    
    cout << " New Vector's contents: ";
    
    for (int i=0; i<(*newVectorPtr).size(); i++)
        cout << (*newVectorPtr)[i] << " ";
    cout << endl;
    
    // Copy Constructor example
    
    vector<int> copyVector(*newVectorPtr);
    
    // The typedef statement could let me be even more abstract in the
    // use of the vector
    
    // Place this statement at the beginning of the .cpp or .h file
    // (If defining a class that uses vectors, place in .h file)
    
    typedef int T;
    
    // I can now refer to the vector in my code as vector<T>
    
    // This vector<T> syntax is standard usage in the Standard Template Library!
    
    return EXIT_SUCCESS;
    
}