#include "Set.h"
/**
 * Implement the ArrayListSet methods correctly
 */
unsigned int ArrayListSet::size() {
    /* YOUR CODE HERE */
    return arr.size();
}

void ArrayListSet::insert(string s) {
    /* YOUR CODE HERE */
    if(find(s)==true){
        return;    
    }
    arr.push_back(s);
}

void ArrayListSet::remove(const string & s) {
    /* YOUR CODE HERE */
    if(find(s)!=true){
        return;    
    }
    int i,count;
    for(i=0;i<size();i++){
        if(arr.at(i)==s){
            count = i;
        }
    }
    arr.erase(arr.begin()+count);
}

bool ArrayListSet::find(const string & s) {
    /* YOUR CODE HERE */
    int i;
    for(i=0;i<size();i++){
        if(arr.at(i)==s){
            return true;
        }
    }
    return false;
}