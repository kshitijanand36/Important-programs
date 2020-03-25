#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

const ll N = 1000000007;
int m;

int memo[1000000];

int tilling(int n){
	if(n==1|| n==0)  return 1;
	if(n<0)  return 0;
    
	if(memo[n]!=-1)  return memo[n];

	int ans=tilling(n-1)%N + tilling(n-m)%N;
    memo[n]=ans%N;
	return ans%N;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin>>t; while(t--)
    {
       int n;
       cin>>n>>m;
	   memset(memo,-1,sizeof(memo));
       int ans=tilling(n);
       cout<<ans<<endl;
    }
}

