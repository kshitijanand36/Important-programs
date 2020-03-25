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
#define P pair<ll,ll>
#define F first
#define S second

const ll N = 100005;
ll sum=0;
ll n;

void build_tree(ll si,ll ei,ll index,ll *tree,ll a[]){

    if(si==ei){
        tree[index]=a[si];
        return;
    }

    ll mid=(si+ei)/2;
    build_tree(si,mid,2*index,tree,a);
    build_tree(mid+1,ei,2*index +1,tree,a);
    tree[index]=max(tree[2*index],tree[2*index+1]);
}

void query(ll *tree,ll si,ll ei,ll qs,ll qe,ll idx,ll k){
    //if there is no element greater than k below the subtree
    if(si>ei||tree[idx]<k||qs>qe||qs>n-1||qe>n-1||ei<qs||qe<si)  return;


    if(si==ei&&tree[idx]>k){
         sum++;
         return;
    }

    ll mid=(si+ei)/2;
    query(tree,si,mid,qs,qe,2*idx,k);    
    query(tree,mid+1,ei,qs,qe,2*idx+1,k);    

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    ll *tree=new ll[4*n+1];
    build_tree(0,n-1,1,tree,arr); 
   ll t; cin>>t; while(t--)
    {
        sum=0;
        ll l,r,k;
        cin>>l>>r>>k;
        query(tree,0,n-1,l-1,r-1,1,k);
        cout<<sum<<endl;
    }
}

