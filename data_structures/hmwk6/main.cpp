#include <iostream>
#include <string>
using namespace std;

struct Node {

  int data;
  Node* next;
  Node(int data) {

    this->data = data;
    next = NULL;

  }

};

struct LinkedList {

  Node* head;
  LinkedList() {

    head = NULL;

  }

//reverse the sublist; add base case to stop reverse
Node* reverse(Node* curNode) {

  //base case
  if(curNode == NULL) {

    return NULL;

  }

  if(curNode->next == NULL) {

    head = curNode;
    return curNode;

  }

  Node* newNode = reverse(curNode->next); //recursive step
  newNode->next = curNode;
  curNode->next = NULL;
  return curNode;

}

LinkedList::push(int data) {

  Node* temp = new Node(data);
  temp->next;
  head = temp;

}

};

int main() {

  LinkedList lL;

  lL.push(0);
  lL.push(2);
  lL.push(4);
  lL.push(9);
  lL.push(6);

  //regular linked list
  Node* temp = head;
  while(temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }

  lL.reverse(lL.head);

  //reversed linked list
  Node* temp = head;
  while(temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }

  return 0;

}
