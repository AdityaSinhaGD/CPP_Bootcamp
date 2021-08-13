//
//  Edge.cpp
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 12/08/21.
//

#include "Edge.hpp"



Edge::Edge(double weight, const std::shared_ptr<DVertex> &startVertex, const std::shared_ptr<DVertex> &endVertex) {
    this->weight = weight;
    this->startVertex = startVertex;
    this->endVertex = endVertex;
}

double Edge::getWeight() const { 
    return this->weight;
}

std::shared_ptr<DVertex> Edge::getStartVertex() const {
    return this->startVertex;
}

std::shared_ptr<DVertex> Edge::getEndVertex() const { 
    return this->endVertex;
}



