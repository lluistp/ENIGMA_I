/**
 * @file Reflector.h
 * @author Lluis Torres (https://github.com/lluistp)
 * @brief 
 * @version 0.1
 * @date 2024-09-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef _REFLECTOR_H_
#define _REFLECTOR_H_

#include <string>
#include <vector>

#include "Constants.h"

using namespace std;

class Reflector{
    public:
        Reflector();
        Reflector(const string type);
        int reflectLetter(int pos);
        
        const string getConfig();
        
    private:
        vector<int> notches;
        string reflec_type;
};

#endif