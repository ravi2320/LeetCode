/*
1514. Path with Maximum Probability
Solved
Medium
Topics
Companies
Hint
You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].

Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.

If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.

 

Example 1:



Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
Output: 0.25000
Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.
Example 2:



Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
Output: 0.30000
Example 3:



Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
Output: 0.00000
Explanation: There is no path between 0 and 2.
 

Constraints:

2 <= n <= 10^4
0 <= start, end < n
start != end
0 <= a, b < n
a != b
0 <= succProb.length == edges.length <= 2*10^4
0 <= succProb[i] <= 1
There is at most one edge between every two nodes.
*/

/*
Intuition:
The problem asks for the maximum probability of reaching a target node (`end`) from a starting node (`start`) in a graph, where edges have probabilities instead of weights. The idea is similar to finding the shortest path but instead, we are looking for a path that maximizes the product of probabilities along the path.

Approach:
1. **Graph Representation**:
   - Represent the graph using an adjacency list where each node points to its neighbors along with the associated probability of moving to that neighbor.
   
2. **Dijkstra-like Algorithm**:
   - Use a priority queue to explore paths with the highest probability first. This is similar to Dijkstra's algorithm but instead of minimizing distance, we are maximizing the probability.
   - Start with the `start` node and initialize its probability to `1.0` (since the probability of being at the start node is certain).
   - For each node, check all its neighbors. If moving to a neighbor through the current node provides a higher probability than previously known, update the probability and push the neighbor into the priority queue.
   
3. **Return the Result**:
   - After processing all nodes, the probability stored in the result vector for the `end` node will give the maximum probability of reaching `end` from `start`.
   - If the `end` node is unreachable, the result will be `0`.

Time Complexity:
- The time complexity is `O((V + E) log V)`, where `V` is the number of nodes and `E` is the number of edges. The logarithmic factor comes from the priority queue operations.

Space Complexity:
- The space complexity is `O(V + E)` for storing the graph and the priority queue.

*/

class Solution {
    typedef pair<double, int> P;  // Define a pair type for priority queue (probability, node)
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int, vector<pair<int, double>>> adj;  // Adjacency list to store the graph
        int m = edges.size();

        // Build the graph
        for(int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];

            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }

        vector<double> res(n, 0);  // To store the maximum probability to reach each node
        res[start] = 1.0;  // Start node has a probability of 1

        priority_queue<P> pq;  // Priority queue to process nodes by maximum probability
        pq.push({1.0, start});

        // Dijkstra-like approach to maximize probability
        while(!pq.empty()) {
            int node = pq.top().second;
            double currProb = pq.top().first;
            pq.pop();

            for(auto &ngbr : adj[node]) {
                double adjProb = ngbr.second;
                int adjNode = ngbr.first;

                // If a higher probability path is found, update and push to queue
                if(res[adjNode] < currProb * adjProb) {
                    res[adjNode] = currProb * adjProb;
                    pq.push({res[adjNode], adjNode});
                }
            }
        }

        return res[end];  // Return the maximum probability to reach the end node
    }
};
