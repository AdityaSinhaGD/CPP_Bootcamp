//
//  Trie.h
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 09/10/21.
//

#ifndef Trie_h
#define Trie_h

class Trie {
private:
    struct Node {
        char c;
        Node* children[26]{};
        bool isWord;
        
        Node(char c) {
            this->c = c;
            this->isWord = false;
        }
    };
    
    Node* root;
    
    Node* getNode(std::string word) {
        Node* current = root;
        for (int i = 0; i < word.length(); i++) {
            char c = word[i];
            if (current->children[c - 'a'] == nullptr) {
                return nullptr;
            }
            current = current->children[c - 'a'];
        }
        return current;
    }
    
public:
    Trie() {
        root = new Node('\0');
    }
    
    void insert(std::string word) {
        
        Node* current = root;
        
        for(int i = 0; i < word.length(); i++) {
            
            char c = word[i];
            
            if(current->children[c - 'a'] == nullptr) {
                current->children[c - 'a'] = new Node(c);
            }
            
            current = current->children[c - 'a'];
        }
        current->isWord = true;
    }
    
    bool wordExists(std::string word) {
        Node* current = getNode(word);
        
        return current != nullptr && current->isWord;
    }
    
    bool prefixExists(std::string prefix) {
        
        return getNode(prefix) != nullptr;
        
    }
    
};

#endif /* Trie_h */
