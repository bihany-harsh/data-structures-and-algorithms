#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> stock_span(vector<int> &prices)
{
    int n = prices.size();
    stack<int> s;

    vector<int> res(n);

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && prices[s.top()] <= prices[i])
            s.pop();
        
        res[i] = s.empty() ? i + 1 : i - s.top();
        s.push(i);
    }

    return res;
}

int main()
{
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    vector<int> res = stock_span(prices);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}