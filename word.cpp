/* 
 * Name: Chris Humphreys
 * Date: 04/04/18
 * File: word.cpp
 * Description:  Declares the 'word' class and its associated functions
 */

#include "word.h"

Word::Word()
{
  left = NULL;
  right = NULL;
  count = -1;
  word = "Not Specified";
}

Word::Word(std::string word, int count)
{
  this->left = NULL;
  this->right = NULL;
  this->count = count;
  this->word = word;
}

void Word::setWord(std::string word)
{
  this->word = word;
}

void Word::setCount(int count)
{
  this->count = count;
}

std::string Word::getWord()
{
  return word;
}

int Word::getCount()
{
  return count;
}
