//
//  Edge.hpp
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 12/08/21.
//

#ifndef Edge_hpp
#define Edge_hpp

#include <stdio.h>
#include "DVertex.hpp"

class Edge {
    double weight;
    std::shared_ptr<DVertex> startVertex;
    std::shared_ptr<DVertex> endVertex;
    
public:
    Edge(double weight, const std::shared_ptr<DVertex>& startVertex, const std::shared_ptr<DVertex>& endVertex);
    double getWeight() const;
    std::shared_ptr<DVertex> getStartVertex() const;
    std::shared_ptr<DVertex> getEndVertex() const;
};

#endif /* Edge_hpp */
