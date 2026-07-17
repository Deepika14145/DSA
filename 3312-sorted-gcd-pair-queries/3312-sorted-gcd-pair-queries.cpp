class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<long long> freq(mx + 1, 0);
        for (int x : nums) freq[x]++;

        vector<long long> cnt(mx + 1, 0);

        // cnt[g] = numbers divisible by g
        for (int g = 1; g <= mx; g++) {
            for (int j = g; j <= mx; j += g)
                cnt[g] += freq[j];
        }

        vector<long long> exact(mx + 1, 0);

        // exact[g] = pairs whose gcd is exactly g
        for (int g = mx; g >= 1; g--) {
            exact[g] = cnt[g] * (cnt[g] - 1) / 2;
            for (int j = g + g; j <= mx; j += g)
                exact[g] -= exact[j];
        }

        vector<long long> prefix(mx + 1, 0);
        for (int g = 1; g <= mx; g++)
            prefix[g] = prefix[g - 1] + exact[g];

        vector<int> ans;

        for (long long q : queries) {
            int l = 1, r = mx;
            while (l < r) {
                int mid = (l + r) / 2;
                if (prefix[mid] > q)
                    r = mid;
                else
                    l = mid + 1;
            }
            ans.push_back(l);
        }

        return ans;
    }
};