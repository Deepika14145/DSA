#include <iostream>
#include <vector>

using namespace std;

// Helper function for DFS
void dfs(int current, int n, vector<int> &result) {
    if (current > n) return; // Stop if the current number exceeds n

    result.push_back(current); // Add the current number to the result

    // Try to append digits 0 to 9 to the current number
    for (int i = 0; i <= 9; i++) {
        int next = current * 10 + i; // Form the next number
        if (next > n) break; // Stop if the next number exceeds n
        dfs(next, n, result); // Recursively explore the next number
    }
}

// Main function to generate lexicographical numbers
vector<int> generateLexicographicalNumbers(int n) {
    vector<int> result;

    // Start DFS for each digit from 1 to 9
    for (int i = 1; i <= 9; i++) {
        dfs(i, n, result);
    }

    return result;
}

int main() {
    int n = 13; // Example: Generate lexicographical numbers from 1 to 13
    vector<int> result = generateLexicographicalNumbers(n);

    // Print lexicographical order
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
