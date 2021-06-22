//
//  Queue.h
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 22/06/21.
//

#ifndef Queue_h
#define Queue_h

#include <memory>

template <class t_Data>
class Queue {
    struct Node {
        t_Data data;
        std::unique_ptr<Node> next;
        Node(const t_Data& _data) : data(_data) {
            
        }
    };
    
    std::unique_ptr<Node> head;
    Node* tail = nullptr;
    int count = 0;
    
public:
    
    void enqueue(const t_Data& item) {
        
        ++count;
        Node* previousTail = tail;
        auto lastNode = std::make_unique<Node>(item);
        tail = lastNode.get();
        
        if (isEmpty()) {
            head = std::move(lastNode);
        }else {
            previousTail->next = std::move(lastNode);
        }
    }
    
    t_Data dequeue() {
        
        if (isEmpty()) {
            throw std::out_of_range("Queue is Empty");
        }
        
        t_Data itemToDequeue = head->data;
        head = std::move(head->next);
        count--;
        
        if (isEmpty()) {
            tail = nullptr;
        }
        return itemToDequeue;
        
    }
    
    bool isEmpty() {
        return head == nullptr;
    }
    
    int size() const {
        return count;
    }
};

#endif /* Queue_h */
