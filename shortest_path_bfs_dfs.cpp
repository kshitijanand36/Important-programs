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

int n , m;

int arr[20][20];

bool visited[20][20] = {};

int fin_ans = INT_MAX;

int dx[] = {1 , 0 , 0 , -1};
int dy[] = {0 , 1 , -1 , 0};

bool is_ok(int r , int c){

    return (r < n && c <m && r>=0 && c>=0);

}


void dfs(int row , int col , int ans , int d1 , int d2 ){
    if(row < 0 || col < 0 || row >=n || col >=m)return;

    if(row == d1 && col == d2){

        fin_ans = min(fin_ans , ans);
        return;
    }
    visited[row][col] = true;


    for(int k = 0; k< 4 ; k++){

        int cr = row + dx[k] , cc = col + dy[k];
        // db(cr);
        // db(cc);

        if(is_ok(cr , cc) && arr[cr][cc] && !visited[cr][cc]){



            dfs(cr , cc , ans + 1 , d1 , d2);
        }
    }

    visited[row][col] =false;

}


//using bfs now!

int bfs(int d1 , int d2){


    queue<pair<int  , P>> q;


    q.push({0 , {0 , 0}});

    // q.push({-1 , -1});

    int ans = 0;


    while(!q.empty()){

        int row = q.front().F;
        int col = q.front().S.F;

        int dist = q.front().S.S;

        q.pop();

        
        if(row == d1 && col == d2){

            return dist;
        }

        for(int k = 0; k< 4 ; k++){

            int cr = row + dx[k] , cc = col + dy[k];

            if(is_ok(cr , cc) && arr[cr][cc] && !visited[cr][cc]){

                visited[cr][cc] = true;
                q.push({cr , {cc , dist + 1}});
            }
    }

}

    return -1;
}



void solve(){

    int a,b  ,c, ans=0, count=0, sum=0;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    fill(visited , false);

    int d1 , d2;


    cin>>d1>>d2;

    fin_ans = INT_MAX;

    

    if(arr[0][0] == 0){
        cout<<-1<<endl;
        return;
    }


    cout<<bfs(d1 , d2)<<endl;


}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    
   int t; cin>>t; while(t--)
    {     
      solve();
    }

  return 0;
}
