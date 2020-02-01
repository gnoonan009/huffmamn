#include "treeNode.h"
#include <stdio.h>

treeNode::treeNode(){
    value = 0;
    character = '\0';
    parent = NULL;
    leftChild = NULL;
    rightChild = NULL;
}
treeNode::treeNode(int val, char c){
    value = val;
    character = c;
    parent = NULL;
    leftChild = NULL;
    rightChild = NULL;
}

int treeNode:: getValue(){
    return value;
}
void treeNode:: setValue(int val){
    value = val;
}

void treeNode:: setChildren(treeNode *left, treeNode *right)
{
    leftChild = left;
    rightChild = right;
}

bool treeNode::equals(treeNode* t){

    if(character == t->character && value == t->value){
        return true;
    }
    return false;
}
char treeNode::getCharacter() const{
    return character;
}


