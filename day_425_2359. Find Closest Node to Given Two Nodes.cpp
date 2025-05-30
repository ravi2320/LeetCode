/*
2359. Find Closest Node to Given Two Nodes
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.

The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from i, then edges[i] == -1.

You are also given two integers node1 and node2.

Return the index of the node that can be reached from both node1 and node2, such that the maximum between the distance from node1 to that node, and from node2 to that node is minimized. If there are multiple answers, return the node with the smallest index, and if no possible answer exists, return -1.

Note that edges may contain cycles.

 

Example 1:


Input: edges = [2,2,3,-1], node1 = 0, node2 = 1
Output: 2
Explanation: The distance from node 0 to node 2 is 1, and the distance from node 1 to node 2 is 1.
The maximum of those two distances is 1. It can be proven that we cannot get a node with a smaller maximum distance than 1, so we return node 2.
Example 2:


Input: edges = [1,2,-1], node1 = 0, node2 = 2
Output: 2
Explanation: The distance from node 0 to node 2 is 2, and the distance from node 2 to itself is 0.
The maximum of those two distances is 2. It can be proven that we cannot get a node with a smaller maximum distance than 2, so we return node 2.
 

Constraints:

n == edges.length
2 <= n <= 105
-1 <= edges[i] < n
edges[i] != i
0 <= node1, node2 < n
*/

/*
Approach:
- We perform a BFS traversal from both node1 and node2 separately to compute the shortest distances from them to every other node.
- Then, we iterate through all nodes to find the node that is reachable from both node1 and node2 and minimizes the maximum distance between the two.
- In case of a tie (same maximum distance), we choose the node with the smallest index.

Intuition:
- Since every node has at most one outgoing edge, we can treat the graph as a collection of paths and cycles.
- The best meeting node is the one that is reachable by both nodes with minimal maximum distance.

Time Complexity: O(N)
- One BFS traversal from node1 and another from node2: O(N) each.
- Final loop to find optimal node: O(N)

Space Complexity: O(N)
- For distance arrays and visited flags.
*/

class Solution {
    int n; // Number of nodes
public:

    // Helper BFS function to fill distance from a given start node
    void bfs(vector<int> &edges, int node, vector<int> &dist, vector<bool> &visited){
        queue<int> q;
        q.push(node);
        visited[node] = true;

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            int next = edges[curr];

            if(next != -1 && !visited[next]){
                visited[next] = true;
                dist[next] = dist[curr] + 1; // Update distance
                q.push(next);
            }
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, INT_MAX);  // Distance from node1
        vector<int> dist2(n, INT_MAX);  // Distance from node2

        vector<bool> visited1(n, false), visited2(n, false);

        // BFS from node1
        dist1[node1] = 0;
        bfs(edges, node1, dist1, visited1);

        // BFS from node2
        dist2[node2] = 0;
        bfs(edges, node2, dist2, visited2);
        
        int idx = -1;
        int mini = INT_MAX;

        // Find node with minimal maximum distance from both sources
        for(int i = 0; i < n; i++){
            if(dist1[i] != INT_MAX && dist2[i] != INT_MAX){
                int maxi = max(dist1[i], dist2[i]);
                if(mini > maxi){
                    mini = maxi;
                    idx = i;
                }
            }
        }

        return idx; // Closest meeting node
    }
};
