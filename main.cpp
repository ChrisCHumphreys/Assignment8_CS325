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
    bst.set("house", 3);
    bst.set("sofa", 3);
    bst.print();
    cout << bst["apple"] << endl;
    cout << bst.min() << endl;
    cout << bst.max() << endl;
    bst.saveFile("testFile.txt");
    return 0;
}

