#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second
#define inf INT_MAX

const int N = 100005;

int memo[100][100];

int max_profit(int arr[],int st,int end,int year){

    if(st>end){
        return 0;
    }

    if(memo[st][end]!=-1){
        return memo[st][end];
    }

    int q1,q2;
    q1= arr[st]*year + max_profit(arr,st+1,end,year+1);
    q2= arr[end]*year + max_profit(arr,st,end-1,year+1);
   
   memo[st][end]=max(q1,q2);
   return memo[st][end];
}


int max_profit_dp(int arr[],int n){
     int dp[10][10];
     memset(dp,0,sizeof(dp));
     int year=n;
     for(int i=0;i<n;i++){
         dp[i][i]= year*arr[i];
     }
     --year;

    for(int len=2;len<=n;len++){
        int start=0;
        int end=n-len;
        
        while(start<=end){
            int endwindow=start+len-1;
            dp[start][endwindow]=max(
                arr[start]*year + dp[start+1][endwindow],
                arr[endwindow]*year + dp[start][endwindow-1]
            );
            ++start;
        }
        --year;
    }

   /* for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    return dp[0][n-1];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
  //  int t; cin>>t; while(t--)
    {
       int n,a,b,c, ans=0, count=0, sum=0;
       cin>>n;
       int arr[n];
       for(int i=0;i<n;i++){
           cin>>arr[i];
       }

       memset(memo,-1,sizeof(memo));
       
       ans = max_profit(arr,0,n-1,1);
       sum = max_profit_dp(arr,n);
      cout<<sum<<endl;
     
    }
}

