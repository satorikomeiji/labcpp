#include "list.h"
#include <stddef.h>
list::list() {
  head = NULL;
  tail = NULL;
  faketail = NULL;
}
list::list(list const & l) {
  iterator it = l.begin();
  while (it != l.end()) {
    this->push_back(*it);
    it++;
  }
}
void list::push_back(int x) {
  Node* n = new Node();
  n->value = x;
  n->next = NULL;
  this->tail = NULL;
  if (this->head == NULL) {
    n->prev = NULL;
    this->head = n;
  }
  else {
    n->prev = faketail;
    faketail->next = n;
  }
  this->faketail = n;
}
void list::pop_back() {
  if (faketail == head) {
    head = NULL;
    faketail = NULL;
    delete faketail;
      
  }
  else {
    faketail = faketail->prev;
  
    delete faketail->next;
    faketail->next = NULL;
  }
}
int list::back() const {
  return faketail->value;
}
void list::push_front(int x) {
  Node* n = new Node();
  n->value = x;
  n->prev = NULL;
  if (head = NULL) {
    faketail = n;
  }
  else {
    head->prev = n;
  }
  n->next = head;
  head = n;
}
int list::front() const {
  return head->value;
}
iterator list::begin() const {
  iterator it;
  it.i = head;
  return  it;
}
iterator list::end() const {
  iterator it;
  it.i = faketail;
  return it;
}
void list::erase(iterator it) {
  Node * a = it.i;
  Node * nn = a->next;
  Node * pn = a->prev;
  if (nn == pn && nn == NULL) {
    delete a;
    head = NULL;
    faketail = NULL;
  }
  else if (nn == NULL) {
    a->prev->next = NULL;
    faketail= a->prev;
    delete a;
  }
  else if (pn == NULL) {
    a->next->prev = NULL;
    head = a->next;
    delete a;
  }
  else {
    a->prev->next = a->next;
    a->next->prev = a->prev;
    delete a;
  }
}
iterator list::insert(iterator it, int x) {
  Node* a = it.i;
  Node* nn = a->next;
    
  if (a-> next == NULL) {
    this->push_back(x);
  }
  else {
    Node * n = new Node ();
    n->value = x;
    n->prev = a;
    n->next = a->next;
    a->next = n;
    n->next->prev = n;
  }
}
int& iterator::operator*() const {
  return i->value;
}
iterator& iterator::operator++() {
  i = i->next;
  
  return  *this;
}
iterator iterator::operator++(int x) {
  i = i->next;
  return *this;
  
}
iterator& iterator::operator--() {
  i = i->prev;
  return *this;
}
iterator iterator::operator--(int x) {
  i = i->prev;
  return *this;
}
bool iterator::operator!=(iterator const & it) const {
  return this->i != it.i;
}
