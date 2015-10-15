/**
 * \file intlist-test.cpp
 * \authors Iris Liu, Ricky Pan
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
 *          Checks the last insert at the front.
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
    assert(myList.frontVal() == 999);
}

/** \brief Test push_front
 *  \detail Adds 1 element to an empty IntList
 *          Front should equal pushed value, and size = 1
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
 * 
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

/** \brief Test push_back on empty IntList
 *  \detail Adds 1 element from the back to an empty IntList
 *          Size = 1
 */
void pushBackEmptyTest()
{
    std::cout << "Testing push_back_empty" << std::endl;

    IntList myList;

    myList.push_back(99999);
    assert(myList.size() == 1);
    assert(myList.frontVal() == 99999);
}

/** \brief Test insert_after on the min case IntList
 *  \detail Adds 2 elements to an IntList and inserts an element
 *          in between. Checks that this list is equal to our
 *          desired list, and checks that the added element is 
 *          present in the list.
 */
void insertAfterTwoElementTest()
{
    std::cout << "Testing insert_after" << std::endl;
    IntList answerList;
    for (size_t i = 0; i != 3; ++i) {
       answerList.push_back(i);
    }

    IntList testList;
    testList.push_back(0);
    testList.push_back(2);

    IntList::iterator a = testList.begin();
    testList.insert_after(a, 1);

    ++a;
    assert(*a == 1);
    assert(answerList == testList);
}

/** \brief Test pop_front
 *  \detail Does 1000 inserts at the front of the list. And pops the
 *     first element. Checks the post-popping size and the popped
 *     element.
 */
void popFrontTest()
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
 *  \detail Calls pop_front on an empty IntList
 *          Should not pop any elements. Returns 0 as default behavior
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
 *          Checks whether the resulting list contents are
 *          correct. Also checks that lists are distinct.
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

    assert (myList == copyList);

    // Add more to the original list
    for (size_t i = 0; i != 1000; ++i) {
       myList.push_front(i);
    }

    // Check that the copy hasn't changed,
    // and that both lists have the correct size.
    assert(copyList.size() == 1000);
    assert(myList.size() == 2000);
}

/** \brief Test iterator functionality through entire IntList
 *  \detail Loops an iterator through an IntList incrementing 
 *          a counter to track the size of the IntList. Compares
 *          the counter value to the IntList size.
 */
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

/** \brief Test iterator equality operator
 *  \detail Initializes 2 iterators to equal the front of
 *          the same IntList. Increments each by 1, and 
 *          checks that iterators are the same.
 */
void intListIteratorEqualityTest()
{
    std::cout << "Testing intList iterator equality" << std::endl;

    IntList myList;
    for (size_t i = 0; i != 1000; ++i) {
       myList.push_front(i);
    }

    IntList::iterator a = myList.begin();
    IntList::iterator b = a;
    ++a;
    ++b;

    assert(a == b);
}

/** \brief Test iterator inequality operator
 *  \detail Initializes 2 iterators to equal the front of
 *          the same IntList. Increments one of them, and 
 *          checks for inequality.
 */
void intListIteratorInequalityTest()
{
    std::cout << "Testing intList iterator inequality " << std::endl;

    IntList myList;
    for (size_t i = 0; i != 1000; ++i) {
       myList.push_front(i);
    }

    IntList::iterator a = myList.begin();
    IntList::iterator b = a;
    ++b;
    
    assert(a != b);
}

/** \brief Test iterator dereference operator
 *  \detail Initializes 2 iterators to equal the front of
 *          the same IntList. Increments each by 1, and 
 *          checks that the values of the elements they 
 *          point to are the same.
 */
void intListIteratorDeferenceTest()
{
    std::cout << "Testing intList iterator dereference" << std::endl;

    IntList myList;
    for (size_t i = 0; i != 1000; ++i) {
       myList.push_front(i);
    }

    IntList::iterator a = myList.begin();
    IntList::iterator b = a;
    ++a;
    ++b;
    assert(*a == *b);
}


/** \brief Test IntList equality operator
 *  \detail Initializes 2 IntLists with the same 
 *          values. Compares that they are equal.
 */
void intListEqualityTest()
{
    IntList firstList;
    for (size_t i = 0; i != 1000; ++i) {
       firstList.push_front(i);
    }
    IntList secondList;
    for (size_t i = 0; i != 1000; ++i) {
       secondList.push_front(i);
    }

    assert(firstList == secondList);
}

/** \brief Test empty IntList equality operator
 *  \detail Initializes 2 empty IntLists.
 *          Compares that they are equal.
 */
void intListEmptyEqualityTest()
{
    IntList firstList;
    IntList secondList;
    assert(firstList == secondList);
}

int main(int, const char**)
{
    defaultConstructorTest();
    pushFrontTest();
    pushFrontEmptyTest();
    pushBackTest();
    pushBackEmptyTest();
    popFrontTest();
    popFrontEmptyTest();
    intListIteratorSizeTest();
    intListIteratorEqualityTest();
    intListIteratorInequalityTest();
    intListIteratorDereferenceTest();
    intListEqualityTest();
    intListEmptyEqualityTest();
    insertAfterTwoElementTest();
    copyConstructorTest();

    // Unix "success" value
    return 0;
}
