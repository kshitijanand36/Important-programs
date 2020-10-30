// Created by Kshitij Anand NSIT
#include <bits/stdc++.h>
//#include <ext/numeric>
//using namespace __gnu_cxx;


using namespace std;


#define int long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second
#define vi vector<int>
#define vc vector<char>
#define vb vector<bool>
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define mp(a, b) make_pair(a, b)
#define min3(a, b, c) min(min(a, b), c)
#define min4(a, b, c, d) min(min(a, b), min(c, d))
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define fill(arr,val) memset(arr,val,sizeof(arr))
#define inf 1e18
#define ps(x,y) fixed<<setprecision(y)<<x
#define db(x)  cout<<#x<<" : "<<x<<endl


const int N = 1000000007;

stack<int> s;
vi *adjlist , *adjlistT;
bool visited[100] = {};

void dfs(int root ){


	visited[root] = true;

	for(auto neighbor : adjlist[root]){

		if(!visited[neighbor]){

			dfs(neighbor);
		}
	}

	s.push(root);
}


void dfs2(int root){

	cout<<root + 1<<" ";

	visited[root] = true;

	for(auto neighbor : adjlistT[root]){

		if(!visited[neighbor]){

			dfs2(neighbor);
		}
	}

}



void solve(){

    int n,a,b,c,e ,  ans=0, count=0, sum=0;
    cin>>n>>e;

    adjlist = new vi[n];
    adjlistT = new vi[n];

    for(int i=0;i<e;i++){
    	cin>>a>>b;

    	adjlist[a - 1].pb(b - 1);
    	adjlistT[b - 1].pb(a - 1);
    }


    dfs(0);


    fill(visited , false);


    while(!s.empty()){

    	while(!s.empty() && visited[s.top()]){
    		s.pop();
    	}
        if(s.empty())break;
    	int curr = s.top();

    	dfs2(curr);
    	
    	cout<<endl;

    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    
  //  int t; cin>>t; while(t--)
    {     
      solve();
    }

  return 0;
}
