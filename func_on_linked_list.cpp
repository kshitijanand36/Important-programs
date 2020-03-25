//Q7. Operations on singly linked list: Insertion,Deletion,Display,Search,Reverse,Merge two

#include <iostream>

using namespace std;

struct node
{
	int data;
	node *link;	
};
node *head=NULL;

void ins_beg()
{
	node *temp= new node();
	int val;
	cout<<"Enter data for the node";
	cin>>val;
	temp->data=val;
	temp->link=NULL;
	if(head==NULL)
		head=temp;
	else
	{
		temp->link=head;
		head=temp;
	}
//	delete temp;		
}

void ins_last()
{
	node *temp= new node; 
	node *newnode= new node;
	int val;
	cout<<"Enter data for the node";
	cin>>val;
	newnode->data=val;
	newnode->link=NULL;
	temp=head;
	while(temp->link!=NULL)
	{
		temp=temp->link;
	}
	temp->link=newnode;
}

void ins_pos()
{
	node *temp= new node;
	node *prev= new node;
	node *newnode= new node;
	int val,c=0,pos;
	cout<<"Enter position to enter the value";
	cin>>pos;
	cout<<"Enter data for the node";
	cin>>val;
	temp=head;
	while(c!=pos)
	{
		prev=temp;
		temp=temp->link;
		c++;
	}
	newnode->data=val;
	prev->link=newnode;
	newnode->link=temp;
}

void del_beg()
{
	node *temp=new node;
	if(head==NULL)
		cout<<"There is nothing to delete(Underflow)";
	else
	{
		cout<<"Deleted data is:"<<head->data;
		temp=head;
		head=head->link;
		delete temp;	
	}
	
}

void del_last()
{
	node *temp, *prev;
	temp=head;
	if(head==NULL)
		cout<<"There is nothing to delete(Underflow)";
	else
	{
		while(temp->link=NULL)
		{
			prev=temp;
			temp=temp->link;
		}
		cout<<"Deleted value is:"<<temp->data;
		prev->link=NULL;
		delete temp;
	}
}

void del_pos()
{
	node *temp, *prev;
	int c=0,pos;
	if(head==NULL)
		cout<<"There is nothing to delete(Underflow)";
	else
	{
		cout<<"Enter position to delete value";
		cin>>pos;
		temp=head;
		while(c!=pos)
		{
			prev=temp;
			temp=temp->link;
			c++;
		}
		cout<<"Deleted value is:"<<temp->data;
		prev->link=temp->link;
		delete temp;
	}	
}

void show()
{
	node *temp= head;
	//temp=head;
	if(temp==NULL)
		cout<<"There is nothing to show(Underflow)";
	else
	{
		cout<<"Your list is:\n";
		//temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<"\t";
			temp=temp->link;
		}
	}
	
}

void search()
{
	node *temp= new node();
	temp=head;
	int val,c=0;
	if(temp==NULL)
		cout<<"There is nothing to search(Underflow)";
	else
	{
		cout<<"Enter value to search";
		cin>>val;
		//temp=head;
		while(temp->data!=val)
		{
			temp=temp->link;
			c++;
		}
		if(temp->data==val)
			cout<<"Position of data is:"<<c;
		else
			cout<<"Data is not available in the list";
	}
}


void menu()
{
	int t;
	cout<<"Enter the no. of operations";
	cin>>t;
	int n;
	while(t--)
	{	
		cout<<"\nEnter from MENU\n";
		cout<<"1. Insert at beginning\n";
		cout<<"2. Insert at last\n";
		cout<<"3. Insert at given position\n";
		cout<<"4. Delete from beginning\n";
		cout<<"5. Delete from last\n";
		cout<<"6. Delete from given position\n";
		cout<<"7. Display the linked list\n";
		cout<<"8. Search data from the list";
		
		cin>>n;
		
		switch(n)
		{
			case 1: ins_beg(); break;
			case 2: ins_last(); break;
			case 3: ins_pos(); break;
			case 4: del_beg(); break;
			case 5: del_last(); break;
			case 6: del_pos(); break;
			case 7: show(); break;
			case 8: search(); break;
		}
			
	} 
	
}

int main()
{
	menu();
	return 0;
}
