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
int arr[25][30];
// bool visited[25][30];
int n;

int ans=INT_MAX;

int min(int a,int b){
    if(a<=b) return a;
    return b;
}
int x=0;
void count_pos(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==1){
                x++;
            }
        }
    }
}
int ch=0;
void funky(int row,int col,int count){
    // visited[row][col]=true;
    bool check=false;

    if(row>=n||col>=n||row<0||col<0||arr[row][col]==0){
        return ;
    }
    arr[row][col]=0;
//    cout<<"fd";
   ch=max(ch,count);
    funky(row-2,col+1,count+1);
    // arr[row-2][col+1]=1;
    funky(row-1,col+2,count+1);
    // arr[row-1][col+2]=1;
    funky(row+1,col+2,count+1);
    // arr[row+1][col+2]=1;
    funky(row-1,col-2,count+1);
    // arr[row-1][col+2]=1;
    funky(row+2,col+1,count+1);
    // arr[row+2][col+1]=1;
    funky(row-2,col-1,count+1);
    // arr[row-2][col-1]=1;
    funky(row+2,col-1,count+1);
    // arr[row+2][col-1]=1;
    funky(row+1,col-2,count+1);
    // arr[row+1][col-2]=1;
    arr[row][col]=1;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    
  //  int t; cin>>t; while(t--)
    {
      
       cin>>n;
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               cin>>arr[i][j];
           }
       }
    //    memset(visited,false,sizeof(visited)); 
    //    arr[0][0]=0;
    count_pos();
       funky(0,0,1);
//       cout<<"mai madarchod hu jo isme aaya";
       cout<<x-ch<<endl;
    }
}

