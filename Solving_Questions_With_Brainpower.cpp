class Solution {
public:
    long long solve(vector<vector<int>>& questions, int i, vector<long long>& memo) {
        int n = questions.size();
        if (i >= n) return 0;
        if (memo[i] != -1) return memo[i];

        long long take = questions[i][0] + solve(questions, i + questions[i][1] + 1, memo);
        long long skip = solve(questions, i + 1, memo);

        return memo[i] = max(take, skip);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> memo(n, -1);
        return solve(questions, 0, memo);
    }
};
