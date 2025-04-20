#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

// create stack using linked list
template <class T>
class Stack
{
    list<T> ll;

public:
    // push element into stack
    void push(T val)
    {
        ll.push_front(val);
    }
    // pop element from stack
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        ll.pop_front();
    }
    T top()
    {
        return ll.front();
    }
    bool isEmpty()
    {
        return ll.size() == 0;
    }
};

int main()
{
    Stack<int> s;

    s.push(3);
    s.push(2);
    s.push(1);

    while (!s.isEmpty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}