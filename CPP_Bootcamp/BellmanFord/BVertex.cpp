//
//  BVertex.cpp
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 13/08/21.
//

#include "BVertex.hpp"


BVertex::BVertex(const std::string &id) { 
    this->id = id;
}

std::string BVertex::getId() const { 
    return this->id;
}

BVertex *BVertex::getPreviousVertex() const { 
    return this->previousVertex;
}

void BVertex::setPreviousVertex(BVertex *predecessor) { 
    this->previousVertex = predecessor;
}

int BVertex::getMinDistance() const { 
    return this->minDistance;
}

void BVertex::setMinDistance(int distance) { 
    this->minDistance = distance;
}

bool BVertex::operator<(const BVertex &other) const { 
    return this->minDistance < other.getMinDistance();
}

bool BVertex::isVisited() const { 
    return this->visited;
}

void BVertex::setVisited(bool visited) { 
    this->visited = visited;
}



std::ostream& operator<<(std::ostream& strm, const BVertex& vertex) {
    
    strm << vertex.id;
    
    return strm;
    
}




