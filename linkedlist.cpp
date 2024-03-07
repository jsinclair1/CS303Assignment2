#include "linkedlist.h"

Linked::Linked() {
  head = nullptr;
  tail = nullptr;
  num_items = 0;
}

void Linked::push_back(int num) {
  //Create a new node (set data & pointer values)
  Node* newNode = new Node;
  newNode->data = num;
  newNode->next = nullptr; 
  num_items++;
  //if the list is empty, set head & tail pointers to new node
  if (head == nullptr){
    head = newNode;
    tail = newNode;
  }
  //else add node to the end
  else {
    tail->next = newNode;
    tail = newNode;
  }
}

void Linked::push_front(int num){
  //Create a new node (set data & pointer values)
  Node* newNode = new Node;
  newNode->data = num;
  //Set next ptr to head
  newNode->next = head;
  head = newNode;
  num_items++;
}

void Linked::print(){
  for (Node* curr = head; curr != nullptr; curr = curr->next){
    cout << curr->data << " ";
  }
}

void Linked::pop_front(){
  //if list is empty, do nothing
  if (head == nullptr){
    return;
  }
  else {
    //if list has only one node, delete it and set head & tail to nullptr
    if (head == tail){
      delete head;
      head = nullptr;
      tail = nullptr;
    }
    //else delete first node and set head to next node
    else {
      Node* temp = head;
      head = head->next;
      delete temp;
    }
    num_items--;
  }
}

void Linked::pop_back(){
  //if list is empty, do nothing
  if (tail == nullptr){
    return;
  }
  else {
    //if list has only one node, delete it and set head & tail to nullptr
    if (head == tail){
      delete head;
      head = nullptr;
      tail = nullptr;
      return;
    }
    //else delete last node and set tail to prev node
    else {
      Node* temp = head;
      while (temp->next != tail) {
        temp = temp->next;
      }
      delete tail;
      tail = temp;
      tail->next = nullptr;
      num_items--;
    }
  }
}
    

  
Node* Linked::front(){
  if (head == nullptr){
    return nullptr;
  }
  return head;
}

Node* Linked::back(){
  if (tail == nullptr){
    return nullptr;
  }
  else {
    return tail;
  }
}

bool Linked::is_empty(){
  if (head == nullptr && tail == nullptr){
    return true;
  }
  else {
    return false;
  }
}

void Linked::insert(size_t index, const Item_type &item){
  //if list is empty, insert at head
  if (head == nullptr || index == 0){
    push_front(item);
  }
  else {
    int currNode = 0;
    for (Node* curr = head; curr != nullptr; curr = curr->next){
      if (index == currNode){
        Node* newNode = new Node;
        newNode->data = item;
          if (curr->next == nullptr){
            curr->next = newNode;
            tail = newNode;
            newNode->next = nullptr;
          }
          else {
          newNode->next = curr->next;
          curr->next = newNode;
          }
      }
      else {
        currNode++;
        }
    }
  }  
}

bool Linked::remove(size_t index){
  //if list is empty, do nothing
  if (head == nullptr || index > num_items -1){
    return false;
  }
    //Pop front if index = 0
  else if (index == 0){
    pop_front();
    num_items--;
    return true;
  }
  //Iterate through list starting after head and increment value to match index
  int currNode = 1;
  for (Node* curr = head; curr != nullptr; curr = curr->next) {
    if (index == currNode){
      //If index == current Node index delete the next node 
      Node* temp = curr->next;
      curr->next = temp->next;
      delete temp;
      num_items--;
      return true;
    }
    else {
      currNode++;
    }
  }
  return false;
}

size_t Linked::find(const Item_type &item){
  int currNode = 0;
   //Iterate through list starting at head and increment value to match index
  for (Node* curr = head; curr != nullptr; curr = curr->next){
    if (curr->data == item){
      return currNode;
    }
    else {
      currNode++;
    }
  }
  return num_items;
}
    
