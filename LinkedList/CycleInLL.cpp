#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class List
{
public:
    Node *head;
    Node *tail;

    List()
    {
        head = NULL;
        tail = NULL;
    }
    void push_front(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    void pop_front()
    {
        if (head == NULL)
        {
            cout << "LL is empty" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
};
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

bool isCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            cout << "cycle exists" << endl;
            return true;
        }
    }
    cout << "No cycle exists" << endl;
    return false;
}

// remove cycle from the list
void removeCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    bool isCycle = false;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            cout << "Cycle exists " << endl;
            isCycle = true;
            break; // cycle exist
        }
    }
    if (!isCycle)
    {
        cout << "Cycle doesn't exist" << endl;
        return;
    }

    slow = head;
    if (slow == fast)
    { // special case : tail -> head
        while (fast->next != slow)
        {
            fast = fast->next;
        }
        fast->next = NULL;
    }
    else
    {
        Node *prev = fast;
        while (slow != fast->next)
        {
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }
        fast->next = NULL;
    }
}

int main()
{
    List ll;
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.tail->next = ll.head;

    // isCycle(ll.head);

    removeCycle(ll.head);
    printList(ll.head);

    return 0;
}