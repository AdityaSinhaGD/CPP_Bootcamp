//
//  DVertex.cpp
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 12/08/21.
//

#include "DVertex.hpp"
#include "Edge.hpp"
#include <cassert>

DVertex::DVertex(const std::string &name) { 
    this->name = name;
}

std::string DVertex::getName() const { 
    return this->name;
}

void DVertex::addNeighbour(Edge* edge) {
    if (edge) {
        assert(edge->getStartVertex().get() == this);
        adjacencyList.push_back(edge);
    }
}

const std::vector<Edge *> &DVertex::getAdjacencyList() { 
    return this->adjacencyList;
}

DVertex *DVertex::getPredecessor() const { 
    return this->predecessor;
}

void DVertex::setPredecessor(DVertex *predecessor) { 
    this->predecessor = predecessor;
}

double DVertex::getMinDistance() const { 
    return this->minDistance;
}

void DVertex::setMinDistance(double distance) { 
    this->minDistance = distance;
}

bool DVertex::operator<(const DVertex& other) const {
    return (this->minDistance < other.getMinDistance());
}


std::ostream& operator<<(std::ostream& strm, const DVertex& vertex) {
    
    strm << vertex.name;
    
    return strm;
    
}







