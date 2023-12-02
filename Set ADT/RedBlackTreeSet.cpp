#include "Set.h"

/**
 * Implement the RedBlackTreeSet methods correctly
 */
unsigned int RedBlackTreeSet::size() {
    /* YOUR CODE HERE */
    return rbt.size();
}

void RedBlackTreeSet::insert(string s) {
    /* YOUR CODE HERE */
    if(find(s)==true){
        return;    
    }
    rbt.insert(s);
}

void RedBlackTreeSet::remove(const string & s) {
    /* YOUR CODE HERE */
    if(find(s)!=true){return;}
    rbt.erase(s);
}

bool RedBlackTreeSet::find(const string & s) {
    /* YOUR CODE HERE */
    if(rbt.find(s)==rbt.end()){
        return false;
    }
    return true;
}