#include <iostream>
#include <climits>
using namespace std;

int trapRainWater(int *height, int n)
{
    int leftMax[20000];
    leftMax[0] = height[0];
    // cout << leftMax[0] << ",";
    for (int i = 1; i < n; i++)
    {
        leftMax[i] = max(leftMax[i - 1], height[i - 1]);
        // cout << leftMax[i] << ",";
    }
    int rightMax[20000];
    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        rightMax[i] = max(rightMax[i + 1], height[i + 1]);
        // cout << rightMax[i] << ",";
    }
    // cout << rightMax[n - 1] << ",";
    int totalWater = 0;
    for (int i = 0; i < n; i++)
    {
        int curWater = min(leftMax[i], rightMax[i]) - height[i];
        if (curWater > 0)
        {
            totalWater += curWater;
        }
        // cout << totalWater << ",";
    }
    return totalWater;
}

int main()
{
    int height[] = {4, 2, 0, 6, 3, 2, 5};
    int n = sizeof(height) / sizeof(int);

    trapRainWater(height, n);
    cout << "Total water trapped is: " << trapRainWater(height, n) << endl;

    return 0;
}