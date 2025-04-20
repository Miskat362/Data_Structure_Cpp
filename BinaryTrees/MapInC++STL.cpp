#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<int, string> m;

    m[101] = "alif";
    m[110] = "ali";
    m[131] = "alif";

    cout << m[101] << endl;

    cout << m.count(101) << endl;
    cout << m.count(100) << endl;

    // loop in map
    for (auto it : m)
    {
        cout << "key = " << it.first << ", value = " << it.second << endl;
    }

    return 0;
}