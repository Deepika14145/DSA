// class Solution {
// public:
//     void mergeArray(vector<int>& arr, int low, int mid, int high) {
//         vector<int> temp;

//         int i = low;
//         int j = mid + 1;

//         while (i <= mid && j <= high) {
//             if (arr[i] <= arr[j])
//                 temp.push_back(arr[i++]);
//             else
//                 temp.push_back(arr[j++]);
//         }

//         while (i <= mid)
//             temp.push_back(arr[i++]);

//         while (j <= high)
//             temp.push_back(arr[j++]);

//         for (int k = low; k <= high; k++)
//             arr[k] = temp[k - low];
//     }

//     void mergeSort(vector<int>& arr, int low, int high) {
//         if (low >= high)
//             return;

//         int mid = low + (high - low) / 2;

//         mergeSort(arr, low, mid);
//         mergeSort(arr, mid + 1, high);

//         mergeArray(arr, low, mid, high);
//     }

//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         vector<int> temp;

//         // Copy first m elements of nums1
//         for (int i = 0; i < m; i++)
//             temp.push_back(nums1[i]);

//         // Copy all elements of nums2
//         for (int i = 0; i < n; i++)
//             temp.push_back(nums2[i]);

//         // Sort using Merge Sort
//         mergeSort(temp, 0, temp.size() - 1);

//         // Copy back to nums1
//         for (int i = 0; i < m + n; i++)
//             nums1[i] = temp[i];
//     }
// };

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }

        while (j >= 0)
            nums1[k--] = nums2[j--];
    }
};