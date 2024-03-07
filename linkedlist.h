#pragma once
#include <iostream>
using namespace std;
  
struct Node {
  int data;
  Node* next;
};

typedef int Item_type;

class Linked {
  private:
    Node* head;
    Node* tail;
    int num_items;
  public:
    Linked();
    void push_front(int num);
    void push_back(int num);
    void pop_front();
    void pop_back();
    void print();
    Node* front();
    Node* back();
    bool is_empty();
    void insert(size_t index, const Item_type& item);
    bool remove(size_t index);
    size_t find(const Item_type& item);


};

