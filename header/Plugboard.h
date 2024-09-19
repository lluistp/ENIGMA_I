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
 * @brief 
 * 
 */
class Plugboard{
    public:
        //CONSTRUCTOR
        /**
         * @brief Construct a new Plugboard object
         * 
         */
        Plugboard();

        //SETTER
        /**
         * @brief Set the Plugboard object
         * 
         * @param letter1 
         * @param letter2 
         */
        void setPlugboard(const int letter1, const int letter2);

        //GETTERS
        /**
         * @brief 
         * 
         * @param letter 
         * @return const int 
         */
        const int swapLetter(int letter);
        /**
         * @brief Get the Config object
         * 
         * @return const vector<int>& 
         */
        const vector<int>& getConfig();

    private:
        vector<int> letterPair; ///<
};

#endif