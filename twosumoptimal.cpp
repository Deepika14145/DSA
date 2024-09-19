#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numMap; // Map to store value and index
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i]; // Find the complement
        // Check if complement exists in the map
        if (numMap.find(complement) != numMap.end()) {
            return {numMap[complement], i}; // Return indices if complement found
        }
        // Add the current number and its index to the map
        numMap[nums[i]] = i;
    }
    return {}; // Return an empty vector if no solution is found (shouldn't happen given constraints)
}

int main() {
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = twoSum(nums1, target1);
    cout << "[" << result1[0] << ", " << result1[1] << "]" << endl; // Output: [0, 1]

    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> result2 = twoSum(nums2, target2);
    cout << "[" << result2[0] << ", " << result2[1] << "]" << endl; // Output: [1, 2]

    vector<int> nums3 = {3, 3};
    int target3 = 6;
    vector<int> result3 = twoSum(nums3, target3);
    cout << "[" << result3[0] << ", " << result3[1] << "]" << endl; // Output: [0, 1]

    return 0;
}
