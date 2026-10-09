#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(NULL), next(NULL) {}
 };


Node* reverseDLL(Node* head) {
    //write code here...
    Node* curr=head;
    Node* newhead=nullptr;
    while(curr!=NULL){
        Node* temp=curr->prev;
        curr->prev=curr->next;
        curr->next=temp;
        newhead=curr;
        curr=curr->prev;
    }
    return newhead;
}
int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    cout << "Enter node values: ";

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;

        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    head = reverseDLL(head);

    cout << "Reversed DLL: ";

    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }

    cout << endl;
    return 0;
}