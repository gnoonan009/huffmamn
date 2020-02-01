#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H
#include "treeNode.h"
#include <vector>
#include <map>
#include <iterator>
#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "binary_heap.h"

using namespace std;

class huffmanTree {
public:
    huffmanTree();
    
    char decode(string& code,  const treeNode*  node);
    int fixTreeValues(treeNode* current);
    
    treeNode insert(string c, int value, string code, treeNode& current);
    treeNode* getRoot();
    
    void addRightChild(treeNode& parent, treeNode& child);
    void addLeftChild(treeNode& parent, treeNode& child);
    void decodeOutput(string enc[]);
    void createTree(map<string,string> codes, map<string, int> frequencies);
    
private:
    treeNode *root;
    friend class huffmandec;
};

#endif

