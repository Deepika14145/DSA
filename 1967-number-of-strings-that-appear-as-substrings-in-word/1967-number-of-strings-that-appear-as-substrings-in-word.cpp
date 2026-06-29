class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for (auto &s : patterns)
            ans += word.find(s) != string::npos;
        return ans;
    }
};