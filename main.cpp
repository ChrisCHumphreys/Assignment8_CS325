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

void menu();

int main()
{
    menu();
    return 0;
}

void menu()
{
    // make an empty tree
    binary_search_tree bst;
    
    cout << "Welcom to Chris's Word Count!" << endl << endl;
    cout << "1: Read in From A File" << endl;
    cout << "2: Print Current Word List" << endl;
    cout << "3: Search For A Word" << endl;
    cout << "4: Add a Word" << endl;
    cout << "5: Increment One Words Value by One" << endl;
    cout << "6: Set a Word to a new amount" << endl;
    cout << "7: Delete a Word" << endl;
    cout << "8: Save Current Word List to Disk" << endl;
    cout << "9: Quit" << endl;
    
}
