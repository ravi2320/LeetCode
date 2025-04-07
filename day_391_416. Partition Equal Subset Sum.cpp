/*
416. Partition Equal Subset Sum
Solved
Medium
Topics
Companies
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
*/

/*
Approach:
1. This problem is a classic variation of the **Subset Sum Problem**.
2. We are to determine if the input array can be split into two subsets with **equal sum**.
3. If total sum is odd, it's impossible to divide it equally → return false.
4. Use **top-down dynamic programming with memoization** (DFS + DP) to check if a subset with sum = totalSum / 2 exists.

Intuition:
- If we can find any subset of the array whose sum is half of the total sum, 
  then the rest of the array must form the other half, meaning partition is possible.

Time Complexity: **O(n * sum/2)**  
Space Complexity: **O(n * sum/2)** → due to the memoization table `dp`.

Where:
- `n` = number of elements in `nums`.
- `sum` = total sum of the array elements.
*/

class Solution {
    vector<vector<int>> dp; // Memoization table
    int n;

public:
    // Recursive function to check if a subset with reqSum can be formed starting from idx
    bool solve(int idx, int currSum, int &reqSum, vector<int> &nums) {
        // Base cases
        if (idx >= n || currSum > reqSum)
            return false;
        if (currSum == reqSum)
            return true;

        // Check memoization table
        if (dp[idx][currSum] != -1)
            return dp[idx][currSum];

        // Choice: take the current number or skip it
        bool take = solve(idx + 1, currSum + nums[idx], reqSum, nums);
        bool skip = solve(idx + 1, currSum, reqSum, nums);

        return dp[idx][currSum] = take || skip;
    }

    // Main function
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // If total sum is odd or 0, partition is not possible
        if (totalSum == 0 || totalSum % 2 != 0)
            return false;

        int reqSum = totalSum / 2;
        dp.resize(n, vector<int>(reqSum + 1, -1)); // Initialize dp with -1

        return solve(0, 0, reqSum, nums); // Start from index 0 and sum 0
    }
};
	