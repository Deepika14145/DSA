class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            // Push current element and its index
            pq.push({nums[i], i});

            // Remove elements outside the current window
            while (!pq.empty() && pq.top().second <= i - k) {
                pq.pop();
            }

            // Window is complete
            if (i >= k - 1) {
                ans.push_back(pq.top().first);
            }
        }

        return ans;
    }
};