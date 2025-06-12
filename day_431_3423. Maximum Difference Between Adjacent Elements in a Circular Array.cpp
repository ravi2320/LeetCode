/*
3423. Maximum Difference Between Adjacent Elements in a Circular Array
Solved
Easy
Topics
premium lock icon
Companies
Hint
Given a circular array nums, find the maximum absolute difference between adjacent elements.

Note: In a circular array, the first and last elements are adjacent.

 

Example 1:

Input: nums = [1,2,4]

Output: 3

Explanation:

Because nums is circular, nums[0] and nums[2] are adjacent. They have the maximum absolute difference of |4 - 1| = 3.

Example 2:

Input: nums = [-5,-10,-5]

Output: 5

Explanation:

The adjacent elements nums[0] and nums[1] have the maximum absolute difference of |-5 - (-10)| = 5.

 

Constraints:

2 <= nums.length <= 100
-100 <= nums[i] <= 100
*/

/*
Approach:
We are given a vector of integers and we need to find the maximum absolute difference
between adjacent elements in a circular manner. That means we also need to compare
the last element with the first element.

Intuition:
To find the maximum adjacent difference in a circular array, we loop through all
elements and for each element at index i, we compute the absolute difference with
element at (i+1) % n. This way, we ensure the circular comparison is included.

Time Complexity: O(n)
We traverse the entire array once to compute the maximum adjacent difference.

Space Complexity: O(1)
We use a constant amount of extra space to store the maximum difference.
*/

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxDiff = INT_MIN;  // to store the maximum absolute difference
        int n = nums.size();    // size of the input vector

        // Traverse through the array and compare each element with the next in circular fashion
        for(int i = 0; i < n; i++) {
            // Calculate the absolute difference between current and next (with wrap-around)
            int diff = abs(nums[i] - nums[(i + 1) % n]);
            // Update the maximum difference
            maxDiff = max(maxDiff, diff);
        }

        return maxDiff;  // return the final maximum adjacent difference
    }
};
