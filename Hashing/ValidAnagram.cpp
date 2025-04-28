#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

bool validAnagram(string s, string t) {
    // if the lengths of the strings are not equal, they cannot be anagrams
    if(s.size() != t.size()) {
        return false;
    }
    unordered_map<char, int> m;
    
    for(int i=0; i<s.size(); i++) {
        if(m.count(s[i])) {
            m[s[i]]++;
        } else {
            m[s[i]] = 1;
        }
    }
    // look for each character in t and decrement the count in the map
    for(int i=0; i<t.size(); i++) {
        if(m.count(t[i])) {
            m[t[i]]--;
            if(m[t[i]] == 0) {
                m.erase(t[i]);
            }
        } else {
            return false;
        }
    }
    
    return m.empty(); // if the map is empty, then s and t are anagrams
}

int main() {
    string s = "race",t = "care";
    string s1 = "tulip", t1 = "lipid";
    
    cout << validAnagram(s, t) << endl; // should return 1 (true)
    cout << validAnagram(s1, t1) << endl; // should return 0 (false)

    return 0;
}