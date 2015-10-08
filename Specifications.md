## Overview
This file describes the interfaces and encodings for the `IntList` and `IntList::Iterator` classes. 
Your implementation must support all the elements of the interfaces, and they must have the specified complexity. 
You may not change the names of anything in the interfaces, nor may you change the encodings. 
However, you are free (and encouraged!) to add private, helper member functions.

The provided code already contains declarations for the interfaces and encodings.

## `IntList` Interface

Your linked-list class must be named `IntList` and must support the following operations:
* A default constructor that creates an empty list.
* A copy constructor that copies all the integer values into a new list. 
* An assignment operator.†
* A destructor.
* A swap operation.†
* A ♉(1) `push_front` function that inserts a single integer at the head of the list.
* A ♉(1) `pop_front` function that removes and returns a single integer from the head of a non-empty list.
* A ♉(1) `push_back` function that inserts a single integer at the tail of the list.
* A ♉(1) `size` function returning the number of elements in the list. 
* A ♉(1) `empty` function returning `true` if the list is empty.
* An equality test (`operator==`) and an inequality test (`operator!=`).
* A `using` statement, defining the type `iterator`.
* A `begin` function that returns an iterator that refers to the start of the list.
* An `end` function that returns an invalid/past-the-end iterator. Note: it is undefined behavior to dereference `end()`; we don’t need to handle that case.
* A ♉(1) `insert_after` function that inserts a single integer after the position indicated by a given iterator. For this member function, you may assume the list is nonempty and the given iterator is not `end()`.

† These functions have been implemented for you; you don't need to modify them.

## `IntList::Iterator` Interface
The `IntList::Iterator` class must provide at least the following operations:
* A default constructor. The resulting iterator doesn't have to be valid (i.e., referring to anything), just overwritable via assignment.
* A copy constructor
* An assignment operator
* A destructor
* An equality test (`operator==`) and an inequality test (`operator!=`). When comparing two iterators, we can assume that the iterators refer to the same `IntList` object. We therefore only need to check that the iterators are also refering to the same element.
* A preincrement operator (`operator++`)
* An `operator*` that returns an `int&` (so that the integer in the current position can be modified if necessary)

It should also be an STL-friendly iterator, which means the class must include appropriate type definitions (see the header file for details).

## `IntList` Encoding

The `IntList` data structure is similar to a linked list. The `IntList` object will be relatively small, and all the data will be in objects of class `IntList::Element` on the heap. 
The `IntList` object will contain pointers to the first and last data element (if any), and a count of the object's size. 
These extensions let the class provide efficient `push_back` and `size` operations.

An empty `IntList`:

![intlist-empty](https://cloud.githubusercontent.com/assets/8798975/10324781/2ca97ffc-6c41-11e5-8506-1e3593c1ccc3.png "An empty IntList")

A nonempty `IntList`:

![A nonempty IntList](https://cloud.githubusercontent.com/assets/8798975/10324782/2cdc3c08-6c41-11e5-9902-9b981ad9ebd8.png "A nonempty IntList")

## `IntList::Iterator` encoding

The list's iterator provides a way to access an element of a list, and it is encoded as a pointer to an Element.

An iterator that refers to the third element of a list:

![An iterator that refers to the third element of a list](https://cloud.githubusercontent.com/assets/8798975/10324793/43a229f2-6c41-11e5-90a5-d9669184d466.png "An iterator that refers to the third element of the list")
