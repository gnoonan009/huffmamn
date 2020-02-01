CXX=clang++ $(CXXFLAGS)
DEBUG=-Wall -g -O2 -std=gnu++11
all: decoder encoder linkedlist

decoder: huffmanTree.o treeNode.o huffmandec.o binary_heap.o
	$(CXX) $(DEBUG) -o decoder huffmanTree.o treeNode.o huffmandec.o binary_heap.o
	@echo "Compiled!"
linkedlist: linkedList.c
	$ clang -o linkedlist linkedList.c 

encoder: binary_heap.o treeNode.o huffmanenc.o
	$(CXX) -o encoder $(DEBUG) binary_heap.o treeNode.o huffmanenc.o
	@echo "Compiled!"

huffmanTree.o: huffmanTree.h huffmanTree.cpp
	$(CXX) -c huffmanTree.cpp
	
treeNode.o: treeNode.h treeNode.cpp    
	$(CXX) -c treeNode.cpp
huffmandec.o: huffmandec.cpp
	$(CXX) -c huffmandec.cpp
binary_heap.o: binary_heap.cpp binary_heap.h
	$(CXX) -c binary_heap.cpp

	
