class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long sum = 0;

        //first window
        for(int i = 0; i<k; i++)
            sum += nums[i];

        long long maxSum = sum;

        //slide the window
        for(int i = k; i<nums.size(); i++){
            sum += nums[i] - nums[i -k];
            maxSum = max(maxSum, sum);
        }

        return (double)maxSum / k;
    }
};