class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = nums[0], mx = nums[0];

        // Find minimum and maximum
        for (int x : nums) {
            if (x < mn) mn = x;
            if (x > mx) mx = x;
        }

        // Euclidean Algorithm for GCD
        while (mx != 0) {
            int rem = mn % mx;
            mn = mx;
            mx = rem;
        }

        return mn;
    }
};