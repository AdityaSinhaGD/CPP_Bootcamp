//
//  StackLL.h
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 22/06/21.
//

#ifndef StackLL_h
#define StackLL_h

#include <memory>

template <class t_Data>
class StackLL {
    struct Node {
        t_Data data;
        std::unique_ptr<Node> next;
        Node(const t_Data& _data) : data(_data) {
            
        }
    };
    
    std::unique_ptr<Node> head;
    int count = 0;
    
public:
    void push(const t_Data& item) {
        std::unique_ptr<Node> newNode = std::make_unique<Node>(item);
        if (isEmpty()) {
            head = std::move(newNode);
            count++;
            return;
        }
        newNode->next = std::move(head);
        head = std::move(newNode);
        count++;
    }
    
    t_Data pop() {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty");
        }
        t_Data itemToPop = head->data;
        head = std::move(head->next);
        count--;
        return itemToPop;
    }
    
    bool isEmpty() {
        return !head;
    }
    
    int size() const {
        return count;
    }
};
#endif /* StackLL_h */
