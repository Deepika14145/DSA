class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt[3] = {}, l = 0, ans = 0, n = s.size();

        for (int r = 0; r < n; r++) {
            cnt[s[r] - 'a']++;

            while (cnt[0] && cnt[1] && cnt[2]) {
                ans += n - r;
                cnt[s[l++] - 'a']--;
            }
        }
        return ans;
    }
};