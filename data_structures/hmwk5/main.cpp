#include <cmath>    //pow()
#include <cstddef>  //size_t
#include <iostream>
#include <vector>
#include <forward_list>

#include "SinglyLinkedList.hpp"

using std::cout;
using std::endl;
using std::forward_list;
using std::pow;
using std::size_t;
using std::vector;

class PolyTerm {

private:
  int _order = 0;
  double _coeff = 0.0;

public:
  PolyTerm() = default;
  PolyTerm(int order, double coefficient) : _order(order), _coeff(coefficient)
  {}

  void setOrder(int order) {_order = order;}
  void setCoeff(double coeff) {_coeff = coeff;}

  int getOrder() const {return _order;}
  double getCoeff() const {return _coeff;}

};

  double evaluate(const vector<double> & coefficients, double x) {
    //to be implemented
    int size;
    double sum = 0.0;
    double exponent = 1.0;
    vector<double> arrayNums = coeffecients;

    for(int i = 0; i < arrayNums; i++) {

      sum += exponent*arrayNums[i];
      exponent *= x;

    }

    return sum;

  }

  double evaluate(const forward_list<PolyTerm> & terms, double x) {
    //to be implemented

    forward_list<PolyTerm> fListNums = terms;

    double sum = 0.0;
    double expo = 1.0;

    for(int& i : fListNums) {

      sum += i*expo;
      expo *= x;

    }

    return sum;

  }

  //intentionally pass by value (there is no size() or end() function to indicate
  //we've visited all nodes)
  double evaluate(SinglyLinkedList<PolyTerm> terms, double x) {
    //to be implemented

    Node* head = nullptr;

    double* sum = new double;
    double exponent = 1.0;

    SinglyLinkedList<PolyTerm> SLLnums = terms;

    for(int i = 0; i < SLLnums; i++) {

      void SinglyLinkedList<PolyTerm>::append(&head, SLLnums[i]);

      *sum = *sum + head->data;

    }

    return sum;

  }

  int main() {

    //polynomial function y = 3.5*x^7 + 2.2 using array; this function is the
    //same as 2.2*x^0 + 0*x^1 + 0*x^2 + ... + 0*x^6 + 3.5*x^7
    vector<double> polyArray = {2.2, 0, 0, 0, 0, 0, 0, 3.5};

    cout << evaluate(polyArray, 1.0) << endl;
    cout << evaluate(polyArray, 2.0) << endl;

    //polynomial function y = 3.5*x^7 + 2.2 using STL's singly linked list
    forward_list<PolyTerm> polyForwardList = {{0, 2.2}, {7, 3.5}};

    cout << evaluate(polyForwardList, 1.0) << endl;
    cout << evaluate(polyForwardList, 2.0) << endl;

    //polynomial function using zyBook inspired linked list
    SinglyLinkedList<PolyTerm> polyLinkedList;

    //develop your initialization part here
    //to be implemented

    polyLinkedList = {
      
      struct Node* head = NULL;

      double sum = 0.0;

      push(&head, 2.2);
      push(&head, 0.0);
      push(&head, 0.0);
      push(&head, 0.0);
      push(&head, 0.0);
      push(&head, 0.0);
      push(&head, 0.0);
      push(&head, 3.5);

    }

    //evaluate your polynomial
    cout << evaluate(polyLinkedList, 1.0) << endl;
    cout << evaluate(polyLinkedList, 2.0) << endl;

    return 0;

  }
