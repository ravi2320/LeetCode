/*
2918. Minimum Equal Sum of Two Arrays After Replacing Zeros
Solved
Medium
Topics
Companies
Hint
You are given two arrays nums1 and nums2 consisting of positive integers.

You have to replace all the 0's in both arrays with strictly positive integers such that the sum of elements of both arrays becomes equal.

Return the minimum equal sum you can obtain, or -1 if it is impossible.

 

Example 1:

Input: nums1 = [3,2,0,1,0], nums2 = [6,5,0]
Output: 12
Explanation: We can replace 0's in the following way:
- Replace the two 0's in nums1 with the values 2 and 4. The resulting array is nums1 = [3,2,2,1,4].
- Replace the 0 in nums2 with the value 1. The resulting array is nums2 = [6,5,1].
Both arrays have an equal sum of 12. It can be shown that it is the minimum sum we can obtain.
Example 2:

Input: nums1 = [2,0,2,0], nums2 = [1,4]
Output: -1
Explanation: It is impossible to make the sum of both arrays equal.
 

Constraints:

1 <= nums1.length, nums2.length <= 105
0 <= nums1[i], nums2[i] <= 106
*/

/*
Approach:
- We are given two integer arrays `nums1` and `nums2` that may contain zeroes.
- The objective is to replace **each 0 with a positive integer ≥ 1** such that:
  - The sum of the two arrays becomes equal.
  - The **minimum possible maximum sum** after replacements is returned.
  - If it is not possible, return -1.

Steps:
1. Iterate through `nums1` and `nums2` to compute:
   - `sum1` and `sum2`: Treat zeros as `1` while summing.
   - `zeroInNums1` and `zeroInNums2`: Count the number of zeros in each array.
2. After zeros are replaced with 1, the sum is minimized.
3. We check:
   - If `sum1 < sum2` and `nums1` has **no zeros**, it’s impossible to match `sum2`.
   - Similarly, if `sum2 < sum1` and `nums2` has **no zeros**, it’s impossible to match `sum1`.
4. Else, we return `max(sum1, sum2)` as the **minimum sum possible after equalization**.

Intuition:
- Replacing 0s with 1 gives the **minimum possible sum**.
- If the lower-sum array still can't be increased (has no zeros), the arrays cannot be equalized.

Time Complexity: O(n + m)  
- `n` = size of `nums1`, `m` = size of `nums2`.

Space Complexity: O(1)  
- Constant extra space used.

*/

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, zeroInNums1 = 0;
        long long sum2 = 0, zeroInNums2 = 0;

        // Compute sum and zero count for nums1
        for (int &x : nums1) {
            sum1 += (x == 0) ? 1 : x;
            zeroInNums1 += (x == 0);
        }

        // Compute sum and zero count for nums2
        for (int &x : nums2) {
            sum2 += (x == 0) ? 1 : x;
            zeroInNums2 += (x == 0);
        }

        // If lower sum can't be increased (no zero), return -1
        if (sum1 < sum2 && zeroInNums1 == 0) return -1;
        if (sum2 < sum1 && zeroInNums2 == 0) return -1;

        // Return the larger of the two minimal possible sums
        return max(sum1, sum2);
    }
};
