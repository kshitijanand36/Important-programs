#include<iostream>
#include<stack>

using namespace std;

class Queue{

	stack<int> s1;
	stack<int> s2;

public:
	void push(int val){

		s1.push(val);
	}

	int pop(){

		int top_val;
		while(!s1.empty()){

			s2.push(s1.top());
			s1.pop();
		}
		top_val = s2.top();
		s2.pop();

		while(!s2.empty()){

			s1.push(s2.top());
			s2.pop();
		}

		return top_val;
	}

	bool is_empty(){

		if(s1.empty()) return true;

		return false;
	}

};



int main(){

	Queue q;

	q.push(5);
	q.push(15);
	q.push(25);
	q.push(35);
	q.push(94);
	q.push(85);

	while(!q.is_empty()){

		cout<<q.pop()<<" ";
	}

	

}