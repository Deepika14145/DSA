class Solution {
public:
  int tupleSameProduct(vector<int>& nums) {
       unordered_map<int, int> productCount;
    int result = 0, n = nums.size();

    // Step 1: Compute and store product frequencies
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int product = nums[i] * nums[j];
            productCount[product]++;
        }
    }

    // Step 2: Compute valid tuples efficiently
    for (auto& pair : productCount) {
        int f = pair.second;
        if (f > 1) {
            result += 4 * f * (f - 1); // fC2 * 8 = (f*(f-1)/2) * 8
        }
    }

    return result;
  }
};

