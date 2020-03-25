#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

const int N = 100005;

int arr[100];
int dp[100];
int memo[100];

int max_profit(int total_len){
     
     if(total_len==0)
     return 0;
   
     if(memo[total_len]!=-1)  return memo[total_len];
    
    int best=0;
     for(int len=1;len<=total_len;len++){
        int temp=arr[len] + max_profit(total_len-len);
         best=max(best,temp);

     }

     memo[total_len]=best;
     return best;
}


int max_profit_dp(int n){

    for(int len=1;len<=n;len++){
        int best=0;
        for(int cut=1;cut<=len;cut++){
            int net=arr[cut]+dp[len-cut];
            best=max(best,net);
        }
        dp[len]=best;

    }

    return dp[n];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
  //  int t; cin>>t; while(t--)
    {
       int n,a,b,c, ans=0, count=0, sum=0;
       cin>>n;
       for(int i=1;i<=n;i++){
           cin>>arr[i];
       }

       memset(memo,-1,sizeof(memo));
      // memo[0]=0;

       ans=max_profit_dp(n);
       cout<<ans<<endl;
    }
}

