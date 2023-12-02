#include <string>
#include <vector>
#include "SuffixArray.h"
#include <map>
#include <iostream>
using namespace std;

/**
 * Implement suffix_array() correctly
 */
vector<unsigned int> suffix_array(const string & s) {
    /* YOUR CODE HERE */
    int n = s.size();
    unsigned int count=0;
    map<string,unsigned int> a;
    string curr="";
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            curr = curr+s[j];
        }
        a.insert(std::pair<string,unsigned int>(curr,count));
        curr="";
        count++;
    }
    vector<unsigned int> b;
    for(auto c:a){
        b.push_back(c.second);
    }
    return b;
}