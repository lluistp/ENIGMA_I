#ifndef _ENIGMA_H_
#define _ENIGMA_H_

#include "Rotor.h"
#include "Reflector.h"
#include "Plugboard.h"

using namespace std;

class Enigma{
    public:
        Enigma();
        void configRightRotor(const string type, const int ring_pos, const int ini_pos);
        void configMiddleRotor(const string type, const int ring_pos, const int ini_pos);
        void configLeftRotor(const string type, const int ring_pos, const int ini_pos);
        void configReflector(const string type);
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