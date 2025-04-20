#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int val)
    {
        data = val;
        next = NULL;
    }
    ~Node()
    {
        // cout << "~Node " << data << endl;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};

class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = NULL;
        tail = NULL;
    }
    ~List()
    {
        // cout << "~List" << endl;
        if (head != NULL)
        {
            delete head;
            head = NULL;
        }
    }

public:
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
    void insert(int val, int pos)
    {
        if (pos == 0)
        {
            push_front(val);
            return;
        }
        Node *newNode = new Node(val);
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void printList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
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
    void pop_back()
    {
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }
    int searchItr(int key)
    {
        Node *temp = head;
        int idx = 0;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }
    int helper(Node *temp, int key)
    {
        if (temp == NULL)
        {
            return -1;
        }
        if (temp->data == key)
        {
            return 0;
        }
        int idx = helper(temp->next, key);
        if (idx == -1)
        {
            return -1;
        }
        return idx + 1;
    }
    int searchRec(int key)
    {
        return helper(head, key);
    }
    void reverse()
    {
        Node *current = head;
        Node *prev = NULL;

        while (current != NULL)
        {
            Node *next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    int getSize()
    {
        Node *temp = head;
        int size = 0;
        while (temp != NULL)
        {
            size++;
            temp = temp->next;
        }
        return size;
    }
    void removeNth(int n)
    {
        int size = getSize();
        Node *prev = head;
        for (int i = 1; i < (size - n); i++)
        {
            prev = prev->next;
        }
        Node *toDel = prev->next;
        cout << "going to delete " << toDel->data << endl;
        prev->next = prev->next->next;
    }
};

int main()
{
    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    // ll.printList(); // 1 -> 2 -> 3 -> NULL

    ll.push_back(4);
    ll.push_back(5);
    // ll.printList(); // 1 -> 2 -> 3 -> 4 -> 5 -> NULL

    // ll.insert(6, 2);
    // ll.printList(); // 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> NULL

    // ll.pop_front();
    // ll.printList(); // 2 -> 6 -> 3 -> 4 -> 5 -> NULL

    // ll.pop_back();
    // ll.printList(); // 2 -> 6 -> 3 -> 4 -> NULL

    // cout << ll.searchItr(4) << endl; // 3

    // cout << ll.searchRec(4) << endl; // 3

    // ll.printList();
    // ll.reverse();
    // ll.printList(); // 5 -> 4 -> 3 -> 2 -> 1 -> NULL

    ll.removeNth(2);
    ll.printList(); // 1 -> 2 -> 3 -> 5 -> NULL

    return 0;
}