/**
 * @file Rotor.h
 * @author Lluis Torres (https://github.com/lluistp)
 * @brief 
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

struct ConfigData{
    string rotor_type;
    int initial_pos = 0;
    int ring_config = 0;
};
class Rotor{

    public:
        Rotor();
        Rotor(const string type, const int ring_pos, const int start_pos);
        /**
         * @brief hi
         * 
         */
        void reset();
        void rotate();
        int stepPreReflector(int pos);
        int stepPastReflector(int letter);
        bool rotateNotchPos();
        const ConfigData getRotorConfig();

    private:
        ConfigData rotorConfig;
        int num_rotations = 0;
        int turning_notch = 0;
        vector<int> notches;
        int standarizationValue(int value);
};

#endif