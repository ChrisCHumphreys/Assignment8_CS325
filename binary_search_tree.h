/* 
 * Name: Chris Humphreys
 * Date: 04/04/18
 * File: binary_search_tree.h
 * Description:  Declares the 'binary_search_tree' class, its attrbiutes and functions.  
 */

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include "word.h"

class binary_search_tree
{
  public:

    
    binary_search_tree();
    /*
     * Description:
     *   Default Constructor, creates and binary search tree and sets attributes.
     *
     * Inputs
     *   None
     *
     * Ouptuts
     *   None
     */

    ~binary_search_tree();
    /*
     * Description:
     *   Completely emptys a binary search tree object.  Frees up all memory.
     *
     * Inputs
     *   None
     *
     * Ouptuts
     *   None
     */
    
    void insertWord(std::string newWord);
    /*
     * Description:
     *   Inserts a new Word object into the binary search tree.
     *
     * Inputs
     *   Word newWord
     *     a Word object
     *
     * Outputs
     *   None
     */

    void deleteWord(std::string deleteWord);
    /*
     * Description:
     *   deletes the first occurence of a node from tree and adjuststs tree to account
     *   for node being deleted.
     *
     * Inputs:
     *   Word deleteWord
     *     the word object to be deleted from the tree.
     *
     * Outputs:
     *   None
     */

    void deleteHelper(Word* &current, Word* &currentPtr, std::string cameFrom, std::string word);
    /* 
     * Description:
     *   helper function to be used with deleteWord.  Allows for recursive deletion of nodes.
     *
     * Inputs
     *   Word* &current
     *     address or a word object
     *   int count
     *     the count attribute of the current word
     *
     * Outputs:
     *   None
     */
    
    void readInFromFile(std::string fileName);
    /*
     * Description:
     *   Reads in words from a file and after cleaning the words adds them to the
     *   binary search tree
     *
     * Inputs
     *   string fileName
     *     a c++ string
     *   int count
     *     the count attribute of the current word
     *
     * Outputs
     *   None
     */
    
    void saveFile(std::string fileName);
    /*
     * Description:
     *   Writes out contents of the binary_search_tree to a file specified by "fileName".
     *   Writes the terms out in alphabetical order, one per line, with a colon and their
     *   value on the same line as the term.
     *
     * Inputs:
     *   string fileName
     *     a c++ string
     *
     * Outputs:
     *   None
     */
    
    void print();
    /*
     * Description:
     *   Prints out the Terms and their values in "Term : count" format to the console.
     *
     * Inputs:
     *   None
     *
     * Outputs:
     *   None
     */
    
    int find(std::string value);
    /*
     * Description:
     *   Given an argument "value", returns the associated "count"
     *
     * Inputs:
     *   string value
     *     a c++ string
     *
     * Outputs:
     *   int
     *     an integer
     */
    
    void set(std::string word, int count);
    /*
     * Description:
     *   Updates the 'count' attribute of 'word' term.  If 'word' does not exist in the binary tree it
     *   adds it and sets count equal to 'count'.  If it does exist, it just updates it's value.
     *
     * Inputs:
     *   string word
     *     a c++ string
     *   int count
     *     an integer
     *
     * Outputs:
     *   None
     */
    
    int& operator[](std::string value);
    /*
     * Description:
     *   Overrides the subscript operator.  Returns the count of the term spcified by 'value'.
     *
     * Inputs:
     *   string value
     *     a c++ string
     *
     * Outputs:
     *   int&
     *     a reference to an integer
     */
    
    std::string min();
    /*
     * Description:
     *   returns the smallest term in the binary search tree.
     *
     * Inputs:
     *   None
     *
     * Outputs:
     *   string
     *     a c++ string
     */
    
    std::string max();
    /*
     * Description:
     *   Returns the largest term in the binary search tree.
     *
     * Inputs:
     *   None
     *
     * Outputs:
     *   string
     *     a c++ string
     */
    
    bool isEmpty();
    /*
     * Description:
     *   Returns true if current binary tree is empty, and false if not.
     *
     * Inputs:
     *   None
     *
     * Outputs:
     *   bool
     *     a c++ boolean
     */

  private:
    Word* root; //root node of the binary search tree
    
    void insertHelper(Word* current, std::string word);
    /*
     * Description:
     *   helper funciton to aid insertWord function.  Allows for recursive insertion.
     *
     * Inputs
     *   Word* &current
     *     a pointer to the address of the current word node.
     *   int count
     *     the count attribute of the current word
     *
     * Outputs
     *   None
     */

    void printHelper(Word* current);
    /*
     * Description:
     *   helper funciton to aid printWord function.  Allows for recursive printing.
     *
     * Inputs
     *   Word* &current
     *     a pointer to the address of the current word node.
     *   int count
     *     the count attribute of the current word
     *
     * Outputs
     *   None
     */   

    void destructorHelper(Word* current);
    /*
     * Description:
     *   helper funciton to aid insertWord function.  Allows for recursive insertion.
     *
     * Inputs
     *   Word* &current
     *     a pointer to the address of the current word node.
     *   int count
     *     the count attribute of the current word
     *
     * Outputs
     *   None
     */
    
    void setHelper(Word *current, std::string value, int count);
    /*
     * Description:
     *   Helper function for 'set' method.  Allows for recursion
     *
     * Inputs:
     *   Word* current
     *     a pointer to a c++ Word object
     *   string value
     *     a c++ string
     *   int count
     *     an integer
     *
     * Outputs:
     *   None
     */
    
    void saveHelper(Word *current, std::ofstream& outFile);
    /*
     * Description:
     *   Helper function for 'save' method.  Allows for recursion.
     *
     * Inputs:
     *   Word* current
     *     a pointer to a c++ Word object
     *   ofstream& outFile
     *     a refrence to an output file stream
     *
     * Outputs:
     *   None
     */
    
    Word* biggestFromSubtree(Word* iterator);
    /*
     * Description:
     *   Helper function for 'delete' method.  Finds biggest value in a subtree.
     *
     * Inputs:
     *   Word* iterator
     *     a pointer to a c++ Word object
     *
     * Outputs:
     *   Word*
     *     a pointer to a c++ Word object
     */
    
    std::string removePunctuation(std::string rawWord);
    /*
     * Description:
     *   Helper function for 'readInFromFile' method.  Recursively remvoves
     *   punctuations from front and back of a word.
     *
     * Inputs:
     *   string rawWord
     *     a c++ string
     *
     * Outputs:
     *   string
     *     a c++ string
     */
};

#endif //BINARY_SEARCH_TREE_H
