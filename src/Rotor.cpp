/**
 * @file Rotor.cpp
 * @author Lluis Torres (https://github.com/lluistp)
 * @brief Contains implementation of the class Rotor. It's documentation in the file Rotor.h .
 * @version 0.1
 * @date 2024-09-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "../header/Rotor.h"

Rotor::Rotor(){
    
}

Rotor::Rotor(const string type, const int ring_pos, const int start_pos){

    rotorConfig.initial_pos = start_pos-1;
    rotorConfig.ring_config = ring_pos-1;
    rotorConfig.rotor_type = type;
    num_rotations = start_pos-1;

    if (type == "I"){
        notches = {5,11,13,6,12,7,4,17,22,26,14,20,15,23,25,8,24,21,19,16,1,9,2,18,3,10}; 
        turning_notch = 16;
    }
    else if (type == "II"){
        notches = {1,10,4,11,19,9,18,21,24,2,12,8,23,20,13,3,17,7,26,14,16,25,6,22,15,5};
        turning_notch = 4;
    }
    else if (type == "III"){
        notches = {2,4,6,8,10,12,3,16,18,20,24,22,26,14,25,5,9,23,7,1,11,13,21,19,17,15};
        turning_notch = 21;
    }
    else if (type == "IV"){
        notches = {5,19,15,22,16,26,10,1,25,17,21,9,18,8,24,12,14,6,20,7,11,4,3,13,23,2};
        turning_notch = 9;
    }
    else {
        notches = {22,26,2,18,7,9,20,25,21,16,19,4,14,8,12,24,1,23,13,10,17,15,6,5,3,11};
        turning_notch = 25;
    }
    
    if (rotorConfig.ring_config != 0){
        for(auto i = notches.begin(); i != notches.end(); ++i) {
            *i = *i + rotorConfig.ring_config;
            if(*i > ALPHABET_LENGTH) *i = *i - (ALPHABET_LENGTH);
        }
    }
    else;
}

void Rotor::reset(){
    num_rotations = rotorConfig.initial_pos;
}

void Rotor::rotate(){
    num_rotations++;
    if (num_rotations == ALPHABET_LENGTH) num_rotations = 0;
}

int Rotor::stepPreReflector(int pos){
    pos = pos + num_rotations - rotorConfig.ring_config;
    pos = standarizationValue(pos);
    pos = notches[pos-1] - num_rotations;
    pos = standarizationValue(pos);
    return pos;
}

int Rotor::stepPastReflector(int letter){
    vector<int>::iterator pos;
    letter = letter + num_rotations;
    letter = standarizationValue(letter);
    pos = find(notches.begin(), notches.end(), letter);
    letter = pos - notches.begin() - num_rotations + rotorConfig.ring_config + 1;
    letter = standarizationValue(letter);
    return letter;
}

bool Rotor::rotateNotchPos(){
    return num_rotations == turning_notch;
}

const ConfigData Rotor::getRotorConfig(){
    return rotorConfig;
}

int Rotor::standarizationValue(int value){
    if (value > ALPHABET_LENGTH) value = value - ALPHABET_LENGTH;
    else if(value <= 0) value = value + (ALPHABET_LENGTH);
    else;
    return value;
}

