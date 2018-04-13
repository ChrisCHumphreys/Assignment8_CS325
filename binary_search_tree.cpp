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
        if (tempWord != "")
        {
            insertWord(tempWord);
        }
    }
    
    inFile.close();
}

void binary_search_tree::saveFile(std::string file)
{
    std::ofstream outFile;
    outFile.open(file.c_str());
    
    saveHelper(root, outFile);
    
    outFile.close();
}

void binary_search_tree::saveHelper(Word *current, std::ofstream& outFile)
{
    if (current != NULL) {
        saveHelper(current->left, outFile);
        outFile << current->word << std::endl;
        saveHelper(current->right, outFile);
    }
}

void binary_search_tree::print() 
{
    printHelper(root);
}


void binary_search_tree::printHelper(Word *current) 
{
    // In-order traversal.
    if(current != NULL) {
        printHelper(current->left);
        std::cout << current->word << ": " << current->count << std::endl;
        printHelper(current->right);
    }
}

int binary_search_tree::find(std::string value)
{
    // if tree is empty return -1
    if (root == NULL)
    {
        return -1;
    }
    Word* currentPtr = root;
    
    // while not at a bottom leaf.
    while ((currentPtr->left != NULL) || (currentPtr->right != NULL))
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
            currentPtr = currentPtr->right;
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

void binary_search_tree::set(std::string word, int count)
{
    if(root == NULL)
    {
        root = new Word(word);
        root->setCount(count);
    }
    else
        setHelper(root, word, count);
}

void binary_search_tree::setHelper(Word *current, std::string value, int count)
{
    // update count if word is already in tree
    if (current->word == value)
    {
        current->count = count;
    }
    else if(value < current->word) {
        //Insert Left
        if(current->left == NULL)
        {
            current->left = new Word(value);
            current->left->setCount(count);
        }
        else
            setHelper(current->left, value, count);
    }
    else {
        //Insert Right
        if(current->right == NULL)
        {
            current->right = new Word(value);
            current->right->setCount(count);
        }
        else
            setHelper(current->right, value, count);
    }
}

std::string binary_search_tree::min()
{
    // If tree is empty let user know
    if (root == NULL)
    {
        return "Empty Tree";
    }
    
    // if there is only one entry return that
    Word *currentPtr = root;
    if ((currentPtr->left == NULL) && (currentPtr->right == NULL))
    {
        return currentPtr->word;
    }
    
    // otherwise, keep going left till you hit the smallest
    while (currentPtr->left != NULL)
    {
        currentPtr = currentPtr->left;
    }
    
    return currentPtr->word;
}

std::string binary_search_tree::max()
{
    // If tree is empty let user know
    if (root == NULL)
    {
        return "Empty Tree";
    }
    
    // if there is only one entry return that
    Word *currentPtr = root;
    if ((currentPtr->left == NULL) && (currentPtr->right == NULL))
    {
        return currentPtr->word;
    }
    
    // keep going to the right till we get to the end
    while (currentPtr->right != NULL)
    {
        currentPtr = currentPtr->right;
    }
    
    return currentPtr->word;
}

int& binary_search_tree::operator[](std::string value) 
{
    
    // if tree is empty return -1
    if (root == NULL)
    {
        set(value, 0);
        return root->count;
    }
    Word* currentPtr = root;
    
    // while not at a bottom leaf.
    while ((currentPtr->left != NULL) || (currentPtr->right != NULL))
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
            currentPtr = currentPtr->right;
        }
    }
    
    if (currentPtr->word == value)
    {
        return currentPtr->count;
    }
    
    // if not found, set the value
    set(value, 0);
    
    // reset to root and then search again.
    currentPtr = root;
    
    // while not at a bottom leaf.
    while ((currentPtr->left != NULL) || (currentPtr->right != NULL))
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
            currentPtr = currentPtr->right;
        }
    }
    
    if (currentPtr->word == value)
    {
        return currentPtr->count;
    }
    // should never reach here, just to make sure no warnings
    return currentPtr->count;
}

void binary_search_tree::deleteWord(std::string deleteWord)
{
    Word* currentPtr = root;
    root = deleteHelper(currentPtr, deleteWord);
    
}

Word* binary_search_tree::deleteHelper(Word* tempRoot, std::string deleteWord)
{
    if (tempRoot == NULL)
    {
        return tempRoot;
    }
    
    if (deleteWord < tempRoot->word)
    {
        deleteHelper(tempRoot->left, deleteWord);
    }
    else if (deleteWord > tempRoot->word)
    {
        deleteHelper(tempRoot->right, deleteWord);
    }
    else
    {
        if ((tempRoot->left == NULL) && (tempRoot->right == NULL))
        {
            delete tempRoot;
            return;
        }
    }
    return tempRoot;
}

Word* binary_search_tree::biggestFromSubtree(Word* iterator)
{
    if (iterator->right == NULL)
    {
        return iterator;
    }
    else
    {
        iterator = iterator->right;
        return biggestFromSubtree(iterator);
    }
}
