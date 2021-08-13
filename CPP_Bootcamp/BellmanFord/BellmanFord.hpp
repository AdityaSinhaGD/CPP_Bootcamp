//
//  BellmanFord.hpp
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 13/08/21.
//

#ifndef BellmanFord_hpp
#define BellmanFord_hpp

#include <stdio.h>
#include "BVertex.hpp"
#include "BEdge.hpp"
#include <vector>

class BellmanFord {
    std::vector<BVertex>& vertexList;
    std::vector<BEdge>& edgeList;
    
public:
    BellmanFord(std::vector<BVertex>& _vertexList, std::vector<BEdge>& _edgeList) : vertexList(_vertexList), edgeList(_edgeList) {
        
    }
    
    void operator() (size_t sourceVectorIndex, size_t targetVectorIndex) const;
    
private:
    bool hasCycle(const BEdge& edge) const;
};

#endif /* BellmanFord_hpp */
