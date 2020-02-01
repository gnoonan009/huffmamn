#include "huffmanTree.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <iterator>
#include <map>
#include "binary_heap.h"
using namespace std;

string getCharFromCode(std::map<string,string> &codeMap, string code){
    string character = "";
    for (auto &i : codeMap) {
        if (i.second == code) {
            character = i.first;
            break;
        }
    }
    return character;
}


int main(int argc, const char * argv[]) {
    
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }
     
    // attempt to open the supplied file; must be opened in binary
    // mode, as otherwise whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    // read in the first section of the file: the prefix codes
    
    std::map<string,string> codes;
    while ( true ) {
        string character, prefix;
        // read in the first token on the line
        file >> character;
        // did we hit the separator?
        if ( (character[0] == '-') && (character.length() > 1) )
            break;
        // check for space
        if ( character == "space" )
            character = " ";
        // read in the prefix code
        file >> prefix;
        // map prefixes to characters
        codes.insert(pair<string,string>(character, prefix));
        /*
        cout << "character '" << character << "' has prefix code '"
        << prefix << "'" << endl;
         */
        
    }
    
    std::map<string, int> frequencies;
    string encodedBits[1000];
    int count = 0;
    while ( true ) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if ( bits[0] == '-' )
            break;
        // add it to the vector of encoded bits
        encodedBits[count] = bits;
        count++;
        string s = "";
        string character = getCharFromCode(codes, bits);
        
        if (frequencies.find(character) == frequencies.end()) {
            // add character to frequencies map if not found, give initial value of 1
            frequencies.insert(pair<string,int>(character,1));
        } else {
            // incremenet frequency of character if found
            map<string, int>::iterator i;
            for (i = frequencies.begin(); i != frequencies.end(); i++) {
                if(i->first == character){
                    i->second++;
                }
            }

        }
    
    }
    huffmanTree huffmanTree;
    huffmanTree.createTree(codes, frequencies);
    huffmanTree.decodeOutput(encodedBits);
    file.close();
}



