//
//  FibonacciMemoize.hpp
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 05/06/21.
//

#ifndef FibonacciMemoize_hpp
#define FibonacciMemoize_hpp

#include <stdio.h>

#include <vector>

class FibonacciMemoize {
    std::vector<int> memoizeTable;
    
public:
    FibonacciMemoize();
    int FibonacciResult(int n);
};

#endif /* FibonacciMemoize_hpp */
