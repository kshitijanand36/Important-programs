#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

const int N = 100005;

int memo[1000][1000];

int s,n;

int money_change(int size[],int i,int s1){

	if(i==n) return 0;

	if(s1>=s){
        return 1;
	}
	// if(s1>s)  return 0;

	if(memo[i][s1]!=-1) return memo[i][s1];
   
    int ans=0;

    if(s1+ size[i]<=s){
	   ans= money_change(size,i+1,s1) + money_change(size,i,s1+size[i]);
    }

    else{
        ans=money_change(size,i+1,s1);
    }   

	memo[i][s1]=ans;
	return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
   int t; cin>>t; while(t--)
    {
    //    int n;
       cin>>n;
       int size[n];
       for(int i=0;i<n;i++){
           cin>>size[i];
       } 
      
       cin>>s;

	  memset(memo,-1,sizeof(memo));

	  int ans=money_change(size,0,0);
      
      cout<<ans<<endl;
    }
}
