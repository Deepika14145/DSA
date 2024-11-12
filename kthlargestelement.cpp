// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
        // // Sort the array in ascending order
        // sort(nums.begin(), nums.end());
        
        // // Return the kth largest element
        // int n = nums.size();
        // return nums[n - k];

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Min-heap to keep track of the k largest elements
        priority_queue<int, vector<int>, greater<int>> minpq;

        // Iterate through each element in the array
        for (int i = 0; i < nums.size(); i++) {
            // If the size of the heap is less than k, push the element
            if (minpq.size() < k) {
                minpq.push(nums[i]);
            } else {
                // If current element is larger than the smallest in the heap
                if (minpq.top() < nums[i]) {
                    minpq.pop();           // Remove the smallest
                    minpq.push(nums[i]);   // Add the current element
                }
            }
        }
        
        // The root of the min-heap will be the kth largest element
        return minpq.top();
    }
};
