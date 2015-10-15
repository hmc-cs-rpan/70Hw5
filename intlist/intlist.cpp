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
    // initialize default values for an IntList
    size_ = 0;
    front_ = nullptr;
    back_ = nullptr;

    // pushes all of the elements in orig into our list
    for(Iterator a = orig.begin(); a != orig.end(); ++a)
    {
        push_back(*a);
    }
}

IntList::~IntList()
{   
    // we use pop_front to pop all elements until front_ = nullptr
    while(front_ != nullptr)
    {
        pop_front();
    }
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
    // helper function to access the value of the first element
    return front_ -> value_;
}


bool IntList::operator==(const IntList& rhs) const
{
    // check that both lists are same size
    if(size_ != rhs.size_)
    {
        return false;
    }

    // initializes 1 iterator to loop through each list
    Iterator a = front_;
    Iterator b = rhs.front_;

    // compares each element's value in each position
    // if any one fails, returns false
    for(size_t i = 0; i < size_; ++i)
    {
        if(*a != *b)
        {
            return false;
        }
        else
        {
            // increments iterators
            ++a;
            ++b;
        }
    }
    return true;
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

    if (size_ == 1)
    {
        back_ = toPushPtr;
    }
}

int IntList::pop_front()
{
    // Check if list is empty
    if (front_ == nullptr)
    {
        cout << "List is empty" << endl;
        return 0;
    }
    else
    {
        // Store front value to return later
        int popValue = front_ -> value_;

        // Create a temporary placeholder for our second element
        Element* second = front_ -> next_;
        delete front_;
    
        // Assign new front to second element and decrement size_
        front_ = second;
        size_--;

        return popValue;
    }    
}
    
void IntList::push_back(int pushee)
{
    // Create a pointer to element to push with next_ = nullptr
    // Set back_ to new element, increment size_
    
    // When empty, make front_ and back_ point to added element
    if (size_ == 0)
    {
        Element* toPushPtr = new Element(pushee, nullptr);
        front_ = toPushPtr;
        back_ = toPushPtr;
        size_++; 
    }
    // Else change back_ to point to added element
    else
    {
        Element* toPushPtr = new Element(pushee, nullptr);
        back_ -> next_ = toPushPtr;
        back_ = toPushPtr;
        size_++; 
    }

}

void IntList::insert_after(iterator where, int value)
{
    // store the pointer to element after current_ in newNext
    Element* newNext = where.current_ -> next_;

    // toPushPtr points to new element, links new element to
    // rest of the IntList
    Element* toPushPtr = new Element(value, newNext);

    // connect the first part of the intList to new element
    where.current_ -> next_ = toPushPtr;
    size_++;
}


IntList::iterator IntList::begin() const
{
    // we want the address of the first element
    return Iterator(front_);
}


IntList::iterator IntList::end() const
{
    // the past-the-end object is a nullptr
    return Iterator(nullptr);
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
    // sets the iterator's pointer to the next element in IntList
    current_ = current_ -> next_;
    return *this;
}


int& IntList::Iterator::operator*() const
{
    // Return the element current_ points to
    return current_ -> value_;
}


bool IntList::Iterator::operator==(const Iterator& rhs) const
{
    // Checks if two iterators point to the same element
    return current_ == rhs.current_;
}


bool IntList::Iterator::operator!=(const Iterator& rhs) const
{
    // Idiomatic code: leverage == to implement !=
    return !(*this == rhs);
}
