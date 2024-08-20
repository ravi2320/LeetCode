/*
540. Single Element in a Sorted Array
Solved
Medium
Topics
Companies
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 105
*/


class Solution {
public:
    /**
     * Intuition:
     * The problem requires finding the single non-duplicate element in a sorted array where every other element appears exactly twice. 
     * The approach leverages binary search to efficiently find this element in O(log n) time by exploiting the properties of the array.
     * - If we split the array into two halves at any index `mid`, one of these halves will always have an odd number of elements (if the single element is in that half).
     * - By checking the relationship between the middle element and its neighbors, we can decide which half to discard and continue the search.
     *
     * Time Complexity:
     * - O(log n) because we are using binary search to divide the search space by half at each step.
     *
     * Space Complexity:
     * - O(1) since the solution only uses a constant amount of additional space.
     */

    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 1, high = n - 2;

        // Edge cases: if the unique element is at the start or the end
        if (n == 1) return nums[0];               // Only one element
        if (nums[0] != nums[1]) return nums[0];   // Unique element at the beginning
        if (nums[n-1] != nums[n-2]) return nums[n-1]; // Unique element at the end

        // Binary search to find the single non-duplicate element
        while (low <= high) {
            int mid = (low + high) >> 1; // Middle index

            // Check if mid is the single element
            if (nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) {
                return nums[mid];
            }

            // Determine which half to search
            else if ((mid % 2 == 1 && nums[mid-1] == nums[mid]) || (mid % 2 == 0 && nums[mid] == nums[mid+1])) {
                low = mid + 1; // Move to the right half
            } else {
                high = mid - 1; // Move to the left half
            }
        }

        // If no element is found (this shouldn't happen given the problem constraints)
        return 0;
    }
};
