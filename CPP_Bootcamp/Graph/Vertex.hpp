//
//  Vertex.hpp
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 07/08/21.
//

#ifndef Vertex_hpp
#define Vertex_hpp

#include <stdio.h>
#include <vector>
#include <iostream>

class Vertex {
private:
    std::string name;
    bool visited = false;
    std::vector<Vertex*> neighbours;
    
public:
    Vertex(const std::string& name);
    ~Vertex();
    const std::string getName() const;
    void setName(const std::string& name);
    bool isVisited() const;
    void setVisited(bool visited);
    const std::vector<Vertex*>& getNeighbourList() const;
    void addNeighbour(Vertex* neighbour);
    friend std::ostream& operator<<(std::ostream& os, const Vertex& vertex);
    
};

#endif /* Vertex_hpp */
