#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second
#define M 1000000007

ll power(ll a,ll b){
     ll res=1;
    while(b!=0){
       
        if(b&1){
            res=(res*a)%M;
        }
        a=(a*a)%M;
        b=b>>1;
    }
    return res%M;
}

ll factorial(ll n){
    
    ll ans=1;
    for(ll i=1;i<=n;i++){
       ans=(ans%M)*(i%M);
    }
    return ans%M;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

   ll n,r;
     cin>>n>>r; 
    ll fact_n=factorial(n);
    ll fact_r=factorial(r);
    ll fact_t=factorial(n-r);
    ll inverse_r=power(fact_r,M-2);
    ll inverse_t=power(fact_t,M-2);
    ll ans=(((fact_n*inverse_r)%M)*inverse_t)%M;
  //   cout<<inverse_r<<endl;
     cout<<ans;


}
