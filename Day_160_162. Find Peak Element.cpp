/*
162. Find Peak Element
Solved
Medium
Topics
Companies
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
 

Constraints:

1 <= nums.length <= 1000
-231 <= nums[i] <= 231 - 1
nums[i] != nums[i + 1] for all valid i.
*/

/*
 * Intuition:
 * The problem is to find a peak element in an array. A peak element is an element that is greater than its neighbors.
 * This solution uses a linear scan to find the maximum element, which will also be a peak element.
 *
 * Time Complexity: O(n), where n is the number of elements in the array, since we scan through the array once.
 * Space Complexity: O(1), as we only use a constant amount of extra space.
 */

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int mx = 0; // Initialize the index of the maximum element
        int n = nums.size();

        // Iterate through the array to find the index of the maximum element
        for(int i = 0; i < n; i++){
            if(nums[mx] < nums[i])
                mx = i;
        }

        // Return the index of the maximum (peak) element
        return mx;
    }
};
