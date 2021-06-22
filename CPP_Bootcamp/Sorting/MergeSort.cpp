//
//  MergeSort.cpp
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 07/06/21.
//

#include "MergeSort.hpp"




std::vector<int> MergeSort::Merge(const std::vector<int>& leftSubVector, const std::vector<int>& rightSubVector) {
    
    int lSubVIndex = 0;
    int rSubVIndex = 0;
    std::vector<int> result;
    
    while (lSubVIndex<leftSubVector.size() && rSubVIndex<rightSubVector.size()) {
        if (leftSubVector[lSubVIndex] <= rightSubVector[rSubVIndex]) {
            result.push_back(leftSubVector[lSubVIndex]);
            lSubVIndex++;
        }
        else {
            result.push_back(rightSubVector[rSubVIndex]);
            rSubVIndex++;
        }
        
    }
    
    while (lSubVIndex < leftSubVector.size()) {
        result.push_back(leftSubVector[lSubVIndex]);
        lSubVIndex++;
    }
    
    while (rSubVIndex < rightSubVector.size()) {
        result.push_back(rightSubVector[rSubVIndex]);
        rSubVIndex++;
    }
    
    return result;
}


std::vector<int> MergeSort::MergeSortImpl(const std::vector<int>& vector) {
    
    std::vector<int> result;
    
    if (vector.size() <= 1) {
        return vector;
    }
    
    int mid = static_cast<int>(vector.size())/2;
    
    std::vector<int> leftSubVector;
    std::vector<int> rightSubVector;
    
    for(int i=0;i<mid;i++){
        leftSubVector.push_back(vector[i]);
    }
    
    for (int i=mid; i<vector.size(); i++) {
        rightSubVector.push_back(vector[i]);
    }
    
    leftSubVector = MergeSortImpl(leftSubVector);
    rightSubVector = MergeSortImpl(rightSubVector);
    result = Merge(leftSubVector, rightSubVector);
    
    return result;
    
}
