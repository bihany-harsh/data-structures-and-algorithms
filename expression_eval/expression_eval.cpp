#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;

int inside_stack_priority(char operand)
{
    if (operand == '+' || operand == '-')
    {
        return 1;
    }
    else if (operand == '*' || operand == '/')
    {
        return 2;
    }
    else if (operand == '^')
    {
        return 3;
    }
    else if (operand == '(')
    {
        return 0;
    }
    else if (operand == '$')
    {
        return -2;
    }
    else
    {
        return -1;
    }
}

int outside_stack_priority(char operand)
{
    if (operand == '+' || operand == '-')
    {
        return 1;
    }
    else if (operand == '*' || operand == '/')
    {
        return 2;
    }
    else if (operand == '^')
    {
        return 4;
    }
    else if (operand == '(')
    {
        return 5;
    }
    else
    {
        return -1;
    }
}

void Execute(stack<int> &N_stack, char Operator)
{
    int operand2 = N_stack.top();
    N_stack.pop();
    int operand1 = N_stack.top();
    N_stack.pop();

    if (Operator == '+')
    {
        N_stack.push(operand1 + operand2);
    }
    else if (Operator == '-')
    {
        N_stack.push(operand1 - operand2);
    }
    else if (Operator == '*')
    {
        N_stack.push(operand1 * operand2);
    }
    else if (Operator == '/')
    {
        N_stack.push(operand1 / operand2);
    }
    else if (Operator == '^')
    {
        N_stack.push(pow(operand1, operand2));
    }
}

int solve(string expression)
{
    expression.push_back('#');
    stack<int> N_stack;
    stack<char> O_stack;

    O_stack.push('$');
    int index = 0;
    while (index < expression.size())
    {
        if (isdigit(expression[index]))
        {
            int number = 0;
            while (isdigit(expression[index]))
            {
                number = number * 10 + (expression[index] - '0');
                index++;
            }
            N_stack.push(number);
        }
        else if (expression[index] == ')')
        {
            while (O_stack.top() != '(')
            {
                char Operator = O_stack.top();
                O_stack.pop();
                Execute(N_stack, Operator);
            }
            O_stack.pop();
            index++;
        }
        else
        {
            while(inside_stack_priority(O_stack.top()) >= outside_stack_priority(expression[index]) && expression[index] != '#')
            {
                char Operator = O_stack.top();
                O_stack.pop();
                Execute(N_stack, Operator);
            }
            if (expression[index] != '#')
            {
                O_stack.push(expression[index++]);
            }
            else
            {
                break;
            }
        }
    }

    while (!O_stack.empty() && O_stack.top() != '$')
    {
        char Operator = O_stack.top();
        O_stack.pop();
        Execute(N_stack, Operator);
    }
    
    return N_stack.top();
}

int main()
{

    // reading from file which has expressions in each line
    ifstream file("expressions.txt");
    string line;
    while (getline(file, line))
    {
        string expression = "";
        expression += line;
        expression += "#";

        // expression evaluation
        cout << solve(expression) << endl;
        cout << expression << endl;
    }
    file.close();

    return 0;
}