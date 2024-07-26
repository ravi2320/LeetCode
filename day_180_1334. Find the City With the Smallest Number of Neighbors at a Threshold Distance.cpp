/*
1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
Solved
Medium
Topics
Companies
Hint
There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

 

Example 1:


Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
Output: 3
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 4 for each city are:
City 0 -> [City 1, City 2] 
City 1 -> [City 0, City 2, City 3] 
City 2 -> [City 0, City 1, City 3] 
City 3 -> [City 1, City 2] 
Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.
Example 2:


Input: n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
Output: 0
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 2 for each city are:
City 0 -> [City 1] 
City 1 -> [City 0, City 4] 
City 2 -> [City 3, City 4] 
City 3 -> [City 2, City 4]
City 4 -> [City 1, City 2, City 3] 
The city 0 has 1 neighboring city at a distanceThreshold = 2.
 

Constraints:

2 <= n <= 100
1 <= edges.length <= n * (n - 1) / 2
edges[i].length == 3
0 <= fromi < toi < n
1 <= weighti, distanceThreshold <= 10^4
All pairs (fromi, toi) are distinct.
*/

#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>

using namespace std;

#define P pair<int, int>

class Solution {
public:
    /**
     * Intuition:
     * The problem requires finding the city with the smallest number of reachable cities within a given distance threshold.
     * This can be efficiently solved using Dijkstra's algorithm to calculate the shortest paths from each city to all other cities.
     * After computing the shortest path distances, we can count the number of cities reachable from each city within the threshold and select the one with the fewest reachable cities.
     * 
     * Time Complexity:
     * - Dijkstra's algorithm runs in O(E log V) per source vertex, where E is the number of edges and V is the number of vertices.
     * - Since we run Dijkstra's for each vertex, the overall complexity is O(VE log V).
     * 
     * Space Complexity:
     * - The space complexity includes the adjacency list representation (O(E)), the ShortPathMatrix (O(V^2)), and additional storage for priority queues and vectors (O(V)).
     * - The overall space complexity is O(V^2 + E).
     */
    
    /**
     * Function to perform Dijkstra's algorithm to find the shortest paths
     * from source vertex S to all other vertices.
     * 
     * @param n Number of vertices in the graph.
     * @param adj Adjacency list of the graph where adj[u] contains pairs {v, wt}
     *        indicating an edge from u to v with weight wt.
     * @param result Vector to store the shortest distance from S to each vertex.
     * @param S Source vertex.
     */
    void dijkstra(int n, unordered_map<int, vector<P>>& adj, vector<int>& result, int S) {
        priority_queue<P, vector<P>, greater<P>> pq;  // Min-heap priority queue
        pq.push({0, S});
        result[S] = 0;

        while (!pq.empty()) {
            int d = pq.top().first;  // Current distance
            int node = pq.top().second;  // Current node
            pq.pop();

            for (auto& p : adj[node]) {
                int adjNode = p.first;  // Adjacent node
                int dist = p.second;  // Distance to adjacent node

                if (d + dist < result[adjNode]) {
                    result[adjNode] = d + dist;
                    pq.push({d + dist, adjNode});
                }
            }
        }
    }

    /**
     * Function to find the city with the smallest number of neighbors
     * at or below a given distance threshold.
     * 
     * @param n Number of cities.
     * @param ShortPathMatrix Matrix containing shortest paths between all pairs of cities.
     * @param D Distance threshold.
     * @return The city index with the least number of reachable cities within distance D.
     */
    int findResultCity(int n, vector<vector<int>>& ShortPathMatrix, int D) {
        int resultCity = -1;
        int leastReachableCity = INT_MAX;

        for (int i = 0; i < n; i++) {
            int reachCount = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && ShortPathMatrix[i][j] <= D) {
                    reachCount++;
                }
            }

            if (reachCount <= leastReachableCity) {
                leastReachableCity = reachCount;
                resultCity = i;
            }
        }

        return resultCity;
    }

    /**
     * Main function to find the city with the smallest number of neighbors
     * at or below the distance threshold.
     * 
     * @param n Number of cities.
     * @param edges List of edges where each edge is represented as {u, v, wt}
     *        indicating an edge from u to v with weight wt.
     * @param distanceThreshold Distance threshold.
     * @return The city index with the least number of reachable cities within the distance threshold.
     */
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> ShortPathMatrix(n, vector<int>(n, 1e9+7));

        for (int i = 0; i < n; i++) {
            ShortPathMatrix[i][i] = 0;  // Distance from a city to itself is 0
        }

        unordered_map<int, vector<P>> adj;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        for (int i = 0; i < n; i++) {
            dijkstra(n, adj, ShortPathMatrix[i], i);
        }

        return findResultCity(n, ShortPathMatrix, distanceThreshold);
    }
};
