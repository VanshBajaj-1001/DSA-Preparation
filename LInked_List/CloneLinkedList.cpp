#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return head;
        }
        Node* curr=head;
        while(curr!=NULL){
            Node* clonenode=new Node(curr->val);
            clonenode->next=curr->next;
            curr->next=clonenode;
            curr=clonenode->next;
        }
        curr=head;
        while(curr!=NULL){
            if(curr->random!=NULL){
                curr->next->random=curr->random->next;
            }
                curr=curr->next->next;
        }
        curr=head;
        Node* cloneHead=head->next;
        while(curr!=NULL){
            Node* clonenode=curr->next;
            curr->next=clonenode->next;
if(clonenode->next!=NULL){
    clonenode->next=clonenode->next->next;
}
curr=curr->next;
        }
        return cloneHead;
    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
    Node* head=nullptr;
    Node* tail=nullptr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        Node* newnode=new Node(x);
        if(head==nullptr){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=tail->next;
        }
    }
    vector<Node*> nodes;
    Node* temp=head;
    while(temp!=NULL){
        nodes.push_back(temp);
        temp=temp->next;
    }
    for(int i=0;i<n;i++){
        int r;
        cin>>r;
        if(r!=-1){
            nodes[i]->random=nodes[r];
        }
    }
    Node* cloneHead=obj.copyRandomList(head);
    temp=cloneHead;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        if(temp->random!=NULL){
            cout<<"Random"<<temp->random->val;
        }
        else{
            cout<<"Random: NULL";
        }
        cout<<endl;
        temp=temp->next;
    }
    return 0;
}