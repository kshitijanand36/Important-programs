#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

const int N = 100005;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin>>t; while(t--)
    {
      int n;
      cin>>n;
      ll sum=0;
      ll A;
      cin>>A;
      sum+=A;
      ll s= (2* pow(10,n))+A;
      cout<<s<<endl;
     // fflush(stdout);
      ll B;
      cin>>B;
      sum+=B;
      ll c= s-sum-pow(10,n);
      cout<<c<<endl;
     // fflush(stdout);
      sum+=c;
      ll d;
      cin>>d;
      sum+=d;
      ll e=s-sum;
      cout<<e<<endl;
      //fflush(stdout);
      sum+=e;
      
     // int res;
      //cin>>res;
      //if(res==-1){
        //exit(0);
  //  }
  if(sum==s){
  	cout<<"YOU LOST :(";
  }
}
}

