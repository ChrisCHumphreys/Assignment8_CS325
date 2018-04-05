/* 
 * Name: Chris Humphreys
 * Date: 04/04/18
 * File: word.cpp
 * Description:  Declares the 'word' class and its associated functions
 */

#include "word.h"

Word::Word(std::string word, int count)
{
  left = NULL;
  right = NULL;
  this->count = count;
  this->word = word;
}

Word::setWord(std::string word)
{
  this->word = word;
}

Word::setCount(int count)
{
  this->count = count;
}

Word::getWord()
{
  return word;
}

Word::getCount()
{
  return count;
}
