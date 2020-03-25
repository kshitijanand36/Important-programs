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
#define P pair<ll,ll>
#define F first
#define S second

const ll N = 100005;

class Edge{

    public:
    ll src;
    ll dest;
    ll weight;
};


class Set{
    public:
    ll parent;
    ll rank;
};

bool comp(Edge a,Edge b){

    // if(a.weight==b.weight)  return a.v1<b.v1;

    return a.weight>b.weight;
}

ll find(Set *set,ll i){

    if(set[i].parent==i)  return i;

     return find(set,set[i].parent);
}

void Union(Set *set,ll v1,ll v2){

    ll v1_superparent=find(set,v1);
    ll v2_superparent=find(set,v2);

    if(set[v1_superparent].rank>=set[v2_superparent].rank){
        set[v2_superparent].parent= v1_superparent;
        set[v2_superparent].rank++;
    }
    else if(set[v1_superparent].rank<set[v2_superparent].rank){
         set[v1_superparent].parent= v2_superparent;
        set[v1_superparent].rank++;
    }
}

void kruskal(Edge *input,ll n,ll e,ll total_weight,ll s){

    sort(input,input+e,comp);
    Edge *output=new Edge[e];

    Set *set= new Set[n];

    for(ll i=0;i<n;i++){
        set[i].parent=i;
        set[i].rank=0;
    }
    ll counter=0;
    ll i=0;
    ll tree_weight=0;
    bool visited[n];
    memset(visited,false,sizeof(visited));
    
    while(counter<n-1){
      
      Edge curr_edge=input[i];

      ll src_superparent=find(set,curr_edge.src);
      ll dest_superparent=find(set,curr_edge.dest);

      if(src_superparent!=dest_superparent){
          Union(set,src_superparent,dest_superparent);
          output[counter]=curr_edge;
          tree_weight+=curr_edge.weight;
          counter++;
          visited[i]=true;
      }
     i++;
    }
    int j=0;
   if(tree_weight>=total_weight-s){
     cout<<n-counter+1<<" "<<total_weight-tree_weight;
     return;

   }

    while(!(tree_weight>=total_weight-s)){

        if(!visited[j]){
            output[counter]=input[j];
            counter++;
            tree_weight+=input[j].weight;
        }
       j++;  
    }
   cout<<n-counter+1<<" "<<total_weight-tree_weight;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n,e,s;
    cin>>n>>e>>s;
    
    // Edge *input=new Edge[e];
    // Graph g(n);
    ll total_weight=0;
    for(ll i=0;i<e;i++){

        ll a,b,wt;
        cin>>a>>b>>wt;
        // input[i].src=a;
        // input[i].dest=b;
        // input[i].weight=wt;
        // total_weight+=wt;
    }

    // kruskal(input,n,e,total_weight,s);
}

