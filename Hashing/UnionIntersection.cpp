#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

//union of two arrays -- O(n+m) time complexity
void unionArrays(vector<int> arr1, vector<int> arr2) {
    unordered_set<int> s;

    // insert all elements of arr1 into the set
    for(int el : arr1) {
        s.insert(el);
    }
    for(int el : arr2) {
        s.insert(el);
    }
    for(int el : s) {
        cout << el << " ";
    }
    cout << endl;
}

// intersection of two arrays -- O(n+m) time complexity
void intersectionArrays(vector<int> arr1, vector<int> arr2) {
    unordered_set<int> s;
    // insert all elements of arr1 into the set
    for(int el : arr1) {
        s.insert(el);
    }
    // check if each element of arr2 is in the set
    for(int el : arr2) {
        if(s.find(el) != s.end()) {
            cout << el << " ";
            s.erase(el); // remove the element from the set to avoid duplicates in the intersection
        }
    }
    cout << endl;
}

int main() {
    vector<int> arr1 = {7, 3, 9};
    vector<int> arr2 = {6, 3, 9, 2, 9, 4};

    cout << "Union: ";
    unionArrays(arr1, arr2); // should return 7 3 9 6 2 4

    cout << "Intersection: ";
    intersectionArrays(arr1, arr2); // should return 3 9

    return 0;
}