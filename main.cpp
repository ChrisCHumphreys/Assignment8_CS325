/* 
 * Name: Chris Humphreys
 * Date: 04/04/18
 * File: main.cpp
 * Description:  Main driver for Assignment 8 binary search tree assignment.  Creates a user menu,
 *   and runs program in an easy to use interface.
 */

#include <iostream>
#include "binary_search_tree.h"

using namespace std;

int main()
{
    binary_search_tree bst;
    bst.readInFromFile("test.dat");
    bst.print();
    cout << bst["sofa"] << endl;
    bst.set("television", 10000);
    bst.set("house", 3);
    bst.set("sofa", 3);
    bst.set("apple", 10);
    bst.print();
    return 0;
}

