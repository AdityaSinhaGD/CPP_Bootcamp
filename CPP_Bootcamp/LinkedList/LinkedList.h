//
//  LinkedList.h
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 09/06/21.
//

#ifndef LinkedList_h
#define LinkedList_h

#include "List.h"
#include <memory>
#include <iostream>

template <class tData>
class LinkedList: public List<tData>
{
    struct Node
    {
        tData data;
        std::unique_ptr<Node> nextNode;
        
        Node(const tData& _data):data(_data){
            
        }
    };
    
    int sizeCounter = 0;
    std::unique_ptr<Node> head;
    
public:
    LinkedList() = default;
    
    void insert(const tData& data) override
    {
        ++sizeCounter;
        std::unique_ptr<Node> newNode = std::make_unique<Node>(data);
        newNode->nextNode = std::move(head);
        head = std::move(newNode);
    }
    
    void push(const tData& data) override
    {
        std::unique_ptr<Node> newNode = std::make_unique<Node>(data);
        if(head==nullptr)
        {
            head = std::move(newNode);
            return;
        }
        
        Node* currentNode = head.get();
        while (currentNode->nextNode!=nullptr) {
            currentNode = currentNode->nextNode.get();
        }
        
        newNode->nextNode = std::move(currentNode->nextNode);
        currentNode->nextNode = std::move(newNode);
    }
    
    void remove(const tData& data) override
    {
        //if list is empty
        if (!head) {
            std::cout<<"List is empty \n";
            return;
        }
        
        //if node to be removed is head node
        if(head->data == data){
            auto newHead = std::move(head->nextNode);
            head = std::move(newHead);
            sizeCounter--;
            return;
        }
        
        Node* currentNode = head.get();
        Node* previousNode = nullptr;
        
        while (currentNode!=nullptr && currentNode->data != data) {
            previousNode = currentNode;
            currentNode = currentNode->nextNode.get();
        }
        
        if (currentNode==nullptr) {
            std::cout<<"Data not found \n";
            return;
        }else{
            previousNode->nextNode = std::move(currentNode->nextNode);
        }
    }
    
    void traverseList() const override
    {
        Node* currentNode = head.get();
        while (currentNode!=nullptr) {
            std::cout<<currentNode->data<<"\n";
            currentNode = currentNode->nextNode.get();
        }
    }
    
    int size() const override {
        return sizeCounter;
    }
    
};

#endif /* LinkedList_h */
