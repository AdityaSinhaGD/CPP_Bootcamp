//
//  GraphColoring.hpp
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 04/06/21.
//

#ifndef GraphColoring_hpp
#define GraphColoring_hpp

#include <stdio.h>
#include <vector>

class GraphColoring {
    std::vector<std::vector<int>> graphAdjacencyMatrix;
    int numberOfColors;
    std::vector<int> colors;
    
public:
    GraphColoring(std::vector<std::vector<int>>& adjacencyMatrix, int _numOfColors);
    void solve();
    
private:
    bool colorVertex(size_t nodeIndex);
    bool isColorValid(size_t nodeIndex, size_t colorIndex);
    void displayResult();
};

#endif /* GraphColoring_hpp */
