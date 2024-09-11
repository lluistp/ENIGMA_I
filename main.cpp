#include <iostream>
#include <string>

#include "Enigma.h"
#include "constants.h"

using namespace std;

void configReflectorEnigma(Enigma& enigma){
    bool config = false;
    string type;
    while(!config){
        cout << "ENTER TYPE FOR THE REFLECTOR (UKW) { A , B , C }" << endl;
        cin >> type;
        if (type == "A" || type == "B" || type == "C"){
            enigma.configReflector(type);
            config = true;
        }
        else cout << "WRONG REFLECTOR TYPE" << endl;
    }
}

void configRotorEnigma(Enigma& enigma){
    bool config = false;
    bool rotor1 = false;
    bool rotor2 = false;
    string type;
    string ringPos;
    string letterPos;
    while(!config){
        if (!rotor1){
            cout << "RIGHT ROTOR: ENTER TYPE { I , II , III , IV , V}" << endl;
            cin >> type;
            if (type == "I" || type == "II" || type == "III" || type == "IV" || type == "V"){
                cout << "RIGHT ROTOR: ENTER RING CONFIGURATION { A ... Z }" << endl;
                cin >> ringPos;
                if (ringPos.size() == 1 && ringPos[0] - LETTERS_ASCII_DIF > 0 && ringPos[0] - LETTERS_ASCII_DIF <= ALPHABET_LENGTH){
                    cout << "RIGHT ROTOR: ENTER INITIAL POSITION { A ... Z }" << endl;
                    cin >> letterPos;
                    if (letterPos.size() == 1 && letterPos[0] - LETTERS_ASCII_DIF > 0 && letterPos[0] - LETTERS_ASCII_DIF <= ALPHABET_LENGTH){
                        enigma.configRightRotor(type, ringPos[0] - LETTERS_ASCII_DIF, letterPos[0] - LETTERS_ASCII_DIF);
                        rotor1 = true;
                    }
                    else cout << "WRONG ROTOR POSITION" << endl;
                }
                else cout << "WRONG RING ROTOR PARAMETER" << endl;
            }
            else cout << "WRONG ROTOR TYPE" << endl;
        }
        else if (!rotor2){
            cout << "MIDDLE ROTOR: ENTER TYPE { I , II , III , IV , V}" << endl;
            cin >> type;
            if (type == "I" || type == "II" || type == "III" || type == "IV" || type == "V"){
                cout << "MIDDLE ROTOR: ENTER RING CONFIGURATION { A ... Z }" << endl;
                cin >> ringPos;
                if (ringPos.size() == 1 && ringPos[0] - LETTERS_ASCII_DIF > 0 && ringPos[0] - LETTERS_ASCII_DIF <= ALPHABET_LENGTH){
                    cout << "MIDDLE ROTOR: ENTER INITIAL POSITION { A ... Z }" << endl;
                    cin >> letterPos;
                    if (letterPos.size() == 1 && letterPos[0] - LETTERS_ASCII_DIF > 0 && letterPos[0] - LETTERS_ASCII_DIF <= ALPHABET_LENGTH){
                        enigma.configMiddleRotor(type, ringPos[0] - LETTERS_ASCII_DIF, letterPos[0] - LETTERS_ASCII_DIF);
                        rotor2 = true;
                    }
                    else cout << "WRONG ROTOR POSITION" << endl;
                }
                else cout << "WRONG RING ROTOR PARAMETER" << endl;
            }
            else cout << "WRONG ROTOR TYPE" << endl;
        }
        else {
            cout << "LEFT ROTOR: ENTER TYPE { I , II , III , IV , V}" << endl;
            cin >> type;
            if (type == "I" || type == "II" || type == "III" || type == "IV" || type == "V"){
                cout << "LEFT ROTOR: ENTER RING CONFIGURATION { A ... Z }" << endl;
                cin >> ringPos;
                if (ringPos.size() == 1 && ringPos[0] - LETTERS_ASCII_DIF > 0 && ringPos[0] - LETTERS_ASCII_DIF <= ALPHABET_LENGTH){
                    cout << "LEFT ROTOR: ENTER INITIAL POSITION { A ... Z }" << endl;
                    cin >> letterPos;
                    if (letterPos.size() == 1 && letterPos[0] - LETTERS_ASCII_DIF > 0 && letterPos[0] - LETTERS_ASCII_DIF <= ALPHABET_LENGTH){
                        enigma.configLeftRotor(type, ringPos[0] - LETTERS_ASCII_DIF, letterPos[0] - LETTERS_ASCII_DIF);
                        config = true;
                    }
                    else cout << "WRONG ROTOR POSITION" << endl;
                }
                else cout << "WRONG RING ROTOR PARAMETER" << endl;
            }
            else cout << "WRONG ROTOR TYPE" << endl;
        }
    }
}

void configPlugboardEnigma(Enigma& enigma){
    bool config = false;
    string pair;
    int letter1;
    int letter2;
    cout << "ENTER PAIR OF LETTERS TO SWAP ON THE PLUGBOARD { (A ... Z)(A ... Z) }" << endl;
    cout << "ENTER \"DONE\" TO FINISH THIS STEP" << endl;
    while(!config){
        cin >> pair;
        if (pair.size() == 2){
            letter1 = pair[0] - LETTERS_ASCII_DIF;
            letter2 = pair[1] - LETTERS_ASCII_DIF;
            if ((letter1 > 0 && letter1 <= ALPHABET_LENGTH) && (letter2 > 0 && letter2 <= ALPHABET_LENGTH)) enigma.configPlugboard(letter1,letter2);
            else cout << "WRONG CHARACTERS" << endl;
        }
        else if (pair == "DONE") config = true;
        else cout << "ENTRY MUST BE A PAIR OF CHARACTERS -> ENTER \"DONE\" TO FINISH THIS STEP" << endl;
    }
}

void configEnigma(Enigma& enigma){
    bool config = false;
    string entry;
    while(!config){
        cout << "START ENIGMA CONFIGURATION:" << endl;
        configReflectorEnigma(enigma);
        configRotorEnigma(enigma);
        configPlugboardEnigma(enigma);
        cout << endl << "ACTUAL CONFIGURATION:" << endl;
        enigma.showEnigmaConfig();
        bool done = false;
        while(!done){
            cout << "FINISH CONFIGURATION { Y } OR START AGAIN { N } ?" << endl;
            cin >> entry;
            if(entry.size() == 1 && (entry == "Y" || entry == "N")){
                if(entry == "Y"){
                    done = true;
                    config = true;
                }
                else done = true;
            }
            else cout << "WRONG ENTRY" << endl;
        }
    }
}

int main(){

    char letter = '1';
    bool config = false;
    Enigma enigma1;
    
    configEnigma(enigma1);

    cin >> letter;
    while(letter != '0'){  
        letter = enigma1.processLetter(letter - LETTERS_ASCII_DIF);
        cout << char(letter + LETTERS_ASCII_DIF) << endl;
        cin >> letter;
    }
    return (0);
}