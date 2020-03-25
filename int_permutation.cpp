#include <bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
#include<list>
#include<vector>
#include<bitset>

// #include < unordered_map > 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;


#define ll long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

const int N = 100005;
int n;

void permute(int in[],int i){
	if(i>n) return;
    if(i==n){
        for(int j=0;j<n;i++){
		cout<<in[j]<<" ";
	}
        return ;
    }

    for(int j=i;j<n;j++){
        // if(in[i]!=in[j]){
            swap(in[i],in[j]);
            permute(in,i+1);
            swap(in[i],in[j]); 
            // permute(in,i+1);
        // }   
        // else{
        //       j++;

        // }    
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
		cin>>arr[i];
	}
    
    // cout<<s<<endl;
    sort(arr,arr+n);
    permute(arr,0);
}

