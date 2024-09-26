# Enigma I Cipher Machine Simulator in C++

## Overview

This project simulates the [Enigma cipher machine](https://en.wikipedia.org/wiki/Enigma_machine), a device used by the German military during World War II for encrypting and decrypting messages. Actually, from all the different types of Enigma
that existed, this project simulates a 1930 Enigma I. This enigma had the following components:

- **Plugboard**: Addition for this specific model, greatly increased it's cryptographic strength. The plugboard had cables that allowed the connection between two letters, swaping them. Although 13 pairs were available, only 10 were used normally. 

- **Reflector**: The reflector connected outputs of the last rotor in pairs, redirecting current back through the rotors by a different route. The reflector ensured that Enigma would be self-reciprocal; thus, with two identically configured machines, a message could be encrypted on one and decrypted on the other, without the need for a bulky mechanism to switch between encryption and decryption modes. The reflector allowed a more compact design, but it also gave Enigma the property that no letter ever encrypted to itself. This was a severe cryptological flaw that was subsequently exploited by codebreakers. For our enigma, three reflectors were available: UKW A, UKW B and UKW C.

- **Rotors**: Each rotor is a disc approximately 10 cm (3.9 in) in diameter made from Ebonite or Bakelite with 26 brass, spring-loaded, electrical contact pins arranged in a circle on one face, with the other face housing 26 corresponding electrical contacts in the form of circular plates. The pins and contacts represent the alphabet — typically the 26 letters A–Z, as will be assumed for the rest of this description. When the rotors are mounted side by side on the spindle, the pins of one rotor rest against the plate contacts of the neighbouring rotor, forming an electrical connection. Inside the body of the rotor, 26 wires connect each pin on one side to a contact on the other in a complex pattern. When the Enigma I was created by 1930, it had available 3 different rotors: 'I', 'II' and 'III'. Our project is based on an Enigma I after 1934, when 2 more rotors were added: 'IV' and 'V'. Those rotors could be configured in any order, position or alphabet tyre configuration. 

With an Enigma ready to work, each letter followed a closed wired circuit. After the keyboard, the signal goes to the plugboard, were it's swapped only if a cable is present on the letter pressed on the keyboard. From that the signal goes from right to left for all three rotors, being changed on all of them. After the rotors it reaches the reflector, were is changed by the appropriate pair, and then goes back to the rotors, but this time from left to right. For last, it goes one last time to the plugboard, and then to the light bulbs that show the result of the encryption.

To know more details about the different components of a Enigma and how they work, please check the following links:

* General information from it's [Wikipedia](https://en.wikipedia.org/wiki/Enigma_machine).
* Technical information about it's wiring, possible configurations, and other particularities on [Crypto_Museum](https://www.cryptomuseum.com/crypto/enigma/wiring.htm) or on [CIPHER_MACHINES_AND_CRYPTOLOGY](https://www.ciphermachinesandcryptology.com/en/enigmatech.htm).
* Video with a great visual explanation of how Enigma works from Jared Owen Youtube's [channel](https://www.youtube.com/watch?v=ybkkiGtJmkM).
* Information about Bletchley Park and how the code was broken on [Britannica](https://www.britannica.com/topic/Enigma-German-code-device).

## Goals

This C++ implementation wanted to provide an exploration of the Enigma machine's functionalities, including rotors, reflectors, and plugboard configurations. It was done out of curiosity to know how the machine worked and to know if I would be able to replicte it. It was done with C++ to use and mantain my skills on this languange while I go through a very innactive period of time. I'm aware it can have some improvements, like how the input is manage or error handling, but perfection was never the goal of this project.

## Features

- [x] **Rotor Configuration**: Select from multiple rotors and set their initial positions and ring configuration.
- [x] **Reflector Configurtation**: Select from multiple reflectors.
- [x] **Plugboard Setup**: Customize the plugboard for letter swaps.
- [x] **Change or Reset**: The program will show the configuration entered and will ask if it's correct to allow changes. Also, the program includes a Reset option to go back to the initial configuration.
- [x] **Encryption & Decryption**: Input either files or type message to encrypt and ciphertext to decrypt. The message can be in capital, undercase or both. Output both on a file "Output.txt" and on terminal. The program allows to encrypt a message, use the reset option, and then enter the result of the first encryption to see how it give us the first message entered.
- [x] **Historical Accuracy**: Simulates the original Enigma I design and mechanisms.

## Requirements

- C++11 or higher
- A compatible compiler (e.g., g++, clang++)

## Installation

Open a terminal or navigate into the project directory and compile the source code:
   ```bash
   g++ -o enigma *.cpp header/*.h src/*.cpp
   ```

## Usage

1. Run the program:
   ```bash
   ./enigma
   ```

2. Follow the prompts to configure the machine:
   - Select rotors and their initial positions and ring configuration.
   - Select the reflector.
   - Set up the plugboard.
   - Choose between the available options to use a message for encryption or decryption.

## Example

To encrypt the message "hello":
```bash
START ENIGMA CONFIGURATION:
ENTER TYPE FOR THE REFLECTOR (UKW) { A , B , C }
B
RIGHT ROTOR: ENTER TYPE { I , II , III , IV , V}
II
RIGHT ROTOR: ENTER RING CONFIGURATION { A ... Z }
A
RIGHT ROTOR: ENTER INITIAL POSITION { A ... Z }
R
MIDDLE ROTOR: ENTER TYPE { I , II , III , IV , V}
IV
MIDDLE ROTOR: ENTER RING CONFIGURATION { A ... Z }
C
MIDDLE ROTOR: ENTER INITIAL POSITION { A ... Z }
D
LEFT ROTOR: ENTER TYPE { I , II , III , IV , V}
I
LEFT ROTOR: ENTER RING CONFIGURATION { A ... Z }
B
LEFT ROTOR: ENTER INITIAL POSITION { A ... Z }
A
ENTER PAIR OF LETTERS TO SWAP ON THE PLUGBOARD { (A ... Z)(A ... Z) }
ENTER "DONE" TO FINISH THIS STEP
BD
TN
ZI
DONE

CONFIGURATION:
UKW: B
RIGHT ROTOR: TYPE: II, RING CONFIG: A, INITIAL POS: R
MIDDLE ROTOR: TYPE: IV,RING CONFIG: C, INITIAL POS: D
LEFT ROTOR: TYPE: I, RING CONFIG: B, INITIAL POS: A
PLUGBOARD CONFIG: B->D D->B I->Z N->T T->N Z->I

FINISH CONFIGURATION { Y } OR START AGAIN { N } ?
Y

OPTIONS:
--- 1 --- PROCESS MESSAGE TO ENCRYPT/DECRYPT
--- 2 --- RESET ENIGMA
--- 3 --- SHOW ENIGMA CONFIGURATION
--- 0 --- FINISH PROGRAM
1
OPTIONS:
--- 1 --- ENTER MESSAGE MANUALLY
--- 2 --- ENTER MESSAGE AS A FILE
--- 0 --- GO BACK
1
ENTER MESSAGE: hello
ENCRYPTION/DECRYPTION: BJTYG
NUMBER OF CHARACTERS: 5

OPTIONS:
--- 1 --- ENTER MESSAGE MANUALLY
--- 2 --- ENTER MESSAGE AS A FILE
--- 0 --- GO BACK
0
OPTIONS:
--- 1 --- PROCESS MESSAGE TO ENCRYPT/DECRYPT
--- 2 --- RESET ENIGMA
--- 3 --- SHOW ENIGMA CONFIGURATION
--- 0 --- FINISH PROGRAM
0
```
## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
