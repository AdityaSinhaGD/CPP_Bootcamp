//
//  GraphColoring.cpp
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 04/06/21.
//

#include "GraphColoring.hpp"
#include <iostream>


GraphColoring::GraphColoring(std::vector<std::vector<int> > &adjacencyMatrix, int _numOfColors) {
    graphAdjacencyMatrix = adjacencyMatrix;
    numberOfColors = _numOfColors;
    colors.resize(graphAdjacencyMatrix.size());
}

bool GraphColoring::colorVertex(size_t nodeIndex) { 
    if(nodeIndex == graphAdjacencyMatrix.size()){
        return true;
    }
    for (int colorIndex=1; colorIndex<=numberOfColors; colorIndex++) {
        if (isColorValid(nodeIndex, colorIndex)) {
            colors[nodeIndex] = colorIndex;
            if (colorVertex(nodeIndex+1)) {
                return true;
            }
        }
    }
    return false;
}

void GraphColoring::displayResult() { 
    for (size_t i=0; i<colors.size(); i++) {
        std::cout<<"The Color of node:"<<i<<" is:"<<colors[i]<<"\n";
    }
}


bool GraphColoring::isColorValid(size_t nodeIndex, size_t colorIndex) {
    for (size_t i=0; i<graphAdjacencyMatrix.size(); i++) {
        if (graphAdjacencyMatrix[nodeIndex][i]==1) {
            if (colors[i]==colorIndex) {
                return false;
            }
        }
    }
    return true;
}


void GraphColoring::solve() { 
    if (colorVertex(0)) {
        displayResult();
    }else{
        std::cout<<"No Solution possible";
    }
}

