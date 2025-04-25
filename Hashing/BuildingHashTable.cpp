#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    string key;
    int val;
    Node* next;

    Node (string key, int val) {
        this->key = key;
        this->val = val;
        this->next = NULL;
    }
};

class HashTable {
    int totSIze;
    int currSize;
    Node** table;

    int hashFunction(string key) {
        int idx = 0;
        
        for (int i = 0; i < key.size(); i++) {
            idx += (key[i] * key[i]) % totSIze;
        }
        return idx%totSIze;
    }

    void rehash() {
        Node** oldTable = table;
        int oldSize = totSIze;

        totSIze *= 2;
        currSize = 0;
        table = new Node*[totSIze];
        for (int i = 0; i < totSIze; i++) {
            table[i] = NULL;
        }
        // copy old value
        for (int i = 0; i < oldSize; i++) {
            Node* temp = oldTable[i];
            while (temp != NULL) {
                insert(temp->key, temp->val);
                temp = temp->next;
            }
        }

        delete[] oldTable;
    }

public:
    HashTable(int size) {
        totSIze = size;
        currSize = 0;

        table = new Node*[totSIze];

        for (int i = 0; i < totSIze; i++) {
            table[i] = NULL;
        }
    }

    void insert(string key, int val) {
        int idx = hashFunction(key);

        Node* newNode = new Node(key, val);
        newNode->next = table[idx];
        table[idx] = newNode;
        currSize++;

        double lambda = currSize / (double)totSIze;
        if (lambda > 1) {
            rehash();
        }
    }

    void remove(string key) {
        int idx = hashFunction(key);
        Node* temp = table[idx];
        Node* prev = temp;

        while (temp != NULL) {
            if (temp->key == key) {
                if (prev == temp) {
                    table[idx] = temp->next;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
                currSize--;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    bool exists(string key) {
        int idx = hashFunction(key);
        Node* head = table[idx];

        while (head != NULL) {
            if (head->key == key) {
                return true;
            }
            head = head->next;
        }
        return false;
    }

    int search(string key) {
        int idx = hashFunction(key);
        Node* head = table[idx];

        while (head != NULL) {
            if (head->key == key) {
                return head->val;
            }
            head = head->next;
        }
        return -1; // Not found
    }

    void printTable() {
        for (int i = 0; i < totSIze; i++) {
            cout << "Index " << i << ": ";
            Node* head = table[i];
            while (head != NULL) {
                cout << head->key << ": " << head->val << " -> ";
                head = head->next;
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    HashTable ht(5);

    ht.insert("China", 150);
    ht.insert("Russia", 100);
    ht.insert("USA", 50);
    ht.insert("BD", 20);
    ht.insert("Brazil", 80);

    if(ht.exists("BD")) {
        cout << "BD Population: " << ht.search("BD") << endl;
    }

    ht.printTable();

    ht.remove("BD");
    cout << "After removing BD:" << endl;
    ht.printTable();

    return 0;
}