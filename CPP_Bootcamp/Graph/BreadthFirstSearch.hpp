//
//  BreadthFirstSearch.hpp
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 07/08/21.
//

#ifndef BreadthFirstSearch_hpp
#define BreadthFirstSearch_hpp

#include <stdio.h>
#include "Vertex.hpp"
#include <memory>
#include <iostream>
#include <queue>

class BreadthFirstSearch {
                
    
public:
    void operator()(std::shared_ptr<Vertex> root) const;
};

#endif /* BreadthFirstSearch_hpp */
