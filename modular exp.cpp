#include <iostream>
using namespace std;

int power(int a,int b,int m){
     int res=1;
    while(b!=0){
       
        if(b&1){
            res=(res*a)%m;
        }
        a=(a*a)%m;
        b=b>>1;
    }
    return res;
}

int main() {
	int a,b,m;
	cin>>a>>b>>m;
    cout<<power(a,b,m);
}

