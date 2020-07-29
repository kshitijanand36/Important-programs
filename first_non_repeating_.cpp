// Created by Kshitij Anand NSIT
#include <bits/stdc++.h>
//#include <ext/numeric>
//using namespace __gnu_cxx;


using namespace std;


#define int long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second
#define vi vector<int>
#define vc vector<char>
#define vb vector<bool>
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define mp(a, b) make_pair(a, b)
#define min3(a, b, c) min(min(a, b), c)
#define min4(a, b, c, d) min(min(a, b), min(c, d))
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define fill(arr,val) memset(arr,val,sizeof(arr))
#define inf 1e18
#define ps(x,y) fixed<<setprecision(y)<<x
#define db(x)  cout<<#x<<" : "<<x<<endl

//problem link:-https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream/0


const int N = 1000000007;

void solve(){

    int n,a,b,c, ans=0, count=0, sum=0;
    cin>>n;

    queue<char> q;

    map<char , int>m;

    for(int i=0; i<n; i++) {

        char input;

        cin>>input;

        if(m[input] >=1 || m[input] == -1){

            m[input] = -1;
        }


        else{
            q.push(input);
            m[input]++;

        }

        while(!q.empty() && m[q.front()] == -1){
            q.pop();

        }



        if(!q.empty() && m[q.front()] !=-1){
            cout<<q.front()<<" ";
        }

        else{

            cout<<-1<<" ";
        }


    }

    cout<<endl;  
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    
   int t; cin>>t; while(t--)
    {     
      solve();
    }

  return 0;
}
