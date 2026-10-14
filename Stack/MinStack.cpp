#include <bits/stdc++.h>
using namespace std;
class MinStack {
public:
       stack<int> st;
       stack<int> minimum;
    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);
        if(minimum.empty()){
            minimum.push(value);
        }
        else{
            minimum.push(min(value,minimum.top()));
        }
    }
    
    void pop() {
        st.pop();
        minimum.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minimum.top();
    }
};

