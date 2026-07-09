class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if (nums.empty())
            return 0;

        sort(nums.begin(), nums.end());

        int longest = 1;
        int curr = 1;

        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] == nums[i - 1])
                continue;                 // Skip duplicates

            if (nums[i] == nums[i - 1] + 1)
                curr++;                   // Consecutive element
            else {
                longest = max(longest, curr);
                curr = 1;                 // Start a new sequence
            }
        }

        longest = max(longest, curr);     // Check the last sequence

        return longest;
    }
};