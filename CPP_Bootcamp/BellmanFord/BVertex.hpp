//
//  BVertex.hpp
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 13/08/21.
//

#ifndef BVertex_hpp
#define BVertex_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <memory>
#include <numeric>
#include <limits>
#include "BEdge.hpp"

const int MAXIMUM_VALUE = 10e7;

class BVertex {
    std::string id;
    bool visited;
    BVertex* previousVertex = nullptr;
    int minDistance = MAXIMUM_VALUE;
    
public:
    BVertex(const std::string& id);
    std::string getId() const;
    BVertex* getPreviousVertex() const;
    void setPreviousVertex(BVertex* predecessor);
    int getMinDistance() const;
    void setMinDistance(int distance);
    bool isVisited() const;
    void setVisited(bool visited);
    
    friend std::ostream& operator <<(std::ostream& strm, const BVertex& vertex);
    bool operator <(const BVertex& other) const;
};

#endif /* BVertex_hpp */
