#include<iostream>
#include<stack> 
using namespace std; 
void deleteMiddle(stack<char> &s, int n, int current=0){ 
    if(s.empty() || current == n){ 
        return; 
    }
    int x = s.top(); 
    s.pop();
    
    deleteMiddle(s, n, current+1); 
    
    if(current != n/2){ 
        s.push(x); 
    }
}
int main(){ 
    stack<char> st; 
    
    st.push('5'); 
    st.push('4'); 
    st.push('3'); 
    st.push('2'); 
    st.push('1'); 
    
    deleteMiddle(st, st.size()); 
    
    while(!st.empty()){ 
        char p=st.top();   v
        st.pop(); 
        cout << p << " "; 
    } 
    
    return 0; 
}