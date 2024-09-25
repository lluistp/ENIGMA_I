/**
 * @file Reflector.h
 * @author Lluis Torres (https://github.com/lluistp)
 * @brief Contains the declaration of the class Reflector with its parameters and methods
 * @version 0.1
 * @date 2024-09-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef _REFLECTOR_H_
#define _REFLECTOR_H_

#include <string>
#include <vector>
#include "Constants.h"

using namespace std;

/**
 * @brief Class meant to represent the reflector of an Enigma and its functionalities. 
 * 
 * For the Enigma I this reflector can have 3 types {'A', 'B', 'C'}, and the type decides what alphabet will contain.
 * Similar to a plugboard fully configured, the reflector alphabet is set in pairs, where position x contains letter y and position y contains letter x. When the reflector gets a position, returns the letter in that position.
 * 
 * To know more about how each element works see the specific class or go back to the main page.
 * 
 * @warning The methods of this class don't do a validation of its inputs.
 * 
 */
class Reflector{
    public:
        //CONSTRUCTORS
        /**
         * @brief Construct a new Reflector object
         * 
         */
        Reflector();
        /**
         * @brief Construct a new Reflector object acordingly to the type entered.
         * 
         * @param[in] type Defines the vector<int> notches of the Reflector with alphabet {'A', 'B', 'C'};
         */
        Reflector(const string type);

        //GETTERS
        /**
         * @brief Returns the letter in the position entered.
         * 
         * @param[in] pos Position to check in the vector<int> notches {1 ... 26}.
         * @return const int with the letter {1 ... 26}.
         */
        const int reflectLetter(int pos);
        /**
         * @brief Get the configuration of the Reflector.
         * 
         * @return const string with the type of the Reflector.
         */
        const string getConfig();
        
    private:
        vector<int> notches; ///<Vector that contains the alphabet of the Reflector
        string reflec_type; ///<Defines the type of alphabet.
};

#endif