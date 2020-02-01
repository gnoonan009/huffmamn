#include "binary_heap.h"
#include <iostream>
#include <iostream>
#include <stdlib.h>
#include "treeNode.h"
#include <stdio.h>
using namespace std;

int main(int argc, const char * argv[]) {
    
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }
     
    
    
    // attempt to open the supplied file.  FILE is a type desgined to
    // hold file pointers.  The first parameter to fopen() is the
    // filename.  The second parameter is the mode -- "r" means it
    // will read from the file.
    
    //FILE *fp = fopen(argv[1], "r");
    FILE *fp = fopen(argv[1], "r");
    // if the file wasn't found, output and error message and exit
    if ( fp == NULL ) {
        cout << "File '" << argv[1] << "' does not exist!" << endl;
        exit(2);
    }
    // read in each character, one by one.  Note that the fgetc() will
    // read in a single character from a file, and returns EOF when it
    // reaches the end of a file.
    char g;
    
    int count[256] = {0};
    int uncompressedSize = 0;
    string text = "";
    while ( (g = fgetc(fp)) != EOF ){
 
        if(g != '\n'){
                   uncompressedSize += 8;
            text += g;
            count[g]++;
        }
    }
    
    binary_heap frequencies;
    for(int i = 0; i < 256; i ++){
        if(count[i] != 0){
            treeNode t (count[i], char(i));
            frequencies.insert(t);
            //cout << char(i) << ": " << count[i] << endl;
        }
    }
    binary_heap huffmanTree = frequencies;
    
    huffmanTree.buildHuffmanTree();
    huffmanTree.outputCompression(frequencies);
    

    
    // a nice pretty separator
    cout << "----------------------------------------" << endl;
    string compressedText = "";
    treeNode root = frequencies.findMin();
    for(char& c : text) {
        string replacement = huffmanTree.getCode(c);
        cout << replacement << " ";
        compressedText += replacement;
    }
    int compressedSize = compressedText.size();
    cout << endl;
    cout << "----------------------------------------" << endl;
    
    cout << "There are a total of " << uncompressedSize/8 << " symbols that are encoded." << endl;
    cout << "There are " << frequencies.size() << " distinct symbols used." << endl;
    cout << "There were " << uncompressedSize << " bits in the original file." << endl;
    cout << "There were " <<compressedSize << " bits in the compressed file." << endl;
    cout << "This gives a compression ratio of " << (double)uncompressedSize/(double)compressedSize << "." << endl;
    
    
    double cost = 0.0;
    for(int i = 1; i < frequencies.size() + 1; i ++){
        string code = huffmanTree.getCode(frequencies.heap[i].getCharacter());
        double pathLength = code.size();
        
        double probabilityOfSymbol = (double)frequencies.heap[i].getValue()/(uncompressedSize/8.0);
        cost += probabilityOfSymbol * pathLength;
    }
    cout << "The cost of the Huffman tree is " << cost << " bits per character." << endl;
    
    // rewinds the file pointer, so that it starts reading the file
    // again from the begnning
    rewind(fp);
    // read the file again, and print to the screen

    // close the file
    fclose(fp);
}




