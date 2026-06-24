class Solution {
public:
    vector<vector<int>>ans;
    vector<int> temp;

    void solve(int idx, vector<int>& candidates, int target){
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        if(idx == candidates.size())
            return;

        if(candidates[idx] <= target){
            temp.push_back(candidates[idx]);

            solve(idx, candidates, target - candidates[idx]);

            temp.pop_back();
        }

        solve(idx + 1, candidates, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(0, candidates, target);
        return ans;
    }
};