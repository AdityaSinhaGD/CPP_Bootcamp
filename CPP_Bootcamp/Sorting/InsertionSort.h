//
//  InsertionSort.h
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 20/08/21.
//

#ifndef InsertionSort_h
#define InsertionSort_h

#include <vector>
#include <iostream>

class InsertionSort {
    
    
public:
    void insertionSort(std::vector<int>& nums) {
        
        for (int i = 1; i < nums.size(); i++) {
            int j = i;
            int value = nums[j];
            while (j > 0 && nums[j - 1] >= value ) {
                nums[j] = nums[j - 1];
                j--;
            }
            nums[j] = value;
        }
        
    }
};

#endif /* InsertionSort_h */
