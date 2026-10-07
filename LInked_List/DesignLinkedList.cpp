#include <bits/stdc++.h>
using namespace std;
class MyLinkedList {
public:
struct Node{
    int val;
    Node* next;
    Node(int x){
        val=x;
        next=nullptr;
    }
};
Node* head;
int size;
    MyLinkedList() {
        head=nullptr;
        size=0;
    }
    
    int get(int index) {
        if(index<0||index>=size){
            return -1;
        }
        Node* curr=head;
        for(int i=0;i<index;i++){
            curr=curr->next;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        Node* newnode=new Node(val);
        newnode->next=head;
        head=newnode;
        size++;
    }
    
    void addAtTail(int val) {
        Node* newnode=new Node(val);
        if(head==nullptr){
            head=newnode;
            size++;
            return;
        }
        Node* curr=head;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=newnode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index<0||index>size){
            return ;
        }
        if(index==0){
            addAtHead(val);
            return;
        }
        Node* curr=head;
        Node* newnode=new Node(val);
        for(int i=0;i<index-1;i++){
curr=curr->next;
        }
        newnode->next=curr->next;
        curr->next=newnode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index<0||index>=size){
            return;
        }
        if(index==0){
            Node*temp=head;
            head=head->next;
            delete temp;
            size--;
            return;
        }
        Node* curr=head;
    for(int i=0;i<index-1;i++){
        curr=curr->next;
    }
    Node* temp=curr->next;
    curr->next=temp->next;
    delete temp;
    size--;

    }
};

