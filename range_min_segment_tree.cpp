// Created by Kshitij Anand NSIT
#include <bits/stdc++.h>
//#include <ext/numeric>
//using namespace __gnu_cxx;


using namespace std;


// #define int long long
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


const int N = 1000000007;

int *tree;


void build(int arr[] , int start , int end , int curr){
    
    if(start > end)return;

	if(start == end){

		tree[curr] = arr[start];
		return;
	}

	int mid = (start + end)/2;

	build(arr , start , mid , 2*curr);
	build(arr , mid  +1 , end , 2*curr + 1);

	tree[curr] = min(tree[2*curr] , tree[2*curr + 1]);
}

void update(int start , int end , int idx , int val , int curr , int arr[]){
    

	if(start == end && start == idx){

		arr[idx] = val;

		tree[curr] = val;
		return;
	}
    if(start >= end)return;

	int mid = (start + end)/2;
	if(idx <= mid){
		update(start , mid , idx , val  ,2*curr , arr);

	}

	else{

		update(mid + 1 , end , idx , val , 2*curr + 1 , arr);

	}
	tree[curr] = min(tree[2*curr] , tree[2*curr + 1]);

}

int query(int start , int end , int req_start , int req_end , int curr){
    
    
    if(start >= req_start && end <= req_end)return tree[curr];

	int mid = (start + end)/2;

	if(mid >= req_end){

		return query(start , mid , req_start , req_end , 2*curr);
	}

	if(mid + 1 <= req_start){

		return query(mid + 1 , end , req_start , req_end , 2*curr + 1);
	}


	int val1 = query(start , mid , req_start , req_end , 2*curr);
	int val2 = query(mid  +1 , end , req_start , req_end , 2*curr + 1);

	return min(val1 , val2);

}

void solve(){

    int n,a,b,c,k,m, ans=0, count=0, sum=0;
    cin>>n>>k;
    int arr[n];
    filler(arr , n);

    tree = new int[4*n + 1];

    build(arr , 0 , n - 1 , 1);  

    while(k--){

    	char g;
    	cin>>g;

    	if(g == 'q'){

    		cin>>a>>b;

    		cout<<query(0 , n- 1 ,a - 1 , b - 1 , 1)<<endl;
    	}

    	else{
    		cin>>a>>b;

    		update(0 , n - 1 , a - 1 , b , 1 , arr);
    	}

    }


}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    
  //  int t; cin>>t; while(t--)
    {     
      solve();
    }

  return 0;
}


