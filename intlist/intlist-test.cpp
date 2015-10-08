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


int main(int, const char**)
{
    defaultConstructorTest();
    pushFrontTest();
    //copyConstructorTest();  // uncomment this line, when you're ready

    // Unix "success" value
    return 0;
}
