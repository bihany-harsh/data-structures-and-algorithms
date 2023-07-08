#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

bool is_operator(string &exp) {
    if (exp == "+" || exp == "-" || exp == "*" || exp == "/")
        return true;
    else
        return false;
}


void operate(stack<int> &s, int num1, int num2, string &op) {
    if (op == "+")
        s.push((num1 + num2));
    else if (op == "-")
        s.push(num1 - num2);
    else if (op == "*")
        s.push(num1 * num2);
    else
        s.push(num1 / num2);
}

int expression_eval(vector <string> &expression) {
    stack<int> num_stack;
    for (auto exp: expression) {
        if (is_operator(exp)) {
            int num2 = num_stack.top();
            num_stack.pop();
            int num1 = num_stack.top();
            num_stack.pop();
            operate(num_stack, num1, num2, exp);
        } else {
            num_stack.push(stoi(exp));
        }
    }
    return num_stack.top();
}

int main() {
    vector<string> expression = {"2", "1", "+", "3", "*"};
    cout << expression_eval(expression) << endl;
    return 0;
}
