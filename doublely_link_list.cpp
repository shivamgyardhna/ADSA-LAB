#include <iostream>
using namespace std;

// Node structure for Doubly Linked List
struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int v) : data(v), prev(NULL), next(NULL) {} // constructor
};

// Doubly Linked List class
class DLL
{
    Node *head;
    Node *tail;

public:
    DLL() : head(NULL), tail(NULL) {} // initialize empty list

    // 1. Insert at end
    void insertEnd(int v)
    {
        Node *n = new Node(v);
        if (!head) // if list empty
        {
            head = tail = n;
            return;
        }
        tail->next = n; // link new node at end
        n->prev = tail;
        tail = n; // update tail
    }

    // 2. Delete by value
    void delVal(int v)
    {
        Node *t = head;
        while (t && t->data != v) // search node
            t = t->next;
        if (!t)
            return; // not found
        if (t->prev)
            t->prev->next = t->next;
        else
            head = t->next; // fix prev link
        if (t->next)
            t->next->prev = t->prev;
        else
            tail = t->prev; // fix next link
        delete t;           // free memory
    }

    // 3. Traverse forward
    void displayF()
    {
        for (Node *t = head; t; t = t->next) // move next
            cout << t->data << " ";
        cout << "\n";
    }

    // 4. Traverse reverse
    void displayR()
    {
        for (Node *t = tail; t; t = t->prev) // move prev
            cout << t->data << " ";
        cout << "\n";
    }

    // 5. Search element
    void search(int v)
    {
        int pos = 1;
        Node *t = head;
        while (t) // check each node
        {
            if (t->data == v)
            {
                cout << "Found at " << pos << "\n";
                return;
            }
            t = t->next;
            pos++;
        }
        cout << "Not found\n";
    }

    // 6. Sort ascending
    void sortList()
    {
        for (Node *i = head; i; i = i->next) // bubble-like sort
            for (Node *j = i->next; j; j = j->next)
                if (i->data > j->data)
                    swap(i->data, j->data);
    }
};

int main()
{
    DLL dl;
    int ch, v;
    while (true)
    {
        cout << "\n1.Insert 2.Delete 3.Fwd 4.Rev 5.Search 6.Sort 7.Exit\n";
        cin >> ch;
        if (ch == 7)
            break; // exit program
        switch (ch)
        {
        case 1:
            cin >> v;
            dl.insertEnd(v);
            break;
        case 2:
            cin >> v;
            dl.delVal(v);
            break;
        case 3:
            dl.displayF();
            break;
        case 4:
            dl.displayR();
            break;
        case 5:
            cin >> v;
            dl.search(v);
            break;
        case 6:
            dl.sortList();
            break;
        }
    }
}
