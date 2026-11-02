// class Solution {
// public:
//     int minMoves2(vector<int>& nums) {
//         int mn = *min_element(nums.begin(), nums.end());
//         int mx = *max_element(nums.begin(), nums.end());

//         long long ans = LLONG_MAX;

//         for(long long target = mn; target <=mx; target++){
//             long long moves = 0;

//             for(int x : nums){
//                 moves += abs((long long)x - target);
//             }
//             ans = min(ans, moves);
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int median = nums[nums.size() / 2];
        long long moves = 0;

        for (int num : nums) {
            moves += abs((long long)num - median);
        }

        return (int)moves;
    }
};
