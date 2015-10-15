/**
 * \file intlist-test.cpp
 * \authors YOUR NAME HERE
 * \brief The program unit tests the IntList class.
 */

/* Note: In testing, it's always a good idea to #include the header you're
 * testing without including anything else beforehand.  That way, if your header
 * refers to strings or vectors or size_t without including the necessary header
 * files, you'll know.
 */
#include "intlist.hpp"

#include <cassert>
#include <iostream>

/** \brief Test default constructor for IntLists
 */
void defaultConstructorTest()
{
  std::cout << "Testing default constructor" << std::endl;

  IntList myList;

  assert(myList.size() == 0);

  return;
}

/** \brief Test push_front
 *  \detail Does 1000 inserts at the front of the list.
 *     Does not (yet) check whether the resulting list contents are
 *     correct, but it's a good sign if this works without
 *     crashing or valgrind errors.
 */
void pushFrontTest()
{
    std::cout << "Testing push_front" << std::endl;

    IntList myList;

    myList.push_front(99999);
    assert(myList.size() == 1);

    for (size_t i = 0; i != 1000; ++i) {
       myList.push_front(i);
    }

    assert(myList.size() == 1001);
}

/** \brief Test push_front
 *  \detail Adds 1 element to an empty IntList
 *   Front should equal pushed value, and size = 1
 */
void pushFrontEmptyTest()
{
    std::cout << "Testing push_front_empty" << std::endl;

    IntList myList;

    myList.push_front(99999);
    assert(myList.size() == 1);
    assert(myList.frontVal() == 99999);
}

/** \brief Test push_back
 *  \detail Does 1000 inserts at the back of the list.
 *     Does not (yet) check whether the resulting list contents are
 *     correct, but it's a good sign if this works without
 *     crashing or valgrind errors.
 */
void pushBackTest()
{
    std::cout << "Testing push_back" << std::endl;

    IntList myList;

    myList.push_back(99999);
    assert(myList.size() == 1);

    for (size_t i = 0; i != 1000; ++i) {
       myList.push_back(i);
    }

    assert(myList.size() == 1001);
    assert(myList.frontVal() == 99999);
}

/** \brief Test back
 *  \detail Adds 1 element from the back to an empty IntList
 *   Front should equal back, and size = 1
 */
void pushBackEmptyTest()
{
    std::cout << "Testing push_back_empty" << std::endl;

    IntList myList;

    myList.push_back(99999);
    assert(myList.size() == 1);
    assert(myList.frontVal() == 99999);
}

/** \brief Test pop_front
 *  \detail Does 1000 inserts at the front of the list. And pops the
 *     first element. Checks the post-popping size and the popped
 *     element.
 */
void popFrontTest() //COME BACK AFTER ITERATOR/DESTRUCTOR
{
    std::cout << "Testing pop_front" << std::endl;

    IntList myList;

    myList.push_front(99999);

    for (size_t i = 0; i != 1000; ++i) {
       myList.push_front(i);
    }

    assert(myList.pop_front() == 999);
    assert(myList.size() == 1000);
}

/** \brief Test pop_front_empty
 *  \detail Pops one element from an empty IntList
 *   Should not pop any elements
 */
void popFrontEmptyTest()
{
    std::cout << "Testing pop_front_empty" << std::endl;

    IntList myList;

    assert(myList.pop_front() == 0);
    assert(myList.size() == 0);
}

/** \brief Test copy constructor for IntLists
 *  \detail Copies a 1000-element list.
 *     Does not (yet) check whether the resulting list contents are
 *     correct, but it's a good sign if this works without
 *     crashing or valgrind errors.
 */
void copyConstructorTest()
{
    std::cout << "Testing list copy constructor" << std::endl;

    IntList myList;
    for (size_t i = 0; i != 1000; ++i) {
       myList.push_front(i);
    }

    // Redundant, but better safe than sorry.
    assert(myList.size() == 1000);

    // Copy the list
    IntList copyList = myList;

    // Add more to the original list
    for (size_t i = 0; i != 1000; ++i) {
       myList.push_front(i);
    }

    // Check that the copy hasn't changed,
    // and that both lists have the correct size.
    assert(copyList.size() == 1000);
    assert(myList.size() == 2000);
}

void intListIteratorSizeTest()
{
    std::cout << "Testing intList iterator size" << std::endl;

    IntList myList;
    for (size_t i = 0; i != 1000; ++i) {
       myList.push_front(i);
    }

    size_t counter = 0;

    for (IntList::iterator i = myList.begin(); i != myList.end(); ++i)
    {
        counter++;
    }

    assert(counter == myList.size());
}

void intListIteratorComparisonTest()
{
    std::cout << "Testing intList iterator comparison" << std::endl;

    IntList myList;
    for (size_t i = 0; i != 1000; ++i) {
       myList.push_front(i);
    }

    IntList::iterator a = myList.begin();
    IntList::iterator b = myList.begin();

    assert(a == b);
}

void intListIteratorTestOne()
{
    std::cout << "Testing intList iterator one" << std::endl;

    IntList myList;
    for (size_t i = 0; i != 1000; ++i) {
       myList.push_front(i);
    }

    size_t counter = 0;

    for (IntList::iterator i = myList.begin(); i != myList.end(); ++i)
    {
        counter++;
    }

    assert(counter == myList.size());
}

int main(int, const char**)
{
    //defaultConstructorTest();
    pushFrontTest();
    //pushBackTest();
    //popFrontTest();
    //intListIteratorTestOne();
    //copyConstructorTest();  // uncomment this line, when you're ready

    // Unix "success" value
    return 0;
}
