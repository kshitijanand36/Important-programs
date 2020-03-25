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
    unordered_map<T,vector<T>> adjlist;
    int size;

    graph(int n){
        size=n;
    }

   void addedge(T a,T b,bool bidirec){
        adjlist[a].pb(b);
        if(bidirec){
            adjlist[b].pb(a);
        }
    }
   

   void bfs(T v){
       queue<T> q;
       q.push(v);
       map<T,bool> visited;
     //  memset(visited,false,sizeof(visited));
       visited[v]=true;
       while(!q.empty()){
           T node=q.front();
           cout<<node<<endl;
           q.pop();
         //  map<T,vector<T>>::iterator i;
           int d= adjlist[node].size();
           for( int i=0;i<d;i++){

               if(!visited[adjlist[node][i]]){
                  q.push(adjlist[node][i]);
                  visited[adjlist[node][i]]=true;
               }
           }
       }

   }
    map<T,bool> visited;
   void dfs(T v,int size){

       if(size==0){
           cout<<v<<endl;
           return;
       }

      
       cout<<v<<endl;
       visited[v]=true;
       int len=adjlist[v].size();
       for(int i=0;i<len;i++){
            T node=adjlist[v][i];
           if(!visited[adjlist[v][i]]){
              visited[adjlist[v][i]]=true;
              dfs(node,size-1);
           }
       }
   }

    void print(){
        unordered_map<string,vector<string>>::iterator i;
        for( i=adjlist.begin();i!=adjlist.end();++i){
            cout<<i->first<<"->";
             
            int s = i->second.size();
            for(int j=0;j<s;j++){
                cout<<i->second[j]<<",";
            }
            cout<<endl;
        }
        
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
     struct graph<string> G(5);
     G.addedge("modi","trump",true);
     G.addedge("imran khan","modi",true);
     G.addedge("trump","jeff bezoz",true);
      G.addedge("jeff bezoz","steve jobs",true);
     G.addedge("imran khan","jeff bezoz",true);
    // G.print();
    //  G.bfs("modi");
      G.dfs("modi",5);

     //cout<<G.adjlist["warren buffet"][1];
}

