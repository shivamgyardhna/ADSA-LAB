/*
Write a menu-driven C++ program to implement a Queue using arrays with the following operations:
1.Enqueue (Insert an element into the queue)
2.Dequeue (Remove an element from the queue)
3.Search (Check if a given element exists in the queue)
4.Display (Show all elements of the queue)
5.Sort (Arrange the elements of the queue in ascending order)
6.Exit the program
*/

#include <iostream>
    using namespace std;

    class Queue
    {
      int front, rear, size, *arr;

    public:
      // Constructor: initialize queue
      Queue(int s) : size(s), front(-1), rear(-1) { arr = new int[size]; }
      ~Queue() { delete[] arr; } // Destructor: free memory

      bool isEmpty() { return front == -1; }               // Check if queue is empty
      bool isFull() { return (rear + 1) % size == front; } // Check if queue is full

      // Insert element at rear
      void enqueue(int val)
      {
        if (isFull())
          return void(cout << "Queue full!\n");
        if (isEmpty())
          front = 0;              // First insertion → set front
        rear = (rear + 1) % size; // Circular increment
        arr[rear] = val;
      }

      // Remove element from front
      void dequeue()
      {
        if (isEmpty())
          return void(cout << "Queue empty!\n");
        cout << "Dequeued: " << arr[front] << "\n";
        (front == rear) ? front = rear = -1 // If only 1 element → reset
                        : front = (front + 1) % size;
      }

      // Search for an element in queue
      void search(int val)
      {
        if (isEmpty())
          return void(cout << "Queue empty!\n");
        for (int i = front;; i = (i + 1) % size)
        {
          if (arr[i] == val)
            return void(cout << val << " found at index " << i << "\n");
          if (i == rear)
            break; // stop after last element
        }
        cout << val << " not found.\n";
      }

      // Display all elements
      void display()
      {
        if (isEmpty())
          return void(cout << "Queue empty!\n");
        cout << "Queue: ";
        for (int i = front;; i = (i + 1) % size)
        {
          cout << arr[i] << " ";
          if (i == rear)
            break;
        }
        cout << "\n";
      }

      // Sort queue elements (ascending order)
      void sort()
      {
        if (isEmpty())
          return void(cout << "Queue empty!\n");
        for (int i = front; i != rear; i = (i + 1) % size)
        {
          for (int j = (i + 1) % size; j != (rear + 1) % size; j = (j + 1) % size)
          {
            if (arr[i] > arr[j])
              swap(arr[i], arr[j]);
          }
        }
        cout << "Queue sorted.\n";
      }
    };

    int main()
    {
      int size, choice, val;
      cout << "Enter queue size: ";
      cin >> size;
      Queue q(size);

      // Menu loop
      do
      {
        cout << "\n--- Menu ---\n";
        cout << "1.Enqueue\n2.Dequeue\n3.Search\n4.Display\n5.Sort\n6.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
          cout << "Enter value: ";
          cin >> val;
          q.enqueue(val);
          break;
        case 2:
          q.dequeue();
          break;
        case 3:
          cout << "Enter value: ";
          cin >> val;
          q.search(val);
          break;
        case 4:
          q.display();
          break;
        case 5:
          q.sort();
          break;
        case 6:
          cout << "Exiting...\n";
          break;
        default:
          cout << "Invalid choice!\n";
        }
      } while (choice != 6);
    }
