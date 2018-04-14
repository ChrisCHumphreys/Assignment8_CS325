# Assignment8_CS325
* Title: Binary Search Tree Assignment
* Description:  Readme file form binary search tree assginment
* Name:  Chris Humphreys
* Date: 04/14/18
* Filename: README.md

## Description
This is my submission for Assignment 9 in CS325.  This program creates a binary search tree, and has methods for
adding and removing terms, finding the smallest and largest terms, updating terms and their values, printing the current
tree, and saving to and reading from files.

It also creates an easy to use intefrace which allows a user to interact with the tree in a simmple way.

## Files Needed
* driver.cpp
* binary_search_tree.cpp
* binary_search_tree.h
* word.cpp
* word.h
* Makefile
* sherlock.txt(optional) - file for reading in and testing
* test.dat(optional) - file for reading in and testing

## How To Run

Assuming you have all files including the optional ones, just make sure you are in the same directory as the files and run `make`. This will build the program. To execute, just type `./binary_tree`. You will be presented with a menu and can follow prompts from that point on.

Included are "sherlock.txt" and "test.dat" files which are text documents for testing.

## Assumptions
1. That you are running program on a Mac or Linux OS. May work on windows, but has not been tested.
2. That you have make and a c++ compiler installed.

## Design Decisions
First, my find method is not actually used at all because I overrode the subscript operater.  Because of this in the main driver, I used the
subscript oprator to find terms for the user.  The find method has been completed and works as per the program assignment, it just became
redundant to use in my actual program.

Second,  I was able to improve the subscript operator versus what was assigned.  The assignment said we would need define two methods
of overriding the subscript operator for accessing and mutating.   By having the operator return a reference to the value, rather than a copy, I
was able to allow accessing and mutating in only one function.

Finally,  my delete funciton is messy and still not quite working right.

##  Bugs - Future Improvements
I would like to implement more error checking, especeially for users entering invalid inputs.  Additionally, the delete funtion is still not working
when deleting a node that is not a leaf.

## Extra Credit
Overrode the subscript operator.  Working well.
