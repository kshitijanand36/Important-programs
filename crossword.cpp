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


const int N = 1000000007;

bool is_valid_vertical(int row , int col , string word , string grid[]){

    int cnt = 0;
    int i;
    for( i= row ;i< row + sz(word) ; i++){

        if(i >= 10) break;

         if(grid[i][col] == '-' ||grid[i][col] == word[cnt] ){

            cnt++;
        }

        else
            return false;
    }



    if(cnt < sz(word)) return false;

    return true;
}

bool is_valid_horizontal(int row , int col , string word , string grid[]){

    int i;

    int cnt = 0;

   ;


    for( i= col ;i< col + sz(word) ; i++){
        int k = row;

        if(i >= 10) break;

        if(grid[row][i] == '-' ||grid[row][i] == word[cnt] ){
            cnt++;
        }


        else{
           
            return false;
        }

    }

    if(cnt < sz(word)) {

        return false;
    }



    return true;
}

string set_vertical(int row , int col , string word , string grid[]){

    string temp;
    int cnt = 0;

    for(int i= row ;i< row + sz(word) ; i++){

        temp += grid[i][col];
        grid[i][col] = word[cnt];
        cnt++;
    }
    return temp;

}


string  set_horizontal(int row , int col , string word , string grid[]){

    string temp;
    int cnt = 0;
    for(int i= col ;i< col + sz(word) ; i++){

        temp += grid[row][i];

        grid[row][i] = word[cnt];
        cnt++;
    }



    return temp;
}


void func(string grid[] , vector<string> words , int curr){
    

    if(curr == sz(words)){

        for(int i=0; i<10; i++) {

            cout<<grid[i]<<endl;
        }

        exit(0);
    }


    for(int i=0; i<10; i++){

        for(int j=0; j<10; j++) {

            if(grid[i][j] == '-'){
                if(is_valid_horizontal(i , j , words[curr] , grid)){
                    string temp = set_horizontal(i , j , words[curr] , grid);
                    func(grid , words , curr+1);

                    set_horizontal(i , j , temp , grid);

                }

                if(is_valid_vertical(i , j , words[curr] , grid)){
                    string temp = set_vertical(i , j , words[curr] , grid);
                    func(grid , words , curr+1);

                    set_vertical(i , j , temp , grid);

                }
            }
        }
    }


}



void solve(){

    int n,a,b,c, ans=0, count=0, sum=0;
    string grid[10];

    for(int i=0; i<10; i++) {

        cin>>grid[i];
    }

    string s;
    cin>>s;
    // db(grid[1])

    vector<string> words;


    int start = 0;

    for(int i=0; i<sz(s); i++) {


        if(s[i] == ';'){
            
            words.pb(s.substr(start , i - start ));
            start = i + 1;
        }
        
    }


    words.pb(s.substr(start , sz(s) - start ));

    func(grid , words , 0);

    // cout<<"hf";

 
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    
  //  int t; cin>>t; while(t--)
    {     
      solve();
    }

  return 0;
}
