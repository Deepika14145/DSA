class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % k == 0)
                st.insert(nums[i]);
        }
        //sort directly using unorder set
        for (int x = k; ; x += k) {
            if (!st.count(x))
                return x;
        }
    }
};