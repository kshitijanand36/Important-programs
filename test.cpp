#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

const int N = 100005;
//template<typename T>

//int dist[N];
struct graph{
    vector<int> *adjlist;
    int size;
    //int *dist;

    graph(int n){
        size=n+1;
        adjlist=new vector<int>[size];
      //  dist=new int[size+1];

    }

   void addedge(int a,int b,bool bidirec){
        adjlist[a].pb(b);
        if(bidirec){
            adjlist[b].pb(a);
        }
    }
  
   void bfs(int v){
       queue<int> q;
       q.push(v);
       int dist[size];
       memset(dist,INT_MAX,sizeof(dist));
       dist[v]= 0 ;
       while(!q.empty()){
           int node=q.front();
       //    cout<<node<<endl;
           q.pop();
           int d= adjlist[node].size();
           for(int i=0;i<d;i++){

               if(dist[adjlist[node][i]]==INT_MAX){
                  q.push(adjlist[node][i]);
                  dist[adjlist[node][i]]= dist[node]+6;
               }
           }
       }

       for(int i=1;i<=size&&i!=v;i++){
             //if(dist[i]!=INT_MAX)
             {
                 cout<<dist[i]<<" ";
             }
           //  else{
             //    cout<<"-1 ";
            // }
        }
        cout<<endl;
      
   }

 /*   void print(int s){
        for(int i=1;i<=size&&i!=s;i++){
             if(dist[i]!=INT_MAX){
                 cout<<dist[i]<<" ";
             }
             else{
                 cout<<"-1 ";
             }
        }
        cout<<endl;
        
    }*/
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
     
    int t;
    cin>>t;
    while(t--){

        int nodes,edges;
        cin>>nodes>>edges;
        struct graph G(nodes);
        while(edges--){
            int edge1,edge2;
            cin>>edge1>>edge2;
            G.addedge((edge1),(edge2),true);
        }

        int s;
        cin>>s;
        G.bfs(s);
      //  G.print(s);
    }
}

