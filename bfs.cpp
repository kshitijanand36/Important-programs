#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

const int N = 100005;
template<typename T>
struct graph{
    vector<T> *edges;
    int size;

    graph(int n){
        size=n;
        edges=new vector<T>[n];
    }

   void addedge(T a,T b,bool bidirec){
        edges[a].pb(b);
        if(bidirec){
            edges[b].pb(a);
        }
    }
   

   void bfs(T v){
       queue<T> q;
       q.push(v);
       bool visited[size];
       memset(visited,false,sizeof(visited));
       visited[v]=true;
       while(!q.empty()){
           T node=q.front();
           cout<<node<<endl;
           q.pop();
           int d= edges[node].size();
           for(int i=0;i<d;i++){

               if(!visited[edges[node][i]]){
                  q.push(edges[node][i]);
                  visited[edges[node][i]]=true;
               }
           }
       }

   }

    void print(){
        for(int i=0;i<size;i++){
            cout<<i<<"->";
             
            int s = edges[i].size();
            for(int j=0;j<s;j++){
                cout<<edges[i][j]<<",";
            }
            cout<<endl;
        }
        
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
     struct graph<int> G(4);
     G.addedge(0,1,true);
     G.addedge(0,2,true);
     //G.addedge(1,3,true);
     //G.addedge(3,4,true);
    // G.addedge(4,2,true);
    // G.print();
      G.bfs(0);
}

