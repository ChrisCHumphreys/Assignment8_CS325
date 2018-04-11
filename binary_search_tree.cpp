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
  // update count if word is already in tree
  if (current->word == value)
  {
    current->count++;
  }
  else if(value < current->word) {
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

void binary_search_tree::print() 
{
  printHelper(root);
  std::cout << std::endl;
}


void binary_search_tree::printHelper(Word *current) 
{
  // In-order traversal.
  if(current != NULL) {
    printHelper(current->left);
    std::cout << current->word << " ";
    printHelper(current->right);
  }
}

void binary_search_tree::find(std::string value)
{
  // if tree is empty return -1
  if (root == NULL)
  {
    return -1;
  }
  Word* currentPtr = root;
  
  while ((currentPtr->left != NULL) && (currentPtr->right != NULL))
  {
    // if root is the word return
    if (currentPtr->word == value)
    {
      return currentPtr->count;
    }
    else if ((currentPtr->word > value) && (currentPtr->left != NULL))
    {
      currentPtr = currentPtr->left;
    }
    else if (currentPtr->right != NULL)
    {
      currentPtr = currentPtr->right
    }
  }
  
  if (currentPtr->word == value)
  {
    return currentPtr->count;
  }

  return -1;
}
/*
Psuedo code for finder helper function

check root
    if null or found return appropriatley
while currentPtr left and right != NULL
    if currentPt->word == value
        return count;
    else if value < word and currentPtr-Left != null
        current pointr == currentptr-Left
    else if value > word and currentPtr-Right != null
        current point == currentptr-Right
return -1;
*/

int binary_search_tree::operator[](std::string value) 
{
  return 3;
}
