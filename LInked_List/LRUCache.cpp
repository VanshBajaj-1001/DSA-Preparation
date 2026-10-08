#include <bits/stdc++.h>
using namespace std;
class LRUCache {
public:
struct Node{
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int k,int v){
    value=v;
    key=k;
    next=nullptr;
    prev=nullptr;
    }
};
int capacity;
unordered_map<int,Node*> mp;
Node* head;
Node* tail;
    LRUCache(int capacity) {
        this->capacity=capacity;
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
    }
    void add(Node* node){
        node->next=head->next;
        node->prev=head;
        head->next->prev=node;
        head->next=node;
    }
    void remove(Node* node){
        Node* previous=node->prev;
        Node* next=node->next;
        previous->next=next;
        next->prev=previous;
    }
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        Node* curr=mp[key];
        remove(curr);
        add(curr);
        return curr->value;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){//already exists
            Node* node=mp[key];
            node->value=value;
            remove(node);
            add(node);
            return ;
        }
        Node* newnode=new Node(key,value);
        mp[key]=newnode;
        add(newnode);
        if(mp.size()>capacity){
            Node* lru=tail->prev;
            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */