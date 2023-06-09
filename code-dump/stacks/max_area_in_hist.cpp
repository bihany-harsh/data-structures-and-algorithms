#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int> &A)
{
    vector<int> nearest_smaller_left(A.size(), -1);
    vector<int> nearest_smaller_right(A.size(), A.size());

    stack<int> s;

    if (A.size() == 1)
        return A[0];

    for (int i = 0; i < A.size(); i++)
    {
        while (!s.empty() && A[s.top()] >= A[i])
            s.pop();
        if (!s.empty())
            nearest_smaller_left[i] = s.top();
        s.push(i);
    }

    while (!s.empty())
        s.pop();

    for (int i = A.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && A[s.top()] >= A[i])
            s.pop();
        if (!s.empty())
            nearest_smaller_right[i] = s.top();
        s.push(i);
    }

    int max_area = -1;

    for (int i = 0; i < A.size(); i++)
    {
        int area = A[i] * (nearest_smaller_right[i] - nearest_smaller_left[i] - 1);
        if (area > max_area)
            max_area = area;
    }

    return max_area;
}

int main()
{
    vector<int> A = {47, 69, 67, 97, 86, 34, 98, 16, 65, 95, 66, 69, 18, 1, 99, 56, 35, 9, 48, 72, 49, 47, 1, 72, 87, 52, 13, 23, 95, 55, 21, 92, 36, 88, 48, 39, 84, 16, 15, 65, 7, 58, 2, 21, 54, 2, 71, 92, 96, 100, 28, 31, 24, 10, 94, 5, 81, 80, 43, 35, 67, 33, 39, 81, 69, 12, 66, 87, 86, 11, 49, 94, 38, 44, 72, 44, 18, 97, 23, 11, 30, 72, 51, 61, 56, 41, 30, 71, 12, 44, 81, 43, 43, 27};
    cout << largestRectangleArea(A) << endl;
    return 0;
}