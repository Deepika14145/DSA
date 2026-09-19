// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();

//         for(int i = 0; i<n; i++){
//             if(nums[i] != i)
//                 return i;
//         }
//         return n;
//     }
// };

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int expected = n * (n + 1) / 2;

        int actual = 0;
        for (int x : nums)
            actual += x;

        return expected - actual;
    }
};