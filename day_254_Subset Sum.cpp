/*
Subset Sum
Moderate
80/80
Average time to solve is 25m
Contributed by
75 upvotes
Problem statement
You are given an array 'A' of 'N' integers. You have to return true if there exists a subset of elements of 'A' that sums up to 'K'. Otherwise, return false.



For Example
'N' = 3, 'K' = 5, 'A' = [1, 2, 3].
Subset [2, 3] has sum equal to 'K'.
So our answer is True.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
4 13
4 3 5 2
Sample Output 1 :
No
Sample Input 2 :
5 14
4 2 5 6 7
Sample Output 2 :
Yes
Constraints :
1 <= 'N' <= 10^3
1 <= 'A[i]' <= 10^3
1 <= 'K' <= 10^3
Time Limit: 1 sec
*/

/*
Approach:
- We use dynamic programming with memoization to solve the subset sum problem.
- We maintain a DP table `dp[n][k]` where `dp[i][j]` indicates whether it is possible to get sum `j` using the first `i` elements of the array.
- The recursive function `solve(n, k, a, dp)` is used to check if a subset with sum `k` exists by including or excluding elements.

Time Complexity: O(n * k) where `n` is the size of the array and `k` is the target sum.
Space Complexity: O(n * k) for storing the DP table.
*/

#include <vector>
using namespace std;

bool solve(int n, int k, vector<int> &a, vector<vector<int>> &dp) {
    // Return the stored result if it's already computed
    if (dp[n][k] != -1) {
        return dp[n][k];
    }

    // Base case: If no elements left, we can form sum 0 only
    if (n == 0) {
        return k == 0;
    }

    // Check if we can form sum `k` without the current element
    if (solve(n - 1, k, a, dp)) {
        return dp[n][k] = true;
    }

    // Check if we can form sum `k` by including the current element
    if (a[n - 1] <= k && solve(n - 1, k - a[n - 1], a, dp)) {
        return dp[n][k] = true;
    }

    // If neither including nor excluding the current element works
    return dp[n][k] = false;
}

bool isSubsetPresent(int n, int k, vector<int> &a) {
    // Initialize DP table with -1 indicating uncomputed states
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

    // Call the recursive function with the initial parameters
    return solve(n, k, a, dp);
}
