//
//  DepthFirstSearch.cpp
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 08/08/21.
//

#include "DepthFirstSearch.hpp"


DepthFirstSearch::DepthFirstSearch(const std::vector<std::shared_ptr<Vertex>> &_vertexList) { 
    this->vertexList = _vertexList;
}

void DepthFirstSearch::operator()() { 
    for (auto& vertex : vertexList) {
        if (!vertex->isVisited()) {
            dfs(vertex.get());
        }
    };
    std::cout<<"\n";
}

void DepthFirstSearch::printVertices() const { 
    for (auto& vertex : vertexList) {
        std::cout << *vertex << "\n";
    };
}

void DepthFirstSearch::dfs(Vertex *vertex) { 
    std::cout << *vertex << "\n";
    
    for (auto& neighbour : vertex->getNeighbourList()) {
        if (!neighbour->isVisited()) {
            neighbour->setVisited(true);
            dfs(neighbour);
        }
    }
    
    
}



