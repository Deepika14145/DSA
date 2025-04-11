//brute force approach
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;

        for (int i = 0; i < nums1.size(); i++) {
            int val = nums1[i];
            int index = -1;

            // Find index of nums1[i] in nums2
            for (int j = 0; j < nums2.size(); j++) {
                if (nums2[j] == val) {
                    index = j;
                    break;
                }
            }

            // Now search for next greater in nums2 to the right of index
            int nextGreater = -1;
            for (int k = index + 1; k < nums2.size(); k++) {
                if (nums2[k] > val) {
                    nextGreater = nums2[k];
                    break;
                }
            }

            result.push_back(nextGreater);
        }

        return result;
    }
};
