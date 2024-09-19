/**
 * @file Enigma.h
 * @author Lluis Torres (https://github.com/lluistp)
 * @brief Contains the declaration of the class Enigma with its parameters and methods
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
 * 
 * To know more about how each element works see the specific class or go back to the main page.
 * 
 * @warning The methods of this class don't do a validation of its inputs. 
 * 
 */
class Enigma{
    public:
        //CONSTRUCTOR
        /**
         * @brief Construct a new Enigma object
         * 
         */
        Enigma();
        //SETTERS
        /**
         * @brief Creates the rotor_right with the configuration entered as parameters.
         * 
         * @param[in] type Defines the type of the right rotor {I, II, III, IV, V}. 
         * @param[in] ring_pos Defines the rotation of only the alphabet of the right rotor {1 to 26}.
         * @param[in] ini_pos Defines the initial position of the full right rotor {1 to 26}.
         */
        void configRightRotor(const string type, const int ring_pos, const int ini_pos);
        /**
         * @brief Creates the rotor_middle with the configuration entered as parameters.
         * 
         * @param[in] type Defines the type of the middle rotor {I, II, III, IV, V}. 
         * @param[in] ring_pos Defines the rotation of only the alphabet of the middle rotor {1 to 26}.
         * @param[in] ini_pos Defines the initial position of the full middle rotor {1 to 26}.
         */        
        void configMiddleRotor(const string type, const int ring_pos, const int ini_pos);
        /**
         * @brief Creates the rotor_left with the configuration entered as parameters.
         * 
         * @param[in] type Defines the type of the left rotor {I, II, III, IV, V}. 
         * @param[in] ring_pos Defines the rotation of only the alphabet of the left rotor {1 to 26}.
         * @param[in] ini_pos Defines the initial position of the full left rotor {1 to 26}.
         */        
        void configLeftRotor(const string type, const int ring_pos, const int ini_pos);
        /**
         * @brief Creates the reflector of the enigma with the type entered.
         * 
         * @param[in] type Defines the type of the reflector {A, B, C}.
         */
        void configReflector(const string type);
        /**
         * @brief Configures the plugboard of the enigma adding the pair of letters entered as input.
         * 
         * @param[in] letter1 Position of the letter in the alphabet {1 to 26}.
         * @param[in] letter2 Position of the letter in the alphabet {1 to 26}.
         */
        void configPlugboard(const int letter1, const int letter2);
        /**
         * @brief Sets the enigma configuration back to the initial one.
         * 
         * Reseting the enigma only implies reseting the three rotors, since the other elements are static.
         */
        void reset();
        /**
         * @brief Advances enigma in one rotation and processes the letter entered as input throught all the steps for it to be encrypted.
         * 
         * @param[in] letter Position of the letter in the alphabet {1 to 26} that we will encrypt.
         * @return int with the position of the letter in the alphabet {1 to 26} resulting from encripting the param letter.
         */
        int processLetter(int letter);
        //GETTERS
        /**
         * @brief Get the Reflector configuration type.
         * 
         * @return const string with the Reflector type.
         */
        const string getReflectorConfig();
        /**
         * @brief Get the right Rotor configuration as a ConfigData object.
         * 
         * @return const ConfigData object with the rotor_right configuration values.
         */
        const ConfigData getRightRotorConfig();
        /**
         * @brief Get the middle Rotor configuration as a ConfigData object.
         * 
         * @return const ConfigData object with the rotor_middle configuration values.
         */
        const ConfigData getMiddleRotorConfig();
        /**
         * @brief Get the left Rotor configuration as a ConfigData object.
         * 
         * @return const ConfigData object with the rotor_left configuration values.
         */
        const ConfigData getLeftRotorConfig();
        /**
         * @brief Get the Plugboard configuration as a reference to its vector letterPair. 
         * 
         * @return const vector<int>& that reflects the pairs of letters of the plugboard.
         */
        const vector<int>& getPlugboardConfig();

    private:
        Rotor rotor_right; ///< Rotor object to represent the right rotor of an ENIGMA I.
        Rotor rotor_middle; ///< Rotor object to represent the middle rotor of an ENIGMA I.
        Rotor rotor_left; ///< Rotor object to represent the left rotor of an ENIGMA I.
        Reflector reflector; ///< Reflector object to represent the reflector of an ENIGMA I.
        Plugboard plugboard; ///< Plugboard object to represent the plugboard of an ENIGMA I.
        
        /**
         * @brief Rotates the necessary rotors of the Enigma every time a letter is introduced.
         * 
         */
        void mechRotation();
};

#endif