//
//  BinarySearchTree.h
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 30/06/21.
//

#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include "Tree.h"
#include <memory>
#include <exception>

//Custom Exception for when BST is empty.
class EmptyTreeException : std::exception {
    
public:
    EmptyTreeException(){};
    const char* what() const noexcept override {
        return "Binary Search Tree is Empty";
    }
    
};

template <class t_Data>
class BinarySearchTree : public Tree<t_Data> {
    
    struct Node {
        t_Data data;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;
        
        Node(const t_Data& _data) : data(_data){}
    };
    
    //Reference to the root of the Binary Search Tree.
    std::unique_ptr<Node> root;
    
public:
    void insert(const t_Data& data) override {
        if (root) {
            insertNode(data, root.get());
        }
        else {
            root = std::make_unique<Node>(data);
        }
    }
    
    void insertNode(const t_Data& data, Node* node) {
        if (data <= node->data) {
            if (node->left) {
                insertNode(data, node->left.get());
            }
            else {
                node->left = std::make_unique<Node>(data);
            }
        }
        else {
            if (node->right) {
                insertNode(data, node->right.get());
            }
            else {
                node->right = std::make_unique<Node>(data);
            }
        }
    }
    
    const t_Data& getMaxValue() const override {
        if (!root) {
            throw EmptyTreeException{};
        }
        return getMax(root.get());
    }
    
    const t_Data& getMax(Node* node) const {
        if (node->right) {
            return getMax(node->right.get());
        }
        return node->data;
    }
    
    const t_Data& getMinValue() const override {
        if(!root) {
            throw EmptyTreeException{};
        }
        return getMin(root.get());
    }
    
    const t_Data& getMin(Node* node) const {
        if (node->left) {
            return getMin(node->left.get());
        }
        return node->data;
    }
    
    void remove(const t_Data& data) override {
        
    }
    
    void traversal() const override {
        
    }
    
};

#endif /* BinarySearchTree_h */
