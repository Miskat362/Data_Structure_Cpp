#include <iostream>
#include <vector>
#include <set>
using namespace std;

int countDistinct(vector<int> arr) {
    set<int> s;
    for(int i=0; i<arr.size(); i++) {
        s.insert(arr[i]); // insert each element into the set
    }
    
    for(int el : s) {
        cout << el << " ";
    }
    cout << endl;
    
    return s.size();
}

int main() {
    vector<int> arr = {4, 3, 2, 5, 6, 7, 3, 4, 2, 1};

    cout << countDistinct(arr) << endl; // should return 7 (1, 2, 3, 4, 5, 6, 7)

    return 0;
}