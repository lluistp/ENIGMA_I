#ifndef _PLUGBOARD_H_
#define _PLUGBOARD_H_

#include <string>
#include <vector>
#include <iostream>

#include "Constants.h"

using namespace std;

class Plugboard{
    public:
        Plugboard();
        void setPlugboard(const int letter1, const int letter2);
        int swapLetter(int letter);
        void showPlugboardConfig();

    private:
        vector<int> letterPair;
};

#endif