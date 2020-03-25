#include <bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
#include<list>
#include<vector>
#include<bitset>

// #include < unordered_map > 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;


#define ll long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

const int N = 100005;

int dp[100][2];

int func(int n){
    if(dp[n][0]==-1){
        dp[1][0]=1;
        dp[1][1]=1;

    for(int i=2;i<=n;i++){
        dp[i][0]=dp[i-1][0] + dp[i-1][1];
        dp[i][1]=dp[i-1][0];
    }
    }
   return dp[n][0] + dp[n][1];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    memset(dp,-1,sizeof(dp));
    
   int t; cin>>t; while(t--)
    {
       int n;
       cin>>n;
       int ans = func(n);
       cout<<ans<<endl;
    }
}

