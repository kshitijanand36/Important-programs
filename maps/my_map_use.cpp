#include <iostream>
#include "hashmap.h"
using namespace std;

int main(){
	
	Map<int> m;
	
	m.insert("abcd" , 45);
	m.insert("fregger" , 32);
	m.insert("fdsf" , 80);
	 m.insert("b" , 80);
	 m.insert("y" , 43);
	 m.insert("ju" , 80);
	 m.insert("fr" , 80);
	 cout<<m.remove("fregger")<<endl;
	
	db(m.getValue("fdsf"));
	
	cout<<m.getValue("fr")<<endl;
	cout<<m.size();
}
