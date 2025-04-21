#include <iostream>
#include <vector> 
#include <string>
#include<queue>
using namespace std;

class Heap {
    vector<int> vec;    // max heap
public:
    void push(int val) {    // O(log n)
        vec.push_back(val);
        // fix heap
        int x = vec.size() - 1; // child index
        int parIdx = (x - 1) / 2; // parent index
        while (parIdx >= 0 && vec[x] > vec[parIdx]) {
            swap(vec[x], vec[parIdx]);
            x = parIdx;
            parIdx = (x - 1) / 2;
        }
    }

    void heapify(int idx) {
        if(idx >= vec.size())
            return; // base case

        int left = 2 * idx + 1; // left child index
        int right = 2 * idx + 2; // right child index
        int max = idx; 

        if (left < vec.size() && vec[left] > vec[max]) {
            max = left;
        }
        if (right < vec.size() && vec[right] > vec[max]) {
            max = right;
        }

        swap(vec[idx], vec[max]);
        if (max != idx) {
            heapify(max);
        }
    }

    void pop() {
        // step 1: swap first and last element
        swap(vec[0], vec[vec.size() - 1]);
        // step 2: remove last element
        vec.pop_back();
        // step 3: fix heap
        heapify(0); // O(log n)
    }

    int top() {   // O(1)
        return vec[0];
    }

    bool empty() {  // O(1)
        return vec.size() == 0;
    }
};

// Priority Queue for Objects
class Student {
public:
    string name;
    int marks;
    Student (string name, int marks) {
        this->name = name;
        this->marks = marks;
    }

    bool operator<(const Student& other) const {
        return this->marks < other.marks; // Higher marks have higher priority
    }
};

// Priority Queue for Pairs
struct ComparePair {
    bool operator()(const pair<string, int>& p1, const pair<string, int>& p2) {
        return p1.second < p2.second; // Higher second value has higher priority
    }
};

int main() {
    // Heap heap;
    // heap.push(10);
    // heap.push(20);
    // heap.push(5);
    // heap.push(30);

    // cout << "Top element: " << heap.top() << endl; // Should print 30
    // heap.pop();
    // cout << "Top element after pop: " << heap.top() << endl; // Should print 20

    // Priority Queue for Objects
    priority_queue<Student> pq;
    // priority_queue<pair<string, int>, vector<pair<string, int>>, ComparePair> pq; // pair

    pq.push(Student("Alice", 90));
    pq.push(Student("Bob", 85));
    pq.push(Student("Charlie", 95));
    pq.push(Student("David", 80));

    while(!pq.empty()) {
        cout << "top: " << pq.top().name << " , " << pq.top().marks << endl;
        pq.pop();
    }
    
    return 0;
}