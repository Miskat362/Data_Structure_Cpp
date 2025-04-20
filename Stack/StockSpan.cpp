#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void stockSpan(vector<int> stock, vector<int> span)
{
    stack<int> s;
    s.push(0);
    span[0] = 1;

    for (int i = 1; i < stock.size(); i++)
    {
        int currPrice = stock[i];
        while (!s.empty() && currPrice >= stock[s.top()])
        {
            s.pop();
        }
        if (s.empty())
        {
            span[i] = i + 1;
        }
        else
        {
            int prevHigh = s.top();
            span[i] = i - prevHigh;
        }
    }
    for (int i = 0; i < span.size(); i++)
    {
        // cout << "Stock Price: " << stock[i] << ", Span: " << span[i] << endl;
        cout << span[i] << " ";
    }
}

int main()
{
    vector<int> stock = {100, 80, 60, 70, 60, 85, 100};
    vector<int> span = {0, 0, 0, 0, 0, 0, 0};

    stockSpan(stock, span);

    return 0;
}