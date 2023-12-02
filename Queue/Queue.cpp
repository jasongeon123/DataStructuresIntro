#include "Queue.h"

/**
 * Implement Queue constructor
 */
Queue::Queue() {
    /* YOUR CODE HERE */
    head=0;
    tail=0;
    numElements=0;
}

/**
 * Implement the Queue destructor
 */
Queue::~Queue() {
    /* YOUR CODE HERE */
    clear();
}

/**
 * Implement size() correctly
 */
unsigned int Queue::size() {
    /* YOUR CODE HERE */
    return numElements;
}

/**
 * Implement clear() correctly without memory leaks
 */
void Queue::clear() {
    /* YOUR CODE HERE */
    while(numElements!=0){
        pop();
    }
    head=0;
    tail=0;
    numElements=0;

}

/**
 * Implement push() correctly
 */
void Queue::push(string s) {
    /* YOUR CODE HERE */
    Node *a = new Node(s);
    if(numElements==0){
        tail = a;
        head = a;
    }else{
        tail->next = a;
        tail =a;
    }
    numElements++;
}

/**
 * Implement pop() correctly without memory leaks
 */
string Queue::pop() {
    /* YOUR CODE HERE */
    Node *b = head;
    head = head ->next;
    if(numElements==1){
        tail = 0;
        head = 0;
    }else if(numElements == 2){
        head = tail;
    }
    numElements--;
    string c= b->data;
    delete b;
    return c;
}