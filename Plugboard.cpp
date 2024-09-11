#include "Plugboard.h"

Plugboard::Plugboard(){
    letterPair = vector<int>(ALPHABET_LENGTH,0);  
}

void Plugboard::setPlugboard(const int letter1, const int letter2){
    if (letterPair[letter1 - 1] != 0 || letterPair[letter2 - 1] != 0){
        int actLetter = letterPair[letter1 - 1];
        letterPair[actLetter - 1] = 0;
        actLetter = letterPair[letter2 - 1];
        letterPair[actLetter - 1] = 0;
    }
    else;
    letterPair[letter1 - 1] = letter2;
    letterPair[letter2 - 1] = letter1;
}

int Plugboard::swapLetter(int letter){
    if (letterPair[letter - 1] != 0) letter = letterPair[letter - 1];
    else;
    return letter;
}

void Plugboard::showPlugboardConfig(){
        cout << "PLUGBOARD: ";
        for(auto i = letterPair.begin(); i != letterPair.end(); ++i) {
            if(*i != 0) cout << char(i-letterPair.begin()+LETTERS_ASCII_DIF+1) << " -> " << char(*i+LETTERS_ASCII_DIF) << " ";
            else;
        }
        cout << endl;
}