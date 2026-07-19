class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26);
        vector<bool> vis(26, false);

        // Store last occurrence of each character
        for (int i = 0; i < s.size(); i++)
            last[s[i] - 'a'] = i;

        string st;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            // Skip if already included
            if (vis[c - 'a']) continue;

            // Remove larger characters if they appear later
            while (!st.empty() &&
                   st.back() > c &&
                   last[st.back() - 'a'] > i) {
                vis[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(c);
            vis[c - 'a'] = true;
        }

        return st;
    }
};