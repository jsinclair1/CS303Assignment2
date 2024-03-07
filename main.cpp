#include <iostream>
#include "linkedlist.h"
#include "stack.h"
using namespace std;

int main() {
  
  Linked list;
  //Insert nums in list
  list.push_back(3);
  list.push_front(2);
  list.push_back(4);
  list.push_front(1);
  cout << "My linked list: " << endl;
  list.print();
  
  list.pop_back();
  cout << endl << "After pop_back: ";
  list.print();
  cout << endl;

  cout << "Head: " << list.front()->data << endl;
  cout << "Tail: " << list.back()->data << endl;
  
  list.pop_front();
  cout << endl << "After pop_front: ";
  list.print();

  cout << endl;
  //list.insert(1, 10);
  //list.print();
  list.remove(3);
  cout << endl;

  int num = 100;
  list.push_back(num);
  list.print();
  cout << endl << "Number: " << num << " is at index " << list.find(100);


  Stacked stack;
  cout << endl << endl << "My stack: " << endl;
  
  stack.insert(16);
  stack.insert(5);
  stack.insert(3);
  stack.insert(40);
  stack.print();
  cout << endl;
  cout << "Top: " << stack.get_top();
  stack.remove();
  cout << endl;
  cout << "Top after removal: " << stack.get_top() << endl;
  stack.print();

  cout << endl << "Average: " << stack.get_average() << endl;
  cout << stack.is_empty() << endl;
  
  return 0;
}