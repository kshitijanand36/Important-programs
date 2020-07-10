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

int dp[101][101];


int func(int arr[] , int st , int end){

    /*the idea is to place paranthesis at each possible place
    Here st->opening parenthesis and end->closing*/

    /*now we will try to find the val for the curr parenthesis 
    along with taking the max*/

    if(st >=end)  return 0;

    if(dp[st][end]!=-1) return dp[st][end];


    int ans = INT_MAX;

    for(int i=st; i<end; i++) {

        ans = min(ans , arr[st - 1]*arr[i]*arr[end] + func(arr , st , i) + func(arr , i + 1 , end));
    }
    dp[st][end] = ans;
    return ans; 
}

void solve(){

    int n,a,b,c, ans=0, count=0, sum=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    fill(dp , -1);

    ans = func(arr , 1 , n - 1);

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
