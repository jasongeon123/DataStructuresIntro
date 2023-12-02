#include <limits>
#include "CountMinSketch.h"
#include "HashFunctions.h"

/**
 * Implement increment() correctly
 */
void CountMinSketch::increment(const string & s) {
    /* YOUR CODE HERE */
    int i;
    for(i=0;i<K;i++){
        unsigned int a = hash_functions[i](s)%M;
        count[i][a] +=1;
    }
}

/**
 * Implement find() correctly
 */
unsigned int CountMinSketch::find(const string & s) {
    /* YOUR CODE HERE */
    int est = -1;
    int i;
    for(i=0;i<K;i++){
        unsigned int a = hash_functions[i](s)%M;
        int curr = count[i][a];
        if(curr>est){
            est = curr;
        }
    }
    return est;
}