/*
1493. Longest Subarray of 1's After Deleting One Element

avatar
Discuss Approach
arrow-up
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

 

Example 1:

Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
Example 2:

Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
Example 3:

Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
*/

/*
Approach:
- We are asked to find the length of the longest subarray containing only 1’s 
  after deleting exactly one element (which can be a 0).
- Use the sliding window (two pointers) technique to maintain a window where 
  the number of zeros is at most 1.
- Expand the window by moving the right pointer `j`, and if the number of 
  zeros exceeds 1, shrink the window from the left by moving `i`.
- Keep track of the maximum length of valid subarray (window size - 1, 
  because one zero must be deleted).

Intuition:
- The problem is similar to "longest subarray with at most k zeros," but here 
  k = 1 and we must delete one element.
- By maintaining a window with at most one zero, we simulate the effect of 
  deleting a zero.
- The result is the maximum window length after removing one element.

Time Complexity:
- O(n), since each element is processed at most twice (once by `j` and once 
  by `i`).
Space Complexity:
- O(1), as we use only a few extra variables.
*/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;          // To store the maximum subarray length
        int i = 0;            // Left pointer of the sliding window
        int zeroCnt = 0;      // Count of zeros in the current window

        // Traverse the array with the right pointer `j`
        for (int j = 0; j < n; j++) {
            if (nums[j] == 0) {
                zeroCnt++;   // Increase zero count if current element is 0
            }

            // If more than 1 zero, shrink the window from the left
            while (zeroCnt > 1) {
                if (nums[i] == 0)
                    zeroCnt--;   // Reduce zero count when removing a 0
                i++;             // Move left pointer forward
            }

            // Update maximum length (subtract 1 to simulate deletion of a zero)
            ans = max(ans, j - i);
        }

        return ans;
    }
};