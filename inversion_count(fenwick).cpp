#include <bits/stdc++.h>
using namespace std;

int BIT[1000]={0};
int arr[1000];


void update(int i,int inc,int n){
    while(i<=n){
        BIT[i]+=inc;
        i+=(i&(-i));
    }
}

int query(int i){
    int sum=0;
    while(i>0){
        sum+=BIT[i];
        i-=(i&(-i));
    }
    return sum;
}

int main() {

    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        
    }
    
    //Here we have maintained a freq array in BIT 
    //We get how may elements are smaller than any particualar no. by seeing the freq of one smaller element.
    //the indexes of BIT denotes the elements of array
    int ans=0;
    for(int i=n;i>=1;i--){
        ans+=query(arr[i]-1);
        update(arr[i],1,n);
    }
    cout<<ans<<endl;
    
    
}

