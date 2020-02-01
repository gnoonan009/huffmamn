#ifndef TREENODE_H
#define TREENODE_H
#include <vector>

using namespace std;

class treeNode {
public:
    treeNode();
    treeNode(int val, char c);

    int getValue();
    void setValue(int val);
    void setChildren(treeNode *left, treeNode *right);
    void setParent(treeNode *node);
    bool equals(treeNode* t);
    char getCharacter() const;
    
    treeNode *parent;
    treeNode *leftChild;
    treeNode *rightChild;
private:
    int value;
    char character;
    friend class binary_heap;
    friend class huffmandec;
};

#endif


