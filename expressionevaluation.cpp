#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

struct Node {
    char data;
    Node* next;
};

class Stack {
    Node* top;

public:
    Stack() : top(nullptr) {}

    bool isEmpty() {
        return top == nullptr;
    }

    void push(char value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;  // Error case
        }
        Node* temp = top;
        top = top->next;
        char value = temp->data;
        delete temp;
        return value;
    }

    char peek() {
        if (isEmpty()) return -1;
        return top->data;
    }
};

// Function to check precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Infix to Postfix Conversion
string infixToPostfix(string infix) {
    Stack s;
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;  // Add operand to result
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();  // Pop until '('
            }
            s.pop();  // Pop '('
        }
        else {  // Operator
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) {
                postfix += s.pop();
            }
            s.push(c);  // Push current operator
        }
    }

    while (!s.isEmpty()) {
        postfix += s.pop();  // Pop remaining operators
    }

    return postfix;
}

// Infix to Prefix Conversion
string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());
    Stack s;
    string prefix = "";

    for (char& c : infix) {
        if (c == '(') {
            c = ')';
        }
        else if (c == ')') {
            c = '(';
        }
    }

    for (char c : infix) {
        if (isalnum(c)) {
            prefix += c;
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                prefix += s.pop();
            }
            s.pop();
        }
        else {  // Operator
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) {
                prefix += s.pop();
            }
            s.push(c);
        }
    }

    while (!s.isEmpty()) {
        prefix += s.pop();
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;
}

// Postfix Expression Evaluation
int evaluatePostfix(string postfix) {
    Stack s;
    for (char c : postfix) {
        if (isalnum(c)) {
            s.push(c - '0');  // Convert char to int
        } else {
            int b = s.pop();
            int a = s.pop();
            switch (c) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
                case '^': s.push(pow(a, b)); break;
            }
        }
    }
    return s.pop();
}

// Prefix Expression Evaluation
int evaluatePrefix(string prefix) {
    Stack s;
    reverse(prefix.begin(), prefix.end());

    for (char c : prefix) {
        if (isalnum(c)) {
            s.push(c - '0');
        } else {
            int a = s.pop();
            int b = s.pop();
            switch (c) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
                case '^': s.push(pow(a, b)); break;
            }
        }
    }
    return s.pop();
}

int main() {
    string infix, postfix, prefix;
    
    cout << "Enter an infix expression: ";
    cin >> infix;

    // Infix to Postfix
    postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;
    cout << "Postfix Evaluation: " << evaluatePostfix(postfix) << endl;

    // Infix to Prefix
    prefix = infixToPrefix(infix);
    cout << "Prefix: " << prefix << endl;
    cout << "Prefix Evaluation: " << evaluatePrefix(prefix) << endl;

    return 0;
}
