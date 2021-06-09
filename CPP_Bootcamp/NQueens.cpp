//
//  NQueens.cpp
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 04/06/21.
//

#include "NQueens.hpp"
#include <iostream>

QueensProblem::QueensProblem(int _numOfQueens){
    numberOfQueens = _numOfQueens;
    chessTable.resize(numberOfQueens);
    for(auto& chessRow:chessTable){
        chessRow.resize(numberOfQueens);
    }
}

void QueensProblem::printQueens() const { 
    for (size_t i=0; i<chessTable.size(); i++) {
        for (size_t j=0; j<chessTable.size(); j++) {
            if (chessTable[i][j]==1) {
                std::cout<<" * ";
            }else{
                std::cout<<" - ";
            }
        }
        std::cout<<std::endl;
    }
}


bool QueensProblem::setQueens(int colIndex) { 
    if(colIndex == numberOfQueens){
        return true;
    }
    for(int rowIndex=0;rowIndex<numberOfQueens;rowIndex++){
        if(isPlaceValid(rowIndex, colIndex)){
            chessTable[rowIndex][colIndex] = 1;
            if(setQueens(colIndex+1)){
                return true;
            }
            chessTable[rowIndex][colIndex] = 0;
        }
    }
    return false;
}


bool QueensProblem::isPlaceValid(int rowIndex, int colIndex) const {
    
    for (int i=0; i<colIndex; i++) {
        if(chessTable[rowIndex][i]==1){
            return false;
        }
    }
    
    for (int i=rowIndex,j=colIndex; i>=0&&j>=0; i--,j--) {
        if(chessTable[i][j]==1){
            return false;
        }
    }
    
    for (int i=rowIndex,j=colIndex; i<numberOfQueens&&j>=0; i++,j--) {
        if(chessTable[i][j]==1){
            return false;
        }
    }
    
    return true;
}


void QueensProblem::solve() { 
    if(setQueens(0)){
        printQueens();
    }else{
        std::cout<<"No solution exists";
    }
}

