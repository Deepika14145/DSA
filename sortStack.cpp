#include <iostream>
#include <stack>

using namespace std;

void sortedInsert(stack<int>& s, int x) {
    // Base case: If stack is empty or top element is smaller than x
    if (s.empty() || s.top() <= x) {
        s.push(x);
        return;
    }

    // Recursively remove and store all greater elements in a temporary stack
    int temp = s.top();
    s.pop();
    sortedInsert(s, x);
    s.push(temp);
}

void sortStack(stack<int>& s) {
    // Base case: If stack is empty or contains only one element
    if (s.empty() || s.size() == 1) {
        return;
    }

    // Remove the top element
    int x = s.top();
    s.pop();

    // Sort the remaining stack recursively
    sortStack(s);

    // Insert the removed element back into the sorted stack
    sortedInsert(s, x);
}
