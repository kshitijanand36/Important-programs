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
    map<T,vector<T> > adjlist;

    Graph(int n){

         size=n;
    }

    void addedge(T a, T b,bool bidirec=true){

        adjlist[a].pb(b);

        if(bidirec){
            adjlist[b].pb(a);
        }
    }

    bool helper(map<T,bool> &visited, T node, T parent){

        visited[node]=true;

            for(T neighbour: adjlist[node]){
                //for the case if it is being visited for the first time
                    if(!visited[neighbour]){
                        bool ans=helper(visited,neighbour,node);
                        if(ans){
                            return  true;
                        }
                    }
                   // if the neighbour is parent itself
                    else if(visited[neighbour] && neighbour!=parent){
                        return true;

                    }
            }
            //remaining case
            return false;

    }

   bool iscyclic_DFS(){

       map<T,bool> visited;

       for(auto x : adjlist){
            T node=x.first;

            if(!visited[node]){
                bool ans=helper(visited,node,node);

                if(ans==true){
                    return true;
                }
       }
       }
       return false;
   }

};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

     struct Graph<int> g(4);

     g.addedge(1,2);
    //  g.addedge(1,2);
     g.addedge(1,3);
     g.addedge(2,4);
    //  g.addedge(2,3);

     bool ans=g.iscyclic_DFS();
     if(ans==true)
         cout<<"THE GIVEN GRAPH IS CYCLIC";
     else
        cout<<"THE GIVEN GRAPH IS ACYCLIC";
}
