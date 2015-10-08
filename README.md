# Overview
In this assignment, you'll implement a singly-linked list class that has
capabilities in-between the C++ STL types `std::forward_list<int>` and
`std::list<int>`. Your list class will also define an iterator, so
that users of the class can iterate over all the elements of the list.

After you've implemented your list, you'll analyze its performance (using ♉ ︎notation) for a number of different operations.

# Reading
In addition to the class wiki notes, you should look through the following before starting this assignment:
* The [Documentation for C++'s iterators](http://www.cplusplus.com/reference/iterator/)
* The [Specifications](Specifications.md) for the `IntList` and `IntList::Iterator` classes
* The [Makefile wiki page](https://github.com/hmc-cs70-fall2015/Admin/wiki/Makefiles), which describes some of the new features in this week's given `Makefile`

# Steps
There are 8 issues to complete for this assignment:

1. Planning Component
1. Testing Component
1. Implement push_front and pop_front
1. Implement push_back
1. Add Iterators
1. Implement insert_after
1. Implement the copy constructor and (in)equality tests
1. Analysis Component

# Grading
Your submission will be graded as follows: 
* 10 points: correctness
* 15 points: completeness
* 5 points: style 
* 5 points: elegance
* 5 points: clarity 
* 10 points: peer review

See the [Grading Guidelines](https://github.com/hmc-cs70-fall2015/Admin/wiki/Grading-Guidelines) wiki page for more information about what we're looking for in each of those categories. 
