#ifndef LIST_H
#define LIST_H
struct Node {
  Node* next;
  Node* prev;
  int value;
};  

struct iterator {
  Node* i;
  int& operator*() const;
  iterator& operator++();
  iterator operator++(int);
  iterator& operator--();
  iterator operator--(int);
  bool operator!=(iterator const &) const;
};  
struct list {
  Node* head;
  Node* tail;
  Node* faketail;
  list();
  list(list const &);
  list & operator=(list const &);
  void push_back(int);
  void pop_back();
  int back() const;
  void push_front(int);
  int front() const;
  iterator begin() const;
  iterator end() const;
  void erase(iterator);
  iterator insert(iterator, int);
};

#endif
