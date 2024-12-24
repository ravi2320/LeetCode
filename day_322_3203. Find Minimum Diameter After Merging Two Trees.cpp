/*
3203. Find Minimum Diameter After Merging Two Trees
Solved
Hard
Topics
Companies
Hint
There exist two undirected trees with n and m nodes, numbered from 0 to n - 1 and from 0 to m - 1, respectively. You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree.

You must connect one node from the first tree with another node from the second tree with an edge.

Return the minimum possible diameter of the resulting tree.

The diameter of a tree is the length of the longest path between any two nodes in the tree.

 

Example 1:

Input: edges1 = [[0,1],[0,2],[0,3]], edges2 = [[0,1]]

Output: 3

Explanation:

We can obtain a tree of diameter 3 by connecting node 0 from the first tree with any node from the second tree.

Example 2:


Input: edges1 = [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]], edges2 = [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]]

Output: 5

Explanation:

We can obtain a tree of diameter 5 by connecting node 0 from the first tree with node 0 from the second tree.

 

Constraints:

1 <= n, m <= 105
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
The task is to calculate the minimum diameter of a tree after merging two trees represented by `edges1` and `edges2`. 

Steps:
1. **Find the Diameter of Each Tree:**
   - Use BFS to find the farthest node from an arbitrary source. This gives one end of the diameter.
   - Perform BFS again starting from the farthest node found in the first BFS to calculate the diameter.

2. **Merge the Trees:**
   - After merging, the combined diameter is calculated as:
     - The sum of the radius of both trees (half of each diameter plus one).
     - Add 1 to account for the edge connecting the two trees.

3. **Final Diameter:**
   - Take the maximum of the two individual diameters and the combined diameter.

Key Functions:
- `findAdjecencyList`: Converts edge lists into an adjacency list representation.
- `BFS`: Finds the farthest node and its distance from a given source node in the tree.
- `findDiameter`: Computes the diameter of a tree using BFS.

Time Complexity:
- BFS: O(V + E) for each tree, where `V` is the number of nodes and `E` is the number of edges.
- Total: O(V1 + E1 + V2 + E2), where `V1` and `E1` are for the first tree, and `V2` and `E2` are for the second tree.

Space Complexity:
- Adjacency list and BFS queue: O(V + E).

Edge Cases:
1. Single-node trees.
2. Highly unbalanced trees.
3. Trees where diameters are close to the combined diameter.

*/

class Solution {
public:
    // Helper function to perform BFS and find the farthest node and its distance
    pair<int, int> BFS(unordered_map<int, vector<int>> &adj, int source) {
        int farthestNode, distance = 0;
        unordered_map<int, bool> visited;
        visited[source] = true;

        queue<int> q;
        q.push(source);

        // BFS traversal
        while (!q.empty()) {
            int n = q.size();

            while (n--) {
                int node = q.front();
                q.pop();

                farthestNode = node;

                // Traverse adjacent nodes
                for (int &adjNode : adj[node]) {
                    if (!visited[adjNode]) {
                        visited[adjNode] = true;
                        q.push(adjNode);    
                    }
                }
            }

            if (!q.empty()) {
                distance++;
            }
        }

        return {farthestNode, distance};
    }

    // Function to find the diameter of a tree
    int findDiameter(unordered_map<int, vector<int>> &adj) {
        auto [farthestNode, dist] = BFS(adj, 0); // Get one end of the diameter
        auto [otherEndNode, diameter] = BFS(adj, farthestNode); // Compute diameter
        return diameter;
    }

    // Converts edge list to adjacency list
    unordered_map<int, vector<int>> findAdjecencyList(vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> adj;
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }

    // Main function to calculate the minimum diameter after merging two trees
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int, vector<int>> adj1 = findAdjecencyList(edges1);
        unordered_map<int, vector<int>> adj2 = findAdjecencyList(edges2);
        
        int d1 = findDiameter(adj1); // Diameter of first tree
        int d2 = findDiameter(adj2); // Diameter of second tree

        // Calculate combined diameter
        int combined = (d1 + 1) / 2 + (d2 + 1) / 2 + 1;

        // Return the maximum of the two individual diameters and the combined diameter
        return max(d1, max(d2, combined));
    }
};