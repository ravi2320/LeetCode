/*
3432. Count Partitions with Even Sum Difference

avatar
Discuss Approach
arrow-up
Solved
Easy
Topics
premium lock icon
Companies
Hint
You are given an integer array nums of length n.

A partition is defined as an index i where 0 <= i < n - 1, splitting the array into two non-empty subarrays such that:

Left subarray contains indices [0, i].
Right subarray contains indices [i + 1, n - 1].
Return the number of partitions where the difference between the sum of the left and right subarrays is even.

 

Example 1:

Input: nums = [10,10,3,7,6]

Output: 4

Explanation:

The 4 partitions are:

[10], [10, 3, 7, 6] with a sum difference of 10 - 26 = -16, which is even.
[10, 10], [3, 7, 6] with a sum difference of 20 - 16 = 4, which is even.
[10, 10, 3], [7, 6] with a sum difference of 23 - 13 = 10, which is even.
[10, 10, 3, 7], [6] with a sum difference of 30 - 6 = 24, which is even.
Example 2:

Input: nums = [1,2,2]

Output: 0

Explanation:

No partition results in an even sum difference.

Example 3:

Input: nums = [2,4,6,8]

Output: 3

Explanation:

All partitions result in an even sum difference.

 

Constraints:

2 <= n == nums.length <= 100
1 <= nums[i] <= 100
*/

/*
---------------------------------------------------------
💡 Approach
---------------------------------------------------------
We want to count how many valid partitions exist such that:

    |sum(left) - sum(right)| is even

Let:
    totalSum = total sum of the array
    currSum  = sum of prefix [0..i]

Right side sum = totalSum - currSum

Condition:
    |currSum - (totalSum - currSum)| % 2 == 0
⇔  |2*currSum - totalSum| % 2 == 0

Since absolute value doesn’t affect parity:
    (2*currSum - totalSum) % 2 == 0

Key observation:
    2 * currSum is always even
Thus parity depends only on totalSum.

Case 1: totalSum is even  
    Equation becomes even - even → even  
    ALWAYS valid → check every prefix.

Case 2: totalSum is odd  
    odd - even → odd → NEVER even  
    NO possible valid partitions.

But the given implementation checks directly:
    abs(2*currSum - totalSum) % 2 == 0
which is equivalent and correct.

We only check first n-1 elements because we need
both partitions to be non-empty.

---------------------------------------------------------
💡 Intuition
---------------------------------------------------------
We are verifying if a cut produces two partitions with
the same parity (both even or both odd).  
Since parity depends on the difference of their sums,
we simply check if:

    (2*prefixSum - totalSum) is even.

---------------------------------------------------------
⏳ Time Complexity
---------------------------------------------------------
O(n) — single pass through the array.

---------------------------------------------------------
💾 Space Complexity
---------------------------------------------------------
O(1) — only constant variables used.

---------------------------------------------------------
*/

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        int currSum = 0;
        int ans = 0;
        int n = nums.size();

        // Check all valid split points (can't split after last element)
        for (int i = 0; i < n - 1; i++) {
            currSum += nums[i];

            // Check if the resulting two sums have even difference
            if (abs(2 * currSum - totalSum) % 2 == 0)
                ans++;
        }

        return ans;
    }
};
