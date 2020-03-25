#include <bits/stdc++.h>
using namespace std;

int query(int *tree,int qs,int qe,int si,int ei,int index){
    //Base case
    // if(si>ei){
    //     return INT_MAX;
    // }
    //complete overlap
    int mid=(si+ei)/2;
    if(qs<=si&&qe>=ei){
        return tree[index];
    }
    //No overlap
    else if(qe<si||ei<qs){
        return INT_MAX;
    }
    //partial overlap
    else{
        return min(query(tree,qs,qe,si,mid,2*index),query(tree,qs,qe,mid+1,ei,2*index+1));
    }
}

void update(int *tree,int idx,int inc,int si,int ei,int i){
    if(si>i||ei<i) return;

    if(si==ei){
        tree[idx]+=inc;
        return;
    }
    int mid=(si+ei)/2;
    update(tree,2*idx,inc,si,mid,i);
    update(tree,2*idx + 1,inc,mid+1,ei,i);
    tree[idx]=min(tree[2*idx],tree[2*idx + 1]);
    return;
}

void build_tree(int si,int ei,int index,int *tree,int a[]){

    if(si==ei){
        tree[index]=a[si];
        return;
    }

    int mid=(si+ei)/2;
    build_tree(si,mid,2*index,tree,a);
    build_tree(mid+1,ei,2*index +1,tree,a);
    tree[index]=min(tree[2*index],tree[2*index+1]);
}

void update_range(int *tree,int si,int ei,int qs,int qe,int idx,int inc){
    //no overlap
    if(qe<si||ei<qs) return ;

    //In this we have no case for complete overlap as we need to update till we have reached the leaf node
    if(si==ei){
        tree[idx]+=inc;
        return;
    }

    //partial overlap
    int mid=(si+ei)/2;
    update_range(tree,si,mid,qs,qe,2*idx,inc);
    update_range(tree,mid+1,ei,qs,qe,2*idx+1,inc);

    tree[idx]=min(tree[2*idx],tree[2*idx +1]);
    return ;
}

int main() {

    int a[]={1,2,-5,10,3,6};
    int n=sizeof(a)/sizeof(int);
    int *tree=new int[4*n+1];
    memset(tree,0,sizeof(tree));
    build_tree(0,n-1,1,tree,a);
    
    cout<<query(tree,0,5,0,n-1,1)<<endl;
    update_range(tree,0,n-1,0,5,1,8);
    cout<<query(tree,0,4,0,n-1,1);

}

