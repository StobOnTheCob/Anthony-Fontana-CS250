#ifndef SPECIALSTACK_H_INCLUDED
#define SPECIALSTACK_H_INCLUDED

#include <iostream>
#include <stack>
#include <stdexcept>

using namespace std;

class SpecialStack {
private:
    stack<int> s; // Standard STL stack to store integers

public:
    // Basic operations
    void push(int value);
    void pop();
    int peek();
    bool empty();
    void printStack();

    // Special operations
    void popOdd();
    void popEven();
};

#endif
