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
#include <unordered_map> 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

#define ll long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

const int N = 100005;


// bool comp(Edge a,Edge b){

//     if(a.weight==b.weight)  return a.v1<b.v1;

//     return a.weight<b.weight;
// }

class Edge{
    public:
    int src;
    int dest;
    int weight;
};

struct table{
    // public:
    int parent;
    bool visited;
    int weight;
};


struct Graph{

    int size;
    vector<pair<int,int> >*adjlist;

    Graph(int n){
        size=n;
        adjlist=new vector<pair<int,int>>[size];
    }

  void addedge(int a,int b,int wt){
 
        adjlist[a].pb(make_pair(b,wt)); 
         adjlist[b].pb(make_pair(a,wt));       
  }

   int min_vertex(bool *visited,int *weight){

      int min=-1;

      for(int i=0;i<size;i++){
          if((!visited[i])&&(min==-1||(weight[i]<weight[min]))){
              min=i;
          }
      }
     return min;
   } 

    void prim(){

        bool *visited=new bool[size];
        int *parent=new int[size];
        int *weight=new int[size];

        for(int i=0;i<size;i++){
            weight[i]=INT_MAX;
            visited[i]=false;
        }

        parent[0]=-1;
        weight[0]=0;
        
        for(int i=0;i<size;i++){
            int node=min_vertex(visited,weight);
            visited[node]=true;
            for(auto neighbour: adjlist[node]){  
                if(!visited[neighbour.F]){
                    if(weight[neighbour.F]>neighbour.S){
                        weight[neighbour.F]= neighbour.S;
                        parent[neighbour.F]=node;
                        // visited=true;
                }
            }
         }
        }

        for(int i=1;i<size;i++){
            cout<<i<<"--"<<parent[i]<<" with weight "<<weight[i]<<endl;
        }
    }
};  



int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,e;
    cin>>n>>e;
    
    Edge *input=new Edge[e];
    Graph g(n);

    for(int i=0;i<e;i++){

        int a,b,wt;
        cin>>a>>b>>wt;
        // input[i].src=a;
        // input[i].dest=b;
        // input[i].weight=wt;
        g.addedge(a,b,wt);
    }

    g.prim();
}

