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

int sum=0;
bool visited[15];

void func(int arr[],int t,int n){

	if(sum==t){
		for(int i=0;i<n;i++){
			if(visited[i]){
				cout<<arr[i]<<" ";
			}
		}
		memset(visited,false,sizeof(visited));
		sum=0;
		cout<<endl;
		return;
	}
	if(sum>t){
		sum=0;
		memset(visited,false,sizeof(visited));
         cout<<"ghj";
		return;
	}
	for(int i=0;i<n;i++){
		if(!visited[i]&&arr[i]<t){
			sum+=arr[i];
			visited[i]=true;
			func(arr,t,n);
            
		}
		
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
  //  int t; cin>>t; while(t--)
    {
       int n,t;
       cin>>n;
       int arr[n];
       for(int i=0;i<n;i++){
           cin>>arr[i];
       }
	   cin>>t;
	   func(arr,t,n); 
    }
}

