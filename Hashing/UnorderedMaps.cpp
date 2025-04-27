#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> m;

    m["China"] = 150;
    m["Russia"] = 200;
    m["US"] = 50;
    m["Nepal"] = 20;

    for(auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    // count function
    cout << m.count("China") << endl; // 1
    cout << m.count("Bangladesh") << endl; // 0

    return 0;
}