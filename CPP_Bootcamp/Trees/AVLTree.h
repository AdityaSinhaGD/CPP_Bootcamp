//
//  AVLTree.h
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 03/03/22.
//

#ifndef AVLTree_h
#define AVLTree_h
#include <iostream>

template<typename tData>
class AVLTree {
    
private:
    struct TreeNode{
        tData val;
        TreeNode* left;
        TreeNode* right;
        int height;
        TreeNode(const tData& _val) {
            this->val = _val;
            left = nullptr;
            right = nullptr;
            height = 1;
        }
    };
    
    TreeNode* root;
    
public:
    AVLTree() {
        root = nullptr;
    }
    
private:
    int getHeight(TreeNode* node) {
        if(node == nullptr) {
            return 0;
        }
        return node->height;
    }
    
    int getBalanceFactor(TreeNode* node) {
        if(node == nullptr) {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }
    
    TreeNode* rightRotate(TreeNode* y) {
        TreeNode* x = y->left;
        y->left = x->right;
        x->right = y;
        
        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
        
        return x;
    }
    
    TreeNode* leftRotate(TreeNode* x) {
        TreeNode* y = x->right;
        x->right = y->left;
        y->left = x;
        
        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
        
        return y;
    }
    
    TreeNode* InsertInAVLTree(TreeNode* root, const tData& _val) {
        if(root == nullptr) {
            return new TreeNode(_val);
        }
        
        if(root->val > _val) {
            root->left = InsertInAVLTree(root->left, _val);
        }
        else if(root->val < _val) {
            root->right = InsertInAVLTree(root->right, _val);
        }
        
        root->height = std::max(getHeight(root->left), getHeight(root->right)) + 1;
        int balanceFactor = getBalanceFactor(root);
        
        if(balanceFactor > 1 && root->left->val > _val) {
            return rightRotate(root);
        }
        
        if(balanceFactor < -1 && root->right->val < _val) {
            return leftRotate(root);
        }
        
        if(balanceFactor > 1 && root->left->val < _val) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        
        if(balanceFactor < -1 && root->right->val > _val) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        
        return root;
        
    }
    
    TreeNode* DeleteFromAVL(TreeNode* root, const tData& _val) {
        
        if(root == nullptr) {
            return root;
        }
        
        if(root->val > _val) {
            root->left = DeleteFromAVL(root->left, _val);
        }
        else if(root->val < _val) {
            root->right = DeleteFromAVL(root->right, _val);
        }
        else {
            if(root->left == nullptr && root->right == nullptr) {
                delete root;
                root = nullptr;
            }
            else if(root->left == nullptr) {
                TreeNode* temp = root;
                root = root->right;
                delete temp;
            }
            else if(root->right == nullptr) {
                TreeNode* temp = root;
                root = root->left;
                delete temp;
            }
            else {
                TreeNode* temp = getMin(root->right);
                root->val = temp->val;
                root->right = DeleteFromAVL(root->right, temp->val);
            }
        }
        
        if(root == nullptr) {
            return root;
        }
        
        root->height = std::max(getHeight(root->left), getHeight(root->right)) + 1;
        int balanceFactor = getBalanceFactor(root);
        
        //Left-Left rotation
        if(balanceFactor > 1 && getBalanceFactor(root->left) >= 0) {
            return rightRotate(root);
        }
        
        //left-right case
        if(balanceFactor > 1 && getBalanceFactor(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        
        //right-right case
        if(balanceFactor < -1 && getBalanceFactor(root->right) <= 0) {
            return leftRotate(root->right);
        }
        
        //right-left case
        if(balanceFactor < -1 && getBalanceFactor(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        
        return root;
        
    }
    
    TreeNode* getMin(TreeNode* root) {
        TreeNode* current = root;
        if(current == nullptr) {
            return current;
        }
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }
    
    void PreorderAVL(TreeNode* root) {
        if(root == nullptr) {
            return;
        }
        std::cout<<root->val<<"\n";
        PreorderAVL(root->left);
        PreorderAVL(root->right);
    }
    
public:
    
    void Insert(const tData& val) {
        root = InsertInAVLTree(root, val);
    }
    
    void Preorder() {
        PreorderAVL(root);
    }
    
};

#endif /* AVLTree_h */
