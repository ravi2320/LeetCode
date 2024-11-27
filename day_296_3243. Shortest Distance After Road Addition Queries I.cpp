/*
3243. Shortest Distance After Road Addition Queries I
Solved
Medium
Topics
Companies
Hint
You are given an integer n and a 2D integer array queries.

There are n cities numbered from 0 to n - 1. Initially, there is a unidirectional road from city i to city i + 1 for all 0 <= i < n - 1.

queries[i] = [ui, vi] represents the addition of a new unidirectional road from city ui to city vi. After each query, you need to find the length of the shortest path from city 0 to city n - 1.

Return an array answer where for each i in the range [0, queries.length - 1], answer[i] is the length of the shortest path from city 0 to city n - 1 after processing the first i + 1 queries.

 

Example 1:

Input: n = 5, queries = [[2,4],[0,2],[0,4]]

Output: [3,2,1]

Explanation:



After the addition of the road from 2 to 4, the length of the shortest path from 0 to 4 is 3.



After the addition of the road from 0 to 2, the length of the shortest path from 0 to 4 is 2.



After the addition of the road from 0 to 4, the length of the shortest path from 0 to 4 is 1.

Example 2:

Input: n = 4, queries = [[0,3],[0,2]]

Output: [1,1]

Explanation:



After the addition of the road from 0 to 3, the length of the shortest path from 0 to 3 is 1.



After the addition of the road from 0 to 2, the length of the shortest path remains 1.

 

Constraints:

3 <= n <= 500
1 <= queries.length <= 500
queries[i].length == 2
0 <= queries[i][0] < queries[i][1] < n
1 < queries[i][1] - queries[i][0]
There are no repeated roads among the queries.
*/

/*
Approach:
1. This problem involves finding the shortest path from node `0` to node `n-1` in a graph after adding edges based on queries.
2. Use Breadth-First Search (BFS) to find the shortest path in the graph:
   - BFS is optimal for finding shortest paths in an unweighted graph.
3. For each query, add the edge `u -> v` to the adjacency list and compute the shortest distance using BFS.

Steps:
1. Build the adjacency list for the initial graph:
   - For each node `i` (except the last), add an edge `i -> i+1`.
2. For each query:
   - Add the edge `u -> v` to the graph.
   - Use BFS to compute the shortest path from node `0` to node `n-1`.
   - Store the result.
3. Return the results as a vector.

Time Complexity:
- BFS: O(V + E) for each query, where `V` is the number of nodes and `E` is the number of edges.
- Total complexity: O(q * (V + E)), where `q` is the number of queries.

Space Complexity:
- O(V + E) for the adjacency list and BFS structures.

*/

class Solution {
public:
    // Helper function for BFS to find the shortest path from node 0 to node n-1
    int bfs(int n, unordered_map<int, vector<int>> &adj) {
        vector<bool> visited(n, false); // Track visited nodes
        queue<int> q;
        q.push(0); // Start BFS from node 0
        visited[0] = true;

        int level = 0; // Current BFS level

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                int node = q.front();
                q.pop();

                if (node == n - 1) {
                    return level; // Found the shortest path
                }

                for (int &neighbor : adj[node]) {
                    if (!visited[neighbor]) {
                        q.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }

            level++; // Increment level after processing all nodes at the current depth
        }

        return -1; // If no path exists
    }

    // Main function to process queries and calculate shortest distances
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries) {
        unordered_map<int, vector<int>> adj;

        // Create initial adjacency list with edges from i to i+1
        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
        }

        vector<int> res;

        // Process each query
        for (vector<int> &query : queries) {
            int u = query[0];
            int v = query[1];

            // Add the new edge from u to v
            adj[u].push_back(v);

            // Compute the shortest distance from 0 to n-1
            int d = bfs(n, adj);
            res.push_back(d);
        }

        return res; // Return results for all queries
    }
};


/*
Approach:
1. The problem involves finding the shortest path in a graph after dynamically adding edges based on queries.
2. Use Dijkstra's algorithm:
   - Optimal for finding shortest paths in weighted graphs with non-negative weights.
   - Use a priority queue to keep track of the minimum distance nodes to process.

Steps:
1. Build an adjacency list representation of the graph:
   - Initially, include edges from `i -> i+1` with weight `1`.
2. For each query:
   - Add the edge `u -> v` to the graph with weight `1`.
   - Use Dijkstra's algorithm to compute the shortest path from node `0` to node `n-1`.
   - Store the result.
3. Return the results as a vector.

Time Complexity:
- Dijkstra's: O((V + E) log V), where `V` is the number of nodes and `E` is the number of edges.
- Total complexity: O(q * (V + E) log V), where `q` is the number of queries.

Space Complexity:
- O(V + E) for the adjacency list and Dijkstra's structures.

*/

#define P pair<int, int>

class Solution {
public:
    // Dijkstra's algorithm to find shortest path from node 0 to node n-1
    int dijikshtra(int n, unordered_map<int, vector<P>> &adj) {
        vector<int> res(n, INT_MAX); // To store the shortest distances
        priority_queue<P, vector<P>, greater<P>> pq; // Min-heap
        pq.push({0, 0}); // {distance, node}
        res[0] = 0;

        while (!pq.empty()) {
            int d = pq.top().first; // Current distance
            int node = pq.top().second; // Current node
            pq.pop();

            // If the target node is reached, return the distance
            if (node == n - 1) {
                return d;
            }

            // Traverse all adjacent nodes
            for (auto &p : adj[node]) {
                int adjNode = p.first; // Adjacent node
                int wt = p.second; // Weight of the edge

                // Relaxation step
                if (d + wt < res[adjNode]) {
                    res[adjNode] = d + wt; // Update shortest distance
                    pq.push({res[adjNode], adjNode}); // Push to priority queue
                }
            }
        }

        return res[n - 1]; // Return the distance to the last node
    }

    // Main function to process queries and calculate shortest distances
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries) {
        unordered_map<int, vector<P>> adj;

        // Create initial adjacency list with edges from i to i+1 with weight 1
        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back({i + 1, 1});
        }

        vector<int> res;

        // Process each query
        for (vector<int> &query : queries) {
            int u = query[0];
            int v = query[1];

            // Add the new edge from u to v with weight 1
            adj[u].push_back({v, 1});

            // Compute the shortest distance from 0 to n-1
            int d = dijikshtra(n, adj);
            res.push_back(d);
        }

        return res; // Return results for all queries
    }
};
