/*
3372. Maximize the Number of Target Nodes After Connecting Trees I
Solved
Medium
Topics
premium lock icon
Companies
Hint
There exist two undirected trees with n and m nodes, with distinct labels in ranges [0, n - 1] and [0, m - 1], respectively.

You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree. You are also given an integer k.

Node u is target to node v if the number of edges on the path from u to v is less than or equal to k. Note that a node is always target to itself.

Return an array of n integers answer, where answer[i] is the maximum possible number of nodes target to node i of the first tree if you have to connect one node from the first tree to another node in the second tree.

Note that queries are independent from each other. That is, for every query you will remove the added edge before proceeding to the next query.

 

Example 1:

Input: edges1 = [[0,1],[0,2],[2,3],[2,4]], edges2 = [[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]], k = 2

Output: [9,7,9,8,8]

Explanation:

For i = 0, connect node 0 from the first tree to node 0 from the second tree.
For i = 1, connect node 1 from the first tree to node 0 from the second tree.
For i = 2, connect node 2 from the first tree to node 4 from the second tree.
For i = 3, connect node 3 from the first tree to node 4 from the second tree.
For i = 4, connect node 4 from the first tree to node 4 from the second tree.

Example 2:

Input: edges1 = [[0,1],[0,2],[0,3],[0,4]], edges2 = [[0,1],[1,2],[2,3]], k = 1

Output: [6,3,3,3,3]

Explanation:

For every i, connect node i of the first tree with any node of the second tree.


 

Constraints:

2 <= n, m <= 1000
edges1.length == n - 1
edges2.length == m - 1
edges1[i].length == edges2[i].length == 2
edges1[i] = [ai, bi]
0 <= ai, bi < n
edges2[i] = [ui, vi]
0 <= ui, vi < m
The input is generated such that edges1 and edges2 represent valid trees.
0 <= k <= 1000
*/

/*
Approach:
- We are given two trees represented by edges1 and edges2.
- For every node in Tree1, we need to compute:
    - How many nodes are reachable from it within distance k in Tree1.
    - Plus, the **maximum** number of nodes reachable from any node in Tree2 within distance (k-1).
- To do this:
    1. Build adjacency lists for both trees.
    2. For every node, perform BFS to count reachable nodes within the specified distance.
    3. For Tree1: call bfs with distance k.
    4. For Tree2: call bfs with distance (k-1) and take the maximum among all nodes.
    5. Add max result of Tree2 to each result from Tree1.

Intuition:
- We're simulating information spread or influence from each node in two different trees.
- Tree1 nodes influence within distance k.
- Tree2 helps in boosting the influence range with (k-1) distance — the best node in Tree2 is added to all Tree1 nodes.

Time Complexity:
- Let N = number of nodes in Tree1 and M = number of nodes in Tree2.
- For each node, we do BFS: O(N^2) for Tree1 and O(M^2) for Tree2.
- So total complexity: O(N^2 + M^2)

Space Complexity:
- O(N + M) for adjacency lists and visited arrays in each BFS.
*/

class Solution {
public:
    // BFS to count nodes reachable within distance 'd' from 'curr'
    int bfs(int curr, unordered_map<int, vector<int>>& adj, int d, int N) {
        queue<pair<int, int>> que;
        que.push({curr, 0});

        vector<bool> visited(N, false);
        visited[curr] = true;

        int count = 0;
        while (!que.empty()) {
            auto [node, dist] = que.front();
            que.pop();

            if (dist > d) continue;

            count++;

            for (int ngbr : adj[node]) {
                if (!visited[ngbr]) {
                    visited[ngbr] = true;
                    que.push({ngbr, dist + 1});
                }
            }
        }

        return count;
    }

    // Helper to get count of reachable nodes within 'd' for each node in the tree
    vector<int> findCount(vector<vector<int>>& edges, int d) {
        int N = edges.size() + 1;  // Total nodes = edges + 1
        unordered_map<int, vector<int>> adj;

        // Build adjacency list
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> result(N);
        for (int i = 0; i < N; i++) {
            result[i] = bfs(i, adj, d, N);
        }

        return result;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int N = edges1.size() + 1;

        // Step 1: Count nodes reachable from each node in Tree1 within distance k
        vector<int> result1 = findCount(edges1, k);

        // Step 2: Count nodes reachable in Tree2 within distance (k - 1)
        vector<int> result2 = findCount(edges2, k - 1);

        // Step 3: Find max reachable nodes from any node in Tree2
        int maxTargetNodesCount = *max_element(result2.begin(), result2.end());

        // Step 4: Add this to each node’s result in Tree1
        for (int i = 0; i < N; i++) {
            result1[i] += maxTargetNodesCount;
        }

        return result1;
    }
};
