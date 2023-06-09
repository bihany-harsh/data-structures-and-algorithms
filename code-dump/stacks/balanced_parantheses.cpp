#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool is_balanced(string A){
    stack<char> s;
    int n = A.size();
    // (()())()
    for (int i = 0; i < n; i++)
    {
        if (A[i] == '(')
            s.push(A[i]);
        else if (A[i] == ')')
        {
            if (s.empty())
                return false;
            s.pop();
        }
    }
    return s.empty();
}

int main()
{
    string A = "(()())()";
    cout << is_balanced(A) << endl;
    return 0;
}