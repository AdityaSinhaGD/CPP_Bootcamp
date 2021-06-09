//
//  MergeSort.cpp
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 07/06/21.
//

#include "MergeSort.hpp"




void MergeSort::Merge(std::vector<int>& leftSubVector, std::vector<int>& rightSubVector, std::vector<int>& result) {
    
    int lSubVIndex = 0;
    int rSubVIndex = 0;
    int resultIndex = 0;
    
    while (lSubVIndex<leftSubVector.size()&&rSubVIndex<rightSubVector.size()) {
        if (leftSubVector[lSubVIndex]<=rightSubVector[rSubVIndex]) {
            result[resultIndex] = leftSubVector[lSubVIndex];
            lSubVIndex++;
        }else{
            result[resultIndex] = rightSubVector[rSubVIndex];
            rSubVIndex++;
        }
        resultIndex++;
        
    }
    
    while (lSubVIndex<leftSubVector.size()) {
        result[resultIndex] = leftSubVector[lSubVIndex];
        lSubVIndex++;
        resultIndex++;
    }
    
    while (rSubVIndex<rightSubVector.size()) {
        result[resultIndex] = rightSubVector[rSubVIndex];
        rSubVIndex++;
        resultIndex++;
        
    }
    
}


void MergeSort::MergeSortImpl(std::vector<int>& vector) {
    
    std::vector<int> result;
    
    if (vector.size()<=1) {
        return;
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
    
    MergeSortImpl(leftSubVector);
    MergeSortImpl(rightSubVector);
    Merge(leftSubVector, rightSubVector, vector);
    
}
