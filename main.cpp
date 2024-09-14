#include <iostream>
#include <fstream>
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

void showConfigEnigma(Enigma& enigma){
    cout << endl << "CONFIGURATION:" << endl;
    cout << "UKW: " << enigma.getReflectorConfig() << endl;
    ConfigData rotorData = enigma.getRightRotorConfig();
    cout << "RIGHT ROTOR: TYPE: " << rotorData.rotor_type << ", RING CONFIG: " << char(rotorData.ring_config+LETTERS_ASCII_DIF+1) << ", INITIAL POS: " << char(rotorData.initial_pos+LETTERS_ASCII_DIF+1) << endl; 
    rotorData = enigma.getMiddleRotorConfig();
    cout << "MIDDLE ROTOR: TYPE: " << rotorData.rotor_type << ",RING CONFIG: " << char(rotorData.ring_config+LETTERS_ASCII_DIF+1) << ", INITIAL POS: " << char(rotorData.initial_pos+LETTERS_ASCII_DIF+1) << endl;
    rotorData = enigma.getLeftRotorConfig();
    cout << "LEFT ROTOR: TYPE: " << rotorData.rotor_type << ", RING CONFIG: " << char(rotorData.ring_config+LETTERS_ASCII_DIF+1) << ", INITIAL POS: " << char(rotorData.initial_pos+LETTERS_ASCII_DIF+1) << endl;
    cout << "PLUGBOARD CONFIG: ";
    vector<int> plugboardConfig = enigma.getPlugboardConfig();
    for(auto i = plugboardConfig.begin(); i != plugboardConfig.end(); ++i) {
        if(*i != 0) cout << char(i-plugboardConfig.begin()+LETTERS_ASCII_DIF+1) << "->" << char(*i+LETTERS_ASCII_DIF) << " ";
        else;
    }
    cout << endl << endl;
}

bool finishConfig(){
    bool done = false;
    string entry;
    while(!done){
        cout << "FINISH CONFIGURATION { Y } OR START AGAIN { N } ?" << endl;
        cin >> entry;
        if(entry.size() == 1 && (entry == "Y" || entry == "N")){
            if(entry == "Y"){
                done = true;
                return true;
            }
            else done = true;
        }
        else cout << "WRONG ENTRY" << endl;
    }
    return false; 
}

void configEnigma(Enigma& enigma){
    bool config = false;
    while(!config){
        cout << "START ENIGMA CONFIGURATION:" << endl;
        configReflectorEnigma(enigma);
        configRotorEnigma(enigma);
        configPlugboardEnigma(enigma);
        showConfigEnigma(enigma);
        config = finishConfig();
        cout << endl;
    }
}

void processMessageManually(Enigma& enigma, ofstream& outputFile){
    string message;
    char letter;
    int counter = 0;
    int addSeparator = 0;
    cout << "ENTER MESSAGE: ";
    cin >> message;
    try {
        if (message.empty())throw "EMPTY MESSAGE";
        else {
            outputFile << "RESULTING MESSAGE: ";
            for(string::iterator it = message.begin(); it != message.end(); it++){
                letter = *it - LETTERS_ASCII_DIF;
                if ((letter > 0 && letter <= ALPHABET_LENGTH) && (letter > 0 && letter <= ALPHABET_LENGTH)){
                    letter = enigma.processLetter(letter);
                    outputFile << char(letter+LETTERS_ASCII_DIF);
                    cout << char(letter+LETTERS_ASCII_DIF);
                    counter++;
                    addSeparator++;
                    if(addSeparator == 5){
                        outputFile << " ";
                        cout << " ";
                        addSeparator = 0;
                    }
                }
                else if ((*it - LETTERS_UNDERCASE_ASCII_DIF > 0 && *it - LETTERS_UNDERCASE_ASCII_DIF <= ALPHABET_LENGTH) && (*it - LETTERS_UNDERCASE_ASCII_DIF > 0 && *it - LETTERS_UNDERCASE_ASCII_DIF <= ALPHABET_LENGTH)){
                    letter = enigma.processLetter(*it - LETTERS_UNDERCASE_ASCII_DIF);
                    outputFile << char(letter+LETTERS_ASCII_DIF);
                    cout << char(letter+LETTERS_ASCII_DIF);
                    counter++;
                    addSeparator++;
                    if(addSeparator == 5){
                        outputFile << " ";
                        cout << " ";
                        addSeparator = 0;
                    }
                }
                else ;
            }
            outputFile << endl;
            outputFile << "NUMBER OF CHARACTERS: " << counter << endl;
            cout << endl;
            cout << "NUMBER OF CHARACTERS: " << counter << endl;
        }
    }
    catch (const char *error){
        cerr << error << endl;
    }
}

void optionProcessMessage(Enigma& enigma, ofstream& outputFile){
    string option;
    bool finish = false;
    while(!finish){
        cout << "OPTIONS:" << endl;
        cout << "--- 1 --- ENTER MESSAGE MANUALLY" << endl;
        cout << "--- 2 --- ENTER MESSAGE AS A FILE" << endl;
        cout << "--- 0 --- GO BACK" << endl;
        cin >> option;
        if(option == "1") processMessageManually(enigma,outputFile);
        else if(option == "2") ;
        else if(option == "0") finish = true;
        else cout << "ENTER A VALID OPTION" << endl;
    }
}

void useEnigma(Enigma& enigma){
    ofstream outputFile("Output.txt");
    string option;
    bool finish = false;
    while(!finish){
        cout << "OPTIONS:" << endl;
        cout << "--- 1 --- PROCESS MESSAGE TO ENCRYPT/DECRYPT" << endl;
        cout << "--- 2 --- RESET ENIGMA" << endl;
        cout << "--- 3 --- SHOW ENIGMA CONFIGURATION" << endl;
        cout << "--- 0 --- FINISH PROGRAM" << endl;
        cin >> option;
        if(option == "1") optionProcessMessage(enigma,outputFile);
        else if(option == "2") enigma.reset();
        else if(option == "3") showConfigEnigma(enigma);
        else if(option == "0") {
            finish = true;
            outputFile.close();
        }
        else cout << "ENTER A VALID OPTION" << endl;
    }
}

int main(){

    Enigma enigma1;

    configEnigma(enigma1);

    useEnigma(enigma1);
    
    return (0);
}