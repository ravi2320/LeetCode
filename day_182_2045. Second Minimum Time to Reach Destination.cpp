/*
'
Solved
Hard
Topics
Companies
Hint
A city is represented as a bi-directional connected graph with n vertices where each vertex is labeled from 1 to n (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself. The time taken to traverse any edge is time minutes.

Each vertex has a traffic signal which changes its color from green to red and vice versa every change minutes. All signals change at the same time. You can enter a vertex at any time, but can leave a vertex only when the signal is green. You cannot wait at a vertex if the signal is green.

The second minimum value is defined as the smallest value strictly larger than the minimum value.

For example the second minimum value of [2, 3, 4] is 3, and the second minimum value of [2, 2, 4] is 4.
Given n, edges, time, and change, return the second minimum time it will take to go from vertex 1 to vertex n.

Notes:

You can go through any vertex any number of times, including 1 and n.
You can assume that when the journey starts, all signals have just turned green.
 

Example 1:

       
Input: n = 5, edges = [[1,2],[1,3],[1,4],[3,4],[4,5]], time = 3, change = 5
Output: 13
Explanation:
The figure on the left shows the given graph.
The blue path in the figure on the right is the minimum time path.
The time taken is:
- Start at 1, time elapsed=0
- 1 -> 4: 3 minutes, time elapsed=3
- 4 -> 5: 3 minutes, time elapsed=6
Hence the minimum time needed is 6 minutes.

The red path shows the path to get the second minimum time.
- Start at 1, time elapsed=0
- 1 -> 3: 3 minutes, time elapsed=3
- 3 -> 4: 3 minutes, time elapsed=6
- Wait at 4 for 4 minutes, time elapsed=10
- 4 -> 5: 3 minutes, time elapsed=13
Hence the second minimum time is 13 minutes.      
Example 2:


Input: n = 2, edges = [[1,2]], time = 3, change = 2
Output: 11
Explanation:
The minimum time path is 1 -> 2 with time = 3 minutes.
The second minimum time path is 1 -> 2 -> 1 -> 2 with time = 11 minutes.
 

Constraints:

2 <= n <= 104
n - 1 <= edges.length <= min(2 * 104, n * (n - 1) / 2)
edges[i].length == 2
1 <= ui, vi <= n
ui != vi
There are no duplicate edges.
Each vertex can be reached directly or indirectly from every other vertex.
1 <= time, change <= 103
*/

/*
Intuition:
The problem requires finding the second shortest path in terms of time from the first node to the nth node in a graph, where each edge traversal takes a fixed amount of time, and certain traffic lights introduce periodic delays. To achieve this, we use a modified Dijkstra's algorithm that tracks not just the shortest path but also the second shortest path for each node. The solution accounts for delays introduced by the traffic lights, which change between red and green at regular intervals.

Time Complexity:
The algorithm runs in O((E + V) log V) time complexity, where V is the number of nodes and E is the number of edges. This is due to the use of a priority queue to always expand the node with the smallest current time.

Space Complexity:
The space complexity is O(V + E) due to the adjacency list representation of the graph and the two arrays d1 and d2, which store the shortest and second shortest times to each node, respectively.
*/

#define P pair<int, int>

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        // Adjacency list representation of the graph
        unordered_map<int, vector<int>> adj;
        for(vector<int> &edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Distance arrays to store the shortest and second shortest times to each node
        vector<int> d1(n+1, INT_MAX);
        vector<int> d2(n+1, INT_MAX);

        // Min-heap priority queue for Dijkstra's algorithm
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 1}); // Starting with node 1 at time 0
        d1[1] = 0; // Shortest time to node 1 is 0

        while(!pq.empty()) {
            auto [timePassed, node] = pq.top();
            pq.pop();

            // If we reached the destination node with a valid second shortest time
            if(node == n && d2[n] != INT_MAX){
                return d2[n];
            }

            // Calculate the time when the light will turn green
            int div = timePassed / change;
            if(div % 2 == 1){
                timePassed = (div + 1) * change;
            }

            // Traverse all neighbors of the current node
            for(auto &ngbr : adj[node]){
                // Update the shortest path
                if(d1[ngbr] > timePassed + time){
                    d1[ngbr] = timePassed + time;
                    pq.push({timePassed + time, ngbr});
                }
                // Update the second shortest path
                else if(d2[ngbr] > timePassed + time && d1[ngbr] != timePassed + time){
                    d2[ngbr] = timePassed + time;
                    pq.push({timePassed + time, ngbr});
                }
            }
        }

        return -1; // If no valid second shortest path exists
    }
};
