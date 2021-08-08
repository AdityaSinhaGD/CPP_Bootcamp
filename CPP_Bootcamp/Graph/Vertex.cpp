//
//  Vertex.cpp
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 07/08/21.
//

#include "Vertex.hpp"


Vertex::Vertex(const std::string &name) { 
    this->name = name;
}

Vertex::~Vertex() = default;

const std::string Vertex::getName() const { 
    return name;
}

void Vertex::setName(const std::string &name) { 
    this->name = name;
}

bool Vertex::isVisited() const { 
    return visited;
}

void Vertex::setVisited(bool visited) { 
    this->visited = visited;
}

const std::vector<Vertex *> &Vertex::getNeighbourList() const { 
    return neighbours;
}

void Vertex::addNeighbour(Vertex *neighbour) { 
    neighbours.push_back(neighbour);
}

std::ostream& operator<<(std::ostream& strm, const Vertex& vertex) {
    
    strm << vertex.name;
    
    return strm;
    
}







