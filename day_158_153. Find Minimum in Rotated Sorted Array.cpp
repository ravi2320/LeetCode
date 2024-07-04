/*
153. Find Minimum in Rotated Sorted Array
Solved
Medium
Topics
Companies
Hint
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
Example 2:

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
Example 3:

Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 
 

Constraints:

n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
All the integers of nums are unique.
nums is sorted and rotated between 1 and n times.
*/

/*
 * Intuition:
 * The problem is to find the minimum element in a rotated sorted array.
 * By leveraging the properties of the rotated sorted array and using binary search, we can find the minimum element in O(log n) time.
 * 
 * Time Complexity: O(log n), where n is the number of elements in the array. This is due to the binary search approach.
 * Space Complexity: O(1), as we are using a constant amount of extra space.
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int ans = INT_MAX;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // If the left part is sorted
            if (nums[left] <= nums[mid]) {
                // The minimum must be in the left part
                ans = min(ans, nums[left]);
                left = mid + 1;
            } 
            // If the right part is sorted
            else {
                // The minimum must be in the right part
                ans = min(ans, nums[mid]);
                right = mid - 1;
            }
        }

        return ans;
    }
};
