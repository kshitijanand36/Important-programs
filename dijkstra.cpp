#include <bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
#include<list>
#include<vector>
#include<bitset>
// #include < unordered_map > 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

#define ll long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

const int N = 100005;

template<typename T>

struct Graph{
    int size;
    map<T,vector<P> > adjlist;

    Graph(int n){
       size=n;
    }

    void addedge(T a, T b,int wt,bool visited=true){

        P temp=make_pair(wt,b);
        adjlist[a].pb(temp);

        if(visited) {
            P temp2=make_pair(wt,a);
            adjlist[b].pb(temp2);
            }

    }

    void dijkstra(T src){
        
        map<T,int> min_dist;
        map<T,bool> visited;

        map<int,int>::iterator it;

        for(auto x : adjlist){
              min_dist[x.first]=INT_MAX;
        }
        int shortest_dist=0;
        priority_queue<P,vector<P>,greater<P>> pq;

        min_dist[src]=0;

        P w=make_pair(0,src); 
        pq.push({0,src});

        while(!pq.empty()){
            T node=(pq.top()).S;
            // cout<<adjlist[node].size(); 
            visited[node]=true;
            // cout<<node;
            for(int i=0;i<adjlist[node].size();i++){
                // cout<<adjlist[node][i].F<<" ";
                // cout<<min_dist[node]<<" ";
                // cout<<min_dist[adjlist[node][i].S]<<endl;
                if(!visited[adjlist[node][i].S]&&(adjlist[node][i].F + min_dist[node])<min_dist[adjlist[node][i].S]){
                     min_dist[adjlist[node][i].S] = adjlist[node][i].F + min_dist[node];
                    //  shortest_dist+=min_dist[adjlist[node][i].S];
                    pq.push(make_pair(min_dist[adjlist[node][i].S],adjlist[node][i].S));
                }
            }
            pq.pop();
        }

        for(it=min_dist.begin();it!=min_dist.end();it++){
            if(it->S==INT_MAX){
                cout<<"-1 ";
            }
            else if(it->S==0) continue;
            else{
                cout<<it->S<<" ";
            }
        }
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin>>t; while(t--)
    {
       int n,e;
       cin>>n>>e;

       Graph<int> g(n+1);

       for(int i=0;i<e;i++){
           int e1,e2,wet;
           cin>>e1>>e2>>wet;
           g.addedge(e1,e2,wet);
       }
       int source;
       cin>>source;
       
       g.dijkstra(source);
    //    cout<<g.adjlist[1].size()<<endl;

    }  
}

