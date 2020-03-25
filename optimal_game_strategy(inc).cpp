#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

const int N = 100005;

int n;

int memo[30][30][30];

int f(int arr[],int i,int j,int count){

    if(i>=j){
        return 0;
    }

    if(memo[i][j][count]!=-1)  return memo[i][j][count];

    int ans=0;

        if(count%2==0){
            ans=max(ans,arr[i] + f(arr,i+1,j,count+1));
            ans=max(ans,arr[j] + f(arr,i,j-1,count+1));
        }
        else{
            int l=max(arr[i],arr[j]);

            if(l==arr[i]){
                ans= max(ans, arr[i+1] + f(arr,i+2,j,count+1));
                ans= max(ans, arr[j] + f(arr,i+1,j-1,count+1));
            }
            else{
                ans=max(ans,arr[i] + f(arr,i+1,j-1,count+1));
                ans=max(ans,arr[j-1] + f(arr,i,j-2,count+1));
            }
        }
        
        memo[i][j][count] = ans;
        return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
  //  int t; cin>>t; while(t--)
    {
    //    int n,a,b,c, ans=0, count=0, sum=0;
       cin>>n;
       int arr[n];
       for(int i=0;i<n;i++){
           cin>>arr[i];
       }
       
       memset(memo,-1,sizeof(memo));
       int ans=f(arr,0,n-1,0); 
       cout<<ans;
    }
}

