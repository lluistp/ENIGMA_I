#include <iostream>
#include <fstream>
#include <string>

#include "Enigma.h"
#include "constants.h"

using namespace std;

/** Ask to the user for a Reflector (UKW) configuration and calls the function to set that Enigma's component.
 * 
 * The function will ask to the user to choose on of the three possible configurations for the reflector of an Enigma I. Those options can be A, B or C, and the function itself makes sure that the entry is correct before calling the Enigma method. In case of an incorrect entry, it shows a message and ask for the configuration again. It has a loop that stays until a correct configuration is entered.
 * @param[in] enigma  Pass by reference of the object ENIGMA we're using.
 */
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

/** Ask to the user for three rotor configurations, one time for each rotor of an ENIGMA I, and calls the function to set those components.
 * 
 * The function will ask to the use all the parameters to set each one of the three rotors of an ENIGMA I, right, middle and left, and will check that entry before calling Enigma's method. The parameters for each rotor are:
 * -# TYPE of the rotor. For an ENIGMA I there are 5 types, named from 1 to 5 in roman numbers
 * -# RING CONFIGURATION sets an initial movement of the array of letters of a rotor before this in inserted in the Enigma
 * -# INITIAL POSITION sets an initial rotation of the rotor, not just the array of letters.
 * Both RING CONFIG. and INITIAL POS. are set with a letter inside the english alphabet, which the method will change to convert it in a number between 1 to 26.
 * This function contain three loops that can't be solved until a correct configuration has been entered for all three rotors.
 * @param[in] enigma  Pass by reference of the object ENIGMA we're using.
 */
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

/** Ask to the user for a plugboard configuration and calls the function to set that Enigma's component.
 * 
 * The function will ask the user to enter pairs of letters inside an english alphabet, it'll convert them in numbers from 1 to 26 and it'll call the enigma's method to set this component. The function will guarantee that the inputs are correct. Also it has a loop to keep entering pairs until the user wants to leave wrinting DONE as input. ENIGMA I works perfectly even if the user desides to skip the Plugboard configuration.
 * @param[in] enigma  Pass by reference of the object ENIGMA we're using.
 */
void configPlugboardEnigma(Enigma& enigma){
    bool config = false;
    string pair;
    int letter1;
    int letter2;
    cout << "ENTER PAIR OF LETTERS TO SWAP ON THE PLUGBOARD { (A ... Z)(A ... Z) }" << endl;
    cout << "ENTER \"DONE\" TO FINISH THIS STEP" << endl;
    while(!config){
        cin >> pair;
        if (pair.size() == 2 && pair[0]!=pair[1]){
            letter1 = pair[0] - LETTERS_ASCII_DIF;
            letter2 = pair[1] - LETTERS_ASCII_DIF;
            if ((letter1 > 0 && letter1 <= ALPHABET_LENGTH) && (letter2 > 0 && letter2 <= ALPHABET_LENGTH)) enigma.configPlugboard(letter1,letter2);
            else cout << "WRONG CHARACTERS" << endl;
        }
        else if (pair == "DONE") config = true;
        else cout << "ENTRY MUST BE A PAIR OF DIFERENT CHARACTERS -> ENTER \"DONE\" TO FINISH THIS STEP" << endl;
    }
}

/** Shows as a cout the actual configuration of our ENIGMA I.
 * 
 * Gets from our Enigma the configuration we have and shows it with the definition of each element as a cout iostream on our terminal.
 * @param[in] enigma  Pass by reference of the object ENIGMA we're using.
 */
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

/** Ask the user if they want to finish the Enigma configuration.
 * 
 * The function will ask the user if they are done with the configuration for the enigma. The entry has to be "Y" or "N". Contains a loop that can be left only with a correct entry.
 * @return true if "Y", false with "N".
 */
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

/** Calls the different functions that will be used to cofigure our ENGIMA I.
 * 
 * This function will call all the necessary functions to configure our ENIGMA I. It contains a loop that ends once the configuration is done (know with the function finishConfig()).
 * @param[in] enigma  Pass by reference of the object ENIGMA we're using.
 */
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
    cin.ignore();
    getline(cin, message);
    if (message.empty())cout << "EMPTY MESSAGE" << endl;
    else {
        outputFile << "MESSAGE ENTERED MANUALLY: " << message << endl << "ENCRYPTION/DECRYPTION: ";
        cout << "ENCRYPTION/DECRYPTION: ";
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
        outputFile << endl << "NUMBER OF CHARACTERS: " << counter << endl << endl;
        cout << endl << "NUMBER OF CHARACTERS: " << counter << endl << endl;
    }
}

void processMessageAsFile(Enigma& enigma, ofstream& outputFile){
    string fileName;
    char letter;
    int counter;
    int addSeparator;
    cout << "ENTER FILE NAME: ";
    cin >> fileName;
    if (fileName.empty())cout << "EMPTY FILENAME" << endl;
    else {
        ifstream inputFile(fileName);
        if(!inputFile.is_open()) cout << "ERROR OPENING THE FILE" << endl;
        else{
            string line;
            while(getline(inputFile,line)){
                outputFile << "MESSAGE ENTERED FROM FILE " << fileName << " : " << line << endl << "ENCRYPTION/DECRYPTION: ";
                cout << "MESSAGE ENTERED FROM FILE " << fileName << " : " << line << endl << "ENCRYPTION/DECRYPTION: ";
                counter = addSeparator = 0;
                for(string::iterator it = line.begin(); it != line.end(); it++){
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
            outputFile << endl << "NUMBER OF CHARACTERS: " << counter << endl << endl;
            cout << endl << "NUMBER OF CHARACTERS: " << counter << endl << endl;
            }
            inputFile.close();
        }
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
        else if(option == "2") processMessageAsFile(enigma,outputFile);
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