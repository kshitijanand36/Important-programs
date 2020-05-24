#include<bits/stdc++.h>
#include<vector>
#define pb push_back
using namespace std;

class Priority_Queue{
    vector<int> pq;
    int last;
    
     public:

    void helper_insert(int curr){
        int parent = (curr-1)/2;
        if(curr<=0){
            return ;
        }
        if(pq[parent]<pq[curr]){
            return;
        }
        if(pq[(curr-1)/2]>pq[curr]){
           
            swap(pq[curr],pq[parent]);
        }
        helper_insert(parent);
    }

    int Min(int i,int j){
        if(pq[i]<pq[j]) return i;
        return j;
    }
    
    bool empty(){
        if(pq.size()==0) return true;
        return false;
    }

    void insert(int element){
        pq.pb(element);
        helper_insert(pq.size()-1);

        for(int i=0;i<pq.size();i++){
            cout<<pq[i]<<" ";
        }
        cout<<endl;
        

    }

    int get_min(){

        return pq[0];
    }

    int pop(){
        
       
        int ans = pq[0];
      
        swap(pq[0],pq[pq.size()-1]);

        pq.pop_back();
        int curr = 0;
        while(2*curr +1 <pq.size()){
            int left_child = 2*curr +1;
            int right_child = 2*curr +2;

            int min_child_index;

            if(right_child<pq.size())
                 min_child_index = Min(right_child,left_child);

            else{
                min_child_index = left_child; 
            }

            if(pq[min_child_index] > pq[curr]){
                break;
            }
            if(pq[min_child_index] < pq[curr]){
                swap(pq[min_child_index],pq[curr]);
            }
            curr = min_child_index;
        }
        return ans;
    }
};

int main() {


    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Priority_Queue p;
    p.insert(3534);
    p.insert(4);
    p.insert(24);
    p.insert(76);
    p.insert(3);
    p.insert(-23);

    while(!p.empty()){
        cout<<p.pop()<<" ";

    }

}

