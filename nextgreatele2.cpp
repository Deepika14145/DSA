class Solution {
public:
    // vector<int> nextGreaterElements(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> result(n, -1);

    //     for(int i = 0; i< n; i++){
    //         for(int j = 1; j<n; j++){
    //             int next = (i +j) % n;

    //             if(nums[next] > nums[i]){
    //                 result[i] = nums[next];
    //                 break;
    //             }

    //         }
            
    //     }
    //     return result;
    vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);       // Initialize result with -1
    stack<int> st;                   // Stack stores indices

    // Traverse the array twice to simulate circular behavior
    for (int i = 0; i < 2 * n; ++i) {
        int current = nums[i % n];   // Use modulo for circular access

        // While stack is not empty and current number > stack's top index value
        while (!st.empty() && nums[st.top()] < current) {
            result[st.top()] = current;  // Set next greater element
            st.pop();
        }

        // Push index in first pass only (i < n)
        if (i < n)
            st.push(i);
    }

    return result;
}

};
