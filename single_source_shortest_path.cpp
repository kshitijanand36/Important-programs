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
       int dist[size];
//       memset(visited,false,sizeof(visited));
       for(int i=0;i<size;i++){
       	   dist[i]=INT_MAX;
	   }
	   
       dist[v]=0;
       while(!q.empty()){
           T node=q.front();
        //    cout<<node<<endl;
           q.pop();
           int d= edges[node].size();
           for(int i=0;i<d;i++){

               if(dist[edges[node][i]]==INT_MAX){
                  q.push(edges[node][i]);
                  dist[edges[node][i]]=dist[node] + 1;
               }
           }
           
           for(int i=0;i<edges[node].size();i++){
       	     cout<<"The distance of "<< node <<" from "<<edges[node][i]<<" is "<<dist[edges[node][i]]<<endl;
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
     struct graph<int> G(5);
     G.addedge(0,1,false);
     G.addedge(0,2,false);
     G.addedge(1,3,false);
     G.addedge(3,4,false);
    G.addedge(4,2,false);
    // G.print();
      G.bfs(0);
}

