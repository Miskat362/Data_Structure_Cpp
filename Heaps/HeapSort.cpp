#include <iostream>
#include <vector>
#include<queue>
using namespace std;

// Function to heapify a subtree rooted at index i
void heapify(int i, vector<int>& arr, int n) {
    int left = 2 * i + 1; // left child index
    int right = 2 * i + 2; // right child index
    int maxI = i; 

    if (left < n && arr[left] > arr[maxI]) {
        maxI = left;
    }
    if (right < n && arr[right] > arr[maxI]) {
        maxI = right;
    }

    if (maxI != i) {
        swap(arr[i], arr[maxI]);
        heapify(maxI, arr, n); 
    }
}

// Function to perform heap sort
void heapSort(vector<int>& arr) {
    int n = arr.size();
    // step 1: Build a max heap
    for(int i = n/2 - 1; i >= 0; i--) {
        heapify(i, arr, n);
    }
    // step 2: Extract elements from heap one by one
    for(int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]); // move current root to end
        heapify(0, arr, i); // call max heapify on the reduced heap
    }
}

int main() {
    vector<int> arr = {1, 4, 2, 5, 3};

    heapSort(arr); // O(n log n)

    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}