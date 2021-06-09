//
//  FibonacciMemoize.cpp
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 05/06/21.
//

#include "FibonacciMemoize.hpp"




int FibonacciMemoize::FibonacciResult(int n) { 
    //base case
    if (n==0) {
        return 0;
    }
    if(n==1){
        return 1;
    }
    
    if (memoizeTable[n]!=0) {
        return memoizeTable[n];
    }
    
    int result = FibonacciResult(n-1)+FibonacciResult(n-2);
    memoizeTable[n]=result;
    return memoizeTable[n];
    
}


FibonacciMemoize::FibonacciMemoize() { 
    memoizeTable.resize(100);
    memoizeTable[0]=0;
    memoizeTable[1]=1;
}
