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

class node{
    public:
    int exp;
    int coeff;
    node *next;
};

node *p1=NULL;
node *p2=NULL;
node *p=NULL;

void poly_add(){
    node *ptr1=p1;
    node *ptr2=p2;
    node *ptr=p;

    while(ptr1!=NULL&&ptr2!=NULL){
    //    cout<<"dfg";
        node *newnode=new node();
        if((ptr1->exp)>(ptr2->exp)){
            newnode->exp=ptr1->exp;
            newnode->coeff=ptr1->coeff;
            if(p==NULL){
               p=newnode;
               ptr=newnode;
            }
            else{
                ptr->next=newnode;
                ptr=ptr->next;
            }
            ptr1=ptr1->next;
        }
        else if((ptr1->exp)<(ptr2->exp)){
             newnode->exp=ptr2->exp;
            newnode->coeff=ptr2->coeff;
            if(p==NULL){
               p=newnode;
               ptr=newnode;
            }
            else{
                ptr->next=newnode;
                ptr=ptr->next;
            }
            ptr2=ptr2->next;
        }
         else if((ptr1->exp)==(ptr2->exp)){
             newnode->exp=ptr2->exp;
            newnode->coeff=ptr2->coeff + ptr1->coeff;
            if(p==NULL){
               p=newnode;
               ptr=newnode;
            }
            else{
                ptr->next=newnode;
                ptr=ptr->next;
            }
            ptr2=ptr2->next;
            ptr1=ptr1->next;
        }
    }

   if(ptr1!=NULL){
       ptr->next=ptr1;
   }
   else if(ptr2!=NULL){
       ptr->next=ptr2;
   }

   node *mb=p;
   while(mb!=NULL){
       cout<<mb->coeff<<" "<<mb->exp<<endl;
       mb=mb->next;
   }
}

int main() {
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin>>n;
    node *ptr=NULL;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        node * newnode=new node();
        newnode->coeff=a;
        newnode->exp=b;  
        if(p1==NULL){
            p1=newnode;
            ptr=newnode;
        }
        else{
            ptr->next=newnode;
            ptr=ptr->next;
        }
    }

    int m;
    cin>>m;
    node *ptr1=NULL;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        node * newnode=new node();
        newnode->coeff=a;
        newnode->exp=b;  
        if(p2==NULL){
            p2=newnode;
            ptr1=newnode;
        }
        else{
            ptr1->next=newnode;
            ptr1=ptr1->next;
        }
    }
    
    poly_add(); 
}

