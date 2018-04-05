/* 
 * Name: Chris Humphreys
 * Date: 04/04/18
 * File: binary_search_tree.h
 * Description:  Declares the 'word' class and the 'binary_search_tree' class.  
 */

#include <iostream>
#include "word.h"

class binary_search_tree
{
  public:
    binary_search_tree();
    ~binary_search_tree();
    void insert(Word newWord);
    void deleteWord(Word deleteWord);
    void deleteHelper(Word* &current, int count);

  private:
    Word* root;
    void insertHelper(Word* &current, int count);
    void printHelper(Word* current);
    void destructorHelper(Word* current);
}
