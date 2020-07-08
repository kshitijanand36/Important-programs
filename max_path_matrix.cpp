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

int n;

int dp[21][21];

int func(vi *arr ,int row , int c){

    if(c == n || c<0){
        return 0;
    }

    if(row == n) return 0;

    if(dp[row][c] !=-1) return dp[row][c];

    int val1 = func(arr , row + 1 , c);
    int val2 = func(arr , row + 1 , c - 1);
    int val3 = func(arr , row + 1 , c + 1);

    int ans = arr[row][c] + max3(val1 , val2 , val3);

    dp[row][c] = ans;

    return ans;

}

void solve(){

    int a,b,c, ans=0, count=0, sum=0;
    cin>>n;
    vector<int> *arr = new vi[n];
    for(int i=0;i<n;i++){
        for(int j=0; j<n; j++) {
            cin>>a;
            arr[i].pb(a);
        }
    }

    for(int i=0; i<n; i++) {
        fill(dp,  -1);
        ans =  max(ans ,func(arr , 0, i));
    }


    cout<<ans<<endl;  
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
