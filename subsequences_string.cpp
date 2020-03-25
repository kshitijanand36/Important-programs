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
int len;

void subsequence(string ip,string op,int i){
    if(i>len){
        return;
    }
    if(i==len){
        cout<<op<<endl;
    }
    subsequence(ip,op + ip[i],i+1);
    subsequence(ip,op,i+1);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s;
    cin>>s;
    len=s.size();
    subsequence(s,"",0);

}

