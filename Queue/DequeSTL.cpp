#include <iostream>
#include <deque>
using namespace std;

/*
push_back() -> Adds an element at the end of the deque.
push_front() -> Adds an element at the beginning of the deque.
pop_front() -> Removes the element at the beginning of the deque.
pop_back() -> Removes the element at the end of the deque.
front() -> Returns the element at the beginning of the deque.
back() -> Returns the element at the end of the deque.
size() -> Returns the number of elements in the deque.
empty() -> Returns true if the deque is empty, false otherwise.
clear() -> Removes all the elements from the deque.
Note: The deque is implemented as a doubly-ended queue, which allows efficient insertion and deletion at both ends.
*/

int main()
{
    deque<int> dq;

    dq.push_front(10);
    dq.push_back(20);
    dq.push_front(30);
    cout << "Front element is " << dq.front() << endl; // Output: Front element is 30
    cout << "Back element is " << dq.back() << endl;   // Output: Back element is 20

    dq.pop_front();
    cout << "Front element after popping is " << dq.front() << endl; // Output: Front element after popping is 20

    return 0;
}