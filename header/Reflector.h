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
 * @brief 
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
         * @brief Construct a new Reflector object
         * 
         * @param type 
         */
        Reflector(const string type);

        //GETTERS
        /**
         * @brief 
         * 
         * @param pos 
         * @return const int 
         */
        const int reflectLetter(int pos);
        /**
         * @brief Get the Config object
         * 
         * @return const string 
         */
        const string getConfig();
        
    private:
        vector<int> notches; ///<
        string reflec_type; ///<
};

#endif