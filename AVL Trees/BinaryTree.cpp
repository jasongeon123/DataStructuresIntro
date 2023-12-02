
#include "BinaryTree.h"

// int count(BinaryTree::Node* root){
//     int count=0;
//     if(root->leftChild!=NULL){
//         count += count(root->leftChild);
//     }
//     if(root->rightChild!=NULL){
//         count += count(root->rightChild);
//     }
//     return count;
// }
unordered_map<int,int> a;

int height(BinaryTree::Node* root){
    if(root==NULL){
        return 0;
    }else{
        int left = height(root->leftChild);
        int right = height(root->rightChild);
        if(left>=right){
            return left+1;
        }else{
            return right+1;
        }
    }

}
int balance(BinaryTree::Node* root){
    return height(root->rightChild)-height(root->leftChild);
}
void next(BinaryTree::Node* root){
    if(root==NULL){
        return;
    }
    a.insert({root->label,balance(root)});
    next(root->leftChild);
    next(root->rightChild);
}
/**
 * Implement balanceFactors() correctly
 */
unordered_map<int,int> BinaryTree::balanceFactors() {
    /* YOUR CODE HERE */
    next(root);
    return a;
}
