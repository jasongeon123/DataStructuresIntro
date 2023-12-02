#include "BloomFilter.h"
#include "HashFunctions.h"
/**
 * Implement insert() correctly
 */
void BloomFilter::insert(const string & s) {
    /* YOUR CODE HERE */
    int i;
    for(i=0;i<K;i++){
        unsigned int a = hash_functions[i](s)%M;
        bits.at(a) = true;
    }
}

/**
 * Implement find() correctly
 */
bool BloomFilter::find(const string & s) {
    /* YOUR CODE HERE */
    int i;
    for(i=0;i<K;i++){
        unsigned int a = hash_functions[i](s)%M;
        if(bits.at(a)==false){
            return false;
        }
    }
    return true;
}