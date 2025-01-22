#include<iostream>
using namespace std;

class Node{
public:
  int data;
  Node* next;

  Node(int x){
      this->data = x;
      this->next = nullptr;
  }
};

int getLength(Node* head){
  int length = 0;

  while(head){
      length++;
      head = head -> next;
  }
  return length;
}

int getMiddle(Node* head){
  int length = getLength(head);

  int mid_index = length / 2;
  while(mid_index--){
      head = head -> next;
  }

int main(){

    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout<< getMiddle(head);

    return 0;

}
