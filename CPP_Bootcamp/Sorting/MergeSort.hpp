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
    std::vector<int> MergeSortImpl(const std::vector<int>& vector);
    std::vector<int> Merge(const std::vector<int>& leftSubVector, const std::vector<int>& rightSubVector);
};

#endif /* MergeSort_hpp */
