/**
 * @file Plugboard.h
 * @author Lluis Torres (https://github.com/lluistp)
 * @brief Contains the declaration of the class Plugboard with its parameters and methods
 * @version 0.1
 * @date 2024-09-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef _PLUGBOARD_H_
#define _PLUGBOARD_H_

#include <string>
#include <vector>
#include "Constants.h"

using namespace std;

/**
 * @brief Class meant to represent a the plugboard of an Enigma mchine and its funcionalities.
 * 
 * The Plugboard is the first and the last step of the encryption of a letter with Enigma. Is also the only one that can be skipped if it's not configured.
 * The plugboard, if configured, works with pair of letters that will be exchange between them. It consist of a vector<int> with size =26, where cada position represents a letter, and its content is the letter that will be exchanged. Since it works in both directions, if we want to change 'A' with 'T', the position 'A' of the vector will contain a 'T', and the 'T' position an 'A'.
 * 
 * To know more about how each element works see the specific class or go back to the main page.
 * 
 * @warning The methods of this class don't do a validation of its inputs.
 * 
 */
class Plugboard{
    public:
        //CONSTRUCTOR
        /**
         * @brief Construct a new Plugboard object initializing its vector<int> letterPair with zeros.
         * 
         */
        Plugboard();

        //SETTER
        /**
         * @brief Adds the pair of letters entered in the vector letterPair.
         * 
         * @param[in] letter1 Letter 1 of a pair {1 ... 26}.
         * @param[in] letter2 Letter 2 of a pair {1 ... 26}.
         */
        void setPlugboard(const int letter1, const int letter2);

        //GETTERS
        /**
         * @brief Checks the vector letterPair at the letter position, and swaps it with its content if necessary.
         * 
         * @param[in] letter Contains the letter to search {1 ... 26}.
         * @return const int with the new letter if (letterPair[letter - 1] != 0), or the same letter entered.
         */
        const int swapLetter(int letter);
        /**
         * @brief Get the configuration of the plugboard as a const reference to the vector<int> letterPair.
         * 
         * @return const vector<int>& to letterPair.
         */
        const vector<int>& getConfig();

    private:
        vector<int> letterPair; ///<Vector<int> with the pair of letters we want to swap, if any.
};

#endif