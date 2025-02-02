class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int n = s.size();

        // Prefix sum array to store the cumulative count of vowels
        vector<int> prefix(n + 1, 0);

        // Build the prefix sum array
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + (vowels.count(s[i]) ? 1 : 0);
        }

        // Find the max number of vowels in any substring of length k
        int maxVowels = 0;
        for (int i = k; i <= n; i++) {
            maxVowels = max(maxVowels, prefix[i] - prefix[i - k]);
        }

        return maxVowels;
    }
};



#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int maxVowels = 0, currentVowels = 0;

        // Count vowels in the first window of size k
        for (int i = 0; i < k; i++) {
            if (vowels.count(s[i])) {
                currentVowels++;
            }
        }
        maxVowels = currentVowels;

        // Sliding window technique
        for (int i = k; i < s.size(); i++) {
            if (vowels.count(s[i])) currentVowels++; // Add new character
            if (vowels.count(s[i - k])) currentVowels--; // Remove old character
            maxVowels = max(maxVowels, currentVowels);
        }

        return maxVowels;
    }
};

int main() {
    Solution sol;
    cout << sol.maxVowels("abciiidef", 3) << endl; // Output: 3
    cout << sol.maxVowels("aeiou", 2) << endl; // Output: 2
    cout << sol.maxVowels("leetcode", 3) << endl; // Output: 2
    return 0;
}
