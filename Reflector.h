#ifndef _REFLECTOR_H_
#define _REFLECTOR_H_

#include <string>
#include <vector>
#include <iostream>

#include "Constants.h"

using namespace std;

class Reflector{
    public:
        Reflector();
        Reflector(const string type);
        int reflectLetter(int pos);
        void showReflectorConfig();
    private:
        vector<int> notches;
        string reflec_type;
};

#endif