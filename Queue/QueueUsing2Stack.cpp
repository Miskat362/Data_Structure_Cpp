#include <iostream>
#include <stack>
using namespace std;

class Queue // FIFO
{
    stack<int> s1, s2;

public:
    void push(int data) // O(n)
    {
        // s1 -> s2
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        // push data to s1
        s1.push(data);
        // s2 -> s1
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    void pop() // O(1)
    {
        s1.pop();
    }
    int front() // O(1)
    {
        return s1.top();
    }
    bool empty() // O(1)
    {
        return s1.empty();
    }
};

int main()
{
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    cout << "Front element is: " << q.front() << endl;

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}