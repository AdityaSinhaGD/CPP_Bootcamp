//
//  BreadthFirstSearch.cpp
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 07/08/21.
//

#include "BreadthFirstSearch.hpp"


void BreadthFirstSearch::operator()(std::shared_ptr<Vertex> root) const { 
    
    std::queue<Vertex*> vertexQueue;
    
    root->setVisited(true);
    
    vertexQueue.push(root.get());
    
    while (!vertexQueue.empty()) {
        
        Vertex* currentVertex = vertexQueue.front();
        vertexQueue.pop();
        
        std::cout<<"Visited Node:"<<currentVertex->getName()<<"\n";
        
        std::vector<Vertex*> neighbours = currentVertex->getNeighbourList();
        
        for (auto& neighbour : neighbours) {
            if (!neighbour->isVisited()) {
                neighbour->setVisited(true);
                vertexQueue.push(neighbour);
            }
        }
        
    }
    
}
