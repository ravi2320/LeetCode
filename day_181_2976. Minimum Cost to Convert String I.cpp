/*
2976. Minimum Cost to Convert String I
Solved
Medium
Topics
Companies
Hint
You are given two 0-indexed strings source and target, both of length n and consisting of lowercase English letters. You are also given two 0-indexed character arrays original and changed, and an integer array cost, where cost[i] represents the cost of changing the character original[i] to the character changed[i].

You start with the string source. In one operation, you can pick a character x from the string and change it to the character y at a cost of z if there exists any index j such that cost[j] == z, original[j] == x, and changed[j] == y.

Return the minimum cost to convert the string source to the string target using any number of operations. If it is impossible to convert source to target, return -1.

Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].

 

Example 1:

Input: source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]
Output: 28
Explanation: To convert the string "abcd" to string "acbe":
- Change value at index 1 from 'b' to 'c' at a cost of 5.
- Change value at index 2 from 'c' to 'e' at a cost of 1.
- Change value at index 2 from 'e' to 'b' at a cost of 2.
- Change value at index 3 from 'd' to 'e' at a cost of 20.
The total cost incurred is 5 + 1 + 2 + 20 = 28.
It can be shown that this is the minimum possible cost.
Example 2:

Input: source = "aaaa", target = "bbbb", original = ["a","c"], changed = ["c","b"], cost = [1,2]
Output: 12
Explanation: To change the character 'a' to 'b' change the character 'a' to 'c' at a cost of 1, followed by changing the character 'c' to 'b' at a cost of 2, for a total cost of 1 + 2 = 3. To change all occurrences of 'a' to 'b', a total cost of 3 * 4 = 12 is incurred.
Example 3:

Input: source = "abcd", target = "abce", original = ["a"], changed = ["e"], cost = [10000]
Output: -1
Explanation: It is impossible to convert source to target because the value at index 3 cannot be changed from 'd' to 'e'.
 

Constraints:

1 <= source.length == target.length <= 105
source, target consist of lowercase English letters.
1 <= cost.length == original.length == changed.length <= 2000
original[i], changed[i] are lowercase English letters.
1 <= cost[i] <= 106
original[i] != changed[i]
*/

/*
Intuition:
The problem involves converting characters from a `source` string to a `target` string using a set of character transformation rules with associated costs. The goal is to find the minimum cost to achieve this transformation for the entire string. The Floyd-Warshall algorithm is used to precompute the shortest path for each character transformation, allowing efficient cost computation for each character pair.

Time Complexity:
The Floyd-Warshall algorithm runs in O(N^3) time complexity, where N is the number of distinct characters (26 in this case for lowercase English letters). Thus, the time complexity for this solution is O(26^3) = O(17576), which is constant for this specific case. The subsequent computation to determine the total transformation cost is O(M), where M is the length of the `source` and `target` strings.

Space Complexity:
The space complexity is O(N^2) due to the adjacency matrix used to store transformation costs. This results in a constant space complexity of O(26^2) = O(676) for this problem. Additional space is used for the input strings and vectors, but this is relatively minor in comparison.
*/

class Solution {
public:
    // Function to implement the Floyd-Warshall algorithm
    void floydWarshall(vector<vector<long long>> &adjMatrix, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = original.size();

        // Initialize the adjacency matrix with given transformation costs
        for (int i = 0; i < n; i++) {
            int s = original[i] - 'a';
            int t = changed[i] - 'a';

            // Set the cost of transforming character s to t
            adjMatrix[s][t] = min(adjMatrix[s][t], (long long)cost[i]);
        }

        // Apply the Floyd-Warshall algorithm to find the shortest path for each character transformation
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
                }
            }
        }
    }

    // Function to find the minimum cost to transform the source string to the target string
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // Initialize the adjacency matrix with a high value (INT_MAX) to represent no direct transformation
        vector<vector<long long>> adjMatrix(26, vector<long long>(26, INT_MAX));

        // Populate the adjacency matrix with the transformation costs
        floydWarshall(adjMatrix, original, changed, cost);

        long long n = source.length();
        long long ans = 0;

        // Calculate the total transformation cost for the entire string
        for (long long i = 0; i < n; i++) {
            // If the characters are the same, no cost is incurred
            if (source[i] == target[i]) {
                continue;
            }

            // If there's no valid transformation path, return -1
            if (adjMatrix[source[i] - 'a'][target[i] - 'a'] == INT_MAX) {
                return -1;
            }

            // Accumulate the transformation cost
            ans += adjMatrix[source[i] - 'a'][target[i] - 'a'];
        }

        return ans;
    }
};

