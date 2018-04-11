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
  count = 0;
  word = "Not Specified";
}

Word::Word(std::string word)
{
  this->left = NULL;
  this->right = NULL;
  this->count = 1;
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
