#include <iostream>
#include <stack>
using namespace std;

stack <int> s, min_s;

class MinStack {
    MinStack();
    void push(int x);
    void pop();
    int top();
    int getMin();
};

MinStack::MinStack() {
    while (!s.empty())
        s.pop();
    while (!min_s.empty())
        min_s.pop();
}

void MinStack::push(int x) {
    s.push(x);
    if (min_s.empty() || x <= min_s.top())
        min_s.push(x);
}

void MinStack::pop() {
    if (s.empty())
        return;
    if (s.top() == min_s.top())
        min_s.pop();
    s.pop();
}

int MinStack::top() {
    if (s.empty())
        return -1;
    return s.top();
}

int MinStack::getMin() {
    if (min_s.empty())
        return -1;
    return min_s.top();
}
