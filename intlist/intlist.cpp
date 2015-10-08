/*
 * \file intlist.cpp
 * \authors YOUR NAMES HERE
 * \brief Implemenation of IntList and its private classes.
 */

#include "intlist.hpp"

#include <cstddef>
#include <cassert>

using namespace std;

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
    // This doesn't look right...

    return 0;
}

bool IntList::empty() const
{
    // This doesn't look right...

    return true;
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
  // This doesn't look right...
}


int IntList::pop_front()
{
  // This doesn't look right...

  return 42;
}


void IntList::push_back(int pushee)
{
  // This doesn't look right...
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
