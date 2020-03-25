#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

const int N = 100005;
// template<typename T>
struct graph{
    vector<int> *edges;
    int size;

    graph(int n){
        size=n;
        edges=new vector<int>[size];
    }

   void addedge(int a,int b,bool bidirec){
        edges[a].pb(b);
        if(bidirec){
            edges[b].pb(a);
        }
    }
   

   int bfs(int v){
       queue<int> q;
       q.push(v);
       int *dist=new int[size];
//       memset(visited,false,sizeof(visited));
       for(int i=0;i<size;i++){
       	   dist[i]=INT_MAX;
	   }
	   
       dist[v]=0;
       while(!q.empty()){
           int node=q.front();
        //    cout<<node<<endl;
           q.pop();
        //    int d= edges[node].size();
           for(auto neighbour : edges[node]){

               if(dist[neighbour]==INT_MAX){
                  q.push(neighbour);
                  dist[neighbour]=dist[node] + 1;
               }
           }
           
    //        for(int i=0;i<edges[node].size();i++){
    //    	     cout<<"The distance of "<< node <<" from "<<edges[node][i]<<" is "<<dist[edges[node][i]]<<endl;
	//    }
       }
        if(dist[100]==INT_MAX) return -1;

		return dist[100];
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
     
    int t;cin>>t;while(t--){

        int n;
        cin>>n;
        graph g(101);
        int board[109];

        for(int i=0;i<=108;i++){
            board[i]=0;
        }
        for(int i=0;i<n;i++){
            int l1,l2;
            cin>>l1>>l2;
            board[l1]=l2-l1;
        }
        int m;
        cin>>m;
        for(int i=0;i<m;i++){
            int s1,s2;
            cin>>s1>>s2;
            board[s1]=s2-s1;
        }

        for(int i=0;i<=100;i++){
            for(int dice=1;dice<=6;dice++){
                int v= i+ dice + board[i + dice];
                g.addedge(i,v,false);

            }
        }
        cout<<g.bfs(1)<<endl;
    }
}

