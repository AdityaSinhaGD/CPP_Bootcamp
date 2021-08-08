//
//  DepthFirstSearch.hpp
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 08/08/21.
//

#ifndef DepthFirstSearch_hpp
#define DepthFirstSearch_hpp

#include <stdio.h>
#include "Vertex.hpp"
#include <vector>
#include <memory>
#include <iostream>

class DepthFirstSearch {
    std::vector<std::shared_ptr<Vertex>> vertexList;
    
public:
    DepthFirstSearch(const std::vector<std::shared_ptr<Vertex>>& _vertexList);
    void operator()();
    void printVertices() const;
    
private:
    void dfs(Vertex* vertex);
};

#endif /* DepthFirstSearch_hpp */
