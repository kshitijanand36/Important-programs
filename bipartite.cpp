#include <bits/stdc++.h>
// #include<iostream>
// #include<stdio.h>
// #include<algorithm>
// #include<math.h>
// #include<stack>
// #include<queue>
// #include<list>
// #include<vector>
// #include<bitset>
// #include < unordered_map > 
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// // #include "boost/algorithm/string.hpp"

using namespace std;


#define ll long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

const int N = 100005;

struct Graph{

    int size;
    vector<int> *adjlist;

    Graph(int n){
        size=n;
        adjlist=new vector<int>[size];
    }

  void addedge(int a,int b,bool bidirec=true){
 
        adjlist[a].pb(b); 

        if(bidirec) adjlist[b].pb(a);       

  }  

  bool ispartite(int src){
       queue<int> q;
       q.push(src);
       int color[size];

       memset(color,-1,sizeof(color));
       color[src]=0;

    //    bool visited[size];

    //    memset(visited,0,sizeof(visited));

       while(!q.empty()){
           int node=q.front();
        //    visited[node]=true;

           q.pop();
           for(auto x : adjlist[node]){
               if(color[x]==-1){
                   q.push(x);
                   color[x]=1-color[node];
               }

               else{
                   if(color[node]==color[x])  return false;
               }
              
           }
       }
   return true;
   }
    
};


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
     Graph g(4);

    g.addedge(0,1);
    g.addedge(1,3);
    g.addedge(0,2);
    g.addedge(2,3);
    g.addedge(1,2);

    bool ans=g.ispartite(0);

    if(ans)   cout<<"YES IT IS";
    if(!ans)   cout<<"NO IT IS NOT";

}
.
