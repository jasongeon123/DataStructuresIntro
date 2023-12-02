#include "Graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <tuple>
#include <string>
#include <map>
#include <queue>
#include <list>
#include<set>
#include <unordered_map>

using namespace std;
Graph::Graph(const char* const & edgelist_csv_fn) {
    // TODO
    ifstream my_file(edgelist_csv_fn);
    string line;
    vector <tuple<string,string,double>> graphs;
    //int count=0;
    multimap<string,pair<string,double>> umap;
    set<tuple<double,string,string>> edge_list;
    while(getline(my_file, line)){
        istringstream ss(line);
        string first,second,third;
        getline(ss,first,',');
        getline(ss,second,',');
        getline(ss,third,'\n');
        double a = stod(third);
        umap.insert(pair<string,pair<string,double>>(first,make_pair(second,a)));
        graphs.push_back(tuple<string,string,double>(first,second,a));
        edge_list.insert(make_tuple(a,first,second));
        //count=+1;
    }

    my_file.close();
    edge_lists=edge_list;
    graph = graphs;
    maps = umap;
    multimap<string,pair<string,double>> samap=maps;
    pair<string,double> place;
    for(auto i:maps){
        place = make_pair(i.first,i.second.second);
        samap.insert(make_pair(i.second.first,place));
    }
    smap = samap;
    // for(auto i:smap){
    //     cout<<i.first;
    //     cout<<i.second.first;
    //     cout<<i.second.second<<endl;
    // }
}
int find(vector<string>a,string c){
    for(auto b : a){
        if(b==c){
            return 1;
        }
    }
    return 0;
}

unsigned int Graph::num_nodes() {
    // TODO
    vector<string> a;
    for(auto i:maps){
        if(find(a,i.first)==0){
            a.push_back(i.first);
        }
        if(find(a,i.second.first)==0){
            a.push_back(i.second.first);
        }
    }
    return a.size();
}

vector<string> Graph::nodes() {
    // TODO
    vector<string> a;
    for(auto i:maps){
        if(find(a,i.first)==0){
            a.push_back(i.first);
        }
        if(find(a,i.second.first)==0){
            a.push_back(i.second.first);
        }
    }
    return a;
}

unsigned int Graph::num_edges() {
    // TODO
    // vector<string> key;
    // for(auto i:graph){
    //     key.push_back(get<0>(i));
    // }
    // return key.size();
    return graph.size();
}

unsigned int Graph::num_neighbors(string const & node_label) {
    // TODO

    int count=-1;
    for(auto i:smap){
        if(i.first == node_label){
            count = smap.count(i.first);
        }
    }
    return count;
}

double Graph::edge_weight(string const & u_label, string const & v_label) {
    // TODO
    for(auto i:smap){
        if(i.first==u_label&&i.second.first==v_label){
            if(i.first==i.second.first||u_label==v_label){
                return 0;
            }
            return i.second.second;
        }
    }
    return -1;

}

vector<string> Graph::neighbors(string const & node_label) {
    // TODO
    vector<string> a;
    for(auto i:smap){
        if(i.first == node_label){
            a.push_back(i.second.first);
        }
    }
    return a;
}

vector<string> Graph::shortest_path_unweighted(string const & start_label, string const & end_label) {
    vector<string> a;
    if(start_label==end_label){
        a.push_back(start_label);
        return a;
    }

    map<string,pair<int,string>> dist;
    for(string a:nodes()){
        dist.insert(make_pair(a, make_pair(-2,"")));
    }
    dist.at(start_label)=make_pair(0,"");
    queue<string> queues;
    queues.push(start_label);
    //works till here
    while(!queues.empty()){
        string u = queues.front();
        queues.pop();
        if(u==end_label){
            break;
        }
        for(auto i:neighbors(u)){
            if(dist.at(i).first==-2){
                queues.push(i);
                dist.at(i).first=dist.at(u).first+1;
                dist.at(i).second = u;
                if(i==end_label){
                    break;
                }
            }
        }
    }
    vector<string> q;
    string back = end_label;
    while(dist.at(back).second!=""&&dist.at(back).first>-1){
        q.insert(q.begin(), back);
        back = dist.at(back).second;
    }
    if(q.size()==0){
        return q;
    }else{
        q.insert(q.begin(),start_label);
    }
    return q;
}

vector<tuple<string,string,double>> Graph::shortest_path_weighted(string const & start_label, string const & end_label) {
    // TODO
    vector<tuple<string,string,double>> res;
    if(start_label==end_label){
        tuple<string,string,double> a = make_tuple(start_label,end_label,-1);
        res.push_back(a);
        return res;
    }
    map<string,pair<double,string>> dist;
    for(string a:nodes()){
        dist.insert(make_pair(a, make_pair(2147483647,"")));
    }
    dist.at(start_label)=make_pair(0,"");
    queue<string> queues;
    queues.push(start_label);
    //works till here
    while(!queues.empty()){
        string u = queues.front();
        queues.pop();
        for(auto i:neighbors(u)){
            double length = edge_weight(u,i);
            if(dist.at(i).first>length+dist.at(u).first){
                dist.at(i).first= length+dist.at(u).first;
                dist.at(i).second = u;
                queues.push(i);
            }
        }
    }
    vector<tuple<string,string,double>> q;
    string back = end_label;
    while(dist.at(back).second!=""&&dist.at(back).first>-1){
        q.insert(q.begin(), make_tuple(dist.at(back).second,back,dist.at(back).first));
        back = dist.at(back).second;
    }
    if(q.size()==0){
        return q;
    }
    double que=0;
    vector<tuple<string,string,double>> k;
    for(auto a:q){
        tuple<string,string,double> it = make_tuple(get<0>(a),get<1>(a),get<2>(a)-que);
        k.push_back(it);
        que = get<2>(a);
    }
    return k;
}


vector<vector<string>> Graph::connected_components(double const & threshold) {
    // TODO
    map<string,bool>a;
    for(string c:nodes()){
        a.insert(make_pair(c,false));
    }
    vector<vector<string>>z;
    for(auto it = a.begin();it!=a.end();it++){
        if(it->second==false){
            vector<string> u;
            queue<string> queues;
            queues.push(it->first);
            u.push_back(it->first);
            a.insert(make_pair(it->first,true));
            while(!queues.empty()){
                string y = queues.front();
                queues.pop();
                for(auto i:neighbors(y)){
                    double length = edge_weight(y,i);
                    if(length<=threshold&&a.at(i)==false){
                        queues.push(i);
                        u.push_back(i);
                        a.at(i)=true;
                    }
                }
            }
            z.push_back(u);
        }
    }
    return z;
}
unordered_map<string,string> disjoint;
string find(string a){
    if(disjoint[a]==a){
        return a;
    }
    return find(disjoint[a]);
}
void Union(string a, string b){
    string c = find(a);
    string d = find(b);
    disjoint[c]=d;
}
double Graph::smallest_connecting_threshold(string const & start_label, string const & end_label) {
    // TODO
    if(start_label==end_label){
        return 0;
    }
    unordered_map<string,string> cim;
    vector<string> it;
    for(string i:nodes()){
        it.push_back(i);
    }
    for(string a:it){
        cim[a]=a;
    }
    disjoint= cim;
    for(auto q:edge_lists){
        Union(get<1>(q),get<2>(q));
        if(find(start_label)==find(end_label)){
            return get<0>(q);
        }
    }
    return -1;
}