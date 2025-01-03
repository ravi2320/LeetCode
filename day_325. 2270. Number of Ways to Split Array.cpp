/*
2270. Number of Ways to Split Array
Solved
Medium
Topics
Companies
Hint
You are given a 0-indexed integer array nums of length n.

nums contains a valid split at index i if the following are true:

The sum of the first i + 1 elements is greater than or equal to the sum of the last n - i - 1 elements.
There is at least one element to the right of i. That is, 0 <= i < n - 1.
Return the number of valid splits in nums.

 

Example 1:

Input: nums = [10,4,-8,7]
Output: 2
Explanation: 
There are three ways of splitting nums into two non-empty parts:
- Split nums at index 0. Then, the first part is [10], and its sum is 10. The second part is [4,-8,7], and its sum is 3. Since 10 >= 3, i = 0 is a valid split.
- Split nums at index 1. Then, the first part is [10,4], and its sum is 14. The second part is [-8,7], and its sum is -1. Since 14 >= -1, i = 1 is a valid split.
- Split nums at index 2. Then, the first part is [10,4,-8], and its sum is 6. The second part is [7], and its sum is 7. Since 6 < 7, i = 2 is not a valid split.
Thus, the number of valid splits in nums is 2.
Example 2:

Input: nums = [2,3,1,0]
Output: 2
Explanation: 
There are two valid splits in nums:
- Split nums at index 1. Then, the first part is [2,3], and its sum is 5. The second part is [1,0], and its sum is 1. Since 5 >= 1, i = 1 is a valid split. 
- Split nums at index 2. Then, the first part is [2,3,1], and its sum is 6. The second part is [0], and its sum is 0. Since 6 >= 0, i = 2 is a valid split.
 

Constraints:

2 <= nums.length <= 105
-105 <= nums[i] <= 105
*/

/*
Approach:
1. Calculate the total sum of the array.
2. Traverse the array to calculate the prefix sum (`sum`) for each split point.
3. For each split, check if the prefix sum (`sum`) is greater than or equal to the remaining sum (`total - sum`).
4. Increment the count if the condition is satisfied.

Intuition:
To split the array such that the left part's sum is greater than or equal to the right part's sum, we only need to keep track of the running prefix sum and compare it with the remaining sum. This avoids recalculating sums for the right part in each iteration, making the solution efficient.

Time Complexity:
- Calculating the total sum: \(O(N)\), where \(N\) is the size of the array.
- Iterating through the array to calculate prefix sums and perform checks: \(O(N)\).
Overall: \(O(N)\).

Space Complexity:
- Constant space is used for variables, resulting in \(O(1)\) additional space.

*/

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        // Calculate the total sum of the array
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        int n = nums.size(); // Size of the array
        long long sum = 0;   // Running prefix sum
        int cnt = 0;         // Counter for valid splits

        // Iterate through the array to calculate prefix sums and check conditions
        for (int i = 0; i < n - 1; i++) { // Stop at n - 1 to ensure non-empty right part
            sum += nums[i]; // Update the prefix sum

            // Check if the left sum is greater than or equal to the right sum
            if (sum >= total - sum) {
                cnt++; // Increment the count of valid splits
            }
        }

        return cnt; // Return the total count of valid splits
    }
};
