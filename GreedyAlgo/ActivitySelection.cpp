#include <iostream>
#include <vector>
using namespace std;

int maxActivities(vector<int> start, vector<int> end)
{
    // sort in end time
    // select A0
    cout << "selecting A0" << endl;
    int count = 1;
    int currEndTime = end[0];

    for (int i = 1; i < start.size(); i++)
    {
        if (start[i] >= currEndTime) // Non-overlapping
        {
            cout << "selecting A" << i << endl;
            count++;
            currEndTime = end[i];
        }
    }

    return count;
}

int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    cout << maxActivities(start, end) << endl;

    return 0;
}