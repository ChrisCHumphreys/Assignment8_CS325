/* 
 * Name: Chris Humphreys
 * Date: 04/04/18
 * File: binary_search_tree.cpp
 * Description:  Defines the 'binary_search_tree' classes functions.
 */

#include "binary_search_tree.h"
#include <fstream> // ofstrem, ifstream
#include <locale>  //to lower, c-string functions

binary_search_tree::binary_search_tree()
{
    root = NULL;
}

binary_search_tree::~binary_search_tree()
{
    // go thorugh and delete all items
    while (root != NULL)
    {
        deleteWord(min());
    }
}
void binary_search_tree::insertWord(std::string value) 
{
    // empty tree
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
    std::string rawWord = "";
    std::ifstream inFile;
    inFile.open(file.c_str());
    
    while(inFile >> rawWord)
    {
        // make lowercase
        for (int i = 0; i < int(rawWord.length()); i++)
        {
            rawWord[i] = tolower(rawWord[i]);
        }
        
        // remove all punctuation
        std::string cleanWord = removePunctuation(rawWord);
        
        // if word is blank, dont add to list.
        if (cleanWord != "")
        {
            insertWord(cleanWord);
        }
    }
    
    // close up nicely
    inFile.close();
}

std::string binary_search_tree::removePunctuation(std::string rawWord)
{
    // if string is empty
    if (rawWord.length() == 0)
    {
        return "";
    }
    
    // if front and back are both letters - return
    if ((std::isalpha(rawWord[0])) && (std::isalpha(rawWord[rawWord.length() - 1])))
    {
        return rawWord;
    }
    
    else 
    {
        // if front is not a letter
        if (!isalpha(rawWord[0]))
        {
            // remove front
            rawWord = rawWord.substr(1, rawWord.length() - 1);
        }
        
        // if back is not a letter
        if (!isalpha(rawWord[rawWord.length() - 1]))
        {
            // remove back
            rawWord = rawWord.substr(0, rawWord.length() - 1);
        }
        
        // clean again
        rawWord = removePunctuation(rawWord);
        
        // return cleaned word
        return rawWord;
    }
}

void binary_search_tree::saveFile(std::string file)
{
    // open the stream
    std::ofstream outFile;
    outFile.open(file.c_str());
    
    saveHelper(root, outFile);
    
    // close the stream
    outFile.close();
}

void binary_search_tree::saveHelper(Word *current, std::ofstream& outFile)
{
    // recursively write to file in alphabetical order
    if (current != NULL) {
        saveHelper(current->left, outFile);
        outFile << current->word << " : " << current->count << std::endl;
        saveHelper(current->right, outFile);
    }
}

void binary_search_tree::print() 
{
    // have to use helper to specify root
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
    
    // word is found
    if (currentPtr->word == value)
    {
        return currentPtr->count;
    }
    
    // if word is not found return -1
    return -1;
}

void binary_search_tree::set(std::string word, int count)
{
    // if tree is empty, just add to tree
    if(root == NULL)
    {
        root = new Word(word);
        root->setCount(count);
    }
    
    // else, search and add
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
    
    // if tree is empty add to tree, set to 0
    if (root == NULL)
    {
        set(value, 0);
        return root->count;
    }
    
    // start at bottom of tree
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
    
    // if found, update value
    if (currentPtr->word == value)
    {
        return currentPtr->count;
    }
    
    // should never reach here, just to make sure no warnings
    return currentPtr->count;
}

void binary_search_tree::deleteWord(std::string deleteWord)
{
    if (root == NULL)
    {
        return;
    }
    
    Word* currentPtr = root;
    Word* parentPtr = NULL;
    std::string cameFrom;
    deleteHelper(currentPtr, parentPtr, cameFrom, deleteWord);
}

void binary_search_tree::deleteHelper(Word* &current, Word* &parentPtr, std::string cameFrom, std::string deleteWord) {
    
    if (deleteWord < current->word)
    {
        if (current->left != NULL)
        {
            cameFrom = "left";
            parentPtr = current;
            current = current->left;
            deleteHelper(current, parentPtr, cameFrom, deleteWord);
        }
        /*
        else
        {
            return;
        }*/
    }
    
    else if (deleteWord > current->word)
    {
        if (current->right != NULL)
        {
            cameFrom = "right";
            parentPtr = current;
            current = current->right;
            deleteHelper(current, parentPtr, cameFrom, deleteWord);
        }
        /*
        else
        {
            return;
        }*/
    }
    
    else if (deleteWord == current->word)
    {
        if ((current->left == NULL) && (current->right == NULL))
        {
            if (cameFrom == "left")
            {
                parentPtr->left = NULL;
                delete current;
            }
            else if (cameFrom == "right")
            {
                parentPtr->right = NULL;
                delete current;
            }
            else
            {
                root = NULL;
                delete current;
            }
        }
        else if (current->left == NULL)
        {
            if (cameFrom == "right")
            {
                parentPtr->right = current->right;
                delete current;
            }
            else if (cameFrom == "left")
            {
                parentPtr->left = current->right;
                delete current;
            }
            else
            {
                root = current->right;
                delete current;
            }
        }
        else if (current->right == NULL)
        {
            if (cameFrom == "right")
            {
                parentPtr->right = current->left;
                delete current;
            }
            else if (cameFrom == "left")
            {
                parentPtr->left = current->left;
                delete current;
            }
            else
            {
                root = current->left;
                delete current;
            }
        }
        else
        {
            Word* biggestFromLeft = biggestFromSubtree(current->left);
            deleteWord = biggestFromLeft->word;
            current->word = biggestFromLeft->word;
            current->count = biggestFromLeft->count;
            parentPtr = current;
            current = current->left;
            cameFrom = "left";
            deleteHelper(current, parentPtr, cameFrom, deleteWord);
        }
    }
}

Word* binary_search_tree::biggestFromSubtree(Word* iterator)
{
    // if at largest value, return
    if (iterator->right == NULL)
    {
        return iterator;
    }
    
    // keep going right
    else
    {
        iterator = iterator->right;
        return biggestFromSubtree(iterator);
    }
}

bool binary_search_tree::isEmpty()
{
    // if empty return true
    if (root == NULL)
    {
        return true;
    }
    
    else
    {
        return false;
    }
}
