/*
2110. Number of Smooth Descent Periods of a Stock

avatar
Discuss Approach
arrow-up
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given an integer array prices representing the daily price history of a stock, where prices[i] is the stock price on the ith day.

A smooth descent period of a stock consists of one or more contiguous days such that the price on each day is lower than the price on the preceding day by exactly 1. The first day of the period is exempted from this rule.

Return the number of smooth descent periods.

 

Example 1:

Input: prices = [3,2,1,4]
Output: 7
Explanation: There are 7 smooth descent periods:
[3], [2], [1], [4], [3,2], [2,1], and [3,2,1]
Note that a period with one day is a smooth descent period by the definition.
Example 2:

Input: prices = [8,6,7,7]
Output: 4
Explanation: There are 4 smooth descent periods: [8], [6], [7], and [7]
Note that [8,6] is not a smooth descent period as 8 - 6 ≠ 1.
Example 3:

Input: prices = [1]
Output: 1
Explanation: There is 1 smooth descent period: [1]
 

Constraints:

1 <= prices.length <= 105
1 <= prices[i] <= 105
*/

/*
Approach:
---------
We need to count the number of "smooth descent periods" in the prices array.
A smooth descent period is a contiguous subarray where:
    prices[k] - prices[k+1] = 1  for all consecutive elements.

Key idea:
---------
Use a sliding window / two-pointer approach.
Maintain a window [i, j] where the descent condition holds.
Whenever the condition breaks, reset the starting pointer `i`.

Steps:
------
1. Initialize:
     - ans = 1 (every single element is a valid descent period)
     - i = 0 (start of current valid window)
2. Iterate j from 1 to n-1:
     - If prices[j-1] - prices[j] != 1:
           reset i = j (new window starts)
     - Number of valid subarrays ending at j = (j - i + 1)
     - Add this to ans
3. Return ans.

Intuition:
----------
For every index j, we count how many descent subarrays end at j.
If the descent condition holds continuously from i to j,
then all subarrays starting at any index between i and j
and ending at j are valid.

Time Complexity:
----------------
O(n) — Single pass through the array.

Space Complexity:
-----------------
O(1) — Constant extra space.

*/

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 1;      // Each individual element is a valid descent period
        int i = 0;
        int n = prices.size();

        // Traverse the prices array
        for (int j = 1; j < n; j++) {
            
            // If descent condition breaks, start a new window
            if (prices[j - 1] - prices[j] != 1)
                i = j;

            // Count all descent subarrays ending at j
            ans += (j - i + 1);
        }

        return ans;
    }
};
