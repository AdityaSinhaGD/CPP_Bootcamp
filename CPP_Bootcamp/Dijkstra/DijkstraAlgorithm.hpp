//
//  DijkstraAlgorithm.hpp
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 12/08/21.
//

#ifndef DijkstraAlgorithm_hpp
#define DijkstraAlgorithm_hpp

#include <stdio.h>
#include "DVertex.hpp"
#include "Edge.hpp"

class DijkstraAlgorithm {
    
    
public:
    void computePaths(std::shared_ptr<DVertex> sourceVertex);
    std::vector<DVertex*> getShortestPath(std::shared_ptr<DVertex> sourceVertex) const;
};

#endif /* DijkstraAlgorithm_hpp */
