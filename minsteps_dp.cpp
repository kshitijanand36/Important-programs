#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

const int N = 10005;
int memo[N];

int reduce_no(int n){
      if(n==1||n==0){
          return 0;
      }
    if(memo[n]!=-1){
        return memo[n];
    }

    int q1=INT_MAX,q2=INT_MAX,q3=INT_MAX;
    if(n%3==0){
        q1=1+reduce_no(n/3);
    }
    if(n%2==0){
        q2=1+reduce_no(n/2);
    }
    q3=1+reduce_no(n-1);

    memo[n]=min(q1,min(q2,q3));
    return memo[n];
    
}


int reduce_no_dp(int n){


     int dp[10000];
     dp[0]=0;
     dp[1]=0;
     dp[2]=1;
     dp[3]=1;
     

   
     for(ll i=4;i<=n;i++){

          ll q1=INT_MAX;
          ll q2=INT_MAX;
          ll q3=INT_MAX;
          if(i%3==0)
          {
              q1= 1+dp[i/3];

          }       
            if(i%2==0)
          {
              q2= 1+dp[i/2];
              
          } 

           q3=1+dp[i-1];
          
          dp[i]=min(q1,min(q2,q3));
     }

     return dp[n];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin>>n;
    fill(memo,memo+n+1,-1);
    int ans= reduce_no_dp(n);
    cout<<ans;
    
}

