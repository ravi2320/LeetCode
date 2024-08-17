/*
1937. Maximum Number of Points with Cost
Solved
Medium
Topics
Companies
Hint
You are given an m x n integer matrix points (0-indexed). Starting with 0 points, you want to maximize the number of points you can get from the matrix.

To gain points, you must pick one cell in each row. Picking the cell at coordinates (r, c) will add points[r][c] to your score.

However, you will lose points if you pick a cell too far from the cell that you picked in the previous row. For every two adjacent rows r and r + 1 (where 0 <= r < m - 1), picking cells at coordinates (r, c1) and (r + 1, c2) will subtract abs(c1 - c2) from your score.

Return the maximum number of points you can achieve.

abs(x) is defined as:

x for x >= 0.
-x for x < 0.
 

Example 1:


Input: points = [[1,2,3],[1,5,1],[3,1,1]]
Output: 9
Explanation:
The blue cells denote the optimal cells to pick, which have coordinates (0, 2), (1, 1), and (2, 0).
You add 3 + 5 + 3 = 11 to your score.
However, you must subtract abs(2 - 1) + abs(1 - 0) = 2 from your score.
Your final score is 11 - 2 = 9.
Example 2:


Input: points = [[1,5],[2,3],[4,2]]
Output: 11
Explanation:
The blue cells denote the optimal cells to pick, which have coordinates (0, 1), (1, 1), and (2, 0).
You add 5 + 3 + 4 = 12 to your score.
However, you must subtract abs(1 - 1) + abs(1 - 0) = 1 from your score.
Your final score is 12 - 1 = 11.
 

Constraints:

m == points.length
n == points[r].length
1 <= m, n <= 105
1 <= m * n <= 105
0 <= points[r][c] <= 105
*/

/*
Intuition:
- The problem involves selecting points from a 2D grid where you can pick points row by row, ensuring that the selections maximize your score.
- The challenge is that each selection in the next row is penalized by the distance from the previous column.
- We use dynamic programming to calculate the maximum points that can be obtained while taking into account the penalty for moving between columns.

Time Complexity:
- The time complexity is O(n * m), where `n` is the number of rows and `m` is the number of columns. This is because we iterate over all elements of the matrix.

Space Complexity:
- The space complexity is O(m) for storing the previous row's results and the current row's results. Since we only need the previous and current rows to compute the next state, we reduce the space usage to O(m).

*/

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(), m = points[0].size();

        // Initialize `prev` to store the max points that can be obtained from the first row.
        vector<long long> prev(m);

        // Copy the points from the first row into `prev`.
        for(int col = 0; col < m; col++){
            prev[col] = points[0][col];
        }

        // Iterate over each subsequent row.
        for(int i = 1; i < n; i++){

            // Calculate the max possible points from the left for each column in the current row.
            vector<long long> left(m, 0);
            left[0] = prev[0];
            for(int j = 1; j < m; j++){
                left[j] = max(prev[j], left[j - 1] - 1);
            }

            // Calculate the max possible points from the right for each column in the current row.
            vector<long long> right(m, 0);
            right[m - 1] = prev[m - 1];
            for(int j = m - 2; j >= 0; j--){
                right[j] = max(prev[j], right[j + 1] - 1);
            }

            // Calculate the current row's maximum points by considering both left and right max points.
            vector<long long> curr(m);
            for(int j = 0; j < m; j++){
                curr[j] = points[i][j] + max(left[j], right[j]);
            }

            // Update `prev` to be the current row's results for the next iteration.
            prev = curr;
        }

        // The answer is the maximum value in the last row.
        return *max_element(prev.begin(), prev.end());
    }
};
