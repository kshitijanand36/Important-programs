class node{
 
public:
 
    int data;
    
 
    node(){
 
        // cnt_even = cnt_odd = 0;
    }
};
 
node *tree;
int size;
 
node merge(node &v1 , node &v2){
 
    node res;
 
    res.data = __gcd(v1.data%N , v2.data%N)%N;
    // res.data = v1.cnt_even + v2.cnt_even;
    return res;
}
 
void build(int curr , int left , int right , int arr[] ){
 
 
    if(left == right){
 
        tree[curr].data = arr[left];
 
 
        return;
    }
 
    int mid = (left + right)/2;
 
    build(2*curr , left , mid , arr);
 
    build(2*curr + 1 , mid + 1 , right , arr);
 
    tree[curr] = merge(tree[2*curr] , tree[2*curr + 1]);
 
    
 
}
 
void update(int curr , int start , int end , int idx , int val){
 
    if(start == end){
 
        
        tree[curr].data = (tree[curr].data%N)*(val%N)%N;
        return;
    }
 
 
    int mid = (start + end)/2;
 
    if(idx > mid){
 
        update(2*curr + 1 , mid + 1 , end , idx , val);
    }
 
    else{
 
        update(2*curr , start , mid , idx , val);
    }
 
    tree[curr] = merge(tree[2*curr] , tree[2*curr + 1]);
 
    
 
}
 
node query(int curr , int start , int end , int left , int right){
 
    node res;
 
    if(end < left || start > right)return res;
 
 
    if(start >= left && end <= right)return tree[curr];
 
    int mid = (start + end)/2;
 
 
    if(right <= mid){
 
        return query(2*curr , start , mid ,left , right);
    }
 
    else if(left >= mid + 1){
 
        return query(2*curr + 1 , mid + 1 , end , left , right);
    }
 
    node var1 = query(2*curr , start , mid , left , right );
 
    node var2 = query(2*curr + 1 , mid + 1 , end , left , right );
 
    res = merge(var1 , var2);
 
    return res;
 
 
}


node query(int left , int right){

    return query(1 , 0 , size-1 , left , right);
}

void update(int idx , int val){

    update(1 , 0 , n-1 , idx , val);
}
