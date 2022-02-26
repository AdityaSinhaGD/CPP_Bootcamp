//
//  CircularQueue.h
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 26/02/22.
//

#ifndef CircularQueue_h
#define CircularQueue_h

#include <exception>

//Custom Exception for when Circular Queue is empty.
class EmptyQueueException : std::exception {
    
public:
    EmptyQueueException(){};
    const char* what() const noexcept override {
        return "Circular Queue is Empty";
    }
    
};

//Custom Exception for when Circular Queue is Full.
class FullQueueException : std::exception {
    
public:
    FullQueueException(){};
    const char* what() const noexcept override {
        return "Circular Queue is full";
    }
    
};

template <typename t_Data>
class CircularQueue {
private:
    int front;
    int rear;
    t_Data* arr;
    int size;
    
public:
    CircularQueue(int _size) {
        arr = new t_Data[_size];
        this->size = _size;
        front = -1;
        rear = -1;
    }
    
    ~CircularQueue() {
        delete [] arr;
    }
    
    void push(const t_Data& value) {
        if (isFull()) {
            throw FullQueueException{};
        }
        
        if (isEmpty()) {
            front++;
            rear++;
            arr[rear] = value;
        }
        else {
            rear = (rear + 1) % size;
            arr[rear] = value;
        }
        
    }
    
    void pop() {
        
        if (isEmpty()) {
            throw EmptyQueueException{};
        }
        
        //If one element exists we emmpty the queue and set front and rear pointers to -1
        if(front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % size;
        }
        
    }
    
    t_Data peekFront() {
        if (isEmpty()) {
            throw EmptyQueueException{};
        }
        return arr[front];
        
    }
    
    t_Data peekRear() {
        if (isEmpty()) {
            throw EmptyQueueException{};
        }
        return arr[rear];
    }
    
    bool isFull() {
        return ((rear + 1) % size) == front;
    }
    
    bool isEmpty() {
        return (front == -1 && rear == -1);
    }
};

#endif /* CircularQueue_h */
