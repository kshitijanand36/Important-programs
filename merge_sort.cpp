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

void merge(int arr[],int l,int m,int n){
    int size1=m-l+1;
    int size2=n-m;
    int *arr1=new int[m-l+1];
    int *arr2=new int[n-m];
    int k=0;
    for(int i=l;i<=m;i++){
        arr1[k]=arr[i];
        k++;
    }
    k=0;
    for(int i=m+1;i<=n;i++){
        arr2[k]=arr[i];
        k++;
    }
    int i=0,j=0;
    k=l;
    while(i<size1&&j<size2){
        if(arr1[i]<arr2[j]){
            arr[k]=arr1[i];
            i++;
        }
        else{
            arr[k]=arr2[j];
            j++;
        }
        k++;
    }
    while(i<size1){
        arr[k]=arr1[i];
        k++;
        i++;
    }
    while(j<size2){
        arr[k]=arr2[j];
        j++;
        k++;
    } 
}

void mergeSort(int arr[],int si,int ei){
    if(si>=ei) return;

    int mid=(si+ei)/2;
    mergeSort(arr,si,mid);
    mergeSort(arr,mid+1,ei);
    merge(arr,si,mid,ei);
    return;
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
  //  int t; cin>>t; while(t--)
    {
       int n,a,b,c, ans=0, count=0, sum=0;
       cin>>n;
       int *arr=new int[n];
       for(int i=0;i<n;i++){
           cin>>arr[i];
       }
       

       mergeSort(arr,0,n-1);
    //    cout<<"ghj0";
       for(int i=0;i<n;i++){
           cout<<arr[i]<<" ";
       }
    }
}

