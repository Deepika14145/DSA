// import java.util.*;

// class Solution {
//     public int longestConsecutive(int[] nums) {

//         if (nums.length == 0)
//             return 0;

//         Arrays.sort(nums);

//         int longest = 1;
//         int curr = 1;

//         for (int i = 1; i < nums.length; i++) {

//             if (nums[i] == nums[i - 1])
//                 continue;   // Skip duplicates

//             if (nums[i] == nums[i - 1] + 1)
//                 curr++;
//             else {
//                 longest = Math.max(longest, curr);
//                 curr = 1;
//             }
//         }

//         longest = Math.max(longest, curr);

//         return longest;
//     }
// }

import java.util.*;

class Solution {
    public int longestConsecutive(int[] nums) {

        if (nums.length == 0)
            return 0;

        HashSet<Integer> set = new HashSet<>();

        for (int num : nums)
            set.add(num);

        int longest = 0;

        for (int num : set) {

            // Start only if it's the first element of a sequence
            if (!set.contains(num - 1)) {

                int curr = 1;
                int x = num;

                while (set.contains(x + 1)) {
                    x++;
                    curr++;
                }

                longest = Math.max(longest, curr);
            }
        }

        return longest;
    }
}