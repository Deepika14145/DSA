class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        for (int start = 1; start <= 9; start++) {
            int num = 0;

            for (int d = start; d <= 9; d++) {
                num = num * 10 + d;

                if (num >= 10 && num >= low && num <= high)
                    ans.push_back(num);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};