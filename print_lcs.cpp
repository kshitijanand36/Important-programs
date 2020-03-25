#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

const int N = 100005;

string maximum(string a,string b){
    int len1=a.size();
    int len2=b.size();

    if(len1<len2) return b;
    if(len1>=len2) return a;
}

string lcs(string a,string b){

    int m=a.size();
    int n=b.size();

    string dp[1000][1000];

    for(int i=0;i<=m;i++)  dp[i][0]="";
    for(int i=0;i<=n;i++)  dp[0][i]="";

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            string ans;
            if(a[i-1]==b[j-1]){
                ans=a[i-1]+dp[i-1][j-1];
            }
            else{
                ans=maximum(dp[i][j-1],dp[i-1][j]);
            }
            dp[i][j]=ans;
        }
    }

    return dp[m][n];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
     string a,b;
     cin>>a>>b;
     string ans=lcs(a,b);
     reverse(ans.begin(),ans.end());
     cout<<ans<<endl;
}

