f#include "Set.h"
#include <iostream>
/**
 * Implement the MultiwayTrieSet constructor
 */
MultiwayTrieSet::MultiwayTrieSet() {
    /* YOUR CODE HERE */
    root = new Node();
    numElements=0;
}
// void iterate_through_tree(MultiwayTrieSet::Node* root){
//     for(int i=0;i<root->children.size();i++){
//         if(root->children[i]==NULL){
//             delete root->children[i];
//         }else{
//             iterate_through_tree(root->children[i]);
//         }
//     }
// }
/**
 * Implement the MultiwayTrieSet destructor
 */
MultiwayTrieSet::~MultiwayTrieSet() {
    /* YOUR CODE HERE */
    //iterate_through_tree(root);
    
    delete root;
}

/**
 * Implement the MultiwayTrieSet methods correctly
 */
unsigned int MultiwayTrieSet::size() {
    /* YOUR CODE HERE */
    return numElements;
}

void MultiwayTrieSet::insert(string s) {
    /* YOUR CODE HERE */
    Node* curr = root;
    for(char c:s){
        if(curr->children.find(c)==curr->children.end()){
            curr->children.insert({c,new Node()});
        }
        curr = curr->children[c];
    }
    if(curr->isWord==false){
        numElements++;
        curr->isWord =true;
    }
}

void MultiwayTrieSet::remove(const string & s) {
    /* YOUR CODE HERE */
    Node* curr = root;
    for(char c:s){
        if(curr->children.find(c)==curr->children.end()){
            return;
        }else{
            curr = curr->children[c];
        }
    }
    if(curr->isWord==true){
        numElements--;
        curr->isWord = false;
    }
}

bool MultiwayTrieSet::find(const string & s) {
    /* YOUR CODE HERE */
    Node* curr = root;
    for(char c:s){
        if(curr->children.find(c)==curr->children.end()){
            return false;
        }else{
            curr = curr->children[c];
        }
    }
    if(curr->isWord == true){
        return true;
    }else{
        return false;
    }
}