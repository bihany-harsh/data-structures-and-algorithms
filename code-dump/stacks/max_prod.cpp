#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int maxSpecialProduct(vector<int> &A)
{
    const int MOD = 1000000007;
    vector<int> nearest_greater_left(A.size(), -1);
    vector<int> nearest_greater_right(A.size(), -1);

    stack<int> s;
    for (int i = 0; i < A.size(); i++)
    {
        while (!s.empty() && A[s.top()] <= A[i])
            s.pop();
        if (!s.empty())
            nearest_greater_left[i] = s.top();
        s.push(i);
    }

    while (!s.empty())
        s.pop();
    
    for (int i = A.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && A[s.top()] <= A[i])
            s.pop();
        if (!s.empty())
            nearest_greater_right[i] = s.top();
        s.push(i);
    }

    long long int max_prod = -1;

    for (int i = 0; i < A.size(); i++)
    {
        long long int prod = nearest_greater_left[i] * nearest_greater_right[i];
        if (prod > max_prod)
            max_prod = prod;
    }

    if (max_prod <= 0)
        return 0;
    return max_prod % MOD;
}