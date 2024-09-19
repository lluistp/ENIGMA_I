/**
 * @file Rotor.h
 * @author Lluis Torres (https://github.com/lluistp)
 * @brief Contains the declaration of the class ConfigData and Rotor with its parameters and methods
 * @version 0.1
 * @date 2024-09-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef _ROTOR_H_
#define _ROTOR_H_

#include <string>
#include <vector>
#include <algorithm>
#include "Constants.h"

using namespace std;

/**
 * @brief 
 * 
 */
struct ConfigData{
    string rotor_type; ///<
    int initial_pos = 0; ///<
    int ring_config = 0; ///<
};

/**
 * @brief 
 * 
 */
class Rotor{
    public:
        //CONSTRUCTORS
        /**
         * @brief Construct a new Rotor object
         * 
         */
        Rotor();
        /**
         * @brief Construct a new Rotor object
         * 
         * @param type 
         * @param ring_pos 
         * @param start_pos 
         */
        Rotor(const string type, const int ring_pos, const int start_pos);

        //SETTERS
        /**
         * @brief 
         * 
         */
        void reset();
        /**
         * @brief 
         * 
         */
        void rotate();

        //GETTERS
        /**
         * @brief 
         * 
         * @param pos 
         * @return const int 
         */
        const int stepPreReflector(int pos);
        /**
         * @brief 
         * 
         * @param letter 
         * @return const int 
         */
        const int stepPastReflector(int letter);
        /**
         * @brief 
         * 
         * @return true 
         * @return false 
         */
        const bool rotateNotchPos();
        /**
         * @brief Get the Rotor Config object
         * 
         * @return const ConfigData 
         */
        const ConfigData getRotorConfig();

    private:
        ConfigData rotorConfig; ///<
        int num_rotations = 0; ///<
        int turning_notch = 0; ///<
        vector<int> notches; ///<

        /**
         * @brief 
         * 
         * @param value 
         * @return int 
         */
        int standarizationValue(int value);
};

#endif