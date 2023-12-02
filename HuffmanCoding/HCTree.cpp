#include<iostream>
#include <queue>
#include <vector>
#include <fstream>
#include "HCTree.hpp"
#include <stack>
using namespace std;

void deletes(HCNode* node){
    if(node==NULL){
        return;
    }
    deletes(node->c0);
    deletes(node->c1);
    delete node;
}

HCTree::~HCTree(){
    deletes(root);
}


void HCTree::build(const vector<int>& freqs){
    std::priority_queue<HCNode*, vector<HCNode*>,HCNodePtrComp> queues;
    for(long unsigned int i=0;i<freqs.size();i++){
        if(freqs[i]!=0){
            HCNode* adding = new HCNode(freqs[i],i);
            queues.push(adding);
            leaves[i]=adding;
        }
    }
    if(queues.size()==0){
        root = NULL;
        return;
    }
    if(queues.size()==1){
        root = queues.top();
    }
    //cout<<queues.size()<<endl;
    while(queues.size()>1){
        HCNode* first_node = queues.top();
        queues.pop();
        HCNode* second_node = queues.top();
        queues.pop();
        HCNode* current_node = new HCNode(first_node->count + second_node->count,first_node->symbol);
        current_node->c0 = first_node;
        current_node->c1 = second_node;
        first_node->p = current_node;
        second_node->p = current_node;
        queues.push(current_node);
    }
    root = queues.top();
    queues.pop();

}
void HCTree::encode(unsigned char symbol, FancyOutputStream & out) const{
    HCNode* target = leaves[symbol];
    if(target == root){
        out.write_bit(0);
        return;
    }
    if(target==NULL){
        return;
    }
    stack<int> stack;
    while(target!=root){
        if(target->p->c0==target){
            stack.push(0);
        }else{
            stack.push(1);
        }
        target=target->p;
    }
    
    while(stack.size()>0){
        out.write_bit(stack.top());
        stack.pop();
    }
}
unsigned char HCTree::decode(FancyInputStream & in) const{
    HCNode* curr= root;
    if(curr==nullptr){
        return -1;
    }
    while(curr->c0!=nullptr||curr->c1!=nullptr){
        int bit = in.read_bit();
        if(bit == 0){
            curr = curr->c0;
        }else if(bit==1){
            curr=curr->c1;
        }else if(bit==-1){
            return -1;
        }
    }
    return curr->symbol;
}
HCNode* HCTree::getRoot(){
    return root;
}
// int height(HCNode* root){
//     if(root == nullptr){
//         return 0;
//     }else{
//         int leftside = height(root->c0);
//         int rside = height(root->c1);
//         if(leftside>rside){
//             return (leftside+1);
//         }else{
//             return rside+1;
//         }
//     }
// }
// void level(HCNode* root, int level){
//     if(root==nullptr){
//         return;
//     }
//     if(level ==1){
//         output.write_byte(root->symbol);
//         output.write_byte(height);
//     }else if(){

//     }
// }
// void HCTree::traverse(HCNode* root, FancyOutputStream& output,int height){
//     if(root == NULL){
//         return;
//     }
//     if(root->c0 == NULL){
//         output.write_byte(root->symbol);
//         output.write_byte(height);
//         cout<<root->symbol<<endl;
//         cout<<height<<endl;
//         return;
//     }
    
//     traverse(root->c0,output,height++);
//     traverse(root->c1,output,height++);
// }

// void HCTree::btraverse(vector<char> leaves, vector<int>height){
//     HCNode* place = new HCNode(0,0);
//     root = place;
//     HCNode* working;
//     int currheight =0;
//     for(long unsigned int i=0;i<leaves.size();i++){
//         while(currheight<height[i]){
//             if(place->c0==NULL){
//                 working = new HCNode(0,0);
//                 place->c0 = working;
//                 working->p = place;
//                 place = working;
//                 currheight++;
//             }else{
//                 working = new HCNode(0,0);
//                 place->c1 = working;
//                 working->p = place;
//                 place = working;
//                 currheight++;
//             }
//         }
//         place->symbol = leaves[i];
//         while(place != root){
//             if(place->p->c1 != NULL){
//                 place = place->p;
//                 currheight--;
//             }else{
//                 break;
//             }
//         }
//         if(place!=root){
//             place = place->p;
//             currheight--;
//         }
//     }
    
// }

