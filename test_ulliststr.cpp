#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr list;
  
  list.push_back("1");
  list.pop_back();

  list.push_front("2");
  list.pop_front();

  list.push_front("3");
  list.push_back("4");

  cout << list.front() << endl;
  cout << list.back() << endl;


  cout << "Size: " << list.size() <<endl;
}

