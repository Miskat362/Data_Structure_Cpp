#include <iostream>
#include <list>
#include <iterator>
using namespace std;

void printList(list<int> ll)
{
    list<int>::iterator itr;
    for (itr = ll.begin(); itr != ll.end(); itr++)
    {
        cout << *itr << " -> "; // prints: 1 2 3 4
    }
    cout << "NULL" << endl; // prints: NULL
}

int main()
{
    list<int> ll;
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(3);
    ll.push_back(4);
    // 1->2->3->4

    printList(ll);
    cout << ll.size() << endl;

    cout << "Head: " << ll.front() << endl;
    cout << "Tail: " << ll.back() << endl;

    ll.pop_front(); // 2->3->4
    printList(ll);

    ll.pop_back(); // 2->3
    printList(ll);

    return 0;
}