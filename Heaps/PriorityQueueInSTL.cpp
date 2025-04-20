#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq; // max heap by default
    //priority_queue<int, vector<int>, greater<int>> pq; // min heap

    pq.push(5);
    pq.push(10);
    pq.push(3);

    cout << "Top " << pq.top() << endl; // should print 10

    while(!pq.empty()) {
        cout << pq.top() << " "; // should print 10 5 3
        pq.pop();
    }
    return 0;
}