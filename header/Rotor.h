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
 * @brief Struct used to contain the necessary values to configurate a Rotor, element of the cipher machine Enigma.
 * 
 * To know more about how each element works see the specific class or go back to the main page.
 */
struct ConfigData{
    string rotor_type; ///<Contains type of the rotor (for Enigma I it can be "I", "II", "III", "IV" or "V"). From it depends the internal wiring, so the order of the letters of the alphabet . 
    int initial_pos = 0; ///<Contains the inital pos of the rotor (it can be 1 to 26).
    int ring_config = 0; ///<Contains the position of the alphabet tyre relative of the internal wiring of the rotor (it can be 1 to 26).
};

/**
 * @brief Class meant to represent the elements and functionalities of a rotor of the cipher machine Enigma.
 * 
 * The rotors are the main element of an Enigma machine. They're responsable of changing the initial entry for another totally different. The output depends on the type of the rotor, the ring configuration, and the position of the rotor. From the type also depends what position is the notch position.
 * Also, and because the real enigma just works as a wiring closed circuit, the rotor works different if the signal comes from the plugboard to the reflector, or comes from the reflector to the plugboard. To summarize, from the plugboard the rotor gets a position and returns the letter contained in that position. From the reflector, the rotor gets a letter and returns the position that contains that letter.
 * In this class, the alphabet of the rotors are done numerically (1 to 26) inside a vector<int>. From those vectors, both the position of the element and its content represent the letters to exchange. For exemeple, with no other changes, the rotor "I" with 'A' as input will return 'E', but in our case 'A' is position 1 and 'E' is 5, the letter contained in that position.
 * Also, since the alphabet never changes once it's set and the rotation of the rotor is always 1 position in the same direction, this class doesn't rotate the vector, it just keeps how many rotations has a rotor done and from that it calculates what position and output it should give. The rotations go from 0 (no rotations) to 25 (full roation - 1), and then starts again. 
 * 
 * To know more about how each element works see the specific class or go back to the main page.
 * 
 * @warning The methods of this class don't do a validation of its inputs.
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
         * @brief Construct a new Rotor object using the parameters entered as input for its configuration.
         * 
         * @param[in] type Defines the type of the rotor {I, II, III, IV, V}.
         * @param[in] ring_pos Defines the alphabet tyre position relative to the rotor {1 ... 26}.
         * @param[in] start_pos Defines the initial position of the rotor {1 ... 26}.
         */
        Rotor(const string type, const int ring_pos, const int start_pos);

        //SETTERS
        /**
         * @brief Sets the configuration of the rotor back to the initial one. 
         * 
         * The reset only affects a the rotations done by the rotor, so it equals the number of rotations to the initial pos of the rotor.
         * 
         */
        void reset();
        /**
         * @brief Adds one rotation to the rotor. Checks if full rotation has been done.
         * 
         */
        void rotate();

        //GETTERS
        /**
         * @brief Returns the letter contained in the position entered considering also rotations and ring configuration.
         * 
         * @param[in] pos Position with the letter we want to find {1 ... 26}.
         * @return const int with the letter of that position {1 ... 26}.
         */
        const int stepPreReflector(int pos);
        /**
         * @brief Returns the position that contains the letter entered considering also rotations and ring configuration.
         * 
         * @param letter Letter we want to find inside the vector<int> {1 ... 26}.
         * @return const int with the position of that letter {1 ... 26}.
         */
        const int stepPastReflector(int letter);
        /**
         * @brief Returns if the rotor is in the turning_notch position.
         * 
         * @return true when rotor position (num_rotations) == notch position (turning_notch).
         * @return false when rotor position (num_rotations) != notch position (turning_notch).
         */
        const bool rotateNotchPos();
        /**
         * @brief Get the Rotor Config object
         * 
         * @return const ConfigData rotorConfig of this rotor.
         */
        const ConfigData getRotorConfig();

    private:
        ConfigData rotorConfig; ///<ConfigData object with the configuration of the rotor.
        int num_rotations = 0; ///<Keeps track of the rotor position with the number of rotations done by it.
        int turning_notch = 0; ///<Contains the rotor position that will affect the rotation of a different rotor at its left, if any.
        vector<int> notches; ///<Vector with the alphabet tyre of the rotor.

        /**
         * @brief Standarizes the value entered to a scale from 1 to 26.
         * 
         * @param[in] value Element to standarize (value > -26 && value < 53).
         * @return int standarized value.
         */
        int standarizationValue(int value);
};

#endif