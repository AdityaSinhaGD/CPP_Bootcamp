//
//  BellmanFord.cpp
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 13/08/21.
//

#include "BellmanFord.hpp"


void BellmanFord::operator()(size_t sourceVectorIndex, size_t targetVectorIndex) const { 
    if (sourceVectorIndex >= vertexList.size() || targetVectorIndex >= vertexList.size()) {
        return;
    }
    
    BVertex& startVertex = vertexList[sourceVectorIndex];
    BVertex& endVertex = vertexList[targetVectorIndex];
    
    startVertex.setMinDistance(0);
    
    for (int i = 0; i < vertexList.size() - 1; i++) {
        for (const auto& edge : edgeList) {
            int calculatedDistance = edge.getStartVertex()->getMinDistance() + edge.getWeight();
            
            if (calculatedDistance < edge.getEndVertex()->getMinDistance()) {
                edge.getEndVertex()->setMinDistance(calculatedDistance);
                edge.getEndVertex()->setPreviousVertex(edge.getStartVertex());
            }
        }
    }
    
    for (auto& edge : edgeList) {
        if (edge.getStartVertex()->getMinDistance() != MAXIMUM_VALUE) {
            if (hasCycle(edge)) {
                return;
            }
        }
    }
    
    if (endVertex.getMinDistance() != MAXIMUM_VALUE) {
        std::cout<<"Shortest path from source to target with cost:"<<endVertex.getMinDistance()<<std::endl;
        BVertex* currentVertex = &endVertex;
        
        while (currentVertex != nullptr) {
            std::cout << *currentVertex << "-";
            currentVertex = currentVertex->getPreviousVertex();
        }
        std::cout<<"\n";
    }
    else {
        std::cout<<"There is no path from source to target";
    }
}

bool BellmanFord::hasCycle(const BEdge &edge) const { 
    return edge.getEndVertex()->getMinDistance() > edge.getStartVertex()->getMinDistance() + edge.getWeight();
}

