#include <iostream>
#include <deque>
using namespace std;

class Stack
{
    deque<int> dq;

public:
    void push(int data)
    {
        dq.push_front(data);
    }
    void pop()
    {
        if (dq.empty())
        {
            cout << "Stack is empty\n";
            return;
        }
        dq.pop_front();
    }
    int top()
    {
        if (dq.empty())
        {
            cout << "Stack is empty\n";
            return -1;
        }
        return dq.front();
    }
    bool empty()
    {
        return dq.empty();
    }
};

int main()
{
    Stack s;
    for (int i = 1; i <= 10; i++)
    {
        s.push(i);
    }

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}