#include "stack.h"
#include <iostream>
using namespace std;

Stacked::Stacked(){
  vector<int> integers = {};
}

bool Stacked::is_empty(){
  if (integers.size() == 0){
    return true;
  }
  else {
    return false;
  }
}

void Stacked::insert(const Item_type &item){
  //Will insert at back of vector, which is the top of the stack
  integers.push_back(item);
  head = item;
}

void Stacked::remove() {
  //Remove top of stack and set head to prev node
  integers.pop_back();
  head = integers.back();
}

int Stacked::get_top() {
  return head;
}

float Stacked::get_average(){
  float sum = 0;
  for (int i = 0; i < integers.size(); i++){
    sum += integers[i];
  }
  return sum / integers.size();
}

void Stacked::print(){
  for (int i = 0; i < integers.size(); i++){
    cout << integers[i] << " ";
  }
}