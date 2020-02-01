#include "huffmanTree.h"

using namespace std;

huffmanTree::huffmanTree(){
    treeNode* temp = new treeNode();
    root = temp;
}

void huffmanTree::addRightChild(treeNode& parent, treeNode& child){
    parent.rightChild = &child;
    child.parent = &parent;
}
void huffmanTree::addLeftChild(treeNode& parent, treeNode& child){
    parent.leftChild = &child;
    child.parent = &parent;
}
char huffmanTree::decode(string& oldCode,  const treeNode*  node) {
    string code = oldCode.substr(0,1);

    if(code == ""){
        return node->getCharacter();
    }
        string newCode = oldCode.substr(1);
    char c;
    if(code == "1"){
        c = decode(newCode, node->rightChild);

    }
    if(code == "0"){
        c = decode(newCode, node->leftChild);

    }
    return c;
}

treeNode huffmanTree::insert(string c, int value, string code, treeNode& current){
    
    // if we arrive at insertion postion, return new node with value and character
    if(code == ""){
        treeNode newNode(value, c.at(0));
        return newNode;
    }
    
    
    if(code.substr(0,1) == "1"){
        if(current.rightChild == NULL){
            treeNode* rightChild = new treeNode();
            addRightChild(current, *rightChild);
            
        }
        *(current.rightChild) = insert(c, value, code.substr(1), *(current.rightChild));
    }
    if(code.substr(0,1) == "0"){
        if(current.leftChild == NULL){
            treeNode* leftChild = new treeNode();
            addLeftChild(current, *leftChild);
            
        }
        *(current.leftChild) = insert(c, value, code.substr(1), *(current.leftChild));
    }
    return current;
}

int huffmanTree::fixTreeValues(treeNode* current){
    if(current->leftChild == NULL && current->rightChild == NULL){
        return current->getValue();
    }
    int sumOfChildren = 0;
    
    if(current->leftChild != NULL){
        sumOfChildren += fixTreeValues(current->leftChild);
    }
    if(current->rightChild != NULL){
        sumOfChildren += fixTreeValues(current->rightChild);
    }
    current->setValue(sumOfChildren);
    return current->getValue();
}

void huffmanTree::createTree(map<string,string> codes, map<string,int> frequencies){

    map<string, string>::iterator i;
    map<string, int>::iterator j;
    
    for (i = codes.begin(); i != codes.end(); i++) {
        for(j = frequencies.begin(); j != frequencies.end(); j++){
            // when we find the same char in both lists
            if(i->first == j->first){
                int value = j->second;
                string code = i->second;
                insert(i->first, value, code, *root);
            }
        }
    }
    
    fixTreeValues(root);
}

void huffmanTree::decodeOutput(string enc[]) {

    for(int i = 0; i < 1000; i++){
        //string s = decodeChar(*i, root);
        char s = decode(enc[i], root);
        cout << s;
    }
    cout << endl;
}

