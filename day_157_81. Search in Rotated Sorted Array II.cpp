/*
81. Search in Rotated Sorted Array II
Solved
Medium
Topics
Companies
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.

 

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
nums is guaranteed to be rotated at some pivot.
-104 <= target <= 104
*/

// Intuition:
// The problem is to search for a target value in a rotated sorted array with possible duplicates.
// We use a modified binary search approach to efficiently find the target:
// - Check the middle element and adjust the search range based on whether the left or right half is sorted.
// - Handle the special case where elements at both ends and the middle are the same (duplicates) by moving the pointers inward.

// Time Complexity: O(log n), where n is the number of elements in the array. Each step of the binary search reduces the search space by half.
// Space Complexity: O(1), constant extra space is used.

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){

            int mid = left + (right - left) / 2;

            // If mid is the target
            if(nums[mid] == target)
                return true;

            // Handle duplicates scenario where nums[left] == nums[mid] == nums[right]
            if(nums[left] == nums[mid] && nums[mid] == nums[right]){
                left++;
                right--;
            }

            // If left half is sorted
            else if(nums[left] <= nums[mid]){
                // If target is within the sorted left half
                if(nums[left] <= target && target < nums[mid])
                    right = mid - 1; // Search left
                else
                    left = mid + 1; // Search right
            }

            // If right half is sorted
            else {
                // If target is within the sorted right half
                if(nums[mid] < target && target <= nums[right])
                    left = mid + 1; // Search right
                else
                    right = mid - 1; // Search left
            }
        }

        return false; // Target not found
    }
};
