 int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n - 1;
        
        // Find longest non-decreasing prefix
        while (left < n - 1 && arr[left] <= arr[left + 1]) left++;

        // If the entire array is already sorted
        if (left == n - 1) return 0;

        // Find longest non-decreasing suffix
        while (right > 0 && arr[right - 1] <= arr[right]) right--;

        // Case 1: Remove everything between left and right
        int min_remove = min(n - left - 1, right);

        // Case 2: Try merging prefix with suffix
        int i = 0, j = right;
        while (i <= left && j < n) {
            if (arr[i] <= arr[j]) {
                min_remove = min(min_remove, j - i - 1);
                i++;
            } else {
                j++;
            }
        }

        return min_remove;
    }
};
