#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define pb push_back
#define P pair<ll,ll>
#define F first
#define S second
#define M 100000000

ll mark[M+1];
vector<ll> primes;

void seive(){
	memset(mark,0,sizeof mark);
	mark[0]=mark[1]=1;
	for(ll i=3;i*i<=M;i+=2){
		if(mark[i]==0){
			for(ll j=i*i;j<=M;j+=2*i){
				mark[j]++;
			}
		}
	}
	primes.pb(2);
    for(ll i=3;i<=M;i+=2){
       if(mark[i]==0){
		   primes.pb(i);
	   }

	}
   // cout<<primes[0]<<" "<<primes[1]<<" "<<primes[3]<<" "<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
  //  ll t; cin>>t; while(t--)
    
       ll n,a,b,c, ans=0, count=0, sum=0;
       cin>>n;
       seive();
	  cout<<primes[n-1];
	  
}
