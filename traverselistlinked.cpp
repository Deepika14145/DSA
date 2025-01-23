#include<iostream>
using namespace std;

struct Node{
      int data;
      Node* next;
      Node* prev;

      Node(int data) : data(data, next(nullprt), prev(nullptr){}
};

void forwardTraversal(Node* head){

    Node* curr = head;

    while(curr != nullptr){
          cout<<curr-> data <<" ";
          curr = curr-> next;
    }
    cout<<endl;
}

void backTraversal(Node* tail){
      Node* curr = tail;

      while(curr != nullptr){

            cout<<curr->data<<" ";
            curr = curr-> prev;
      }
cout<<endl;
}
