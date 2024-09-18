/**
 * @file Plugboard.h
 * @author Lluis Torres (https://github.com/lluistp)
 * @brief 
 * @version 0.1
 * @date 2024-09-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef _PLUGBOARD_H_
#define _PLUGBOARD_H_

#include <string>
#include <vector>

#include "Constants.h"

using namespace std;

class Plugboard{
    public:
        Plugboard();
        void setPlugboard(const int letter1, const int letter2);
        int swapLetter(int letter);

        const vector<int>& getConfig();

    private:
        vector<int> letterPair;
};

#endif