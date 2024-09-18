/**
 * @file Enigma.h
 * @author Lluis Torres (https://github.com/lluistp)
 * @brief Contains the declaratio of the class Enigma with its components
 * @version 0.1
 * @date 2024-09-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef _ENIGMA_H_
#define _ENIGMA_H_

#include "Rotor.h"
#include "Reflector.h"
#include "Plugboard.h"

using namespace std;

/**
 * @brief Class meant to represent the functionalities and use of the electromechanical cipher machine developed by Germany in the early to mid 20th century.
 * 
 * The Enigma represented by this class is the Enigma I. Said Enigma had the following elements:
 * - 1 Reflector (UKW). The machine had 3 different reflectors available.
 * - 3 Rotors. There was 5 different rotors, and Enigma used 3 of them inserted on any order, with any configuration and with any initial pos.
 * - 1 Plugboard. Used to connect pairs of letters to be exchanged and add another level of complexity. 
 * @warning The methods of this class don't do a validation of its inputs. 
 * 
 */
class Enigma{
    public:
        /**
         * @brief Construct a new Enigma object
         * 
         */
        Enigma();
        /**
         * @brief Creates the rotor_right with the configuration entered as parameters.
         * 
         * @param[in] type Defines the type of the right rotor. 
         * @param[in] ring_pos Defines the rotation of only the alphabet of the right rotor.
         * @param[in] ini_pos Defines the initial position of the full right rotor.
         */
        void configRightRotor(const string type, const int ring_pos, const int ini_pos);
        /**
         * @brief Creates the rotor_middle with the configuration entered as parameters.
         * 
         * @param[in] type Defines the type of the middle rotor. 
         * @param[in] ring_pos Defines the rotation of only the alphabet of the middle rotor.
         * @param[in] ini_pos Defines the initial position of the full middle rotor.
         */        
        void configMiddleRotor(const string type, const int ring_pos, const int ini_pos);
        /**
         * @brief Creates the rotor_left with the configuration entered as parameters.
         * 
         * @param[in] type Defines the type of the left rotor. 
         * @param[in] ring_pos Defines the rotation of only the alphabet of the left rotor.
         * @param[in] ini_pos Defines the initial position of the full left rotor.
         */        
        void configLeftRotor(const string type, const int ring_pos, const int ini_pos);
        /**
         * @brief Creates the reflector of the enigma with the type entered.
         * 
         * @param[in] type Defines the type of the reflector 
         */
        void configReflector(const string type);
        /**
         * @brief 
         * 
         * @param letter1 
         * @param letter2 
         */
        void configPlugboard(const int letter1, const int letter2);
        void reset();

        const string getReflectorConfig();
        const ConfigData getRightRotorConfig();
        const ConfigData getMiddleRotorConfig();
        const ConfigData getLeftRotorConfig();
        const vector<int>& getPlugboardConfig();

        int processLetter(int letter);

    private:
        Rotor rotor_right;
        Rotor rotor_middle;
        Rotor rotor_left;
        Reflector reflector;
        Plugboard plugboard;
        
        void mechRotation();
};

#endif