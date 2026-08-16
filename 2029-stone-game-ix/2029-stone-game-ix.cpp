class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {};

        for (int x : stones)
            cnt[x % 3]++;

        // If number of remainder-0 stones is even,
        // Alice wins if both types (1 and 2) exist.
        if (cnt[0] % 2 == 0) {
            return cnt[1] > 0 && cnt[2] > 0;
        }

        // If remainder-0 count is odd,
        // Alice needs one side to have at least 2 more stones.
        return abs(cnt[1] - cnt[2]) > 2;
    }
};