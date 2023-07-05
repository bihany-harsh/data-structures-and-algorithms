#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int longest_valid_parantheses(string A)
{
    int n = A.size();
    if (n <= 1)
        return 0;
    int result = 0;
    stack<int> s;
    s.push(-1);

    for (int i = 0; i < n; i++)
    {
        if (A[i] == '(')
            s.push(i);
        else
        {
            s.pop();
            if (s.empty())
                s.push(i);
            else
                result = max(result, i - s.top());
        }
    }
    return result;
}

int main()
{
    string str = "())()()(())))";
    cout << longest_valid_parantheses(str) << endl;
    return 0;
}