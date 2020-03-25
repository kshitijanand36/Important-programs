#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

const int N = 100005;

int lis(int arr[],int n){
	int dp[100];

	for(int i=0;i<n;i++){
		dp[i]=1;
	}

    int best=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
           if(arr[j]<=arr[i]){
			   dp[i]=max(dp[i],1+dp[j]);
		   }

		}
		best= max(best,dp[i]);
	}

	return best;
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

	   ans=lis(arr,n);
	   cout<<ans<<endl;

    }
}
\
