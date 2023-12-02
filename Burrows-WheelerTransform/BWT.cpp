#include <string>
#include "BWT.h"
#include <map>
#include <iostream>
using namespace std;

/**
 * Implement bwt() correctly
 */
string bwt(const string & s) {
    /* YOUR CODE HERE */
    int n = s.size();
    string last;
    map<string,string> a;
    string curr="";
    for(int i=0;i<n;i++){
        for(int j=n-i;j<n;j++){
            curr = curr+s[j];
        }
        for(int l=0;l<n-i;l++){
            curr=curr+s[l];
        }
        last = curr[n-1];
        a.insert(std::pair<string,string>(curr,last));
        curr="";
    }
    string end;
    for(auto c:a){
        end = end+(c.second);
    }
    return end;
    

}