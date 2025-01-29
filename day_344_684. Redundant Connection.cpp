/*
684. Redundant Connection
Solved
Medium
Topics
Companies
In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

 

Example 1:


Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
Example 2:


Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]
 

Constraints:

n == edges.length
3 <= n <= 1000
edges[i].length == 2
1 <= ai < bi <= edges.length
ai != bi
There are no repeated edges.
The given graph is connected.
*/

/*
Approach:
1. **Graph Representation**: Use an adjacency list to store the edges.
2. **Cycle Detection Using DFS**:
   - Before adding an edge, check if a path already exists between the two nodes using DFS.
   - If a path exists, that edge is redundant and should be removed.
   - Otherwise, add the edge to the adjacency list.
3. **Return the redundant edge** once found.

Intuition:
- A tree with \( n \) nodes has exactly \( n-1 \) edges.
- If we have \( n \) edges, one of them must be creating a cycle.
- The redundant edge is the one that forms a cycle when added to the graph.

Time Complexity:
- For each edge: \( O(n) \) in the worst case due to DFS traversal.
- Total: \( O(n^2) \) in the worst case.

Space Complexity:
- **Adjacency List**: \( O(n) \).
- **Visited Array**: \( O(n) \).
- **Recursive DFS Stack**: \( O(n) \) in the worst case.
- **Total Space**: \( O(n) \).

*/

class Solution {
public:
    // DFS to check if there's a path between u and v before adding an edge.
    bool dfs(unordered_map<int, vector<int>>& adj, int u, int v, vector<bool>& visited) {
        visited[u] = true;
        
        if (u == v) {
            return true; // If we reached the target node, a cycle is detected.
        }

        for (int &neighbor : adj[u]) {
            if (!visited[neighbor] && dfs(adj, neighbor, v, visited)) {
                return true; // If path exists from neighbor to v, return true.
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int, vector<int>> adj; // Graph representation using adjacency list.

        // Iterate through all edges.
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];

            vector<bool> visited(n + 1, false); // Track visited nodes for DFS.

            // If a path exists between u and v before adding the edge, it's redundant.
            if (adj.count(u) && adj.count(v) && dfs(adj, u, v, visited)) {
                return edge;
            }

            // Otherwise, add the edge to the graph.
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {}; // This should never be reached for a valid input.
    }
};


/*
Approach:
1. **Use Disjoint Set Union (DSU)** (also known as Union-Find) to efficiently check for cycles.
2. **Find Operation (Path Compression)**:
   - If two nodes belong to the same component, adding an edge between them creates a cycle.
   - This helps find the representative (root) of a node efficiently.
3. **Union Operation (Union by Rank)**:
   - If two nodes belong to different components, merge the smaller tree into the larger one.
   - This keeps the structure balanced and improves efficiency.

Intuition:
- A tree with \( n \) nodes has \( n-1 \) edges.
- If we have \( n \) edges, one of them must create a cycle.
- The **first edge that forms a cycle** when added is the redundant edge.

Time Complexity:
- **Find with Path Compression**: \( O(\alpha(n)) \) (Inverse Ackermann function, nearly constant time)
- **Union by Rank**: \( O(\alpha(n)) \)
- **Overall Complexity**: \( O(n) \), significantly faster than DFS \( O(n^2) \).

Space Complexity:
- **Parent & Rank Arrays**: \( O(n) \)
- **Total Space**: \( O(n) \).

*/

class DSU {
    vector<int> parent, rank;
public:
    // Constructor: Initialize DSU with `n` nodes.
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0); // All nodes start with rank 0.

        // Initially, each node is its own parent (self-loop).
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    // Find operation with path compression.
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression: flatten tree.
        }
        return parent[x];
    }

    // Union by rank: Attach smaller tree under larger tree.
    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) return; // Already in the same set.

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent; // Attach y to x.
        } 
        else if (rank[y_parent] > rank[x_parent]) {
            parent[x_parent] = y_parent; // Attach x to y.
        } 
        else {
            parent[x_parent] = y_parent; // Attach x to y and increase rank.
            rank[y_parent]++;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n); // Initialize DSU.

        // Process each edge.
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];

            // If u and v already belong to the same component, this edge is redundant.
            if (dsu.find(u) == dsu.find(v)) {
                return edge;
            }

            // Otherwise, unite the sets.
            dsu.Union(u, v);
        }

        return {}; // Should not reach here in a valid input.
    }
};