#include <iostream>
#include <vector>
using namespace std;

int coinChange(vector<int> coins, int amount)
{
    int ans = 0;
    int n = coins.size();

    for (int i = n - 1; i >= 0, amount > 0; i--)
    {
        if (amount >= coins[i])
        {
            ans += amount / coins[i];
            amount %= coins[i]; // to get the remaining amount after the coin is used up.
        }
    }
    cout << "Minimum coin used " << ans << endl;
    return ans;
}

int main()
{
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 2000};
    int amount = 590;

    coinChange(coins, amount);

    return 0;
}