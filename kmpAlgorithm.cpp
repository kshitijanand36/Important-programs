// Created by Kshitij Anand NSIT
#include <bits/stdc++.h>
//#include <ext/numeric>
//using namespace __gnu_cxx;


using namespace std;


#define int long long //-->this can cause TLE
#define pb push_back
#define P pair<int,int>
#define F first
#define S second
#define vi vector<int>
#define vc vector<char>
#define vb vector<bool>
#define vp vector<P>
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define mp(a, b) make_pair(a, b)
#define min3(a, b, c) min(min(a, b), c)
#define min4(a, b, c, d) min(min(a, b), min(c, d))
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define fill(arr,val) memset(arr,val,sizeof(arr))
#define ps(x,y) fixed<<setprecision(y)<<x
#define db(x)  cout<<#x<<" : "<<x<<endl
#define filler(arr, n)          \
    for (int i = 0; i < n; i++) \
        cin >> arr[i];
#define filler2(arr, n , m)     \
    for (int i = 0; i < n; i++) \
        for(int j=0; j<m; j++)  \
            cin >> arr[i][j];

const int N = 1e9 + 7;            

inline int add(int a,int b) {return ((a%N)+(b%N))%N;}
inline int sub(int a,int b) {return ((a%N)-(b%N)+N)%N;}
inline int mul(int a,int b) {return ((a%N)*(b%N))%N;}


void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" : "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

/*
    pre processing
    binary search
    target sum
    set/ map
    shuffle equation
    dp
    pattern
*/

void createLps(int *lps, string p){

	int  m = sz(p);

	int len = 0;

	int i = 1 ;

	while(i < m){

		if(p[i] == p[len]){

			len++;
			lps[i] = len;
			i++;
		}

		else{

			if(len){
				len = lps[len-1];

			}

			else{

				len = 0;
				i++;
			}
		}
	}



}

void solve(){

    int n,a,b,c,k,m, ans=0, count=0, sum=0;
    
    string s,p;

    cin>>s>>p;
    n = sz(s);
    int *lps = new int[n + 1]();
    m = sz(p);
    createLps(lps , p);

    int ptr1 = 0 , ptr2 = 0;

    bool foundPattern = false;

    while(ptr1 < n ){

    	if(s[ptr1] == p[ptr2]){
    		ptr1++;
    		ptr2++;
    	}

    	else{

    		if(ptr2 > 0){
    			ptr2 = lps[ptr2-1];
    		}
    		else{

	    		ptr1++;
    		}


    	}

    	if(ptr2 == m){

    		cout<<"Pattern found at "<<ptr1-1<<endl;
    		ptr2 = lps[ptr2-1];

    		foundPattern = true;
    	}
    }

    if(!foundPattern){
    	cout<<"No pattern found :(\n";
    }
    

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    
  int t = 1;
  //cin>>t;
  for(int i = 1; i <= t; i++) {
    //cout<<"Case #"<<i<<": ";
    solve();
  }

  return 0;
}

/*Things to do if you are stuck:-
1.Read the problem statement again, maybe you've read something wrong.
2.See the explanation for the sample input .
3.If the solution is getting too complex in cases where no. of submissions 
  are high ,then drop that idea because there is something simple which you are
  missing.
4.Check for runtime errors if unexpected o/p is seen.
5.Check on edge cases before submitting.
6.Ensure that you have read all the inputs before returning for a test case.
7.Try to think of brute force first if nothing is striking.
8.Take more examples
9.Don't give up , maybe you're just one statement away! 
*/
