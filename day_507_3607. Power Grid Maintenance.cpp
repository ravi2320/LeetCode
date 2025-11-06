/*
3607. Power Grid Maintenance

You are given an integer c representing c power stations, each with a unique identifier id from 1 to c (1‑based indexing).

These stations are interconnected via n bidirectional cables, represented by a 2D array connections, where each element connections[i] = [ui, vi] indicates a connection between station ui and station vi. Stations that are directly or indirectly connected form a power grid.

Initially, all stations are online (operational).

You are also given a 2D array queries, where each query is one of the following two types:

[1, x]: A maintenance check is requested for station x. If station x is online, it resolves the check by itself. If station x is offline, the check is resolved by the operational station with the smallest id in the same power grid as x. If no operational station exists in that grid, return -1.

[2, x]: Station x goes offline (i.e., it becomes non-operational).

Return an array of integers representing the results of each query of type [1, x] in the order they appear.

Note: The power grid preserves its structure; an offline (non‑operational) node remains part of its grid and taking it offline does not alter connectivity.

 

Example 1:

Input: c = 5, connections = [[1,2],[2,3],[3,4],[4,5]], queries = [[1,3],[2,1],[1,1],[2,2],[1,2]]

Output: [3,2,3]

Explanation:



Initially, all stations {1, 2, 3, 4, 5} are online and form a single power grid.
Query [1,3]: Station 3 is online, so the maintenance check is resolved by station 3.
Query [2,1]: Station 1 goes offline. The remaining online stations are {2, 3, 4, 5}.
Query [1,1]: Station 1 is offline, so the check is resolved by the operational station with the smallest id among {2, 3, 4, 5}, which is station 2.
Query [2,2]: Station 2 goes offline. The remaining online stations are {3, 4, 5}.
Query [1,2]: Station 2 is offline, so the check is resolved by the operational station with the smallest id among {3, 4, 5}, which is station 3.
Example 2:

Input: c = 3, connections = [], queries = [[1,1],[2,1],[1,1]]

Output: [1,-1]

Explanation:

There are no connections, so each station is its own isolated grid.
Query [1,1]: Station 1 is online in its isolated grid, so the maintenance check is resolved by station 1.
Query [2,1]: Station 1 goes offline.
Query [1,1]: Station 1 is offline and there are no other stations in its grid, so the result is -1.
 

Constraints:

1 <= c <= 105
0 <= n == connections.length <= min(105, c * (c - 1) / 2)
connections[i].length == 2
1 <= ui, vi <= c
ui != vi
1 <= queries.length <= 2 * 105
queries[i].length == 2
queries[i][0] is either 1 or 2.
1 <= queries[i][1] <= c
*/

/*
Intuition:
We are given a network of nodes (represented as `c` nodes) and a series of connection queries. Each node can be in one of two states: online or offline. When a node is online, it can communicate with other nodes that are in the same connected component of the network. The task is to process a list of queries that ask for either:
- The first online node in the same connected component as a given node.
- To set a node offline, effectively removing it from future queries.

Approach:
1. **Graph Construction:** 
   - We first create an undirected graph using the `connections` list where each connection represents an edge between two nodes.
   
2. **DFS to Identify Components:**
   - Perform DFS (Depth First Search) starting from each unvisited node to identify connected components in the graph. Each connected component is a set of nodes that can communicate with each other.
   
3. **Handling Queries:**
   - For each query, we need to:
     - **Action 1 (Node Query):** Return the first node in the connected component of a given node that is online. If no nodes in the component are online, return `-1`.
     - **Action 2 (Offline Node):** Mark a node as offline, and remove it from its respective component's set of online nodes.

Time Complexity:
- Building the graph: O(E), where E is the number of edges (connections).
- DFS traversal: O(V + E), where V is the number of nodes and E is the number of edges.
- Processing Queries: O(1) per query (using a set for online/offline node tracking and component mapping).

Space Complexity:
- O(V + E) for storing the graph (adjacency list) and visited information.
- O(V) for tracking the connected components.
- O(Q) for storing the answers to queries, where Q is the number of queries.

*/

class Solution {
public:
    // Helper function to perform DFS and find connected components
    void dfs(int node, int start, vector<int> &visited, unordered_map<int, vector<int>> &adj, set<int> &st) {
        if (visited[node])  // If the node is already visited, return
            return;

        st.insert(node);  // Insert node into current connected component
        visited[node] = start;  // Mark node as visited and assign it to the component group

        // Explore all neighbors (connected nodes)
        for (int &ngbr : adj[node]) {
            dfs(ngbr, start, visited, adj, st);
        }
    }

    // Main function to process all the queries
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        
        unordered_map<int, vector<int>> adj;  // Adjacency list to store graph
        // Build the graph from the given connections
        for (auto &con : connections) {
            int u = con[0];
            int v = con[1];
            adj[u].push_back(v);
            adj[v].push_back(u);  // Since the graph is undirected
        }

        unordered_set<int> online, offline;
        for (int i = 1; i <= c; i++) {  // Initially, all nodes are online
            online.insert(i);
        }

        vector<int> visited(c + 1, 0);  // Visited array to mark which nodes belong to which component
        unordered_map<int, set<int>> mp;  // Map to store components and their nodes

        // Run DFS to identify all connected components
        for (int i = 1; i <= c; i++) {
            if (!visited[i]) {
                set<int> st;  // To store the nodes in the current component
                dfs(i, i, visited, adj, st);  // Perform DFS to find the entire component
                mp[i] = st;  // Map the component ID (start node) to the set of nodes in that component
            }
        }

        vector<int> ans;  // To store the answers for each query
        for (auto &query : queries) {
            int action = query[0];  // Action (1: query, 2: set offline)
            int node = query[1];    // Node involved in the query

            if (action == 1) {  // Query action
                if (online.count(node)) {  // If the node is online, return the node itself
                    ans.push_back(node);
                } else {
                    int group = visited[node];  // Find the component the node belongs to
                    int begin = *mp[group].begin();  // Get the first node in the component
                    ans.push_back(begin == 0 ? -1 : begin);  // If no node in the group is online, return -1
                }
            } else {  // Set node offline action
                offline.insert(node);  // Mark node as offline
                online.erase(node);    // Remove the node from online set
                int group = visited[node];  // Find the group of the node
                mp[group].erase(node);  // Remove the node from the component's set
            }
        }

        return ans;  // Return the answers for all queries
    }
};
