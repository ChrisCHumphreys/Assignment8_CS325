/* 
 * Name: Chris Humphreys
 * Date: 04/04/18
 * File: word.h
 * Description:  Declares the 'word' class.
 */
#ifndef WORD_H
#define WORD_H

#include <iostream>
#include <string>

class Word {
  private:
    Word *left, *right;
    std::string word;
    int count;

  public:
    Word();
    /*
     * Description:
     *   Default Constructor for Word Class.  Sets all pointer values to null, count to -1
     *   and word to 'Not Specified'.
     *
     * Inputs:
     *   None
     *
     * Outputs:
     *   a Word node
     */

    Word(std::string word, int count);
    /*
     * Description:
     *   Paramaterized constructor for the Word Class.  Sets left and right pointers to null
     *   and sets value of word and count.
     *  
     * Inputs:
     *   std::string word
     *     a c++ string
     *   int count
     *     an integer
     *
     * Outputs:
     *   a Word node for use in a binary search tree.
     */
    
    void setWord(std::string word);
    /*
     * Description:
     *   Setter function for word node.  Updates value of word attribute to whatever is specified
     *   by argument 'word'
     *
     * Inputs:
     *   std::string word)
     *     a c++ string
     *
     * Outputs:
     *   None
     */

    void setCount(int count);
    /*
     * Description:
     *   Setter function for word node.  Updates value of word attribute to whatever is specified
     *   by argument 'word'
     *
     * Inputs:
     *   int count
     *     an integer
     *
     * Outputs:
     *   None
     */

    std::string getWord();
    /*
     * Description:
     *   Getter function for word node.  Returns the value of the 'word' attribute of a Word node.
     *
     * Inputs
     *   None
     *
     * Outputs
     *   std::string word
     *     a c++ string
     */

    int getCount();
    /*
     * Description:
     *   Getter function for word node.  Returns the value of the 'count' attribute of a Word node.
     *
     * Inputs
     *   None
     *
     * Outputs
     *   int count
     *     an integer
     */
};

#endif //WORD_H
