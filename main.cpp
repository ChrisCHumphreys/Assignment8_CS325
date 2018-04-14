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
/*
 * Description:
 *   Main driver of Program.  Creates a binary_search_tree object and then allows
 *   user to manipulate tree through a simple and clean user interface.
 *
 * Inputs:
 *   None
 *
 * Outputs:
 *   None
 */

void readFromFile(binary_search_tree &bst);
/*
 * Description:
 *   Reads in from a file and adds terms to current binary_search_tree.  If tree is
 *   already populated, terms from file wll be added to current list.
 *
 * Inputs:
 *   binary_search_tree& bst
 *     a binary_search_tree object
 *
 * Outputs:
 *   None
 */

int main()
{
    // call main menu
    menu();
    return 0;
}

void menu()
{
    // function variables
    string menuOption = "0";
    
    // make an empty tree
    binary_search_tree bst;
    
    // loop until user decides to quit
    while (menuOption != "10")
    {
        cout << "Welcome to Chris's Word Count!" << endl << endl;
        cout << "1: Read in From A File" << endl;
        cout << "2: Print Current Word List" << endl;
        cout << "3: Search For A Word" << endl;
        cout << "4: Update/Add a Word" << endl;
        cout << "5: Increment One Words Value by One" << endl;
        cout << "6: Delete a Word" << endl;
        cout << "7: Find Largest Word" << endl;
        cout << "8: Find Smallest Word" << endl;
        cout << "9: Save Current Word List to Disk" << endl;
        cout << "10: Quit" << endl << endl;
        cout << "Your Choice(1 - 10): ";
        cin >> menuOption;
        
        // read from file
        if (menuOption == "1")
        {
            readFromFile(bst);
        }
        
        // print list
        else if (menuOption == "2")
        {
            if (bst.isEmpty())
            {
                cout << "Empty List" << endl << endl;
            }
            else
            {
                cout << endl;
                bst.print();
                cout << endl;
            }
        }
        
        // search for a term
        else if (menuOption == "3")
        {
            string searchTerm = "";
            
            cout << "Enter Search Word: ";
            cin >> searchTerm;
            cout << searchTerm << " occurs " << bst[searchTerm] << " times in the document(s)." << endl << endl;
        }
        
        // update/add a word
        else if (menuOption == "4")
        {
            string newWord = "";
            int newCount = 0;
            
            cout << "If Word already exists its number of occurences will be overwritten." << endl;
            cout << "If Word does not exist it will be added." << endl;
            cout << "Please Enter Word to update/add to list: ";
            cin >> newWord;
            cout << "Please enter number of occurences of word: ";
            cin >> newCount;
            bst.set(newWord, newCount);
            cout << "Term->" << newWord << " now occurs in list with value of " << newCount << "." << endl << endl;
        }
        
        // increment a word
        else if (menuOption == "5")
        {
            string incWord = "";
            
            cout << "WARNING - If word entered does not exit in list, it will be added with a value of 1" << endl;
            cout << "Please enter word to increment: ";
            cin >> incWord;
            bst[incWord]++;
            
            cout << incWord << " now has a value of " << bst[incWord] << endl << endl;
        }
        
        // delete a word
        else if (menuOption == "6")
        {
            string toBeDeleted = "";
            
            cout << "Enter word to delete: ";
            cin >> toBeDeleted;
            bst.deleteWord(toBeDeleted);
            cout << toBeDeleted << " removed from list." << endl << endl;
        }
        
        // show min word
        else if (menuOption == "7")
        {
            cout << "The smallest word is " << bst.min() << endl << endl;
        }
        
        // show max word
        else if (menuOption == "8")
        {
            cout << "The largest word is " << bst.max() << endl << endl;
        }
        
        // save to disk
        else if (menuOption == "9")
        {
            string fileName = "";
            
            cout << "Enter name of file to save to: ";
            cin >> fileName;
            bst.saveFile(fileName);
            cout << "File Saved" << endl << endl;
        }
        
        // exit
        else if (menuOption == "10")
        {
            return;
        }
        
        // reset counter for invalid entry
        else
        {
            menuOption = "0";
        }
    }
}

void readFromFile(binary_search_tree &bst)
{
    // function variables
    string fileName = "";
    
    cout << "Enter Name of File To Be Loaded: ";
    cin >> fileName;
    
    bst.readInFromFile(fileName);
    
    // if tree is empty warn user
    if (bst.isEmpty())
    {
        cout << "ERROR: " << fileName << " is missing or does not exist" << endl << endl;
    }
    
    // return success message
    else
    {
        cout << "LOADED: " << fileName << endl << endl;
    }
}
