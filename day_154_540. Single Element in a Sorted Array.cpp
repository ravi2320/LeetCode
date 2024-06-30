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

// Intuition:
// The problem involves finding the single non-duplicate element in an array where every other element appears exactly twice. Using the XOR operation, we can efficiently find the non-duplicate element because XOR-ing a number with itself results in 0, and XOR-ing with 0 results in the number itself. Thus, XOR-ing all elements in the array will cancel out all elements that appear twice, leaving only the non-duplicate element.

// Time Complexity: O(n), where n is the number of elements in the array. Each element is processed once.
// Space Complexity: O(1), as we only use a constant amount of additional space.

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int Xor = 0; // Variable to store the XOR result.
        int n = nums.size(); // Get the size of the array.

        // XOR all elements in the array.
        for(int i = 0; i < n; i++) {
            Xor ^= nums[i];
        }

        return Xor; // The result is the single non-duplicate element.
    }
};
