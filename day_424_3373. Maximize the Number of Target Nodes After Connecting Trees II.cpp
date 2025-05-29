/*
3373. Maximize the Number of Target Nodes After Connecting Trees II
Solved
Hard
Topics
premium lock icon
Companies
Hint
There exist two undirected trees with n and m nodes, labeled from [0, n - 1] and [0, m - 1], respectively.

You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree.

Node u is target to node v if the number of edges on the path from u to v is even. Note that a node is always target to itself.

Return an array of n integers answer, where answer[i] is the maximum possible number of nodes that are target to node i of the first tree if you had to connect one node from the first tree to another node in the second tree.

Note that queries are independent from each other. That is, for every query you will remove the added edge before proceeding to the next query.

 

Example 1:

Input: edges1 = [[0,1],[0,2],[2,3],[2,4]], edges2 = [[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]]

Output: [8,7,7,8,8]

Explanation:

For i = 0, connect node 0 from the first tree to node 0 from the second tree.
For i = 1, connect node 1 from the first tree to node 4 from the second tree.
For i = 2, connect node 2 from the first tree to node 7 from the second tree.
For i = 3, connect node 3 from the first tree to node 0 from the second tree.
For i = 4, connect node 4 from the first tree to node 4 from the second tree.

Example 2:

Input: edges1 = [[0,1],[0,2],[0,3],[0,4]], edges2 = [[0,1],[1,2],[2,3]]

Output: [3,6,6,6,6]

Explanation:

For every i, connect node i of the first tree with any node of the second tree.
Constraints:

2 <= n, m <= 105
edges1.length == n - 1
edges2.length == m - 1
edges1[i].length == edges2[i].length == 2
edges1[i] = [ai, bi]
0 <= ai, bi < n
edges2[i] = [ui, vi]
0 <= ui, vi < m
The input is generated such that edges1 and edges2 represent valid trees.
*/

/*
Approach:
1. For both trees (Tree A and Tree B), construct their adjacency list from edge list.
2. Perform a DFS on both trees to perform bipartition (0 and 1 marking of nodes):
   - Track how many nodes are marked 0 (`zeroCnt`) and 1 (`oneCnt`) in both trees.
3. For Tree A:
   - For each node, if it is marked as 0, its count of reachable nodes in Tree A is `zeroCntA`, else `oneCntA`.
   - Add the maximum color count from Tree B (either `zeroCntB` or `oneCntB`) to it.
   - This simulates adding nodes from Tree B at distance 1.
4. Return the result vector.

Intuition:
- We are coloring both trees with two colors (bipartite coloring) using DFS.
- The max number of reachable nodes from a node `i` in Tree A = all same-color nodes in A + the larger color class in B.
- Why? Because we can connect any Tree A node to all of the larger color class in Tree B.

Time Complexity: O(N + M), where N = nodes in Tree A, M = nodes in Tree B
Space Complexity: O(N + M) for adjacency lists and marker arrays
*/

class Solution {
public:
    // Helper to convert edge list to adjacency list
    vector<vector<int>> getAdj(vector<vector<int>> &edges) {
        int N = edges.size() + 1;
        vector<vector<int>> adj(N);
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }

    // DFS to color nodes alternately and count 0s and 1s
    void dfs(int curr, vector<vector<int>> &adj, int parent, vector<int> &mark, int &zeroCnt, int &oneCnt) {
        if (mark[curr] == 0) {
            zeroCnt++;
        } else {
            oneCnt++;
        }

        for (auto &ngbr : adj[curr]) {
            if (ngbr != parent) {
                mark[ngbr] = (mark[curr] == 0 ? 1 : 0); // Alternate color
                dfs(ngbr, adj, curr, mark, zeroCnt, oneCnt);
            }
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int N = edges1.size() + 1;
        int M = edges2.size() + 1;

        // Build adjacency lists for both trees
        vector<vector<int>> adjA = getAdj(edges1);
        vector<vector<int>> adjB = getAdj(edges2);

        // DFS Tree A
        vector<int> markA(N, -1);
        markA[0] = 0;
        int zeroCntA = 0, oneCntA = 0;
        dfs(0, adjA, -1, markA, zeroCntA, oneCntA);

        // DFS Tree B
        vector<int> markB(M, -1);
        markB[0] = 0;
        int zeroCntB = 0, oneCntB = 0;
        dfs(0, adjB, -1, markB, zeroCntB, oneCntB);

        // Get the maximum bipartite set from Tree B
        int maxFromTree2 = max(zeroCntB, oneCntB);

        // Calculate result for each node in Tree A
        vector<int> res(N, -1);
        for (int i = 0; i < N; i++) {
            res[i] = (markA[i] == 0 ? zeroCntA : oneCntA) + maxFromTree2;
        }

        return res;
    }
};