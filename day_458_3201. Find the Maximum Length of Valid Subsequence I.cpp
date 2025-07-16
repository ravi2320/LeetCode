/*
3201. Find the Maximum Length of Valid Subsequence I

avatar
Discuss Approach
arrow-up
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given an integer array nums.
A subsequence sub of nums with length x is called valid if it satisfies:

(sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2.
Return the length of the longest valid subsequence of nums.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: nums = [1,2,3,4]

Output: 4

Explanation:

The longest valid subsequence is [1, 2, 3, 4].

Example 2:

Input: nums = [1,2,1,1,2,1,2]

Output: 6

Explanation:

The longest valid subsequence is [1, 2, 1, 2, 1, 2].

Example 3:

Input: nums = [1,3]

Output: 2

Explanation:

The longest valid subsequence is [1, 3].

 

Constraints:

2 <= nums.length <= 2 * 105
1 <= nums[i] <= 107
*/

/*
Approach:
- Traverse the array while tracking the longest subarray where even and odd numbers alternate.
- Also count total number of odd and even elements.
- Track the current parity and increase the alternating count when parity switches.
- The result is the maximum of:
  a) longest alternating subsequence,
  b) total odd numbers (if all are odd),
  c) total even numbers (if all are even).

Intuition:
- We want the longest sequence where even and odd alternate.
- But also, if the entire array is all even or all odd, the max length can be the total count of that.

Time Complexity: O(n) – One pass through the array.
Space Complexity: O(1) – Constant space used.
*/

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();

        // Initial parity flag (0 for even, 1 for odd)
        int flag = nums[0] % 2;

        // Counts for alternating sequence, total even, total odd
        int ans = 1;
        int odd = 0, even = 0;

        if (flag) odd++;
        else even++;

        // Traverse the array
        for (int i = 1; i < n; i++) {
            if (nums[i] % 2 == 0) {
                // Current number is even
                if (flag) {
                    ans++;        // Parity changed from odd → even
                    flag = 0;
                }
                even++;
            } else {
                // Current number is odd
                if (!flag) {
                    ans++;        // Parity changed from even → odd
                    flag = 1;
                }
                odd++;
            }
        }

        // The max can be:
        // 1. Longest alternating sequence
        // 2. Total number of evens
        // 3. Total number of odds
        return max({ans, odd, even});
    }
};
