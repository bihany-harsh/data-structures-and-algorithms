#include <iostream>
#include <stack>
#include <string>
using namespace std;

int longest_valid_substring(string str)
{
    int n = str.length();
    stack<int> stack_;

    stack_.push(-1);
    int result = 0;

    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(')
            stack_.push(i);
        else
        {
            if (!stack_.empty())
            {
                stack_.pop();
            }
             
            if (!stack_.empty())
                result = max(result, i - stack_.top());
 
            else
                stack_.push(i);
        }
    }

    return result;
}

int main()
{
    cout << longest_valid_substring("((()") << endl;
    cout << longest_valid_substring(")()())") << endl;
    cout << longest_valid_substring("()(()))))") << endl;

    return 0;
}