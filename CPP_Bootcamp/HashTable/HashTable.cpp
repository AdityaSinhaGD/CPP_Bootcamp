//
//  HashTable.cpp
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 23/07/21.
//

#include "HashTable.hpp"

#include <iostream>

HashTable::HashTable() { 
    hashTable.resize(TABLE_SIZE);
}

int HashTable::get(int key) {
    
    int generatedVectorIndex = hash(key);
    
    std::list<HashItem>& items = hashTable[generatedVectorIndex];
    
    if (items.empty()) {
        return -1;
    }
    
    for (auto& item : items) {
        if (item.key == key) {
            return item.value;
        }
    }
    
    return -1;
}

void HashTable::put(int key, int value) { 
    
    int hashVectorIndex = hash(key);
    
    std::list<HashItem>& items = hashTable[hashVectorIndex];
    
    if (items.empty()) {
        std::cout << "No collision there simple insertion \n";
    }
    else {
        
        std::cout << "Collision detected when inserting key:"<<key<<"\n";
        
        for (auto& item : items) {
            if (item.key == key) {
                std::cout << "Key already present.. updating value \n";
                //alternately update the corresponding key's value here.
                item.value = value;
                return;
            }
        }
    }
    
    items.push_back(HashItem{key, value});
    
}

int HashTable::hash(int key) { 
    
    return key % TABLE_SIZE;
    
}



