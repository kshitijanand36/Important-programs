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

class Edge{

    public:
    int src;
    int dest;
    int weight;
};


class Set{
    public:
    int parent;
    int rank;
};

bool comp(Edge a,Edge b){

    // if(a.weight==b.weight)  return a.v1<b.v1;

    return a.weight<b.weight;
}

int find(Set *set,int i){

    if(set[i].parent==i)  return i;

     return find(set,set[i].parent);
}

void Union(Set *set,int v1,int v2){

    int v1_superparent=find(set,v1);
    int v2_superparent=find(set,v2);

    if(set[v1_superparent].rank>=set[v2_superparent].rank){
        set[v2_superparent].parent= v1_superparent;
        set[v2_superparent].rank++;
    }
    else if(set[v1_superparent].rank<set[v2_superparent].rank){
         set[v1_superparent].parent= v2_superparent;
        set[v1_superparent].rank++;
    }
}

void kruskal(Edge *input,int n,int e){

    sort(input,input+e,comp);
    Edge *output=new Edge[n-1];

    Set *set= new Set[n];

    for(int i=0;i<n;i++){
        set[i].parent=i;
        set[i].rank=0;
    }
    int counter=0;
    int i=0;

    while(counter<n-1){
      
      Edge curr_edge=input[i];

      int src_superparent=find(set,curr_edge.src);
      int dest_superparent=find(set,curr_edge.dest);

      if(src_superparent!=dest_superparent){
          Union(set,src_superparent,dest_superparent);
          output[counter]=curr_edge;
          counter++;
      }
     i++;
    }

    for(int i=0;i<n-1;i++){
        cout<<output[i].src<<"--"<<output[i].dest<<" with weight "<<output[i].weight<<endl;

    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,e;
    cin>>n>>e;
    
    Edge *input=new Edge[e];
    // Graph g(n);

    for(int i=0;i<e;i++){

        int a,b,wt;
        cin>>a>>b>>wt;
        input[i].src=a;
        input[i].dest=b;
        input[i].weight=wt;
    }

    kruskal(input,n,e);
}

