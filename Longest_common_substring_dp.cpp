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
string s1 , s2;

int fin_ans = 0;


void solve(){

    int n,a,b,c, ans=0, count=0, sum=0;
    int m ; 
    cin>>n>>m;

    int dp[201][210] = {} ;
    cin>>s1>>s2;

    fin_ans = 0;
   

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {

            if(s1[i] == s2[j]){
                if(i>=1&&j>=1)
                dp[i][j] =  1 + dp[i - 1][j - 1];
                else{
                    dp[i][j] = 1;
                }

            }
            ans = max(dp[i][j] , ans);
        }
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
