//
//  Heap.cpp
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 13/07/21.
//

#include "Heap.hpp"


Heap::Heap() { 
    heap.resize(CAPACITY);
}

//Peek operation..
int Heap::getMax() const { 
    if(heapSize == 0) {
        throw std::length_error("Heap is empty...");
    }
    return heap[0];
}


void Heap::insert(int item) { 
    if (isHeapFull()) {
        throw std::overflow_error("Heap is full...");
    }
    
    heap[heapSize] = item;
    ++heapSize;
    
    fixUp(heapSize-1);
}

void Heap::heapSort() { 
    int size = heapSize;
    
    for (int i = 0; i<size; i++) {
        int max = poll();
        std::cout<<max<<" ";
    }
    
    std::cout<<std::endl;
}

//Pop operation...
int Heap::poll() { 
    int max = getMax();
    
    std::swap(heap[0], heap[heapSize - 1]);
    --heapSize;
    
    fixDown(0);
    return max;
}

bool Heap::isHeapFull() const { 
    return CAPACITY == heapSize;
}


void Heap::fixDown(int index) { 
    
    int leftChild = 2*index + 1;
    int rightChild = 2*index + 2;
    
    int largestIndex = index;
    
    if (leftChild < heapSize && heap[largestIndex] < heap[leftChild]) {
        largestIndex = leftChild;
    }
    
    if(rightChild < heapSize && heap[largestIndex] < heap[rightChild]) {
        largestIndex = rightChild;
    }
    
    if (index != largestIndex) {
        std::swap(heap[index], heap[largestIndex]);
        fixDown(largestIndex);
    }
}


void Heap::fixUp(int index) { 
    
    int parentIndex = (index - 1)/2;
    
    if(index > 0 && heap[index] > heap[parentIndex]) {
        std::swap(heap[index], heap[parentIndex]);
        fixUp(parentIndex);
    }
}



