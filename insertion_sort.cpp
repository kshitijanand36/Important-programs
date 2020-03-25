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

void shift(int arr[],int j,int i,int temp){
    for(int l=i-1;l>=j;l--){
        arr[l+1]=arr[l];
    }
    
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
    //   shift(arr,2,7,arr[8]);

    //   cout<<arr[2];
     count=0;
       for(int i=1;i<n;i++){
           int temp=arr[i];
           int g=i;
           bool check=false;
           for(int j=i-1;j>=0;j--){
               if(temp<arr[j]){
                  arr[j+1]=arr[j]; 
                  arr[j]=temp;
                //    break;
               }
           }
         
       }
       for(int i=0;i<n;i++){
           cout<<arr[i]<<" ";
       }
       cout<<endl; 
    //    cout<<count;
    }  
}

