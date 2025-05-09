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
    void push_back(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
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

Node *splitAtMid(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *slow = head;
    Node *fast = head;
    Node *prev = NULL;

    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (prev != NULL)
    {
        prev->next = NULL; // split at middle
    }
    return slow; // slow = rightHead
}
Node *merge(Node *left, Node *right)
{
    List ans;
    Node *i = left;
    Node *j = right;

    while (i != NULL && j != NULL)
    {
        if (i->data <= j->data)
        {
            ans.push_back(i->data);
            i = i->next;
        }
        else
        {
            ans.push_back(j->data);
            j = j->next;
        }
    }
    while (i != NULL)
    {
        ans.push_back(i->data);
        i = i->next;
    }
    while (j != NULL)
    {
        ans.push_back(j->data);
        j = j->next;
    }
    return ans.head;
}
Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *rightHead = splitAtMid(head);

    Node *left = mergeSort(head);       // left head
    Node *right = mergeSort(rightHead); // right head

    return merge(left, right); // head of sorted LL
}
int main()
{
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_front(5);
    printList(ll.head); // 5 -> 4 -> 3 -> 2 -> 1 -> NULL

    ll.head = mergeSort(ll.head);
    printList(ll.head); // 1 -> 2 -> 3 -> 4 -> 5 -> NULL

    return 0;
}