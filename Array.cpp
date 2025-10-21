#include <iostream>
using namespace std;

class Arr
{
    int a[100], n; // array + size
public:
    Arr() : n(0) {}

    // 1. Insert at end
    void insertEnd(int v)
    {
        a[n++] = v;
    }

    // 2. Delete by value
    void delVal(int v)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] == v)
            {
                for (int j = i; j < n - 1; j++)
                    a[j] = a[j + 1];
                n--;
                return;
            }
        }
    }

    // 3. Search element
    void search(int v)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] == v)
            {
                cout << "Found at " << i + 1 << "\n";
                return;
            }
        }
        cout << "Not found\n";
    }

    // 4. Sort ascending (Bubble Sort)
    void sortArr()
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (a[j] > a[j + 1])
                {
                    int t = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = t;
                }
            }
        }
    }

    // 5. Display
    void display()
    {
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }
};

int main()
{
    Arr arr;
    int ch, v;
    while (true)
    {
        cout << "\n1.Insert 2.Delete 3.Search 4.Sort 5.Display 6.Exit\n";
        cin >> ch;
        if (ch == 6)
            break;
        switch (ch)
        {
        case 1:
            cin >> v;
            arr.insertEnd(v);
            break; // insert
        case 2:
            cin >> v;
            arr.delVal(v);
            break; // delete
        case 3:
            cin >> v;
            arr.search(v);
            break; // search
        case 4:
            arr.sortArr();
            break; // sort
        case 5:
            arr.display();
            break; // display
        }
    }
}
