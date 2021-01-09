//Michael Dimapindan CPSC 131 Fall 2019

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iterator>     // std::next, std::prev

using std::string;
using std::ifstream;

struct Node {

  string urlData;
  size_t sizeData;

  Node* next;
  Node* prev;

};

class BrowserHistory {
public:
    BrowserHistory();

    void visitSite(string url, size_t filesize);
    void backButton();
    void forwardButton();

    void readFile(string fileName);

    string currentUrl();
    size_t currentPageSize();
    size_t getHistoryLength();

private:
  // TO BE COMPLETED

  Node* head;
  Node* tail;
  Node* current;

  string action;
  string url_;
  size_t size_;

};

Node* head = nullptr;
Node* tail = nullptr;
Node* current = nullptr;

//constructor
//create empty list (DLL) using a dummy node
BrowserHistory::BrowserHistory() {

  Node* newNode = new Node();
  newNode->prev = nullptr;
  newNode->next = nullptr;
  head = newNode;
  tail = newNode;
  current = newNode;

}

//visits a webpage with given URL and web page size
//insert a new node with data (URL, filesize)
void BrowserHistory::visitSite(string url, size_t filesize) {

  Node* newNode = new Node();
  newNode->urlData = url;
  newNode->sizeData = filesize;

  current->next = newNode;
  newNode->prev = current;

  //deleting next node(s) if inserting in middle of list
    while(tail != current) {

      tail = tail->prev;
      delete[] tail->next;

    }

  current = newNode;
  tail = newNode;
  newNode->next = nullptr;

}
//changes current to previous webpage; if no prev exists, stay on current page
void BrowserHistory::backButton() {

  //head is empty node
  if(current->prev == head) {

    current->prev = current->prev;

  }
  else {

    current = current->prev;

  }

}
//changes current to next webpage; if no next exists, stay on current page
void BrowserHistory::forwardButton() {

  if(current->next == nullptr) {

    current->next = current->next;

  }
  else {

  current = current->next;

}

}
//reads a text file of user's browsing history; should contain three words:
//visit, back and forward
//if action is 'visit', follow up with the url and page size
void BrowserHistory::readFile(string fileName) {

  ifstream inFile;
  inFile.open(fileName);

  while(inFile.good()){

    inFile >> action >> url_ >> size_;

    if(action == "visit"){
      visitSite(url_, size_);
    }
    else if(action == "back") {
      backButton();
    }
    else if(action == "forward") {
      forwardButton();
    }
  }

  inFile.close();

}
//return webpage's URL, return empty string if empty
string BrowserHistory::currentUrl() {

  return (current->urlData);

  string isEmpty = "Empty string";
  //head is empty node
  if (current == head) {

  return isEmpty;

  }

}
//return webpage's num of bytes, return 0 if empty
size_t BrowserHistory::currentPageSize() {

  return (current->sizeData);
  //head is empty node
  if(head == tail) {

  return 0;

}

}
//return length of browser's history, return 0 if empty
size_t BrowserHistory::getHistoryLength() {

  size_t count = 0;
  current = head; //head is empty node

  while (current->next != nullptr) {

    current = current->next;
    count++;

  }

  return count;

  //head is empty node
  if(head == tail) {

  return 0;

}

}
