/*
1976. Number of Ways to Arrive at Destination
Solved
Medium
Topics
Companies
Hint
You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.

 

Example 1:


Input: n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
Output: 4
Explanation: The shortest amount of time it takes to go from intersection 0 to intersection 6 is 7 minutes.
The four ways to get there in 7 minutes are:
- 0 ➝ 6
- 0 ➝ 4 ➝ 6
- 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
- 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6
Example 2:

Input: n = 2, roads = [[1,0,10]]
Output: 1
Explanation: There is only one way to go from intersection 0 to intersection 1, and it takes 10 minutes.
 

Constraints:

1 <= n <= 200
n - 1 <= roads.length <= n * (n - 1) / 2
roads[i].length == 3
0 <= ui, vi <= n - 1
1 <= timei <= 109
ui != vi
There is at most one road connecting any two intersections.
You can reach any intersection from any other intersection.
*/

/*
    Approach:
    - Use Dijkstra's algorithm to find the shortest paths from node 0 to all other nodes.
    - Maintain an additional array `pathCount[]` to count the number of ways to reach each node with the minimum time.
    - For each node:
        - If we find a shorter path, update the shortest time and reset the path count.
        - If we find another path with the same minimum time, increment the path count modulo 1e9+7.

    Intuition:
    - We need both shortest distance and the number of shortest paths.
    - Dijkstra naturally gives us shortest distance.
    - Counting paths requires checking if multiple paths lead to same shortest distance.

    Time Complexity: O(E * log(V)), where V = number of nodes, E = number of edges.
    Space Complexity: O(V + E) for adjacency list, distance array, path count array.
*/

class Solution {
public:
    typedef pair<long long, int> P;
    const int M = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {
        // Adjacency list: node -> {adjacent node, travel time}
        unordered_map<int, vector<pair<int, int>>> adj;

        for (auto &road : roads) {
            int u = road[0], v = road[1], time = road[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        // Min-heap priority queue: {current time, node}
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<long long> res(n, LLONG_MAX);  // Stores shortest distance
        vector<int> pathCount(n, 0);          // Stores number of shortest paths

        res[0] = 0;  // Start node
        pathCount[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            long long currTime = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            // For all adjacent nodes
            for (auto &vec : adj[currNode]) {
                int adjNode = vec.first;
                int roadTime = vec.second;

                // Found shorter path
                if (currTime + roadTime < res[adjNode]) {
                    res[adjNode] = currTime + roadTime;
                    pathCount[adjNode] = pathCount[currNode];
                    pq.push({res[adjNode], adjNode});
                }
                // Found another path with same minimum time
                else if (currTime + roadTime == res[adjNode]) {
                    pathCount[adjNode] = (pathCount[adjNode] + pathCount[currNode]) % M;
                }
            }
        }

        return pathCount[n - 1];
    }
};