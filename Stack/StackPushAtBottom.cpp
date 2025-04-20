#include <iostream>
#include <stack>
using namespace std;

// Function to push a value at the bottom of a stack using recursion
void pushAtBottom(stack<int> &s, int value)
{
    // Base case: If the stack is empty, push the value
    if (s.empty())
    {
        s.push(value);
        return;
    }

    // Remove the top element
    int topValue = s.top();
    s.pop();

    // Recursively call the function with the remaining stack
    pushAtBottom(s, value);

    // Push the top element back to the stack
    s.push(topValue);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    int valueToPush = 0;
    pushAtBottom(s, valueToPush);

    cout << "Stack after pushing " << valueToPush << " at the bottom:" << endl;
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
