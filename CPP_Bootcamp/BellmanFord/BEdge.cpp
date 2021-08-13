//
//  BEdge.cpp
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 13/08/21.
//

#include "BEdge.hpp"


BEdge::BEdge(BVertex *startVertex, BVertex *endVertex, int weight) { 
    this->startVertex = startVertex;
    this->endVertex = endVertex;
    this->weight = weight;
}

int BEdge::getWeight() const { 
    return this->weight;
}

void BEdge::setWeight(int weight) { 
    this->weight = weight;
}

BVertex *BEdge::getStartVertex() const { 
    return this->startVertex;
}

void BEdge::setStartVertex(BVertex *startVertex) { 
    this->startVertex = startVertex;
}

BVertex *BEdge::getEndVertex() const { 
    return this->endVertex;
}

void BEdge::setEndVertex(BVertex *endVertex) { 
    this->endVertex = endVertex;
}






