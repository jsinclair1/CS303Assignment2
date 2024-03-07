#pragma once
#include <vector>
#include "linkedlist.h"

class Stacked {
  private:
    vector<int> integers;
    int head;
  public:
    Stacked();
    bool is_empty();
    void insert(const Item_type& item);
    void remove();
    int get_top();
    float get_average();
    void print();
};
