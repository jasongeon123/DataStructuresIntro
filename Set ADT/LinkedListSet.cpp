#include "Set.h"

/**
 * Implement the LinkedListSet methods correctly
 */
unsigned int LinkedListSet::size() {
    /* YOUR CODE HERE */
    return linked.size();
}

void LinkedListSet::insert(string s) {
    /* YOUR CODE HERE */
    if(find(s)==true){
        return;    
    }
    linked.push_back(s);
}

void LinkedListSet::remove(const string & s) {
    /* YOUR CODE HERE */
    if(find(s)!=true){
        return;    
    }
    list<string>::iterator a=linked.begin();
    for(string element : linked) {
        if(element == s) {
            linked.erase(a);
            break;
        }
        a++;
    }
    
}

bool LinkedListSet::find(const string & s) {
    /* YOUR CODE HERE */
    for(string element : linked) {
        if(element == s) {
            return true;
        }
    }
    
    return false;
}