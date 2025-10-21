#include <iostream>
using namespace std;

// Node structure
struct Node
{
  int data;
  Node *next;
  Node(int v) : data(v), next(NULL) {}
};

class CLL
{
  Node *last; // pointer to last node
public:
  CLL() : last(NULL) {}

  // 1. Insert at end
  void insertEnd(int v)
  {
    Node *n = new Node(v);
    if (!last)
    { // empty list
      last = n;
      last->next = last;
      return;
    }
    n->next = last->next;
    last->next = n;
    last = n;
  }

  // 2. Delete by value
  void delVal(int v)
  {
    if (!last)
      return; // empty
    Node *cur = last->next, *prev = last;
    do
    {
      if (cur->data == v)
      {
        if (cur == last && cur->next == last)
        { // only one node
          delete cur;
          last = NULL;
        }
        else
        {
          prev->next = cur->next;
          if (cur == last)
            last = prev;
          if (cur == last->next)
            last->next = cur->next;
          delete cur;
        }
        return;
      }
      prev = cur;
      cur = cur->next;
    } while (cur != last->next);
  }

  // 3. Traverse
  void display()
  {
    if (!last)
    {
      cout << "Empty\n";
      return;
    }
    Node *t = last->next;
    do
    {
      cout << t->data << " ";
      t = t->next;
    } while (t != last->next);
    cout << "\n";
  }

  // 4. Search element
  void search(int v)
  {
    if (!last)
    {
      cout << "Not found\n";
      return;
    }
    int pos = 1;
    Node *t = last->next;
    do
    {
      if (t->data == v)
      {
        cout << "Found at " << pos << "\n";
        return;
      }
      pos++;
      t = t->next;
    } while (t != last->next);
    cout << "Not found\n";
  }

  // 5. Sort ascending
  void sortList()
  {
    if (!last || last->next == last)
      return;
    Node *i = last->next;
    do
    {
      Node *j = i->next;
      while (j != last->next)
      {
        if (i->data > j->data)
          swap(i->data, j->data);
        j = j->next;
      }
      i = i->next;
    } while (i != last->next);
  }
};

int main()
{
  CLL cl;
  int ch, v;
  while (true)
  {
    cout << "\n1.Insert 2.Delete 3.Display 4.Search 5.Sort 6.Exit\n";
    cin >> ch;
    if (ch == 6)
      break;
    switch (ch)
    {
    case 1:
      cin >> v;
      cl.insertEnd(v);
      break;
    case 2:
      cin >> v;
      cl.delVal(v);
      break;
    case 3:
      cl.display();
      break;
    case 4:
      cin >> v;
      cl.search(v);
      break;
    case 5:
      cl.sortList();
      break;
    }
  }
}
