#include "BST.h"
#include <vector>
#include<iostream>

/**
 * Implement the BST constructor
 */
BST::BST() {
    /* YOUR CODE HERE */
    numElements=0;
    root=nullptr;
}

/**
 * Implement the BST destructor
 */
BST::~BST() {
    /* YOUR CODE HERE */
    BST::clear();
}

/**
 * Implement size() correctly
 */
unsigned int BST::size() const {
    /* YOUR CODE HERE */
    return numElements;
}
void clearing(BST::Node* root){
    if(root == nullptr){
        return;
    }
    clearing(root->leftChild);
    clearing(root->rightChild);
    delete root;
}
/**
 * Implement clear() correctly without memory leaks
 */
void BST::clear() {
    /* YOUR CODE HERE */
    clearing(root);
    numElements=0;
    root=nullptr;
}
/*
 * Implement insert() correctly
 */
bool BST::insert(int element) {
    Node *a = new Node(element);
    if(root==nullptr){
        root=a;
        numElements++;
        return true;
    }
    Node* b = root;
    while(b->data!=element){
        if(b->data>element){
            if(b->leftChild==nullptr){
                b->leftChild=a;
                b->leftChild->parent=b;
                numElements++;
                return true;
            }else{
                b = b->leftChild;
            }
        }else if(element>b->data){
            if(b->rightChild==nullptr){
                b->rightChild = a;
                b->rightChild->parent=b;
                numElements++;
                return true;
            }else{
                b = b->rightChild;
            }
        }
    }
    delete a;
    return false;
}

int finds(BST::Node* root,int query){
    if(root==nullptr){
        return false;
    }
    if(root->data==query){
        return true;
    }
    if(finds(root->leftChild,query)==true){
        return true;
    }
    bool b = finds(root->rightChild,query);
    return b;
    
}

/**
 * Implement find() correctly
 */
bool BST::find(const int & query) const {
    return finds(root,query);
}

/**
 * Implement the getLeftMostNode() function correctly
 */
BST::Node* BST::getLeftMostNode() {
    /* YOUR CODE HERE */
    Node* a = root;
    while(a&&a->leftChild != 0){
        a = a->leftChild;
    }
    return a;
}
/**
 * Implement the BST::Node successor function correctly
 */
BST::Node* BST::Node::successor() {
    /* YOUR CODE HERE */
    if(this->rightChild!=nullptr){
        Node* curr=this->rightChild;
        while(curr->leftChild!=nullptr){
            curr = curr->leftChild;
        }
        return curr;
    }else{
        Node* curr=this;
        while(curr->parent!=nullptr){
            if(curr==curr->parent->leftChild){
                return curr->parent;
            }else{
                curr=curr->parent;
            }
        }

    }
    return nullptr;
}