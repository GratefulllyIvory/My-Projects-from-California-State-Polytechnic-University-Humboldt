/************************************************************/
/* ADAPTED FROM:                                            */
/* http://www.cs.colorado.edu/~main/chapter4/bag2.h         */
/*                                                          */
/* Main and Savitch, "Data Structures and Other Objects     */
/*    using C++", 2nd edition, Addison-Wesley, Ch.4, p. 172 */
/************************************************************/

//-----------------------------------------------------------
// File: Bag.h
// Name: <Jacob Rojeski> and <Daniel Desforges> Spring 2021
//
// Class: Bag (a container class for a collection of items)
//
// VALUE SEMANTICS for the Bag class:
//    Assignments and the copy constructor may be used
//       with Bag objects.
//
// DYNAMIC MEMORY USAGE by the Bag:
//    If there is insufficient dynamic memory, then the
//       following functions throw bad_alloc:
//          The constructors, reserve, insert, operator +=,
//          operator +, and the assignment operator.
//-----------------------------------------------------------

#ifndef BAG_H
#define BAG_H

#include <cstdlib>  // Provides size_t
using namespace std;

class Bag {
    public:

        /****************************************************/
        /* TYPEDEFS and MEMBER CONSTANTS for the Bag class  */
        /****************************************************/

        // Bag::value_type is the data type of the items in the
        //    Bag. It may be any of the C++ built-in types
        //    (int, char, etc.), or a class with a default
        //    constructor, an assignment operator, and
        //    operators to test for equality (x == y) and
        //    non-equality (x != y).
        //
        // (CHANGE to desired type...)
        //
        typedef int value_type;

        // Bag::DEFAULT_CAPACITY is the initial capacity of a
        //    Bag that is created by the default constructor.
        //
        static const size_t DEFAULT_CAPACITY = 30;

        /****************************************************/
        /* CONSTRUCTORS and DESTRUCTOR                      */
        /****************************************************/

        // assumption regarding Bag capacity:
        //    The insert member function will work efficiently
        //    (without allocating new memory) until this
        //    capacity is reached.

        // postcondition: creates an empty Bag instance with an
        //    initial capacity of DEFAULT_CAPACITY
        //
        Bag();

        // postcondition: creates an empty Bag instance with an
        //    initial capacity of initial_capacity
        //
	    Bag(size_t initial_capacity);

        // copy constructor
        //
        Bag(const Bag& source);

        // destructor
        //
        ~Bag();

        /*************************************************************/
        /* ACCESSORS and other constant member functions (observers) */
        /*************************************************************/

        // postcondition: returns the number of items in the Bag.
        //
        size_t get_size() const {
            return used;
        }

        // postcondition: returns the number of times that target
        //    is in the Bag.
        //
	    size_t get_count(const value_type& target) const;

        // postcondition: returns the current capacity of this
        //    Bag (course text doesn't include --- but should,
        //    if it's going to have reserve() function)
        //
        size_t get_capacity() const {
            return capacity;
        }

        /****************************************************/
        /* MODIFIERS and other modifying member functions   */
        /****************************************************/

        // postcondition: a new copy of entry has been inserted
        //    into the Bag.
        //
        void insert(const value_type& entry);

        // postconditions: removes all copies of target from the
        //    Bag; returns number of copies so removed (which
        //    could be zero).
        //
	size_t erase(const value_type& target);

        // postconditions:
        //    *   if target was in the Bag, then one copy of it
        //        has been removed; otherwise, Bag is unchanged.
        //    *   returns true if one copy was removed, false
        //        otherwise.
        //
	bool erase_one(const value_type& target);

        // postconditions:
        //    *   if new_capacity < used, Bag's capacity is
        //        changed to used (will not make the capacity
        //        less than the number of items already in
        //        the Bag).
        //    *   otherwise, the Bag's current capacity is
        //        changed to new_capacity.
        //
	void reserve(size_t new_capacity);

        /****************************************************/
        /* OVERLOADED OPERATORS                             */
        /****************************************************/

        // postcondition: each item in addend has been added to
        //    this Bag.
        //
	void operator +=(const Bag& addend);

        // postcondition: the Bag that activated this function
        //    has the same items and capacity as source.
        //
	void operator =(const Bag& source);

    private:

        value_type  *data;      // Pointer to partially filled dynamic array
	size_t      used;       // How much of array is being used
	size_t      capacity;   // Current capacity of the Bag

};

/*************************************************/
/* NONMEMBER FUNCTIONS for the Bag class         */
/*************************************************/

// postcondition: the Bag returned is the union of
//       b1 and b2.
//
Bag operator +(const Bag& b1, const Bag& b2);

#endif


