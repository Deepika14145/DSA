class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];

        for(int i = 1; i< nums.size(); i++){
            if(nums[i] == nums[i-1] + 1){
                sum += nums[i];
            }else{
                break;
            }
        }

         // Find smallest missing number >= sum
        int x = sum;

        while (find(nums.begin(), nums.end(), x) != nums.end()) {
            x++;
        }

        return x;
    }
};