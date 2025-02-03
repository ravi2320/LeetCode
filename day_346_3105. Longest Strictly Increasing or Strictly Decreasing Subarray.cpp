/*
3105. Longest Strictly Increasing or Strictly Decreasing Subarray
Solved
Easy
Topics
Companies
You are given an array of integers nums. Return the length of the longest 
subarray
 of nums which is either 
strictly increasing
 or 
strictly decreasing
.

 

Example 1:

Input: nums = [1,4,3,3,2]

Output: 2

Explanation:

The strictly increasing subarrays of nums are [1], [2], [3], [3], [4], and [1,4].

The strictly decreasing subarrays of nums are [1], [2], [3], [3], [4], [3,2], and [4,3].

Hence, we return 2.

Example 2:

Input: nums = [3,3,3,3]

Output: 1

Explanation:

The strictly increasing subarrays of nums are [3], [3], [3], and [3].

The strictly decreasing subarrays of nums are [3], [3], [3], and [3].

Hence, we return 1.

Example 3:

Input: nums = [3,2,1]

Output: 3

Explanation:

The strictly increasing subarrays of nums are [3], [2], and [1].

The strictly decreasing subarrays of nums are [3], [2], [1], [3,2], [2,1], and [3,2,1].

Hence, we return 3.

 

Constraints:

1 <= nums.length <= 50
1 <= nums[i] <= 50
*/

/*
Approach:
1. Traverse the array and track two counts:
   - `cntInc`: Length of the current increasing subarray.
   - `cntDec`: Length of the current decreasing subarray.
2. For each pair of consecutive elements:
   - If the current element is **greater**, increment `cntInc` and reset `cntDec` to 1.
   - If the current element is **smaller**, increment `cntDec` and reset `cntInc` to 1.
   - If both elements are **equal**, reset both `cntInc` and `cntDec` to 1.
3. At each step, update the result `res` with the maximum of `cntInc` and `cntDec`.
4. The final `res` will be the length of the longest monotonic (either increasing or decreasing) subarray.

Intuition:
- The goal is to identify the longest sequence of strictly increasing or strictly decreasing numbers without needing to restart from scratch each time.

Time Complexity:
- **O(N)** where N is the size of the input array `nums`. We only traverse the array once.

Space Complexity:
- **O(1)** as we are using a constant number of variables for tracking counts and results.
*/

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int res = 1;           // To store the length of the longest monotonic subarray
        int cntInc = 1;        // Counter for the current increasing sequence
        int cntDec = 1;        // Counter for the current decreasing sequence
        int n = nums.size();   // Size of the input array

        // Traverse the array from the second element
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] < nums[i]) {
                // Strictly increasing sequence
                cntInc++;
                cntDec = 1; // Reset decreasing counter
            } else if (nums[i - 1] > nums[i]) {
                // Strictly decreasing sequence
                cntDec++;
                cntInc = 1; // Reset increasing counter
            } else {
                // Equal elements: reset both counters
                cntInc = 1;
                cntDec = 1;
            }

            // Update the result with the maximum of both counts
            res = max(res, max(cntInc, cntDec));
        }

        return res;
    }
};
