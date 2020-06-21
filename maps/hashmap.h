#include<iostream>
#include<string>
#define db(x) cout<<#x<<" : "<<x<<endl

using namespace std;

template <typename V>

/*here I am implementing using chaining method hence I will be
using aray of head of linked list*/

class mapnode{

public:
	
	string key;
	V value;
	mapnode<V> *next;
	
	mapnode(string key , V value){
		this->key = key;
		this->value = value;
		next = NULL;
	}
	
	~mapnode(){
		delete next;
	}
	
};


template <typename V>

class Map{
	mapnode<V> **buckets;
	int count;
	int num_buckets;
	
public:
	Map(){
		count = 0;
		
		num_buckets = 5;
		
		buckets = new mapnode<V> *[num_buckets];
		
		for(int i=0 ; i< num_buckets ; i++){
			
			buckets[i] = NULL;
		}
	}
	
	~Map(){
		
		for(int i=0; i<num_buckets ; i++){
			
			delete buckets[i];
		}
		
		delete [] buckets;
	}
	
	
	int size(){
		
		return count;
	}
	
	//we use this func to maintain the load_factor( by increasing the size)
	void rehash(){
		
		mapnode<V> **temp = buckets;
		
		int prev_size = num_buckets;
		
		
		buckets = new mapnode<V> *[2*num_buckets];
		
		for(int i = 0; i< 2*num_buckets ; i++){
			buckets[i] = NULL;
		}
		count = 0;
		num_buckets*=2;
		
		
		for(int i=0 ; i< prev_size ; i++){
			
			mapnode<V> *head = temp[i];
			
			while(head!=NULL){
				
					
				string curr_key = head->key;
				
				V curr_data = head->value;
				
				
				insert(curr_key , curr_data);
				
				head = head->next;
			}
		}
		
		for(int i=0;i <prev_size ; i++){
			
			mapnode<V> *head = temp[i];
			delete head;
			
		}
		
		delete [] temp;
		
		
	}
	V getValue(string key){
		int index = getBucketIndex(key);
		
		mapnode<V> *head = buckets[index];
		
		while(head!=NULL){
			
			if(head->key == key){
				
				return head->value;
			}
			
			head = head->next;
		}
		
		return 0;	
	}
		
	
private:
	
	int getBucketIndex(string key){
		
		int hashcode = 0;
		
		int p =37;
		
		int curr_coeff = 1;
		
		//doing this to get the hashcode
		
		for(int i=key.size() - 1 ; i>=0 ; i--){
			hashcode += key[i]*curr_coeff;
			hashcode %= num_buckets;
			curr_coeff = ((curr_coeff%num_buckets)*(p%num_buckets)%num_buckets);
		}
			
		return hashcode % num_buckets;
	}
	
	
	
public:	
	
	void insert(string key , V value){
		
		int my_index = getBucketIndex(key);
		
		mapnode<V>* head =  buckets[my_index];
		
		mapnode<V>* curr = head;
		//if the key is already present then we need to just update it.
		while(head != NULL){
			
			
			if(head->key == key){
				head->value = value;
				return;
			}
			
			head = head->next;
		}
		
		//else add it in the list
		
		mapnode<V> *newnode = new mapnode<V>(key , value);
		newnode->next = curr;
		
		buckets[my_index] = newnode;
		count++;
		
		double load_factor = (1.0* count)/num_buckets;

		
		if(load_factor > 0.7){
			rehash();
		}
	}
	
	
	V remove(string key){
		
		int index = getBucketIndex(key);
		
		mapnode<V> *head = buckets[index];
		
		mapnode<V>* curr = head;
		
		mapnode<V> *prev = NULL;
		
		V curr_val;
		
		while(curr!=NULL){
			
			if(curr->key == key){
				
				curr_val = curr->value;
				
				if(prev == NULL){
					buckets[index] = curr->next;
					return curr_val;
				}
				prev->next = curr->next;
				
				//as the delete func will otherwise delete the whole linked list(as it is recursive)
				curr->next = NULL;
				
				delete curr;
				return curr_val;
			}
			
			prev = curr;
			
			curr = curr->next;
		}
		
		return 0;
		
	}
	
};


