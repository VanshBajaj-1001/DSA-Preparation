#include <bits/stdc++.h>
using namespace std;
class myQueue {

  public:
  stack<int> s1;
  stack<int> s2;
    myQueue() {
        // Initialize your data members
    }

    void enqueue(int x) {
        // Implement enqueue operation
        s1.push(x);
    }

    void dequeue() {
        // Implement dequeue operation
        if(s1.empty()) return;
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int front=s2.top();
        s2.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    int front() {
        // Implement front operation
        if(s1.empty()) return -1;
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int front=s2.top();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return front;
    }

    int size() {
        // Implement size operation
        return s1.size();
    }
};
/*
class MyQueue {
public:
        stack<int> s1;
        stack<int> s2;
    MyQueue() {
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        while(s1.empty()!=1){
            s2.push(s1.top());
            s1.pop();
        }
        int front=s2.top();
        s2.pop();
        while(s2.empty()!=1){
            s1.push(s2.top());
            s2.pop();
        }
        return front;
        
    }
    
    int peek() {
         while(s1.empty()!=1){
            s2.push(s1.top());
            s1.pop();
        }
        int front=s2.top();
        while(s2.empty()!=1){
            s1.push(s2.top());
            s2.pop();
        }
        return front;
    }
    
    bool empty() {
        return s1.empty();
    }
};

*/