/*
Intuition:
The task is to transform a `source` string into a `target` string using a set of character transformation rules, each with an associated cost. The goal is to find the minimum total cost to achieve this transformation. This problem can be approached using graph theory, where each character represents a node and each transformation rule represents a weighted edge. Dijkstra's algorithm, known for finding the shortest paths in a graph, is used here to precompute the minimum cost for transforming each character into any other character.

Time Complexity:
Dijkstra's algorithm runs in O(E + V log V) time, where E is the number of edges and V is the number of vertices. Given that we have 26 characters (vertices) and potentially 26 * 26 edges (if every character can transform into every other character), the time complexity for each Dijkstra's run is O(26 + 26 log 26). We run Dijkstra's algorithm 26 times (once for each character), leading to a total time complexity of O(26 * (26 + 26 log 26)). This is effectively O(26^2 log 26) for the worst-case scenario, which is still constant time complexity for this problem.

Space Complexity:
The space complexity is dominated by the adjacency list and matrix, which are O(V^2) in size due to storing paths and distances for each pair of characters. Thus, the space complexity is O(26^2) = O(676), which is manageable for this specific problem size.
*/

#define P pair<long long, long long>

class Solution {
public:
    // Function to implement Dijkstra's algorithm for finding shortest paths
    void dijkstra(unordered_map<long long, vector<P>>& adj, vector<long long>& res, int src) {
        // Priority queue to store (distance, node) pairs
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, src});
        res[src] = 0;

        while (!pq.empty()) {
            long long d = pq.top().first; // Current distance
            long long node = pq.top().second; // Current node
            pq.pop();

            // Explore adjacent nodes
            for (P& temp : adj[node]) {
                long long adjNode = temp.first; // Adjacent node
                long long dist = temp.second; // Distance to adjacent node

                // Relaxation step to update the shortest distance
                if (d + dist < res[adjNode]) {
                    res[adjNode] = d + dist;
                    pq.push({d + dist, adjNode});
                }
            }
        }
    }

    // Function to find the minimum cost to transform the source string to the target string
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // Initialize the adjacency list for graph representation
        unordered_map<long long, vector<P>> adj;
        vector<vector<long long>> adjMatrix(26, vector<long long>(26, LLONG_MAX));

        // Build the adjacency list from transformation rules
        for (int i = 0; i < original.size(); i++) {
            adj[original[i] - 'a'].push_back({changed[i] - 'a', cost[i]});
        }

        // Run Dijkstra's algorithm from each character as the source
        for (int i = 0; i < 26; i++) {
            dijkstra(adj, adjMatrix[i], i);
        }

        long long n = source.length();
        long long ans = 0;

        // Calculate the total minimum cost for the transformation
        for (long long i = 0; i < n; i++) {
            int srcIndex = source[i] - 'a';
            int tgtIndex = target[i] - 'a';

            // Skip if the characters are the same
            if (srcIndex == tgtIndex) {
                continue;
            }

            // If there's no path from source to target, return -1
            if (adjMatrix[srcIndex][tgtIndex] == LLONG_MAX) {
                return -1;
            }

            // Add the minimum cost to the total
            ans += adjMatrix[srcIndex][tgtIndex];
        }

        return ans;
    }
};
