/*
1192. Critical Connections in a Network
Solved
Hard
Topics
Companies
Hint
There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.

 

Example 1:


Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
Example 2:

Input: n = 2, connections = [[0,1]]
Output: [[0,1]]
 

Constraints:

2 <= n <= 105
n - 1 <= connections.length <= 105
0 <= ai, bi <= n - 1
ai != bi
There are no repeated connections.
*/

/*
Approach:
- Use DFS traversal with timestamps.
- For each node, track:
    - tin[node] = discovery time
    - low[node] = lowest discovery time reachable
- If for a neighbor `ngbr`, low[ngbr] > tin[node], the edge (node, ngbr) is a bridge.

Time Complexity: O(V + E)
Space Complexity: O(V + E) for graph + O(V) for tin/low/visited
*/

class Solution {
    int timer = 1;

    // DFS to find bridges
    void dfs(int node, int parent, vector<bool> &vis, vector<int> &tin, 
             vector<int> &low, vector<vector<int>> &bridges, 
             unordered_map<int, vector<int>> &adj) {
        
        vis[node] = true;
        tin[node] = low[node] = timer++;

        for(auto &ngbr : adj[node]){
            if(ngbr == parent) continue;  // Skip the edge to parent
            
            if(!vis[ngbr]){
                dfs(ngbr, node, vis, tin, low, bridges, adj);
                low[node] = min(low[node], low[ngbr]);

                // Check for bridge
                if(low[ngbr] > tin[node]){
                    bridges.push_back({node, ngbr});
                }
            }
            else{
                // Back edge
                low[node] = min(low[node], tin[ngbr]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<int>> adj;

        // Build undirected graph
        for(auto &conn : connections){
            int u = conn[0];
            int v = conn[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> tin(n), low(n);
        vector<bool> vis(n, false);
        vector<vector<int>> bridges;

        // Start DFS from node 0
        dfs(0, -1, vis, tin, low, bridges, adj);

        return bridges;
    }
};
