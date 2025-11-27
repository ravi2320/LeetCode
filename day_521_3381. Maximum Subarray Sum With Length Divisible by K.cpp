/*
3381. Maximum Subarray Sum With Length Divisible by K

avatar
Discuss Approach
arrow-up
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given an array of integers nums and an integer k.

Return the maximum sum of a subarray of nums, such that the size of the subarray is divisible by k.

 

Example 1:

Input: nums = [1,2], k = 1

Output: 3

Explanation:

The subarray [1, 2] with sum 3 has length equal to 2 which is divisible by 1.

Example 2:

Input: nums = [-1,-2,-3,-4,-5], k = 4

Output: -10

Explanation:

The maximum sum subarray is [-1, -2, -3, -4] which has length equal to 4 which is divisible by 4.

Example 3:

Input: nums = [-5,1,2,-3,4], k = 2

Output: 4

Explanation:

The maximum sum subarray is [1, 2, -3, 4] which has length equal to 4 which is divisible by 2.

 

Constraints:

1 <= k <= nums.length <= 2 * 105
-109 <= nums[i] <= 109
*/

/*
Intuition:
-----------
We want the maximum subarray sum, but with the restriction that subarrays must be
formed by taking *k-sized blocks starting at the same modulo position*.

Example:
If k = 3, valid windows start at:
    index 0 → [0..2], [3..5], [6..8], ...
    index 1 → [1..3], [4..6], [7..9], ...
    index 2 → [2..4], [5..7], [8..10], ...

For each starting offset 'start' (0 to k-1), we extract consecutive blocks of size k
and apply **Kadane’s Algorithm** on those block-sums.

Why prefix sum?
---------------
To compute each k-length subarray sum in O(1) time:
    subSum = prefSum[j] - prefSum[i-1]

Approach:
---------
1. Build prefix sum array.
2. For each start position in [0, k-1]:
       - Jump in steps of k: i, i+k, i+2k, ...
       - Compute the k-length block sum subSum
       - Apply Kadane’s logic:
            currSum = max(subSum, currSum + subSum)
       - Update global result
3. Return maximum value observed.

Time Complexity:
----------------
O(n + k * (n / k)) = O(n)

Space Complexity:
-----------------
O(n) for prefix sum.

*/

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        // Prefix sum array to compute block sums in O(1)
        vector<long long> prefSum(n);
        prefSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefSum[i] = prefSum[i - 1] + nums[i];
        }

        long long result = LLONG_MIN;

        // Try all possible starting offsets
        for (int start = 0; start < k; start++) {

            long long currSum = 0;  // Kadane's current sum
            int i = start;

            // Jump in multiples of k: process k-length blocks
            while (i < n && (i + k - 1) < n) {

                int j = i + k - 1;  // Ending index of current block (size k)

                // Compute sum of subarray nums[i..j]
                long long subSum = prefSum[j] - ((i > 0) ? prefSum[i - 1] : 0);

                // Apply Kadane’s algorithm on block sums
                currSum = max(subSum, currSum + subSum);

                // Update global result
                result = max(result, currSum);

                // Move to next block
                i += k;
            }
        }

        return result;
    }
};
