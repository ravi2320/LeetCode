/*
2419. Longest Subarray With Maximum Bitwise AND
Solved
Medium
Topics
Companies
Hint
You are given an integer array nums of size n.

Consider a non-empty subarray from nums that has the maximum possible bitwise AND.

In other words, let k be the maximum value of the bitwise AND of any subarray of nums. Then, only subarrays with a bitwise AND equal to k should be considered.
Return the length of the longest such subarray.

The bitwise AND of an array is the bitwise AND of all the numbers in it.

A subarray is a contiguous sequence of elements within an array.

 

Example 1:

Input: nums = [1,2,3,3,2,2]
Output: 2
Explanation:
The maximum possible bitwise AND of a subarray is 3.
The longest subarray with that value is [3,3], so we return 2.
Example 2:

Input: nums = [1,2,3,4]
Output: 1
Explanation:
The maximum possible bitwise AND of a subarray is 4.
The longest subarray with that value is [4], so we return 1.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 106
*/

/*
Approach:
1. The task is to find the length of the longest subarray consisting of the maximum element in the given array `nums`.
2. We iterate through the array and keep track of the maximum value encountered so far (`maxVal`).
3. We also maintain a variable `streak` to count the length of consecutive occurrences of `maxVal`, and `result` to store the longest streak.
4. If we encounter a number greater than the current `maxVal`, we update `maxVal` and reset the streak.
5. If the number is equal to `maxVal`, we increase the streak, otherwise, reset the streak.

Time Complexity:
- O(n): We only need to iterate through the array once, where `n` is the size of the array.

Space Complexity:
- O(1): The algorithm only uses a constant amount of extra space.

*/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = 0;   // Stores the maximum value encountered in the array.
        int result = 0;   // Stores the length of the longest subarray of `maxVal`.
        int streak = 0;   // Tracks the length of the current streak of `maxVal`.

        // Iterate through the array.
        for(int num : nums) {

            // If a new maximum value is found, reset `maxVal`, `result`, and `streak`.
            if(num > maxVal) {
                maxVal = num;
                result = 0;
                streak = 0;
            }

            // If the current number equals `maxVal`, increase the streak.
            if(num == maxVal) {
                streak++;
            }
            else {
                // If the current number is not `maxVal`, reset the streak.
                streak = 0;
            }

            // Update the result to keep track of the longest streak of `maxVal`.
            result = max(result, streak);
        }

        return result;  // Return the length of the longest subarray of `maxVal`.
    }
};
