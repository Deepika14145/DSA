class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() -1;
        int count = 0;

        while(left < right){
            int sum = nums[left] + nums[right];
            if(sum == k){
                count++;
                left++;
                right--;
            } else if(sum < k){
                left++;
            } else {
                right--;
            }
        }
        return count;
    }
};
///////////////////////////////////////////////////////

int maxOperations(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    int count = 0;

    for (int num : nums) {
        int complement = k - num;
        if (freq[complement] > 0) {
            count++;         // Found a pair
            freq[complement]--; // Use up one occurrence of complement
        } else {
            freq[num]++; // Store the current number in map
        }
    }
    return count;
}
