#include <bits/stdc++.h>
using namespace std;

int lazy[]={0};
int n;

void lazy_update(int *tree,int idx,int inc,int si,int ei,int qs,int qe){
    //No Overlap
    if(qe<si||qs>ei) return;
    if(si>ei||idx>4*n) return;
  
    if(lazy[idx]!=0){
        tree[idx]+=lazy[idx];
        if(si!=ei){
            lazy[2*idx]+=lazy[idx];
            lazy[2*idx + 1]+=lazy[idx];
        }
        lazy[idx]=0;
    }
    //leaf node
    // if(si==ei){
    //     tree[idx]+=inc;
    //     return;
    // }
    if(si<=qs&&ei>=qe){
        tree[idx]+=inc;
        if(si!=ei){
            lazy[2*idx]+=inc;
            lazy[2*idx + 1] +=inc;
        }
    }
        //partial overlap
    int mid=(si + ei)/2;
    lazy_update(tree,2*idx,inc,si,mid,qs,qe);   
    lazy_update(tree,2*idx+1,inc,mid+1,ei,qs,qe);
    // tree[idx]=min(tree[2*idx],tree[2*idx+1]);   

}

int query(int *tree,int qs,int qe,int si,int ei,int index){

    if(lazy[index]!=0){
        tree[index]+=lazy[index];
        if(si!=ei){
            lazy[2*index]+=lazy[index];
            lazy[2*index+1]+=lazy[index];
        }
        lazy[index]=0;
    }
    
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
     n=sizeof(a)/sizeof(int);
    int *tree=new int[4*n+1];
    memset(tree,0,sizeof(tree));
    build_tree(0,n-1,1,tree,a);
    
    cout<<query(tree,0,5,0,n-1,1)<<endl;
    lazy_update(tree,1,4,0,n-1,0,5);
    cout<<query(tree,3,5,0,n-1,1);

}

