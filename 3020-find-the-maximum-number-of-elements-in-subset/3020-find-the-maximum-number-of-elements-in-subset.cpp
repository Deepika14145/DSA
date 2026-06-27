class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;

        for (int x : nums)
            freq[x]++;

        int ans = 1;

        // Handle 1 separately
        if (freq.count(1))
            ans = (freq[1] % 2 ? freq[1] : freq[1] - 1);

        for (auto &[start, cnt] : freq) {
            if (start == 1) continue;

            long long cur = start;
            int len = 0;

            while (freq.count(cur)) {

                // Current number can only be the center
                if (freq[cur] == 1) {
                    len++;
                    break;
                }

                // Current number contributes to both sides
                len += 2;

                // Prevent overflow and check if next square exists
                if (cur > 1000000000LL / cur) {
                    len--;
                    break;
                }

                long long nxt = cur * cur;

                if (!freq.count(nxt)) {
                    len--;
                    break;
                }

                cur = nxt;
            }

            ans = max(ans, len);
        }

        return ans;
    }
};