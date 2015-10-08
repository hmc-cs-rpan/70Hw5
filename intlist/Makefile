#
# Makefile for CS 70 IntList Assignment
# 
# As usual, you can build this software by typing
#
#     make
#

# ----- Make Variables -----

CXXFLAGS = -g -std=c++11 -Wall -Wextra -pedantic
CXX = clang++

TARGETS = intlist-test
BENCH_OBJECTS = intlist.o
TEST_OBJECTS = intlist-test.o intlist.o


# ----- Make Rules -----

all: $(TARGETS)

intlist-test: $(TEST_OBJECTS)
	$(CXX) -o intlist-test $(TEST_OBJECTS)

intlist.o: intlist.cpp intlist.hpp
	$(CXX) -c $(CXXFLAGS) intlist.cpp

intlist-test.o: intlist-test.cpp intlist.hpp
	$(CXX) -c $(CXXFLAGS) intlist-test.cpp

clean:
	rm -rf $(TARGETS) *.o documentation

doxygen:
	doxygen doxygen.config
