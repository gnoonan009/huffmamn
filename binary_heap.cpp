#include <iostream>
#include "binary_heap.h"
using namespace std;

// default constructor
binary_heap::binary_heap() : heap_size(0) {
    treeNode t;
    heap.push_back(t);
}

// builds a heap from an unsorted vector
binary_heap::binary_heap(vector<treeNode> vec) : heap_size(vec.size()) {
    heap = vec;
    heap.push_back(heap[0]);
    
    treeNode t;
    heap[0] = t;
    for ( int i = heap_size/2; i > 0; i-- )
        percolateDown(i);
}

// the destructor doesn't need to do much
binary_heap::~binary_heap() {
}

void binary_heap::insert(treeNode &t) {
    // a vector push_back will resize as necessary
    
    heap.push_back(t);
    // move it up into the right position
    percolateUp(++heap_size);
}

void binary_heap::percolateUp(int hole) {
    treeNode t = heap[hole];
    // get the value just inserted
    int x = t.value;
    // while we haven't run off the top and while the
    // value is less than the parent...
    for ( ; (hole > 1) && (x < heap[hole/2].value); hole /= 2 )
        heap[hole] = heap[hole/2]; // move the parent down
    // correct position found!  insert at that spot
    heap[hole] = t;
}

treeNode* binary_heap::deleteMin() {
    // make sure the heap is not empty
    if ( heap_size == 0 )
        throw "deleteMin() called on empty heap";
    // save the value to be returned
    treeNode* ret = new treeNode();
    *ret = heap[1];
    // move the last inserted position into the root
    heap[1] = heap[heap_size--];
    // make sure the vector knows that there is one less element
    heap.pop_back();
    // percolate the root down to the proper position
    percolateDown(1);
    // return the old root node
    return ret;
}

void binary_heap::percolateDown(int hole) {
    treeNode* t = new treeNode();
    *t = heap[hole];
    // get the value to percolate down
    int x = t->value;
    // while there is a left child...
    while ( hole*2 <= heap_size ) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ( (child+1 <= heap_size) && (heap[child+1].value < heap[child].value) )
            child++;
        // if the child is greater than the node...
        if ( x > heap[child].value ) {
            heap[hole] = heap[child]; // move child up
            hole = child;             // move hole down
        } else
            break;
    }
    // correct position found!  insert at that spot
    heap[hole] = *t;
}

treeNode binary_heap::findMin() {
    if ( heap_size == 0 )
        throw "findMin() called on empty heap";
    return heap[1];
}

unsigned int binary_heap::size() {
    return heap_size;
}

void binary_heap::makeEmpty() {
    heap_size = 0;
    heap.resize(1);
}

bool binary_heap::isEmpty() {
    return heap_size == 0;
}

void binary_heap::print() {
    cout << "(" << heap[0].value << ") ";
    for ( int i = 1; i <= heap_size; i++ ) {
        cout << heap[i].value << " ";
        // next line from from http://tinyurl.com/mf9tbgm
        bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
        if ( isPow2 )
            cout << endl << "\t";
    }
    cout << endl;
}
void binary_heap::buildHuffmanTree(){

    while(heap_size > 1){
        
        treeNode* a = deleteMin();
        treeNode* b = deleteMin();
        
        treeNode* parent = new treeNode();
        parent->value = a->getValue() + b->getValue();
        parent->character = '\0';
        parent->setChildren(a, b);
        
        a->parent = parent;
        b->parent = parent;
        
        insert(*parent);
    }

}

string getPath(treeNode subtree, treeNode* t){
    if(subtree.leftChild != NULL){
        // See if target immediately available
        if (subtree.leftChild->equals(t)){
            return "0";
        }
        
        // Search deeper
        string leftResult = getPath(*(subtree.leftChild), t);
        if (leftResult != ""){
            return "0" + leftResult;
        }
    }
    if(subtree.rightChild != NULL){
        if (subtree.rightChild->equals(t)){
            return "1";
        }
        string rightResult = getPath(*(subtree.rightChild), t);
        if (rightResult != ""){
            return "1" + rightResult;
        }
    }
    
    // Not found
    return "";
}

void binary_heap::outputCompression(binary_heap& frequencies){
    treeNode root = findMin();
    for(int i = 1; i < frequencies.heap_size + 1; i++){
        treeNode* target = &frequencies.heap[i];
        char character = frequencies.heap[i].character;
        string path = getPath(root, target);
        if(character == '\n'){
            cout << "\\n" << " : " << path << endl;
        }else if(character == '\0'){
            cout << "_" << " : " << path << endl;
        }else{
            cout << frequencies.heap[i].character << " : " << path << endl;
        }
        map.insert(pair<char,string>(character,path));
    }
    
}


string binary_heap::getCode(const char c){
    return map.at(c);
}




