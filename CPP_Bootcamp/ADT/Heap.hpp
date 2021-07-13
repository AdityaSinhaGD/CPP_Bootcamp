//
//  Heap.hpp
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 13/07/21.
//

#ifndef Heap_hpp
#define Heap_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

class Heap {
    std::vector<int> heap;
    int heapSize = 0;
    constexpr static int CAPACITY = 10;
    
public:
    Heap();
    
    void insert(int item);
    
    int getMax() const;
    
    int poll();
    
    void heapSort();
    
private:
    
    void fixUp(int index);
    
    void fixDown(int index);
    
    bool isHeapFull() const;
    
};

#endif /* Heap_hpp */
