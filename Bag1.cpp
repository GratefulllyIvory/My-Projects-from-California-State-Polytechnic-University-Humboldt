/************************************************************/
/* ADAPTED FROM:                                            */
/* http://www.cs.colorado.edu/~main/chapter4/bag2.cxx       */
/*                                                          */
/* Main and Savitch, "Data Structures and Other Objects     */
/*    using C++", 2nd edition, Addison-Wesley, Ch.4,        */
/*    pp. 178-180 (mostly)                                  */
/************************************************************/

//-----------------------------------------------------------
// File: Bag.cpp
// Name <Jacob Rojeski> and <Daniel Desforges> Spring 2021 
// Class implemented: Bag
//                    (a container clas for a
//                    collection of items)
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
//
// INVARIANT for the Bag class:
//   1. The number of items in the Bag is in the
//      member variable used;
//   2. The actual items of the Bag are stored in a partially
//      filled array. The array is a dynamic array, pointed to
//      by the member variable data;
//   3. The size of the dynamic array is in the member
//      variable capacity.
//--------------------------------------------------------------

#include <algorithm>     // Provides copy function
#include <cassert>       // Provides assert function
#include "Bag.h"
using namespace std;

// (note that the following MAY be required for the named constant)

const size_t Bag::DEFAULT_CAPACITY;

/********************************************************/
/* CONSTRUCTORS and DESTRUCTOR                          */
/********************************************************/

// postcondition: creates an empty Bag instance with an
//    initial capacity of DEFAULT_CAPACITY
//
Bag::Bag() {
    data = new value_type[DEFAULT_CAPACITY];
    capacity = DEFAULT_CAPACITY;
    used = 0;
}

// postcondition: creates an empty Bag instance with an
//    initial capacity of initial_capacity
//
Bag::Bag(size_t initial_capacity) {
    data = new value_type[initial_capacity];
    capacity = initial_capacity;
    used = 0;
}

// Copy constructor
//
// Library facilities used: algorithm
//
Bag::Bag(const Bag& source) {
    data = new value_type[source.capacity];
    capacity = source.capacity;
    used = source.used;

    // (copy is from the algorithm library)
    copy(source.data, source.data + used, data);
}

// Destructor
//
Bag::~Bag() {
    delete [ ] data;
}

/*************************************************************/
/* ACCESSORS and other constant member functions (observers) */
/*************************************************************/

// get_size was already implemented in the Bag.h file...!

// get_count
//
// postcondition: returns the number of times that target
//    is in the Bag.
//
size_t Bag::get_count(const value_type& target) const {
    size_t answer;
    size_t i;

    answer = 0;

    // check each item of Bag, counting each target instance
    for (i = 0; i < used; i++) {
	if (target == data[i]) {
	        answer++;
       }
    }

    return answer;
}

// get_capacity was already implemented in the Bag.h file...!

/****************************************************/
/* MODIFIERS and other modifying member functions   */
/****************************************************/

// insert
//
// postcondition: a new copy of entry has been inserted
//    into the Bag.
//
void Bag::insert(const value_type& entry) {
    // increase Bag's capacity if necessary
    if (used == capacity) {
        reserve(used+1);
    }

    data[used] = entry;
    used++;
}

// erase
//
// postconditions: removes all copies of target from the
//    Bag; returns number of copies so removed (which
//    could be zero).
//
size_t Bag::erase(const value_type& target) {
    size_t index = 0;
    size_t num_removed = 0;

    // look for target amongst all current Bag items
    while (index < used) {
        if (data[index] == target) {
            used--;

            // move the "last" item into the "hole" created
            //    by removing target
            data[index] = data[used];

            num_removed++;

            // (note that index is NOT changed in this case ---
            //    so, next time through loop, you'll check
            //    "last" item just swapped into the "hole",
            //    in case it, TOO, is target!)
            // (and THIS is why while is used instead of for!)
        }

        else {
            index++;
        }
    }

    return num_removed;
}

// erase_one
//
// postconditions:
//    *   if target was in the Bag, then one copy of it
//        has been removed; otherwise, Bag is unchanged.
//    *   returns true if one copy was removed, false
//        otherwise.
//
bool Bag::erase_one(const value_type& target) {
    size_t index; // The location of target in the data array

    // First, set index to the location of target in the data
    //    array, which could be as small as 0 or as large as used-1.
    //    If target is not in the array, then index will be set
    //    equal to used.
    index = 0;

    while ((index < used) && (data[index] != target)) {
        index++;
    }

    // if target isn't in the Bag, then there's no work to do
    if (index == used) {
        return false;
    }

    // IF execution reaches here, target is in the Bag at
    //    data[index]. So, reduce used by 1 and copy the
    //    last item onto data[index].
    used--;
    data[index] = data[used];
    return true;
}

// reserve
//
// postconditions:
//    *   if new_capacity < used, Bag's capacity is
//        changed to used (will not make the capacity
//        less than the number of items already in
//        the Bag).
//    *   otherwise, the Bag's current capacity is
//        changed to new_capacity.
//
// Library facilities used: algorithm
//
void Bag::reserve(size_t new_capacity) {
    value_type *larger_array;

    // if allocated memory is already the right size, we're done;
    if (new_capacity == capacity) {
        return;
    }

    // WILL let capacity of Bag be reduced, but NOT
    //    any smaller than current number of items.
    if (new_capacity < used) {
        // can't allocate less than we are using
        new_capacity = used;
    }

    // allocate new array and copy over Bag items
    larger_array = new value_type[new_capacity];
    copy(data, data + used, larger_array); // from algorithm library

    // (notice that we are freeing the "old" array...)
    delete [ ] data;

    data = larger_array;
    capacity = new_capacity;
}

/****************************************************/
/* OVERLOADED OPERATORS                             */
/****************************************************/

// +=
//
// postcondition: each item in addend has been added to
//    this Bag.
//
// Library facilities used: algorithm
//
void Bag::operator +=(const Bag& addend) {
    // increase Bag capacity if necessary
    if (used + addend.used > capacity) {
        reserve(used + addend.used);
    }

    // (from algorithm library)
    copy(addend.data, addend.data + addend.used, data + used);

    used += addend.used;
}

// =
//
// postcondition: the Bag that activated this function
//    has the same items and capacity as source.
//
// Library facilities used: algorithm
//
void Bag::operator =(const Bag& source) {
    value_type *new_data;

    // Check for possible self-assignment:
    if (this == &source) {
        return;
    }

    // If needed, allocate an array with a different size:
    if (capacity != source.capacity) {
        new_data = new value_type[source.capacity];
        delete [ ] data;
        data = new_data;
        capacity = source.capacity;
    }

    // Copy the data from the source array:
    used = source.used;
    copy(source.data, source.data + used, data); // from algorithm lib
}

/*************************************************/
/* NONMEMBER FUNCTIONS for the Bag class         */
/*************************************************/

//------------------------------------------
// slick: just implement nonmember + here!
// (how can you tell it isn't a member?
//    ...no Bag:: !)
//-----------------------------------------

// non-member +
//
// postcondition: the Bag returned is the union of
//       b1 and b2.
//
Bag operator +(const Bag& b1, const Bag& b2) {
    Bag answer(b1.get_size() + b2.get_size());

    answer += b1;
    answer += b2;
    return answer;
}
