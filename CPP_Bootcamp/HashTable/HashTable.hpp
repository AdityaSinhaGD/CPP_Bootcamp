//
//  HashTable.hpp
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 23/07/21.
//

#ifndef HashTable_hpp
#define HashTable_hpp

#include <stdio.h>
#include <vector>
#include <list>

class HashTable {
    
    //maximum we can store in the map.
    static constexpr int TABLE_SIZE = 10;
    
    //every item in the map is a key value pair.
    struct HashItem {
        int key;
        int value;
    };
    
    std::vector<std::list<HashItem>> hashTable;
    
public:
    HashTable();
    
    int get(int key);
    
    void put(int key, int value);
    
private:
    
    static int hash(int key);
};

#endif /* HashTable_hpp */
