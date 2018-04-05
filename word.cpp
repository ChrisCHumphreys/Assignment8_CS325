/* 
 * Name: Chris Humphreys
 * Date: 04/04/18
 * File: word.cpp
 * Description:  Declares the 'word' class and its associated functions
 */


Word::Word(std::string word, int data)
{
  left = NULL;
  right = NULL;
  this->data = data;
  this->word = word;
}
