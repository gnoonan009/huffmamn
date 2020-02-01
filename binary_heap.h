#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <vector>
#include "treeNode.h"
#include <iterator>
#include <map>
using namespace std;

class binary_heap {
public:
    binary_heap();
    binary_heap(vector<treeNode> vec);
    ~binary_heap();
    
    void insert(treeNode& t);
    treeNode findMin();
    treeNode* deleteMin();
    unsigned int size();
    void makeEmpty();
    bool isEmpty();
    void print();
    void buildHuffmanTree();
    void outputCompression(binary_heap& frequencies);
    
    string getCode(const char c);

     vector<treeNode> heap;
    
private:
   
    unsigned int heap_size;
    map<char, string> map;
    void percolateUp(int hole);
    void percolateDown(int hole);
};

#endif


