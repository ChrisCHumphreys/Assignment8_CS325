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
void readFromFile(binary_search_tree bst);

int main()
{
    menu();
    return 0;
}

void menu()
{
    // function variables
    string menuOption = "0";
    
    // make an empty tree
    binary_search_tree bst;
    
    while (menuOption != "9")
    {
        cout << "Welcom to Chris's Word Count!" << endl << endl;
        cout << "1: Read in From A File" << endl;
        cout << "2: Print Current Word List" << endl;
        cout << "3: Search For A Word" << endl;
        cout << "4: Add a Word" << endl;
        cout << "5: Increment One Words Value by One" << endl;
        cout << "6: Set a Word to a new amount" << endl;
        cout << "7: Delete a Word" << endl;
        cout << "8: Save Current Word List to Disk" << endl;
        cout << "9: Quit" << endl << endl;
        cout << "Your Choice(1 - 9):";
        cin >> menuOption;
        
        if (menuOption == "1"){
            readFromFile(bst);
        }
        else if (menuOption == "9")
        {
            return;
        }
        else
        {
            menuOption = "0";
        }
    }
}

void readFromFile(binary_search_tree)
{
    // function variables
    string fileName = "";
    
    cout << "Enter Name of File To Be Loaded: ";
    cin >> fileName;
    
    bst.readInFromFile(fileName);
    
    
}
