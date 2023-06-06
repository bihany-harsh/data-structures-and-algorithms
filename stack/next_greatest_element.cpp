#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> next_greatest_element(vector<int> &arr)
{
    int n = arr.size();
    stack<int> s;
    vector<int> res(n);

    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= arr[i])
            s.pop();

        res[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }

    return res;
}

vector<int> next_smallest_element(vector<int> &arr)
{
    int n = arr.size();
    stack<int> s;
    vector<int> res(n);

    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() >= arr[i])
            s.pop();

        res[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }

    return res;
}

int main()
{
    vector<int> arr = {1, 3, 0, 0, 1, 2, 4};
    vector<int> res1 = next_greatest_element(arr);
    vector<int> res2 = next_smallest_element(arr);

    for (int i = 0; i < res1.size(); i++)
    {
        cout << res1[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < res2.size(); i++)
    {
        cout << res2[i] << " ";
    }
    cout << endl;

    return 0;
}