#include "Enigma.h"

        Enigma::Enigma(){}

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

        void Enigma::showEnigmaConfig(){
            reflector.showReflectorConfig();
            cout << "RIGHT ROTOR -> ";
            rotor_right.showRotorConfig();
            cout << "MIDDLE ROTOR -> ";
            rotor_middle.showRotorConfig();
            cout << "RIGHT ROTOR -> ";
            rotor_left.showRotorConfig();
            plugboard.showPlugboardConfig();
        }

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