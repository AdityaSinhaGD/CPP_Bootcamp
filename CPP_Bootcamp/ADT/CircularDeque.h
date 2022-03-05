//
//  CircularDeque.h
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 04/03/22.
//

#ifndef CircularDeque_h
#define CircularDeque_h

#include <iostream>

template<typename tData>
class CircularDeque {
private:
    int front;
    int rear;
    int size;
    tData* deque = nullptr;
    
public:
    CircularDeque(int _size) {
        deque = new tData[_size];
        this->size = _size;
        this->front = -1;
        this->rear = -1;
    }
    
    ~CircularDeque() {
        delete [] deque;
    }
    
    bool isEmpty() {
        return (front == -1 && rear == -1);
    }
    
    bool isFull() {
        return ((rear + 1) % size == front);
    }
    
    void pushBack(const tData& val) {
        if (isFull()) {
            throw std::out_of_range("Deque is Full");
        }
        if(isEmpty()) {
            front  = 0;
            rear = 0;
        }
        else {
            rear = (rear + 1) % size;
        }
        deque[rear] = val;
        
    }
    
    void pushFront(const tData& val) {
        if (isFull()) {
            throw std::out_of_range("Deque is Full");
        }
        if(isEmpty()) {
            front  = 0;
            rear = 0;
        }
        else if(front == 0) {
            front = size - 1;
        }
        else {
            front--;
        }
        deque[front] = val;
    }
    
    void popFront() {
        if (isEmpty()) {
            throw std::out_of_range("Deque is Empty");
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % size;
        }
    }
    
    void popBack() {
        if (isEmpty()) {
            throw std::out_of_range("Deque is Empty");
        }
        if(front == rear) {
            front = -1;
            rear = -1;
        }
        else if(rear == 0) {
            rear = size - 1;
        }
        else {
            rear--;
        }
    }
    
    tData peekFront() {
        if (isEmpty()) {
            throw std::out_of_range("Deque is Empty");
        }
        return deque[front];
    }
    
    tData peekBack() {
        if (isEmpty()) {
            throw std::out_of_range("Deque is Empty");
        }
        return deque[rear];
    }
    
    void display() {
        int fr = front;
        while(fr != rear) {
            std::cout << deque[fr] << " ";
            fr = (fr + 1) % size;
        }
        std::cout << deque[fr] << "\n";
    }
    
};


#endif /* CircularDeque_h */
