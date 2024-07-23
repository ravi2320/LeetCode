/*
2392. Build a Matrix With Conditions
Solved
Hard
Topics
Companies
Hint
You are given a positive integer k. You are also given:

a 2D integer array rowConditions of size n where rowConditions[i] = [abovei, belowi], and
a 2D integer array colConditions of size m where colConditions[i] = [lefti, righti].
The two arrays contain integers from 1 to k.

You have to build a k x k matrix that contains each of the numbers from 1 to k exactly once. The remaining cells should have the value 0.

The matrix should also satisfy the following conditions:

The number abovei should appear in a row that is strictly above the row at which the number belowi appears for all i from 0 to n - 1.
The number lefti should appear in a column that is strictly left of the column at which the number righti appears for all i from 0 to m - 1.
Return any matrix that satisfies the conditions. If no answer exists, return an empty matrix.

 

Example 1:


Input: k = 3, rowConditions = [[1,2],[3,2]], colConditions = [[2,1],[3,2]]
Output: [[3,0,0],[0,0,1],[0,2,0]]
Explanation: The diagram above shows a valid example of a matrix that satisfies all the conditions.
The row conditions are the following:
- Number 1 is in row 1, and number 2 is in row 2, so 1 is above 2 in the matrix.
- Number 3 is in row 0, and number 2 is in row 2, so 3 is above 2 in the matrix.
The column conditions are the following:
- Number 2 is in column 1, and number 1 is in column 2, so 2 is left of 1 in the matrix.
- Number 3 is in column 0, and number 2 is in column 1, so 3 is left of 2 in the matrix.
Note that there may be multiple correct answers.
Example 2:

Input: k = 3, rowConditions = [[1,2],[2,3],[3,1],[2,3]], colConditions = [[2,1]]
Output: []
Explanation: From the first two conditions, 3 has to be below 1 but the third conditions needs 3 to be above 1 to be satisfied.
No matrix can satisfy all the conditions, so we return the empty matrix.
 

Constraints:

2 <= k <= 400
1 <= rowConditions.length, colConditions.length <= 104
rowConditions[i].length == colConditions[i].length == 2
1 <= abovei, belowi, lefti, righti <= k
abovei != belowi
lefti != righti
*/

/**
 * Intuition:
 * 1. **Topological Sorting:** Use Kahn's algorithm to get a valid topological order for the row and column conditions.
 * 2. **Matrix Construction:** Map the positions according to the topological order obtained from the conditions.
 * 3. **Edge Cases:** If a valid topological order cannot be obtained (cycle in graph), return an empty matrix.
 *
 * Time Complexity: O(k + E)
 * - O(k) for initializing graph structures and O(E) for processing each edge in the conditions.
 *
 * Space Complexity: O(k + E)
 * - Space for graph representation and storage for the in-degree of each node.
 */

class Solution {
public:
    // Function to build a k x k matrix given row and column conditions
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        // Obtain topological orders for row and column conditions
        vector<int> rowOrder = kahn(rowConditions, k);
        vector<int> colOrder = kahn(colConditions, k);

        // Check if valid topological order was obtained for both row and column conditions
        if (rowOrder.size() < k || colOrder.size() < k)
            return {};

        // Map to store the column position of each element according to colOrder
        unordered_map<int, int> colPosition;
        vector<vector<int>> ans(k, vector<int>(k, 0));

        // Assign column positions based on colOrder
        for (int i = 0; i < k; ++i) {
            colPosition[colOrder[i]] = i;
        }

        // Fill the matrix using the positions from rowOrder and colPosition
        for (int i = 0; i < k; ++i) {
            int row = rowOrder[i];
            int col = colPosition[row];
            ans[i][col] = row;
        }

        return ans;
    }

private:
    // Function to perform Kahn's algorithm for topological sorting
    vector<int> kahn(vector<vector<int>>& conditions, int k) {
        vector<vector<int>> graph(k + 1);  // Graph adjacency list
        vector<int> degree(k + 1, 0);      // In-degree of each node

        // Build the graph and compute in-degrees
        for (auto& condition : conditions) {
            graph[condition[0]].push_back(condition[1]);
            degree[condition[1]]++;
        }

        queue<int> q;
        // Enqueue nodes with in-degree of 0
        for (int i = 1; i <= k; ++i) {
            if (degree[i] == 0)
                q.push(i);
        }

        vector<int> ans;  // Resultant topological order
        // Perform Kahn's algorithm
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (int neighbour : graph[node]) {
                degree[neighbour]--;
                if (degree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        return ans;
    }
};
