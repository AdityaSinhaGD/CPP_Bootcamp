//
//  DijkstraAlgorithm.cpp
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 12/08/21.
//

#include "DijkstraAlgorithm.hpp"
#include <set>

void DijkstraAlgorithm::computePaths(std::shared_ptr<DVertex> sourceVertex) {
    
    auto fCompare = [&](const std::shared_ptr<DVertex>& l, const std::shared_ptr<DVertex>& r) {
        return *l < *r;
    };
    
    sourceVertex->setMinDistance(0.);
    
    std::multiset<std::shared_ptr<DVertex>, decltype(fCompare)> queue(fCompare);
    
    queue.insert(sourceVertex);
    
    while (!queue.empty()) {
        auto iBegin = queue.begin();
        auto actualVertex = *iBegin;
        queue.erase(iBegin);
        
        std::vector<Edge*> neighbours = actualVertex->getAdjacencyList();
        
        for (auto& edge : neighbours) {
            std::shared_ptr<DVertex> from = edge->getStartVertex();
            std::shared_ptr<DVertex> to = edge->getEndVertex();
            
            double calculatedDistance = actualVertex->getMinDistance() + edge->getWeight();
            
            if(calculatedDistance < to->getMinDistance()) {
                
                //Update value inside heap.
                for (auto it = queue.begin(); it != queue.end(); ++it) {
                    if ((*it)->getName() == to->getName()) {
                        queue.erase(it);
                        break;
                    }
                }
                
                to->setMinDistance(calculatedDistance);
                to->setPredecessor(actualVertex.get());
                queue.insert(to);
                
            }
        }
        
    }
    
}

std::vector<DVertex *> DijkstraAlgorithm::getShortestPath(std::shared_ptr<DVertex> sourceVertex) const {
    std::cout<<"Min Distance: "<<sourceVertex->getMinDistance()<<std::endl;
    std::vector<DVertex*> path;
    for (DVertex* it = sourceVertex.get(); it != nullptr; it = it->getPredecessor()) {
        path.push_back(it);
    }
    std::reverse(path.begin(), path.end());
    return path;
}

