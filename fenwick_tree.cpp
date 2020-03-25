#include <bits/stdc++.h>
using namespace std;

int BIT[1000]={0};
int arr[1000];

void update(int inc,int i,int n){
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
        update(arr[i],i,n);
    }
    int t;cin>>t;while(t--){
        int l,r;
        cin>>l>>r;
        cout<<query(r)-query(l-1)<<endl;
    }

    // for(int i=1;i<=n;i++){
    //     cout<<BIT[i]<<" ";
    // }
    
}

