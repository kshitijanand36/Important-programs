#include<bits/stdc++.h>
using namespace std;

bool ispossible(int k,int arr[],int n,int c){
     int isplaced=1;
	 int placed_at=0;
	 for(int i=1;i<n;i++){
		 if(arr[i]-arr[placed_at]>=k){
			 placed_at=i;
			 isplaced++;
		 }
	 }
	 if(isplaced>=c){
		 return true;
	 }
	 else
	 return false;

}

int main() {
	int n,c;
	cin>>n>>c;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
    sort(arr,arr+n);
	int rt=1000007;
	int lf=0;
	
    int ans;

    while(lf<=rt){
        int mid=(lf+rt)/2;
        if(ispossible(mid,arr,n,c)){
            ans=mid;
            lf=mid+1;
        }
        else{
            rt=mid-1;
        }
    }
	
	cout<<ans<<endl;
	return 0;
}
