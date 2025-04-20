#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverse(queue<int> &q)
{
    stack<int> s;
    // Move elements from queue to stack
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    // Move elements from stack back to queue
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}

int main()
{
    queue<int> q;
    for (int i = 1; i <= 5; i++)
    {
        q.push(i);
    }

    reverse(q);
    cout << "Reversed queue: ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}