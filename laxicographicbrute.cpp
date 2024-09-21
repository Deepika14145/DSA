class Solution {
public:
    vector<int> lexicalOrder(int n) {
    vector<string> strNumbers;
    vector<int> result;

    // Convert numbers from 1 to n into strings
    for (int i = 1; i <= n; i++) {
        strNumbers.push_back(to_string(i));
    }

    // Sort the strings lexicographically
    sort(strNumbers.begin(), strNumbers.end());

    // Convert sorted strings back to integers
    for (const string &s : strNumbers) {
        result.push_back(stoi(s));
    }

    return result;
}    
    
};