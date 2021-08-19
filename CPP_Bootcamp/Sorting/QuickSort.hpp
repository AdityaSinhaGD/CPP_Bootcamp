//
//  QuickSort.hpp
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 19/08/21.
//

#ifndef QuickSort_hpp
#define QuickSort_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

class QuickSort {
    
private:
    int partition(std::vector<int>& arr, int low, int high);
    void QuickSortImpl(std::vector<int>& arr, int low, int high);
    
public:
    void QuickSortRun(std::vector<int>& arr);
};

#endif /* QuickSort_hpp */
