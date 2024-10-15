/*
216. Combination Sum III
Solved
Medium
Topics
Companies
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

 

Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.
Example 3:

Input: k = 4, n = 1
Output: []
Explanation: There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.
 

Constraints:

2 <= k <= 9
1 <= n <= 60
*/

/*
Approach:
- This solution is a recursive backtracking approach to find all combinations of `k` distinct numbers that add up to `n`.
- The function `solve` is responsible for exploring combinations starting from a given index `idx`, trying all numbers between `idx` and 9.
- It stops exploring further combinations when the sum `n` becomes negative, meaning it is impossible to form a valid combination from that point.
- If `n` becomes 0 and the current combination's size equals `k`, the combination is added to the result.
- A simple pruning condition is added: If at any point `n < 0`, we return early to save unnecessary recursive calls.
- Additionally, if `k > n` initially, we can return early as no valid combinations are possible in this case.

Time Complexity:
- O(9 choose k), or O(C(9, k)), which is the number of ways to choose `k` numbers from 9 distinct options. This is due to the nature of the backtracking algorithm.
- Since `k` can be at most 9, the worst-case time complexity is O(2^9).

Space Complexity:
- O(k) for the recursion stack and the temporary array `curr` used to store the current combination.

*/

class Solution {
public:
    // Helper function for recursive backtracking
    void solve(int idx, int k, int n, vector<int> &curr, vector<vector<int>> &res) {
        // Base case: If the sum `n` becomes negative, stop the recursion
        if (n < 0) return;

        // If sum becomes 0 and the current combination has `k` numbers, add to result
        if (n == 0 && curr.size() == k) {
            res.push_back(curr);
            return;
        }

        // Try numbers from `idx` to 9, ensuring that we pick distinct numbers
        for (int i = idx; i <= 9 && i <= n; i++) {
            curr.push_back(i);  // Include number in the current combination
            solve(i + 1, k, n - i, curr, res);  // Recur for remaining sum and next number
            curr.pop_back();  // Backtrack by removing the number
        }
    }

    // Main function to find all valid combinations
    vector<vector<int>> combinationSum3(int k, int n) {
        // Early return if `k > n`, as no combination is possible in that case
        if (k > n) return {};

        vector<vector<int>> res;  // Result container to store all valid combinations
        vector<int> curr;  // Temporary array to store current combination
        solve(1, k, n, curr, res);  // Start backtracking from number 1

        return res;  // Return the result
    }
};
