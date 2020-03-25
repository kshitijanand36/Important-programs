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
    map<T,vector<T>> adjlist;
    int size;

    graph(int n){
        size=n;
    }

   void addedge(T a,T b,bool bidirec=true){
        adjlist[a].pb(b);
        if(bidirec){
            adjlist[b].pb(a);
        }
    }
   

   void bfs(T v){
       queue<T> q;
       q.push(v);
       map<T,bool> visited;
    //   memset(visited,false,sizeof(visited));
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
   void dfs(T v){

      
       cout<<v<<endl;
       visited[v]=true;
       int len=adjlist[v].size();
       for(int i=0;i<len;i++){
            T node=adjlist[v][i];
           if(!visited[adjlist[v][i]]){
              visited[adjlist[v][i]]=true;
              dfs(node);
           }
       }
  }

list<T> ordering;

void helper(T node, map<T,bool> &visited){

    // if(size==0)  return;

    visited[node]=true;

    for(int i=0;i<adjlist[node].size();i++){

         if(!visited[adjlist[node][i]]){
             helper(adjlist[node][i],visited);

         }
    }
    
     
      ordering.push_front(node);    
}

void dfs_topological(){
       
        map<T,bool> visited;

      // visited[node] =true;
        map<string,vector<string>> :: iterator it;

      for(it=adjlist.begin();it!=adjlist.end();it++)
      {   if(!visited[it->first]){
            // int len=(it->second).size();
            helper(it->first,visited);
            visited[it->first]=true;
         }
      }

      
}

void bfs_topological(){

    queue<T> q;

    map<T,bool> visited;
    map<T,int> indegree;

    map<string,vector<string>> :: iterator it;

    for(it=adjlist.begin();it!=adjlist.end();it++){

        T node= it->first;

        visited[node]=false;
        indegree[node]=0;
    }

    for(it=adjlist.begin();it!=adjlist.end();it++){
      T node= it->first;
        for(int j=0;j<adjlist[node].size();j++){
             indegree[adjlist[node][j]]++;
        }
    }

    for(it=adjlist.begin();it!=adjlist.end();it++){

        if(indegree[it->first]==0){

            q.push(it->first);
        }
    }

    while(!q.empty()){

        T node=q.front();
        q.pop();
        cout<<node<<"-->";
        visited[node]=true;

        for(int i=0;i<adjlist[node].size();i++){
            indegree[adjlist[node][i]]--;

            if(indegree[adjlist[node][i]]==0){

                q.push(adjlist[node][i]);
            }
        }
    }

    
}

    void print(){
        list<string>::iterator i;
        for( i=ordering.begin();i!=ordering.end();++i){
            cout<<(*i)<<"->";
             
            // int s = i->second.size();
            // for(int j=0;j<s;j++){
            //     cout<<i->second[j]<<",";
            // }
            // cout<<endl;
        }
        
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
     struct graph<string> G(5);
     G.addedge("maths","programming logic",false);
     G.addedge("english","HTML",false);
     G.addedge("english","programming logic",false);
     G.addedge("programming logic","HTML",false);
     G.addedge("programming logic","python",false);
     G.addedge("programming logic","java",false);
     G.addedge("programming logic","JS",false);
      G.addedge("HTML","CSS",false);
     G.addedge("CSS","JS",false);
     G.addedge("JS","web development",false);
     G.addedge("python","web development",false);
     G.addedge("java","web development",false);
    // // G.print();
    // //  G.bfs("modi");
      G.bfs_topological();
//       G.print();

     //cout<<G.adjlist["warren buffet"][1];
}

