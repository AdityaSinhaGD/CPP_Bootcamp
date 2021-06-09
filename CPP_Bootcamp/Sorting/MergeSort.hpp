//
//  MergeSort.hpp
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 07/06/21.
//

#ifndef MergeSort_hpp
#define MergeSort_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

class MergeSort {
    
    
public:
    void MergeSortImpl(std::vector<int>& vector);
    void Merge(std::vector<int>& leftSubVector, std::vector<int>& rightSubVector, std::vector<int>& result);
};

#endif /* MergeSort_hpp */
