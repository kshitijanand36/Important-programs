#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

const int N = 100005;

int grid[100][100]; 
int dp[100][100];

int min_sum(int row,int col){
   
   dp[0][0]=grid[0][0];

    for(int i=1;i<row;i++){
         dp[i][0]= dp[i-1][0] + grid[i][0];
    }
   
   
    for(int i=1;i<col;i++){
         dp[0][i]= dp[0][i-1] + grid[0][i];
    }

    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            dp[i][j]= min(
                dp[i-1][j],
                dp[i][j-1]
            ) + grid[i][j];
        }
    }
     
    // for(int i=0;i<row;i++){
    //     for(int j=0;j<col;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return dp[row-1][col-1];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    

    int row,col;
    cin>>row>>col;
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>grid[i][j];
        }
    }

int ans=min_sum(row,col);
    cout<<ans<<endl;

    
}

