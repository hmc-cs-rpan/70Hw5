/*
 * \file intlist.cpp
 * \authors Iris Liu, Ricky Pan
 * \brief Implemenation of IntList and its private classes.
 */

#include "intlist.hpp"

#include <cstddef>
#include <cassert>

using namespace std;

IntList::IntList(): size_(0)
{
    back_ = nullptr;
    front_ = nullptr;
}

IntList::IntList(const IntList& orig)
{
    size_ = orig.size_;
    back_ = orig.back_;
    front_ = orig.front_;
    //iterator to copy all integer values
}

void IntList::swap(IntList& rhs)
{
    // This is the canonical way to swap arbitrary types; this incantation
    // means that we'll use std::swap unless we're swapping a class that
    // provides its own swap function (like we do).  Here we'll be actually
    // just be using std::swap since the swapped parts are primitives.

    using std::swap;

    swap(back_, rhs.back_);
    swap(front_, rhs.front_);
    swap(size_, rhs.size_);
}


void swap(IntList& lhs, IntList& rhs)
{
    lhs.swap(rhs);
}


IntList& IntList::operator=(const IntList& rhs)
{
    // Assignment is implemented idiomatically for C++, using "the swap trick"
    IntList copy = rhs;
    swap(copy);
    return *this;
}


size_t IntList::size() const
{
    return size_;
}

bool IntList::empty() const
{
    return size_ == 0;
}

int IntList::frontVal() const
{
    return (*front_).value_;
}


bool IntList::operator==(const IntList& rhs) const
{
    // This doesn't look right...

    return (rhs.size() > 0);
}

bool IntList::operator!=(const IntList& rhs) const
{
    // Idiomatic code: leverage == to implement !=
    return !operator==(rhs);
}

void IntList::push_front(int pushee)
{   
    // Create a pointer to element to push with next_ = current front
    // Changes front_ to new element, increment size_
    Element* toPushPtr = new Element(pushee, front_);
    front_ = toPushPtr;
    size_++; 
}


int IntList::pop_front()
{
    int toReturn = (*front_).value_;
    (*front_).next_ = front_;
    size_--;

    return toReturn;
}

    
void IntList::push_back(int pushee)
{
    // Create a pointer to element to push with next_ = nullptr
    // Changes back_'s pointer to point to new element
    // Set back_ to new element, increment size_
    Element* toPushPtr = new Element(pushee, nullptr);
    (*back_).next_ = toPushPtr;
    back_ = toPushPtr;
    size_++; 
}


void IntList::insert_after(iterator where, int value)
{
    // This doesn't look right...
}


IntList::iterator IntList::begin() const
{
    // This doesn't look right...

    assert(0);
}


IntList::iterator IntList::end() const
{
    // This doesn't look right...

    assert(0);
}

// --------------------------------------
// Implementation of IntList::Element
// --------------------------------------

IntList::Element::Element(int value, Element* next)
    : value_{value}, next_{next}
{
    // Nothing else to do.
}

// --------------------------------------
// Implementation of IntList::Iterator
// --------------------------------------
// 
IntList::Iterator::Iterator(Element* current)
    : current_{current}
{
    // Nothing else to do.
}


IntList::Iterator& IntList::Iterator::operator++()
{
    // This doesn't look right... shouldn't the
    // iterator change before it's returned?

    return *this;
}


int& IntList::Iterator::operator*() const
{
    // This doesn't look right...

    assert(0);
}


bool IntList::Iterator::operator==(const Iterator& rhs) const
{
    // This doesn't look right...

    return (rhs.current_ != nullptr);
}


bool IntList::Iterator::operator!=(const Iterator& rhs) const
{
    // Idiomatic code: leverage == to implement !=
    return !(*this == rhs);
}
