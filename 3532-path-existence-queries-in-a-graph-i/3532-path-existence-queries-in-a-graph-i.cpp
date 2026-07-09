// n nodes 0 to n-1
// nums(n) -> ascending order and maxDiff
// edges are undirected  between i and j
// abs(nums[i] - nums[j] <= maxDiff)
//queries[i] = [ui, vi] -> determine whether there exists path in between u and v
//return answer -> boolean - true if theres path between nodes

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        
        vector<int> component(n);
        component[0] = 0;

        // Assign component number to each node
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] <= maxDiff)
                component[i] = component[i - 1];
            else
                component[i] = component[i - 1] + 1;
        }

        vector<bool> ans;

        for (auto &q : queries) {
            ans.push_back(component[q[0]] == component[q[1]]);
        }

        return ans;
    }
};