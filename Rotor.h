#ifndef _ROTOR_H_
#define _ROTOR_H_

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#include "Constants.h"

using namespace std;

class Rotor{

    public:
        Rotor();
        Rotor(const string type, const int ring_pos, const int start_pos);
        void reset();
        void rotate();
        int stepPreReflector(int pos);
        int stepPastReflector(int letter);
        bool rotateNotchPos();
        void showRotorConfig();

    private:
        int initial_pos = 0;
        int num_rotations = 0;
        int turning_notch = 0;
        int ring_config = 0;
        string rotor_type;
        vector<int> notches;
        
        int standarizationValue(int value);
};

#endif