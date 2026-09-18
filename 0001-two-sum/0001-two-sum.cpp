// // class Solution {
// // public:
// //     vector<int> twoSum(vector<int>& nums, int target) {
// //         for(int i = 0; i < nums.size(); i++) {
// //             for(int j = i + 1; j < nums.size(); j++) {

// //                 if(nums[i] + nums[j] == target) {
// //                     return {i, j};
// //                 }
// //             }
// //         }

// //         return {};
// //     }
// // };


// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<pair<int, int>> arr;

//         for(int i = 0; i < nums.size(); i++) {
//             arr.push_back({nums[i], i});
//         }

//         sort(arr.begin(), arr.end());

//         int left = 0;
//         int right = arr.size() - 1;

//         while(left < right) {
//             int sum = arr[left].first + arr[right].first;

//             if(sum == target)
//                 return {arr[left].second, arr[right].second};

//             if(sum < target)
//                 left++;
//             else
//                 right--;
//         }

//         return {};
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> arr;

        for(int i = 0; i < nums.size(); i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        int left = 0;
        int right = arr.size() - 1;

        while(left < right) {
            int sum = arr[left].first + arr[right].first;

            if(sum == target)
                return {arr[left].second, arr[right].second};

            if(sum < target)
                left++;
            else
                right--;
        }

        return {};
    }
};