/* 
 * Name: Chris Humphreys
 * Date: 04/04/18
 * File: binary_search_tree.cpp
 * Description:  Defines the 'binary_search_tree' classes functions.  
 */

#include "binary_search_tree.h"

binary_search_tree::binary_search_tree()
{
  root = NULL;
}

void binary_search_tree::insertWord(std::string value) {
  if(root == NULL)
    root = new Word(value);
  else
    insertHelper(root, value);
}

void binary_search_tree::insertHelper(Word *current, std::string value) {
  if(value < current->word) {
    //Insert Left
    if(current->left == NULL)
      current->left = new Word(value);
    else
      insertHelper(current->left, value);
  }
  else {
    //Insert Right
    if(current->right == NULL)
      current->right = new Word(value);
    else
      insertHelper(current->right, value);
  }

}
