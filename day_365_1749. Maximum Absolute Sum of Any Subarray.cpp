/*
1749. Maximum Absolute Sum of Any Subarray
Solved
Medium
Topics
Companies
Hint
You are given an integer array nums. The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).

Return the maximum absolute sum of any (possibly empty) subarray of nums.

Note that abs(x) is defined as follows:

If x is a negative integer, then abs(x) = -x.
If x is a non-negative integer, then abs(x) = x.
 

Example 1:

Input: nums = [1,-3,2,3,-4]
Output: 5
Explanation: The subarray [2,3] has absolute sum = abs(2+3) = abs(5) = 5.
Example 2:

Input: nums = [2,-5,1,-4,3,-2]
Output: 8
Explanation: The subarray [-5,1,-4] has absolute sum = abs(-5+1-4) = abs(-8) = 8.
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
*/

/**
 * Approach:
 * - We need to find the **maximum absolute sum** of any subarray.
 * - This translates to finding:
 *   1. **Maximum subarray sum** (Kadane’s Algorithm)
 *   2. **Minimum subarray sum** (Kadane’s Algorithm on negative numbers)
 * - The answer is the **maximum absolute value** of these two sums.
 *
 * 🔹 **Time Complexity**: O(N) (Single pass Kadane's Algorithm)
 * 🔹 **Space Complexity**: O(1) (Constant extra space)
 */

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currMinSum = 0, currMaxSum = 0;
        int minSum = 0, maxSum = 0;

        for (int num : nums) {
            currMaxSum = max(num, currMaxSum + num);
            maxSum = max(maxSum, currMaxSum);

            currMinSum = min(num, currMinSum + num);
            minSum = min(minSum, currMinSum);
        }

        return max(maxSum, abs(minSum));
    }
};