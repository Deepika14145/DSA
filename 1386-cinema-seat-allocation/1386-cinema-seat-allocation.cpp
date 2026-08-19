class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> reserved;

        // Store reserved seats row-wise
        for (auto &seat : reservedSeats) {
            reserved[seat[0]].insert(seat[1]);
        }

        long long ans = 2LL * n;

        for (auto &[row, seats] : reserved) {
            // This row was initially counted as 2 groups
            ans -= 2;

            bool left = true;    // 2,3,4,5
            bool middle = true;  // 4,5,6,7
            bool right = true;   // 6,7,8,9

            // Check left block
            for (int s = 2; s <= 5; s++) {
                if (seats.count(s)) {
                    left = false;
                    break;
                }
            }

            // Check middle block
            for (int s = 4; s <= 7; s++) {
                if (seats.count(s)) {
                    middle = false;
                    break;
                }
            }

            // Check right block
            for (int s = 6; s <= 9; s++) {
                if (seats.count(s)) {
                    right = false;
                    break;
                }
            }

            // Two non-overlapping groups
            if (left && right)
                ans += 2;

            // At least one group can fit
            else if (left || middle || right)
                ans += 1;
        }

        return ans;
    }
};