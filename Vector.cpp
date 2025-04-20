#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec1;
    vector<int> vec2 = {1, 2, 3, 4};
    vector<int> vec3(5, -1);
    cout << vec1.size() << endl;

    for (int i = 0; i < vec3.size(); i++)
    {
        cout << vec3[i] << " ";
    }

    return 0;
}