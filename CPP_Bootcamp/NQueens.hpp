//
//  NQueens.hpp
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 04/06/21.
//

#ifndef NQueens_hpp
#define NQueens_hpp

#include <stdio.h>
#include <vector>

class QueensProblem {
    std::vector<std::vector<int>> chessTable;
    int numberOfQueens = 0;
    
public:
    QueensProblem(int _noOfQueens);
    void solve();
    
private:
    bool isPlaceValid(int rowIndex,int colIndex) const;
    bool setQueens(int colIndex);
    void printQueens() const;
};

#endif /* NQueens_hpp */
