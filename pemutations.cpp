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

void permute(char in[],int i){
    if(in[i]=='\0'){
        cout<<in<<endl;
        return ;
    }

    for(int j=i;in[j]!='\0';j++){
        if(in[i]!=in[j]){
            swap(in[i],in[j]);
            permute(in,i+1);
            swap(in[i],in[j]); 
        }   
        else{
            permute(in,i+1);

        }    
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    char in[8];
    cin>>in;
    int s=strlen(in);
    // cout<<s<<endl;
    sort(in,in+s);
    permute(in,0);
}

