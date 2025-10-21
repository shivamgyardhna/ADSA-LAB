#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *next;
  Node(int v) : data(v), next(NULL) {}
};

class LinkedList
{
  Node *head = NULL;

public:
  void insertEnd(int val)
  {
    Node *n = new Node(val);
    if (!head)
    {
      head = n;
      return;
    }
    Node *t = head;
    while (t->next)
      t = t->next;
    t->next = n;
  }
  void deleteVal(int val)
  {
    if (!head)
      return;
    if (head->data == val)
    {
      Node *d = head;
      head = head->next;
      delete d;
      return;
    }
    Node *t = head;
    while (t->next && t->next->data != val)
      t = t->next;
    if (t->next)
    {
      Node *d = t->next;
      t->next = d->next;
      delete d;
    }
  }
  void display()
  {
    for (Node *t = head; t; t = t->next)
      cout << t->data << " ";
    cout << "\n";
  }
  void search(int val)
  {
    int pos = 1;
    for (Node *t = head; t; t = t->next, pos++)
      if (t->data == val)
      {
        cout << "Found at position " << pos << "\n";
        return;
      }
    cout << "Not found\n";
  }
  void sortList()
  {
    for (Node *i = head; i; i = i->next)
      for (Node *j = i->next; j; j = j->next)
        if (i->data > j->data)
          swap(i->data, j->data);
  }
};

int main()
{
  LinkedList l;
  int ch, val;
  while (1)
  {
    cout << "1.Insert 2.Delete 3.Display 4.Search 5.Sort 6.Exit\n";
    cin >> ch;
    if (ch == 1)
    {
      cin >> val;
      l.insertEnd(val);
    }
    else if (ch == 2)
    {
      cin >> val;
      l.deleteVal(val);
    }
    else if (ch == 3)
      l.display();
    else if (ch == 4)
    {
      cin >> val;
      l.search(val);
    }
    else if (ch == 5)
      l.sortList();
    else if (ch == 6)
      break;
  }
}
