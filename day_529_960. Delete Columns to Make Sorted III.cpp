/*
960. Delete Columns to Make Sorted III

avatar
Discuss Approach
arrow-up
Solved
Hard
Topics
premium lock icon
Companies
You are given an array of n strings strs, all of the same length.

We may choose any deletion indices, and we delete all the characters in those indices for each string.

For example, if we have strs = ["abcdef","uvwxyz"] and deletion indices {0, 2, 3}, then the final array after deletions is ["bef", "vyz"].

Suppose we chose a set of deletion indices answer such that after deletions, the final array has every string (row) in lexicographic order. (i.e., (strs[0][0] <= strs[0][1] <= ... <= strs[0][strs[0].length - 1]), and (strs[1][0] <= strs[1][1] <= ... <= strs[1][strs[1].length - 1]), and so on). Return the minimum possible value of answer.length.

 

Example 1:

Input: strs = ["babca","bbazb"]
Output: 3
Explanation: After deleting columns 0, 1, and 4, the final array is strs = ["bc", "az"].
Both these rows are individually in lexicographic order (ie. strs[0][0] <= strs[0][1] and strs[1][0] <= strs[1][1]).
Note that strs[0] > strs[1] - the array strs is not necessarily in lexicographic order.
Example 2:

Input: strs = ["edcba"]
Output: 4
Explanation: If we delete less than 4 columns, the only row will not be lexicographically sorted.
Example 3:

Input: strs = ["ghi","def","abc"]
Output: 0
Explanation: All rows are already lexicographically sorted.
 

Constraints:

n == strs.length
1 <= n <= 100
1 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/

/*
Approach:
---------
We are given an array of strings, all having the same length.
We want to delete the minimum number of columns so that the resulting
columns are **lexicographically non-decreasing** for every row.

Instead of deciding which columns to delete directly, we reframe the problem:
- Find the **longest sequence of columns** that can be kept
- Such that for every row, characters are non-decreasing across these columns

This becomes a variant of **Longest Increasing Subsequence (LIS)**,
where each column acts as an element.

Steps:
------
1. Let:
     - rows = number of strings
     - cols = length of each string
2. Use DP where:
     dp[i] = length of the longest valid column sequence ending at column i
3. For each pair of columns (j < i):
     - Check if column j can come before column i
     - This is valid if for every row k:
           strs[k][j] <= strs[k][i]
4. If valid:
     dp[i] = max(dp[i], dp[j] + 1)
5. The answer is:
     cols - LIS (minimum deletions)

Intuition:
----------
We want to keep as many columns as possible that preserve the sorted order
in every row. Removing fewer columns is equivalent to keeping a longest
valid column subsequence.

This is similar to LIS but with a custom comparison across all rows.

Time Complexity:
----------------
O(cols² * rows)
- cols² comparisons of column pairs
- rows comparisons per pair

Space Complexity:
-----------------
O(cols)
- DP array to store LIS values

*/

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int cols = strs[0].length();

        // dp[i] = length of longest valid column sequence ending at i
        vector<int> dp(cols, 1);

        int LIS = 1;

        // Try to extend sequences ending at each column
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < i; j++) {

                bool isSafe = true;

                // Check if column j can precede column i
                for (int k = 0; k < rows; k++) {
                    if (strs[k][j] > strs[k][i]) {
                        isSafe = false;
                        break;
                    }
                }

                // Update LIS dp
                if (isSafe) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            // Track maximum LIS length
            LIS = max(LIS, dp[i]);
        }

        // Minimum deletions required
        return cols - LIS;
    }
};
