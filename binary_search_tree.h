/* 
 * Name: Chris Humphreys
 * Date: 04/04/18
 * File: binary_search_tree.h
 * Description:  Declares the 'binary_search_tree' class, its attrbiutes and functions.  
 */

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
    
    void insertWord(Word newWord);
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

    void deleteWord(Word deleteWord);
    /*
     * Description:
     *   class destructor, deletes nodes from tree and adjuststs tree to account
     *   for node being deleted.
     *
     * Inputs:
     *   Word deleteWord
     *     the word object to be deleted from the tree.
     *
     * Outputs:
     *   None
     */

    void deleteHelper(Word* &current, std::string word);
    /* 
     * Description:
     *   helper function to be used with deleteWord.  Allows for recursive deletion of nodes.
     *
     * Inputs
     *   Word* &current
     *     address or a word object
     *   int count
     *     the count attribute of the current word
     */

  private:
    Word* root; //root node of the binary search tree
    void insertHelper(Word* &current, std::string word);
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
};
