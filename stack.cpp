#include <iostream>
using namespace std;

class stack{
    public:
    int *s;
    int top;
    int size;

    stack(int n){
        size=n;
        top=-1;
        s=new int[size];
    }

    void push(int val){
       if(top>=size-1){
           return;
       }
    //    if(top=-1){
    //        s[0]=val;
    //        top++;
    //    }
       s[++top]=val;
    }

    int pop(){
        if(top<=-1) return 0;

        return s[top--];
    }

    bool empty(){
        if(top==-1) return true;

        return false;
    } 
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    stack st(5);

    st.push(4);
    st.push(2);
    st.push(9);
    st.push(42);
    st.push(76);

    while(!st.empty()){
        cout<<st.pop()<<endl;
    }


}

