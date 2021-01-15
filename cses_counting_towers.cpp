// Created by Kshitij Anand NSIT
#include <bits/stdc++.h>
//#include <ext/numeric>
//using namespace __gnu_cxx;


using namespace std;


#define int long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second
#define vi vector<int>
#define vc vector<char>
#define vb vector<bool>
#define vp vector<P>
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define mp(a, b) make_pair(a, b)
#define min3(a, b, c) min(min(a, b), c)
#define min4(a, b, c, d) min(min(a, b), min(c, d))
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define fill(arr,val) memset(arr,val,sizeof(arr))
#define inf 1e18
#define ps(x,y) fixed<<setprecision(y)<<x
#define db(x)  cout<<#x<<" : "<<x<<endl
#define filler(arr, n)          \
    for (int i = 0; i < n; i++) \
        cin >> arr[i];
#define filler2(arr, n , m)          \
    for (int i = 0; i < n; i++) \
        for(int j=0; j<m; j++)  \
            cin >> arr[i][j];        


const int N = 1e9 + 7;


int dp[1000001][2];

int func(int rem1){


	int ans = 0;	

	for(int i = 1 ; i<=rem1 ; i++){
		dp[i][1] = (dp[i][1]%N +  ((4*(dp[i - 1][1] %N))%N +dp[i - 1][0]%N)%N)%N;
		dp[i][0] = (dp[i][0]%N +  (((dp[i - 1][1] %N))%N +2*dp[i - 1][0]%N)%N)%N;

	}


	return (dp[rem1][0]%N + dp[rem1][1]%N)%N;

}

void solve(){

    int n,a,b,c,k,m, ans=0, count=0, sum=0;
    cin>>n;
    cout<<(dp[n][0]%N + dp[n][1]%N)%N<<endl;
      
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
	fill(dp , 0);
	dp[1][1] = 1;
	dp[1][0] = 1;

	func(1000000);
    
   int t; cin>>t; while(t--)
    {     
      solve();
    }

  return 0;
}

/*Things to do if you are stuck:-
1.Read the problem statement again, maybe you've read something wrong.
2.See the explanation for the sample input .
3.If the solution is getting too complex in cases where no. of submissions 
  are high ,then drop that idea because there is something simple which you are
  missing.
4.Check for runtime errors if unexpected o/p is seen.
5.Check on edge cases before submitting.
6.Ensure that you have read all the inputs before returning for a test case.
7.Try to think of brute force first if nothing is striking.
8.Don't give up , maybe you're just one statement away! 
*/

