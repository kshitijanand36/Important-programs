#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

const int N = 100005;

void swap(int arr[],int i,int j){

    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int max_index(int arr[],int si,int ei){
    
    int max=0;
    for(int i=si;i<=ei;i++){
          if(arr[i]>arr[max]){
              max=i;
          }

    }

    return max;
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
       a=n;
       while(a>0){

           int i=max_index(arr,0,a-1);
           swap(arr,i,a-1);
           a--;
       }

       for(int i=0;i<n;i++){
           cout<<arr[i]<<" ";
       } 
    }
}

