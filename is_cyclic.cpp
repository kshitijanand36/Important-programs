#include <bits/stdc++.h>

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
    vector<int> *adjlist;

    Graph(int n){
        size=n;
        adjlist=new vector<int>[size];
    }

    void addedge(int a,int b,bool check=true){
     
      adjlist[a].pb(b);

      if(check){
          adjlist[b].pb(a);
      }
    }

    bool iscyclic(int src){

        bool visited[size];
        int parent[size];
        queue<int> q;
        memset(visited,0,sizeof(visited));
        memset(parent,-1,sizeof(parent));

        parent[src]=src;
        q.push(src);
        visited[src]=true;

        while(!q.empty()){

            int node=q.front();
            q.pop();
            for(int i=0;i<adjlist[node].size();i++){
 
               if(visited[adjlist[node][i]]==true && parent[adjlist[node][i]]!=node){
                   return true;
               }
               else if(!visited[adjlist[node][i]]){
                   q.push(adjlist[node][i]);
                   visited[adjlist[node][i]]=true;
                   parent[adjlist[node][i]]=node;
               }
            }
        }
     return false;
    }

};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    struct Graph g(5);
    g.addedge(1,2,false);
    g.addedge(1,3,false);
    g.addedge(2,4,false);
    g.addedge(3,4,false);
    bool ans=g.iscyclic(1);
    if(ans) 
      cout<<"is cyclic";
    else 
      cout<<"is not cyclic";
    
    
}

