//
//  DVertex.hpp
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 12/08/21.
//

#ifndef DVertex_hpp
#define DVertex_hpp

#include <stdio.h>

#include <stdio.h>
#include <iostream>
#include <vector>
#include <memory>
#include <numeric>

class Node;
class Edge;

const int MAX_VALUE = 10e7;

class DVertex {
    std::string name;
    std::vector<Edge*> adjacencyList;
    DVertex* predecessor = nullptr;
    double minDistance = MAX_VALUE;
    
public:
    DVertex(const std::string& name);
    std::string getName() const;
    void addNeighbour(Edge* edge);
    const std::vector<Edge*>& getAdjacencyList();
    DVertex* getPredecessor() const;
    void setPredecessor(DVertex* predecessor);
    double getMinDistance() const;
    void setMinDistance(double distance);
    
    friend std::ostream& operator <<(std::ostream& strm, const DVertex& vertex);
    bool operator <(const DVertex& other) const;
};

#endif /* DVertex_hpp */
