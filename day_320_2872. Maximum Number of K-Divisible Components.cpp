/*
2872. Maximum Number of K-Divisible Components
Solved
Hard
Topics
Companies
Hint
There is an undirected tree with n nodes labeled from 0 to n - 1. You are given the integer n and a 2D integer array edges of length n - 1, where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

You are also given a 0-indexed integer array values of length n, where values[i] is the value associated with the ith node, and an integer k.

A valid split of the tree is obtained by removing any set of edges, possibly empty, from the tree such that the resulting components all have values that are divisible by k, where the value of a connected component is the sum of the values of its nodes.

Return the maximum number of components in any valid split.

 

Example 1:


Input: n = 5, edges = [[0,2],[1,2],[1,3],[2,4]], values = [1,8,1,4,4], k = 6
Output: 2
Explanation: We remove the edge connecting node 1 with 2. The resulting split is valid because:
- The value of the component containing nodes 1 and 3 is values[1] + values[3] = 12.
- The value of the component containing nodes 0, 2, and 4 is values[0] + values[2] + values[4] = 6.
It can be shown that no other valid split has more than 2 connected components.
Example 2:


Input: n = 7, edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]], values = [3,0,6,1,5,2,1], k = 3
Output: 3
Explanation: We remove the edge connecting node 0 with 2, and the edge connecting node 0 with 1. The resulting split is valid because:
- The value of the component containing node 0 is values[0] = 3.
- The value of the component containing nodes 2, 5, and 6 is values[2] + values[5] + values[6] = 9.
- The value of the component containing nodes 1, 3, and 4 is values[1] + values[3] + values[4] = 6.
It can be shown that no other valid split has more than 3 connected components.
 

Constraints:

1 <= n <= 3 * 104
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
values.length == n
0 <= values[i] <= 109
1 <= k <= 109
Sum of values is divisible by k.
The input is generated such that edges represents a valid tree.
*/

/*
Approach:
The problem involves determining the maximum number of connected components in a tree where each component's total sum of values is divisible by `k`. The solution uses a post-order traversal approach to propagate and combine values while checking divisibility.

Steps:
1. Build an adjacency list to represent the tree.
2. Use a queue to simulate a post-order traversal of the tree. Start with leaf nodes.
3. For each node:
   - Check if its value modulo `k` is 0, and count it as a valid component.
   - Propagate its modular value to its parent node.
   - Reduce the degree (number of neighbors) of its parent, and push the parent into the queue when it becomes a leaf.
4. The final result is the count of components.

Edge Cases:
1. Single-node tree.
2. All values are multiples of `k`.
3. No value is divisible by `k`.

Time Complexity:
- O(n): Each node and edge is visited once.

Space Complexity:
- O(n): For the adjacency list and additional data structures.

*/

class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        unordered_map<int, vector<int>> adj;
        vector<int> neighbour(n, 0);

        // Build adjacency list
        for (vector<int>& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        queue<int> q;
        // Initialize neighbor counts and queue leaf nodes
        for (int i = 0; i < n; i++) {
            neighbour[i] = adj[i].size();
            if (adj[i].size() == 1) { // Leaf node
                q.push(i);
            }
        }

        int ans = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            // Check if the current node's value is divisible by k
            if (values[node] % k == 0) {
                ans++;
            }

            for (int& ngbr : adj[node]) {
                if (neighbour[ngbr] > 0) { 
                    // Update the neighbor's value with modular arithmetic
                    values[ngbr] = (values[ngbr] + values[node]) % k;
                    neighbour[ngbr]--;

                    // Push to the queue if it becomes a leaf
                    if (neighbour[ngbr] == 1) {
                        q.push(ngbr);
                    }
                }
            }
        }

        // At least one component will always exist
        return max(ans, 1);
    }
};
