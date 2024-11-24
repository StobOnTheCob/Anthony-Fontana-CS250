#include "SpecialStack.h"

using namespace std;

// Push an element onto the stack
void SpecialStack::push(int value) {
    s.push(value);
}

// Pop the top element from the stack
void SpecialStack::pop() {
    if (s.empty()) {
        throw runtime_error("Stack is empty; Cannot perform pop.");
    }
    s.pop();
}

// Peek at the top element
int SpecialStack::peek() {
    if (s.empty()) {
        throw runtime_error("Stack is empty; Cannot perform peek.");
    }
    return s.top();
}

// Check if the stack is empty
bool SpecialStack::empty() {
    return s.empty();
}

// Print the stack elements (top to bottom)
void SpecialStack::printStack() {
    if (s.empty()) {
        cout << "Stack is empty." << endl;
        return;
    }

    stack<int> temp = s;
    cout << "Stack from top to bottom: ";
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

// Pop the latest added odd number
void SpecialStack::popOdd() {
    if (s.empty()) {
        throw runtime_error("Stack is empty; Cannot perform popOdd.");
    }

    stack<int> temp;
    bool found = false;

    // Transfer elements until we find the latest odd number
    while (!s.empty()) {
        if (s.top() % 2 != 0 && !found) {
            s.pop();
            found = true; // Found and removed the latest odd number
            break;
        } else {
            temp.push(s.top());
            s.pop();
        }
    }

    // Put back the remaining elements
    while (!temp.empty()) {
        s.push(temp.top());
        temp.pop();
    }

    if (!found) {
        throw runtime_error("No odd number found in the stack.");
    }
}

// Pop the latest added even number
void SpecialStack::popEven() {
    if (s.empty()) {
        throw runtime_error("Stack is empty; Cannot perform popEven.");
    }

    stack<int> temp;
    bool found = false;

    // Transfer elements until we find the latest even number
    while (!s.empty()) {
        if (s.top() % 2 == 0 && !found) {
            s.pop();
            found = true; // Found and removed the latest even number
            break;
        } else {
            temp.push(s.top());
            s.pop();
        }
    }

    // Put back the remaining elements
    while (!temp.empty()) {
        s.push(temp.top());
        temp.pop();
    }

    if (!found) {
        throw runtime_error("No even number found in the stack.");
    }
}
