//
//  QuickSort.cpp
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 19/08/21.
//

#include "QuickSort.hpp"


int QuickSort::partition(std::vector<int>& arr, int low, int high) {
    int mid = (low + high) / 2;
    std::swap(arr[mid], arr[high]);
    
    int pivotIndex = low;
    for (size_t i = low; i < high; i++) {
        if (arr[i] <= arr[high]) {
            std::swap(arr[i], arr[pivotIndex]);
            pivotIndex++;
        }
    }
    
    std::swap(arr[high], arr[pivotIndex]);
    return pivotIndex;
}

void QuickSort::QuickSortImpl(std::vector<int>& arr, int low, int high) {
    if (low >= high) {
        return;
    }
    
    int pivotIndex = partition(arr, low, high);
    QuickSortImpl(arr, low, pivotIndex - 1);
    QuickSortImpl(arr, pivotIndex + 1, high);
}

void QuickSort::QuickSortRun(std::vector<int>& arr) {
    QuickSortImpl(arr, 0, static_cast<int>(arr.size() - 1));
}


