/*
2192. All Ancestors of a Node in a Directed Acyclic Graph
Solved
Medium
Topics
Companies
Hint
You are given a positive integer n representing the number of nodes of a Directed Acyclic Graph (DAG). The nodes are numbered from 0 to n - 1 (inclusive).

You are also given a 2D integer array edges, where edges[i] = [fromi, toi] denotes that there is a unidirectional edge from fromi to toi in the graph.

Return a list answer, where answer[i] is the list of ancestors of the ith node, sorted in ascending order.

A node u is an ancestor of another node v if u can reach v via a set of edges.

 

Example 1:


Input: n = 8, edgeList = [[0,3],[0,4],[1,3],[2,4],[2,7],[3,5],[3,6],[3,7],[4,6]]
Output: [[],[],[],[0,1],[0,2],[0,1,3],[0,1,2,3,4],[0,1,2,3]]
Explanation:
The above diagram represents the input graph.
- Nodes 0, 1, and 2 do not have any ancestors.
- Node 3 has two ancestors 0 and 1.
- Node 4 has two ancestors 0 and 2.
- Node 5 has three ancestors 0, 1, and 3.
- Node 6 has five ancestors 0, 1, 2, 3, and 4.
- Node 7 has four ancestors 0, 1, 2, and 3.
Example 2:


Input: n = 5, edgeList = [[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Output: [[],[0],[0,1],[0,1,2],[0,1,2,3]]
Explanation:
The above diagram represents the input graph.
- Node 0 does not have any ancestor.
- Node 1 has one ancestor 0.
- Node 2 has two ancestors 0 and 1.
- Node 3 has three ancestors 0, 1, and 2.
- Node 4 has four ancestors 0, 1, 2, and 3.
 

Constraints:

1 <= n <= 1000
0 <= edges.length <= min(2000, n * (n - 1) / 2)
edges[i].length == 2
0 <= fromi, toi <= n - 1
fromi != toi
There are no duplicate edges.
The graph is directed and acyclic.
*/

// Intuition:
// The problem involves finding all ancestors for each node in a directed graph. We can use Depth-First Search (DFS) to explore all paths from each node and record ancestors accordingly.
// For each node, we initiate a DFS to explore all its descendants. While exploring, we keep track of the ancestor node and update the results vector.

// Time Complexity: O(n + e), where n is the number of nodes and e is the number of edges. Each node and edge is processed once during the DFS traversal.
// Space Complexity: O(n + e), to store the adjacency list and the result list, and also considering the recursion stack space in the worst case.

class Solution {
public:
    // DFS function to explore all descendants and record the ancestor.
    void DFS(int ancestor, unordered_map<int, vector<int>> &adj, int currNode, vector<vector<int>> &res) {
        // Iterate over each neighbor of the current node.
        for(int neighbour : adj[currNode]) {
            // If the ancestor is not already recorded for the neighbor, record it.
            if(res[neighbour].empty() || res[neighbour].back() != ancestor) {
                res[neighbour].push_back(ancestor);
                // Continue DFS traversal with the neighbor as the current node.
                DFS(ancestor, adj, neighbour, res);
            }
        }
    }

    // Function to get ancestors for each node in a directed graph.
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> res(n); // Result vector to store ancestors of each node.
        unordered_map<int, vector<int>> adj; // Adjacency list to represent the graph.

        // Construct the adjacency list from the edges.
        for(vector<int> &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }

        // Perform DFS for each node to find and record ancestors.
        for(int i = 0; i < n; i++) {
            int ancestor = i;
            DFS(ancestor, adj, i, res);
        }

        return res; // Return the result vector containing ancestors for each node.
    }
};
