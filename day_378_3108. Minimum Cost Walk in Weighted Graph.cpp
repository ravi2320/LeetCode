/*
3108. Minimum Cost Walk in Weighted Graph
Solved
Hard
Topics
Companies
Hint
There is an undirected weighted graph with n vertices labeled from 0 to n - 1.

You are given the integer n and an array edges, where edges[i] = [ui, vi, wi] indicates that there is an edge between vertices ui and vi with a weight of wi.

A walk on a graph is a sequence of vertices and edges. The walk starts and ends with a vertex, and each edge connects the vertex that comes before it and the vertex that comes after it. It's important to note that a walk may visit the same edge or vertex more than once.

The cost of a walk starting at node u and ending at node v is defined as the bitwise AND of the weights of the edges traversed during the walk. In other words, if the sequence of edge weights encountered during the walk is w0, w1, w2, ..., wk, then the cost is calculated as w0 & w1 & w2 & ... & wk, where & denotes the bitwise AND operator.

You are also given a 2D array query, where query[i] = [si, ti]. For each query, you need to find the minimum cost of the walk starting at vertex si and ending at vertex ti. If there exists no such walk, the answer is -1.

Return the array answer, where answer[i] denotes the minimum cost of a walk for query i.

 

Example 1:

Input: n = 5, edges = [[0,1,7],[1,3,7],[1,2,1]], query = [[0,3],[3,4]]

Output: [1,-1]

Explanation:


To achieve the cost of 1 in the first query, we need to move on the following edges: 0->1 (weight 7), 1->2 (weight 1), 2->1 (weight 1), 1->3 (weight 7).

In the second query, there is no walk between nodes 3 and 4, so the answer is -1.

Example 2:

Input: n = 3, edges = [[0,2,7],[0,1,15],[1,2,6],[1,2,1]], query = [[1,2]]

Output: [0]

Explanation:


To achieve the cost of 0 in the first query, we need to move on the following edges: 1->2 (weight 1), 2->1 (weight 6), 1->2 (weight 1).

 

Constraints:

2 <= n <= 105
0 <= edges.length <= 105
edges[i].length == 3
0 <= ui, vi <= n - 1
ui != vi
0 <= wi <= 105
1 <= query.length <= 105
query[i].length == 2
0 <= si, ti <= n - 1
si != ti
*/

/*
    Approach:
    - Use Disjoint Set Union (DSU) with Path Compression to group connected components.
    - Maintain an additional 'cost' array to store the cumulative AND of all edge weights in each connected component.
    - For each edge, merge the two nodes and update the cost by applying bitwise AND with the current edge's weight.
    - For each query:
        - If both nodes belong to the same component, return the component's cost.
        - If they are disconnected, return -1.
        - If both nodes are the same, return 0.

    Intuition:
    - The key insight is to track the minimum common cost (AND operation) in each connected component.
    - DSU efficiently helps us check connectivity and merge components while maintaining costs.

    Time Complexity:
    - O(E * α(N)) for processing edges using DSU (α(N) is inverse Ackermann, nearly constant).
    - O(Q * α(N)) for processing queries.
    - Overall: O((E + Q) * α(N)), where E = number of edges, Q = number of queries, N = number of nodes.

    Space Complexity:
    - O(N) for parent and cost arrays.
*/

class Solution {
    vector<int> parent;
    vector<int> cost;
    
public:
    // Find function with path compression
    int Find(int x) {
        if (parent[x] != x) {
            parent[x] = Find(parent[x]);
        }
        return parent[x];
    }
    
    // Union function: merge components and update cost
    void Union(int u, int v, int w) {
        int pu = Find(u);
        int pv = Find(v);
        if (pu == pv) return;  // already in the same component
        
        // Merge pv into pu
        parent[pv] = pu;
        cost[pu] &= cost[pv];  // combine cost of both components
        cost[pu] &= w;         // include current edge weight
    }
    
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        cost.resize(n, -1);  // Initialize cost with all bits set (-1)
        
        // Initially, each node is its own parent
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        
        // Process each edge
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            Union(u, v, w);
        }
        
        vector<int> res;
        
        // Process each query
        for (auto &q : query) {
            int s = q[0], t = q[1];
            
            if (s == t) {
                res.push_back(0);  // same node query
            }
            else if (Find(s) != Find(t)) {
                res.push_back(-1);  // disconnected
            }
            else {
                res.push_back(cost[Find(s)]);  // same component cost
            }
        }
        
        return res;
    }
};