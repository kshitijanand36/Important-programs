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

int dp[100001][101];

bool func(int arr[] ,int n , int curr , int sum){

    if(sum == 0) return true;

    if(sum <0 or curr == n) return false;
    
    if(dp[sum][curr] !=-1) return dp[sum][curr];

    bool ans = func(arr , n , curr + 1 , sum) | func(arr , n ,curr + 1 , sum - arr[curr]);
    dp[sum][curr] = ans;
    return ans;
}

void solve(){

    int n,a,b,c, ans=0, count=0, sum=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum += arr[i];
    }


    if(sum%2){
        cout<<"NO\n";
        return;
    }
    
    fill(dp , -1);

    sum/=2;

    bool check = func(arr , n, 0 ,sum);

    if(check){
        cout<<"YES\n";
    }

    else
        cout<<"NO\n";

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
