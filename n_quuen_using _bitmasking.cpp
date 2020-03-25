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

int done;
int n;
int ans=0;

void solve(int row,int rd,int ld){

    if(row==done){
        ans++;
        return;
    }
    
    int safe=done&(~(row|ld|rd));
    // int p;
        // cout<<"fg"<<" ";
    while(safe){
        int p=safe&(-safe);
        safe=safe-p;
        solve(row|p,(rd|p)>>1,(ld|p)<<1);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
  //  int t; cin>>t; while(t--)
    {
       cin>>n;
       done=(1<<n) -1;
        solve(0,0,0);
       cout<<ans<<endl;
    }
}

