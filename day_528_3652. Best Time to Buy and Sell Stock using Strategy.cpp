/*
3652. Best Time to Buy and Sell Stock using Strategy

avatar
Discuss Approach
arrow-up
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given two integer arrays prices and strategy, where:

prices[i] is the price of a given stock on the ith day.
strategy[i] represents a trading action on the ith day, where:
-1 indicates buying one unit of the stock.
0 indicates holding the stock.
1 indicates selling one unit of the stock.
You are also given an even integer k, and may perform at most one modification to strategy. A modification consists of:

Selecting exactly k consecutive elements in strategy.
Set the first k / 2 elements to 0 (hold).
Set the last k / 2 elements to 1 (sell).
The profit is defined as the sum of strategy[i] * prices[i] across all days.

Return the maximum possible profit you can achieve.

Note: There are no constraints on budget or stock ownership, so all buy and sell operations are feasible regardless of past actions.

 

Example 1:

Input: prices = [4,2,8], strategy = [-1,0,1], k = 2

Output: 10

Explanation:

Modification	Strategy	Profit Calculation	Profit
Original	[-1, 0, 1]	(-1 × 4) + (0 × 2) + (1 × 8) = -4 + 0 + 8	4
Modify [0, 1]	[0, 1, 1]	(0 × 4) + (1 × 2) + (1 × 8) = 0 + 2 + 8	10
Modify [1, 2]	[-1, 0, 1]	(-1 × 4) + (0 × 2) + (1 × 8) = -4 + 0 + 8	4
Thus, the maximum possible profit is 10, which is achieved by modifying the subarray [0, 1]​​​​​​​.

Example 2:

Input: prices = [5,4,3], strategy = [1,1,0], k = 2

Output: 9

Explanation:

Modification	Strategy	Profit Calculation	Profit
Original	[1, 1, 0]	(1 × 5) + (1 × 4) + (0 × 3) = 5 + 4 + 0	9
Modify [0, 1]	[0, 1, 0]	(0 × 5) + (1 × 4) + (0 × 3) = 0 + 4 + 0	4
Modify [1, 2]	[1, 0, 1]	(1 × 5) + (0 × 4) + (1 × 3) = 5 + 0 + 3	8
Thus, the maximum possible profit is 9, which is achieved without any modification.

 

Constraints:

2 <= prices.length == strategy.length <= 105
1 <= prices[i] <= 105
-1 <= strategy[i] <= 1
2 <= k <= prices.length
k is even
*/

/*
Approach:
---------
We are given:
- prices[i]   → stock price on day i
- strategy[i] → original action taken on day i (-1 sell, 0 hold, +1 buy)
- k           → length of a window where the strategy can be modified

Goal:
-----
Maximize total profit by modifying the strategy for exactly one subarray
(window) of length k.

Key Observations:
-----------------
1. Original profit for each day:
        profit[i] = strategy[i] * prices[i]
2. Total original profit is the sum of all profit[i].
3. When modifying a window of length k:
   - First k/2 days → forced SELL (profit = -prices[i])
   - Second k/2 days → forced BUY (profit = +prices[i])

4. We compute:
   - originalWindowProfit: profit under original strategy
   - modifiedWindowProfit: profit under modified strategy

The gain from modifying a window:
        gain = modifiedWindowProfit - originalWindowProfit

We want to maximize this gain using a sliding window.

Intuition:
----------
Instead of recalculating profits for every possible window (O(nk)),
we slide a window of size k and update profits incrementally.
This keeps the solution efficient and clean.

Time Complexity:
----------------
O(n) — Sliding window processes each element once.

Space Complexity:
-----------------
O(n) — Profit array is used to store original profits.

*/

class Solution {
public:
    typedef long long ll;

    ll maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();

        ll actualProfit = 0;
        vector<ll> profit(n); // Original profit for each day

        // Calculate original profit
        for (int i = 0; i < n; i++) {
            profit[i] = (ll)strategy[i] * prices[i];
            actualProfit += profit[i];
        }

        ll originalWindowProfit = 0;   // Profit under original strategy
        ll modifiedWindowProfit = 0;   // Profit under modified strategy
        ll maxGain = 0;                // Maximum extra profit achievable

        int i = 0, j = 0;

        // Sliding window technique
        while (j < n) {

            // Add current day's original profit
            originalWindowProfit += profit[j];

            // Second half of window contributes positive prices
            if (j - i + 1 > k / 2) {
                modifiedWindowProfit += prices[j];
            }

            // Shrink window if it exceeds size k
            if (j - i + 1 > k) {
                originalWindowProfit -= profit[i];
                modifiedWindowProfit -= prices[i + k / 2];
                i++;
            }

            // When window size is exactly k, evaluate gain
            if (j - i + 1 == k) {
                maxGain = max(maxGain, modifiedWindowProfit - originalWindowProfit);
            }

            j++;
        }

        return actualProfit + maxGain;
    }
};
