/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
  Node* node5 = new Node(5, nullptr);
  Node* node4 = new Node(4, node5);
  Node* node3 = new Node(3, node4);
  Node* node2 = new Node(2, node3);
  Node* node1 = new Node(1, node2); // head of list

  Node* head = node1;


  Node* odds = nullptr;
  Node* evens = nullptr;

  split(head, odds, evens);
  cout << "Odds: " << endl;
  while (odds != nullptr)
  {
    cout << odds -> value << " " << endl;
    odds = odds -> next;
  }

  cout << "Evens: " << endl;
  while (evens != nullptr)
  {
    cout << evens -> value << " " << endl;
    evens = evens -> next;
  }

  delete node5;
  delete node4;
  delete node3;
  delete node2;
  delete node1;

}

