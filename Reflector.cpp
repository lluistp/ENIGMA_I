#include "Reflector.h"

Reflector::Reflector(){
    
}

Reflector::Reflector(string type){
    reflec_type = type;
    if (type == "A") notches = {5,10,13,26,1,12,25,24,22,2,23,6,3,18,17,21,15,14,20,19,16,9,11,8,7,4}; 
    else if (type == "B") notches = {25,18,21,8,17,19,12,4,16,24,14,7,15,11,13,9,5,2,6,26,3,23,22,10,1,20};
    else notches = {6,22,16,10,9,1,15,25,5,4,18,26,24,23,7,3,20,11,21,17,19,2,14,13,8,12};
}

int Reflector::reflectLetter(int pos){
    return notches[pos-1];
}

const string Reflector::getConfig(){
    return reflec_type;
}

