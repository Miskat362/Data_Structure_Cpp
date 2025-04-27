#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> s;

    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);

    cout << "Size: " << s.size() << endl; // 4

    if(s.find(2) != s.end()) {
        cout << "2 is present" << endl; // 2 is present
    } else {
        cout << "2 is not present" << endl;
    }

    s.erase(2); // remove 2
    cout << "Size after erasing 2: " << s.size() << endl; // 3

    if(s.find(2) != s.end()) {
        cout << "2 is present" << endl;
    } else {
        cout << "2 is not present" << endl; // 2 is not present
    }

    printf("Elements in the set: ");
    for(auto el : s) {
        cout << el << " "; // 1 3 4
    }

    return 0;
}