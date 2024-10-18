/*
2044. Count Number of Maximum Bitwise-OR Subsets
Solved
Medium
Topics
Companies
Hint
Given an integer array nums, find the maximum possible bitwise OR of a subset of nums and return the number of different non-empty subsets with the maximum bitwise OR.

An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b. Two subsets are considered different if the indices of the elements chosen are different.

The bitwise OR of an array a is equal to a[0] OR a[1] OR ... OR a[a.length - 1] (0-indexed).

 

Example 1:

Input: nums = [3,1]
Output: 2
Explanation: The maximum possible bitwise OR of a subset is 3. There are 2 subsets with a bitwise OR of 3:
- [3]
- [3,1]
Example 2:

Input: nums = [2,2,2]
Output: 7
Explanation: All non-empty subsets of [2,2,2] have a bitwise OR of 2. There are 23 - 1 = 7 total subsets.
Example 3:

Input: nums = [3,2,1,5]
Output: 6
Explanation: The maximum possible bitwise OR of a subset is 7. There are 6 subsets with a bitwise OR of 7:
- [3,5]
- [3,1,5]
- [3,2,5]
- [3,2,1,5]
- [2,5]
- [2,1,5]
 

Constraints:

1 <= nums.length <= 16
1 <= nums[i] <= 105
*/

/*
Approach:
- The problem is to find the number of subsets of a given array `nums` that yield the maximum bitwise OR value.
- We calculate the maximum OR value (`maxOr`) by performing bitwise OR on all elements of the array.
- Using backtracking, we explore all subsets and count how many of them have a bitwise OR equal to the maximum OR value.
- In the backtracking function `solve`, at each index `idx`, we either include the current number in the subset (by performing OR operation) or exclude it.
- The recursion continues until we process all elements, and for each subset with OR value equal to `maxOr`, we increment the count.

Time Complexity:
- O(2^n), where `n` is the number of elements in `nums`.
  - We generate all subsets of `nums`, which is 2^n.
  
Space Complexity:
- O(n), due to the recursion stack in the backtracking function.

*/

class Solution {
public:
    // Recursive function to count subsets with OR equal to maxOr
    int solve(int idx, int &maxOr, int currOr, vector<int> &nums, int n) {
        // Base case: If we've processed all elements
        if (idx == n) {
            // Check if the current OR value is equal to the maximum OR value
            if (currOr == maxOr)
                return 1;  // Count this subset
            return 0;  // This subset doesn't contribute to the count
        }

        // Option 1: Include the current number (OR it with the current OR value)
        int take = solve(idx + 1, maxOr, currOr | nums[idx], nums, n);

        // Option 2: Exclude the current number (OR value remains the same)
        int notTake = solve(idx + 1, maxOr, currOr, nums, n);

        // Return the total count of valid subsets
        return take + notTake;
    }

    // Function to count subsets with maximum OR value
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;  // Variable to store the maximum OR value

        // Calculate the maximum OR value by performing OR on all elements
        for (int &x : nums) {
            maxOr |= x;
        }

        // Start backtracking from index 0 with initial OR value of 0
        return solve(0, maxOr, 0, nums, nums.size());
    }
};