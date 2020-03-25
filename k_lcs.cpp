#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

const int N = 100005;

int k_lcs(int arr1[],int arr2[],int m,int n,int k){
	if(m==0||n==0)  return 0;

	
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int m,n,k;
	cin>>m>>n>>k;
    
    int arr1[m];
    int arr2[n];

	for(int i=0;i<m;i++){
		cin>>arr1[i];
	}

	for(int i=0;i<n;i++){
		cin>>arr2[i];
	}

  int ans=k_lcs(arr1,arr2,m,n,k);
}

