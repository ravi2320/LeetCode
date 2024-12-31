/*
983. Minimum Cost For Tickets
Solved
Medium
Topics
Companies
You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

Train tickets are sold in three different ways:

a 1-day pass is sold for costs[0] dollars,
a 7-day pass is sold for costs[1] dollars, and
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.

For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
Return the minimum number of dollars you need to travel every day in the given list of days.

 

Example 1:

Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total, you spent $11 and covered all the days of your travel.
Example 2:

Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
Output: 17
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1, 2, ..., 30.
On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
In total, you spent $17 and covered all the days of your travel.
 

Constraints:

1 <= days.length <= 365
1 <= days[i] <= 365
days is in strictly increasing order.
costs.length == 3
1 <= costs[i] <= 1000
*/

/*
Approach:
The problem is solved using dynamic programming with memoization. We aim to find the minimum cost to cover all the given days with three types of passes:
1. 1-day pass
2. 7-day pass
3. 30-day pass

Steps:
1. **Recursive Function `solve`**:
   - For each day `i`, calculate the minimum cost by considering three cases:
     - Buy a 1-day pass.
     - Buy a 7-day pass.
     - Buy a 30-day pass.
   - Use a helper loop to find the next valid day that each pass covers.

2. **Memoization**:
   - Store results in a `t` array to avoid redundant calculations.

3. **Base Case**:
   - If we have processed all days, return 0.

4. **Initialization and Execution**:
   - The `mincostTickets` function initializes the memoization array and starts the recursive process from the first day.

Time Complexity:
- Each day is processed at most once for each pass type: O(n).
- Finding the next valid day for 7-day and 30-day passes is O(n), leading to a total complexity of O(n^2) in the worst case.

Space Complexity:
- Memoization array `t`: O(n).
- Recursive stack depth: O(n).

Edge Cases:
1. Single travel day.
2. Sparse travel days spread over months.
3. Frequent travel over consecutive days.

*/

class Solution {
    int t[366]; // Memoization array, as days are constrained to 1-365
public:
    // Recursive helper function
    int solve(vector<int>& days, vector<int>& costs, int n, int i) {
        // Base case: No more days to process
        if (i >= n) {
            return 0;
        }

        // Return the memoized result if already calculated
        if (t[i] != -1) {
            return t[i];
        }

        // Cost for a 1-day pass
        int day_1 = costs[0] + solve(days, costs, n, i + 1);

        // Cost for a 7-day pass
        int j = i;
        int maxDays = days[i] + 7; // End day for 7-day pass
        while (j < n && days[j] < maxDays) {
            j++;
        }
        int day_7 = costs[1] + solve(days, costs, n, j);

        // Cost for a 30-day pass
        j = i;
        maxDays = days[i] + 30; // End day for 30-day pass
        while (j < n && days[j] < maxDays) {
            j++;
        }
        int day_30 = costs[2] + solve(days, costs, n, j);

        // Store and return the minimum cost
        return t[i] = min({day_1, day_7, day_30});
    }

    // Main function to calculate the minimum cost of tickets
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        memset(t, -1, sizeof(t)); // Initialize memoization array with -1
        return solve(days, costs, n, 0); // Start solving from the first day
    }
};

/*
Approach:
This solution uses a dynamic programming approach to minimize the cost of tickets for a series of travel days. The key idea is to maintain a DP array where each index `i` represents the minimum cost to cover travel up to day `i`.

Steps:
1. **Preprocessing**:
   - Use an unordered set to mark travel days for quick lookup.
   - Determine the last travel day (`lastDay`) from the input `days`.

2. **Dynamic Programming Array**:
   - Use a vector `t` of size `lastDay + 1` initialized to 0, where `t[i]` stores the minimum cost to cover travel days up to day `i`.

3. **Iterative Calculation**:
   - For each day `i` from 1 to `lastDay`:
     - If `i` is not a travel day, copy the value from the previous day (`t[i] = t[i-1]`).
     - Otherwise, compute the cost for three pass options:
       - 1-day pass: `costs[0] + t[i-1]`
       - 7-day pass: `costs[1] + t[max(0, i-7)]`
       - 30-day pass: `costs[2] + t[max(0, i-30)]`
     - Store the minimum of the three options in `t[i]`.

4. **Result**:
   - The answer is stored in `t[lastDay]`.

Time Complexity:
- O(lastDay), where `lastDay` is the largest travel day. Each day from 1 to `lastDay` is processed once.

Space Complexity:
- O(lastDay) for the DP array.

Edge Cases:
1. Single travel day.
2. Sparse travel days across a year.
3. Continuous travel days for weeks/months.

*/

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // Use a set to quickly check if a day is a travel day
        unordered_set<int> st(days.begin(), days.end());
        
        // Last day of travel
        int lastDay = days.back();

        // DP array to store minimum cost up to each day
        vector<int> t(lastDay + 1, 0);

        // Fill the DP array
        for (int i = 1; i <= lastDay; i++) {
            // If it's not a travel day, cost remains the same as the previous day
            if (st.find(i) == st.end()) {
                t[i] = t[i - 1];
                continue;
            }

            // Cost for a 1-day pass
            int day_1 = costs[0] + t[i - 1];

            // Cost for a 7-day pass
            int day_7 = costs[1] + t[max(i - 7, 0)];

            // Cost for a 30-day pass
            int day_30 = costs[2] + t[max(i - 30, 0)];

            // Store the minimum cost
            t[i] = min({day_1, day_7, day_30});
        }

        // Return the cost for the last travel day
        return t[lastDay];
    }
};