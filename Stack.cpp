#include <iostream>
using namespace std;

class Stack
{
    int a[100], top;

public:
    Stack() : top(-1) {}

    // 1. Push
    void push(int v)
    {
        if (top == 99)
        {
            cout << "Overflow\n";
            return;
        }
        a[++top] = v;
    }

    // 2. Pop
    void pop()
    {
        if (top == -1)
        {
            cout << "Underflow\n";
            return;
        }
        top--;
    }

    // 3. Search
    void search(int v)
    {
        for (int i = 0; i <= top; i++)
        {
            if (a[i] == v)
            {
                cout << "Found at pos " << i + 1 << "\n"; // from bottom
                return;
            }
        }
        cout << "Not found\n";
    }

    // 4. Sort (Bubble Sort)
    void sortStack()
    {
        for (int i = 0; i <= top; i++)
        {
            for (int j = 0; j < top - i; j++)
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
        if (top == -1)
        {
            cout << "Empty\n";
            return;
        }
        for (int i = top; i >= 0; i--)
            cout << a[i] << " ";
        cout << "\n";
    }
};

int main()
{
    Stack st;
    int ch, v;
    while (true)
    {
        cout << "\n1.Push 2.Pop 3.Search 4.Sort 5.Display 6.Exit\n";
        cin >> ch;
        if (ch == 6)
            break;
        switch (ch)
        {
        case 1:
            cin >> v;
            st.push(v);
            break;
        case 2:
            st.pop();
            break;
        case 3:
            cin >> v;
            st.search(v);
            break;
        case 4:
            st.sortStack();
            break;
        case 5:
            st.display();
            break;
        }
    }
}
