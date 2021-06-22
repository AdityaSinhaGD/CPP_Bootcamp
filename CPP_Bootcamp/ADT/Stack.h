//
//  Stack.h
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 22/06/21.
//

#ifndef Stack_h
#define Stack_h

#include <memory>

//Array implementation of Stack.
template <class t_Data>
class Stack {
    t_Data* stack = nullptr;
    int numberOfItems = 0;
    int capacity = 0;
    
public:
    Stack() {
        stack = new t_Data[1];
        capacity = 1;
    }
    
    ~Stack() {
        delete[] stack;
    }
    
    void push(const t_Data& item) {
        if (numberOfItems == capacity) {
            resize(2*capacity);
        }
        stack[numberOfItems++] = item;
    }
    
    t_Data pop() {
        if(isEmpty()) {
            throw std::out_of_range("Stack is Empty");
        }
        
        t_Data itemToPop = stack[--numberOfItems];
        
        if(numberOfItems > 0 && numberOfItems == capacity/4) {
            resize(capacity/2);
        }
        
        return  itemToPop;
    }
    
    bool isEmpty() {
        return numberOfItems == 0;
    }
    
    int size() const {
        return numberOfItems;
    }
    
    void resize(int _capacity) {
        t_Data* stackCopy = new t_Data[_capacity];
        for (int i=0; i<numberOfItems; i++) {
            stackCopy[i] = stack[i];
        }
        delete [] stack;
        stack = stackCopy;
        capacity = _capacity;
    }
};

#endif /* Stack_h */
