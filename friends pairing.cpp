#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define pb push_back
#define P pair<ll,ll>
#define F first
#define S second

const int N = 100005;

ll memo[100];
ll counts=0;


ll friends(ll n){
    counts++;
	if(n<=1){
		return 1;
	}

	if(memo[n]!=-1)  return memo[n];

	ll ans=friends(n-1) +(n-1)*friends(n-2);
    memo[n]=ans;
	return ans;
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
  //  ll t; cin>>t; while(t--)
    {
       ll t;
	   cin>>t;
	   while(t--){
		   ll n;
		   cin>>n;
           ll ans;
		   memset(memo,-1,sizeof(memo));
		   ans=friends(n);
		   cout<<ans<<endl;
		   cout<<counts<<endl;
	   } 
    }
}

