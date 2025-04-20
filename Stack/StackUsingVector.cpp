#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <class T>
// create stack using vector
class Stack
{
    vector<T> vec;

public:
    // push element into stack
    void push(T val)
    {
        vec.push_back(val);
    }
    // pop element from stack
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        vec.pop_back();
    }
    T top()
    {
        // if (isEmpty())
        // {
        //     cout << "Stack is empty" << endl;
        //     return -1;
        // }
        int lastIdx = vec.size() - 1;
        return vec[lastIdx];
    }
    bool isEmpty()
    {
        return vec.empty();
    }
};

int main()
{
    Stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);

    while (!s.isEmpty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}