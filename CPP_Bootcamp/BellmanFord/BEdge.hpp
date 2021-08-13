//
//  BEdge.hpp
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 13/08/21.
//

#ifndef BEdge_hpp
#define BEdge_hpp

#include <stdio.h>
class BVertex;

class BEdge {
    int weight;
    BVertex* startVertex;
    BVertex* endVertex;
    
public:
    
    BEdge(BVertex* startVertex, BVertex* endVertex, int weight);
    
    int getWeight() const;
    void setWeight(int weight);
    
    BVertex* getStartVertex() const;
    void setStartVertex(BVertex* startVertex);
    
    BVertex* getEndVertex() const;
    void setEndVertex(BVertex* endVertex);
    
};


#endif /* BEdge_hpp */
