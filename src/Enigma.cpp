/**
 * @file Enigma.cpp
 * @author Lluis Torres (https://github.com/lluistp)
 * @brief Contains implementation of the class Enigma. It's documentation in the file Enigma.h .
 * @version 0.1
 * @date 2024-09-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "../header/Enigma.h"
        //CONSTRUCTOR
        Enigma::Enigma(){}

        //SETTERS
        void Enigma::configRightRotor(const string type, const int ring_pos, const int ini_pos){
            rotor_right = Rotor(type, ring_pos, ini_pos);
        }

        void Enigma::configMiddleRotor(const string type, const int ring_pos, const int ini_pos){
            rotor_middle = Rotor(type, ring_pos, ini_pos);
        }

        void Enigma::configLeftRotor(const string type, const int ring_pos, const int ini_pos){
            rotor_left = Rotor(type, ring_pos, ini_pos);
        }

        void Enigma::configReflector(const string type){
            reflector = Reflector(type);
        }

        void Enigma::configPlugboard(const int letter1, const int letter2){
            plugboard.setPlugboard(letter1,letter2);
        }

        void Enigma::reset(){
            rotor_right.reset();
            rotor_middle.reset();
            rotor_left.reset();
        }

        //GETTERS
        const string Enigma::getReflectorConfig(){
            return reflector.getConfig();
        }

        const ConfigData Enigma::getRightRotorConfig(){
            return rotor_right.getRotorConfig();
        }
        
        const ConfigData Enigma::getMiddleRotorConfig(){
            return rotor_middle.getRotorConfig();
        }

        const ConfigData Enigma::getLeftRotorConfig(){
            return rotor_left.getRotorConfig();
        }

        const vector<int>& Enigma::getPlugboardConfig(){
            return plugboard.getConfig();
        }

        /**
         * @details Every time a letter is entered, and after the rotation is done, it goes througt 9 different steps (2 times each rotor, 2 times through the plugboard, and once through the reflector). 
         * Also, the steps through the rotors differ if it's pre or after the reflector. That's because the signal on the real rotors goes right to left before getting to the reflector, and left to right once the reflector returns the signal.
         * 
         */
        int Enigma::processLetter(int letter){
            
            mechRotation();
            letter = plugboard.swapLetter(letter);

            letter = rotor_right.stepPreReflector(letter);
            letter = rotor_middle.stepPreReflector(letter);
            letter = rotor_left.stepPreReflector(letter);

            letter = reflector.reflectLetter(letter);

            letter = rotor_left.stepPastReflector(letter);
            letter = rotor_middle.stepPastReflector(letter);
            letter = rotor_right.stepPastReflector(letter);

            letter = plugboard.swapLetter(letter);
            
            return letter;
        }

        //PRIVATE METHOD
        /**
         * @details Every time processLetter(int letter) is called the Enigma makes a rotation. That process makes the rotor_right rotates every single time, and then checks for the notch position of the right and the middle rotor to decide if the middle and the left rotor have to rotate respectively. 
         * Also, this method takes in consideration the double stepping: once the middle rotor is in notch position, the mechanical process makes both the left and the middle one rotate. That means that the middle one, in this situation, rotates twice in a raw, first after the right rotor triggers it, an then because it's on the notch position.
         * Last, for how the mechanical process works, the rotation has to be done from left to right. 
         * 
         */
        void Enigma::mechRotation(){
            if(rotor_middle.rotateNotchPos()){
                rotor_middle.rotate();
                rotor_left.rotate(); 
            }
            else;
            if(rotor_right.rotateNotchPos())rotor_middle.rotate();
            else;
            rotor_right.rotate();
        }