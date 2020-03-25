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
//#include < unordered_map > 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

const int N = 100005;


using namespace std;

class node{
	public:
		int data;
		node *next;
		node *prev;

//        node(){
//            next=NULL;
//            prev=NULL;
//        }
	};
		
node *head=NULL;

void insert(int val){
	
	node *newnode = new node();
	newnode->data=val;
    // cout<<newnode->data<<endl;
	
	if(head==NULL){
		head= newnode;
        head->next=NULL;
	}
	else if(head->next==NULL){
		head->next=newnode;
		newnode->prev=head;
        newnode->next=NULL;
		
	}
	else{
		node *curr=head;
		while(curr->next!=NULL){
			curr=curr->next;
		}
		curr->next=newnode;
		newnode->prev=curr;
        newnode->next=NULL;
	}
}

void print(){
	
	node *curr=head;
	
	while(curr->next!=NULL){
		cout<<curr->data<<endl;
        curr=curr->next;
	}
    cout<<curr->data;
}	

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    
    insert(4);
    insert(5);
    insert(7);
    insert(8);
    
    print();
    // int val=head->data;
    // cout<<val;
}

