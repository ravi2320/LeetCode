/*
2685. Count the Number of Complete Components
Solved
Medium
Topics
Companies
Hint
You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.

Return the number of complete connected components of the graph.

A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

A connected component is said to be complete if there exists an edge between every pair of its vertices.

 

Example 1:



Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
Output: 3
Explanation: From the picture above, one can see that all of the components of this graph are complete.
Example 2:



Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
Output: 1
Explanation: The component containing vertices 0, 1, and 2 is complete since there is an edge between every pair of two vertices. On the other hand, the component containing vertices 3, 4, and 5 is not complete since there is no edge between vertices 4 and 5. Thus, the number of complete components in this graph is 1.
 

Constraints:

1 <= n <= 50
0 <= edges.length <= n * (n - 1) / 2
edges[i].length == 2
0 <= ai, bi <= n - 1
ai != bi
There are no repeated edges.
*/

/*
    Approach:
    - Use Disjoint Set Union (DSU) to group nodes into connected components.
    - For each component:
        - Count the number of vertices (using DSU size array).
        - Count the number of edges.
    - A complete component with v vertices has exactly v*(v-1)/2 edges.
    - Traverse each component root and check if its edge count matches the complete graph condition.

    Intuition:
    - DSU helps efficiently group connected components.
    - Since DSU keeps track of parent and size, we can easily calculate number of vertices in each component.
    - Count edges separately and validate completeness condition.

    Time Complexity: O(N + E * α(N)), where N = number of vertices, E = number of edges, α = inverse Ackermann (almost constant).
    Space Complexity: O(N + E) for DSU, map, and input graph.
*/

class DSU {
public:
    vector<int> size, parent;

    DSU(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Path compression find
    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    // Union by size
    void Union(int x, int y) {
        int parent_x = find(x);
        int parent_y = find(y);

        if (parent_x == parent_y)
            return;

        if (size[parent_x] < size[parent_y]) {
            parent[parent_x] = parent_y;
            size[parent_y] += size[parent_x];
        } else {
            parent[parent_y] = parent_x;
            size[parent_x] += size[parent_y];
        }
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        unordered_map<int, int> edgeCount;

        // Union all edges
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            dsu.Union(u, v);
        }

        // Count edges in each component
        for (auto &edge : edges) {
            int u = edge[0];
            int root = dsu.find(u);
            edgeCount[root]++;
        }

        int result = 0;

        // Check completeness condition for each component
        for (int i = 0; i < n; i++) {
            if (dsu.find(i) == i) { // If i is the root
                int vertices = dsu.size[i];
                int edges = edgeCount[i];

                // Each edge counted once, so total edges = e
                // Complete graph edges = v * (v - 1) / 2
                if (edges == vertices * (vertices - 1) / 2) {
                    result++;
                }
            }
        }

        return result;
    }
};
