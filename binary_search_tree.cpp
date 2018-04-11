/* 
 * Name: Chris Humphreys
 * Date: 04/04/18
 * File: binary_search_tree.cpp
 * Description:  Defines the 'binary_search_tree' classes functions.  
 */

#include "binary_search_tree.h"
#include <fstream>

binary_search_tree::binary_search_tree()
{
  root = NULL;
}

binary_search_tree::~binary_search_tree()
{
    //
}
void binary_search_tree::insertWord(std::string value) 
{
  if(root == NULL)
    root = new Word(value);
  else
    insertHelper(root, value);
}

void binary_search_tree::insertHelper(Word *current, std::string value) 
{
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

void binary_search_tree::readInFromFile(std::string file)
{
  std::string tempWord = "";
  std::ifstream inFile;
  inFile.open(file.c_str());

  while(inFile)
  {
    getline(inFile, tempWord);
    insertWord(tempWord);
  }

  inFile.close();
}

void binary_search_tree::print() {
  printHelper(root);
  cout << endl;
}


void binary_search_tree::printHelper(Word *current) {
  // In-order traversal.
  if(current != NULL) {
    printHelper(current->left);
    cout << current->word << " ";
    printHelper(current->right);
  }
}
