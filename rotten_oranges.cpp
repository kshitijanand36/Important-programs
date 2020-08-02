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


int dx[] = {0 , 1 , -1 , 0};
int dy[] = {-1 , 0 , 0 , 1};

int n , m;

bool is_ok(int r , int c){


    return r<n&&c<m&&c>=0&&r>=0;
}

void solve(){

    int a,b,c, ans=0, count=0, sum=0;
    cin>>n>>m;
    int arr[n][m];

    queue<P> q;
    for(int i=0;i<n;i++){

        for(int j=0; j<m; j++) {

            cin>>arr[i][j];

            if(arr[i][j] == 2){

                q.push({i , j});
            }

            if(arr[i][j] == 1)count++;
        }
    }


    while(!q.empty()){


        ans++;

        int curr_size = q.size();


        for(int i = 0;i<curr_size ; i++){

            P curr = q.front();

            q.pop();

            for(int k = 0 ;k<4  ;k++){
                int cr = curr.F + dx[k];
                int cc = curr.S + dy[k];
                if(is_ok(cr , cc) && arr[cr][cc]!=0 && arr[cr][cc] !=2){

                    q.push({cr , cc});
                    count--;
                    arr[cr][cc] = 2;
                }
            }
        }
    }

    cout<<(count ==  0 ? ans - 1 : -1)<<endl;

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
