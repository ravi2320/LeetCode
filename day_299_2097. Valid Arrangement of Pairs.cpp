/*
2097. Valid Arrangement of Pairs
Solved
Hard
Topics
Companies
Hint
You are given a 0-indexed 2D integer array pairs where pairs[i] = [starti, endi]. An arrangement of pairs is valid if for every index i where 1 <= i < pairs.length, we have endi-1 == starti.

Return any valid arrangement of pairs.

Note: The inputs will be generated such that there exists a valid arrangement of pairs.

 

Example 1:

Input: pairs = [[5,1],[4,5],[11,9],[9,4]]
Output: [[11,9],[9,4],[4,5],[5,1]]
Explanation:
This is a valid arrangement since endi-1 always equals starti.
end0 = 9 == 9 = start1 
end1 = 4 == 4 = start2
end2 = 5 == 5 = start3
Example 2:

Input: pairs = [[1,3],[3,2],[2,1]]
Output: [[1,3],[3,2],[2,1]]
Explanation:
This is a valid arrangement since endi-1 always equals starti.
end0 = 3 == 3 = start1
end1 = 2 == 2 = start2
The arrangements [[2,1],[1,3],[3,2]] and [[3,2],[2,1],[1,3]] are also valid.
Example 3:

Input: pairs = [[1,2],[1,3],[2,1]]
Output: [[1,2],[2,1],[1,3]]
Explanation:
This is a valid arrangement since endi-1 always equals starti.
end0 = 2 == 2 = start1
end1 = 1 == 1 = start2
 

Constraints:

1 <= pairs.length <= 105
pairs[i].length == 2
0 <= starti, endi <= 109
starti != endi
No two pairs are exactly the same.
There exists a valid arrangement of pairs.
*/

/*
Approach:
1. **Graph Representation**:
   - Use an adjacency list (`adj`) to represent the graph.
   - Maintain `indegree` and `outdegree` maps to determine the starting node of the Eulerian path.

2. **Finding the Start Node**:
   - The starting node has `outdegree[node] - indegree[node] == 1`.
   - If no such node exists, start from any node in the graph (as the graph will still have an Eulerian path).

3. **Finding Eulerian Path**:
   - Use a stack to perform an iterative Hierholzer’s algorithm.
   - Push nodes onto the stack until you reach a dead-end, then backtrack and add nodes to the Eulerian path in reverse.

4. **Formatting the Output**:
   - Reverse the Eulerian path and construct the output as a list of consecutive edges.

Time Complexity:
- **O(V + E)**: Iterating over all nodes and edges.

Space Complexity:
- **O(V + E)**: For storing the adjacency list, stack, and result.

*/

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        // Adjacency list representation of the graph
        unordered_map<int, vector<int>> adj;

        // To store the indegree and outdegree of each node
        unordered_map<int, int> indegree, outdegree;

        // Build the graph and calculate in/out degrees
        for (auto& edge : pairs) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            outdegree[u]++;
            indegree[v]++;
        }

        // Find the starting node for the Eulerian path
        int startNode = pairs[0][0]; // Default start node
        for (auto& itr : adj) {
            int node = itr.first;
            if (outdegree[node] - indegree[node] == 1) {
                startNode = node;
                break;
            }
        }

        // Find the Eulerian path using Hierholzer’s algorithm
        vector<int> eulerPath;
        stack<int> st;
        st.push(startNode);

        while (!st.empty()) {
            int curr = st.top();

            if (!adj[curr].empty()) {
                // Move to the next neighbor
                int ngbr = adj[curr].back();
                adj[curr].pop_back();
                st.push(ngbr);
            } else {
                // Add to the Eulerian path when no more neighbors
                eulerPath.push_back(curr);
                st.pop();
            }
        }

        // Reverse the Eulerian path to get the correct order
        reverse(eulerPath.begin(), eulerPath.end());

        // Format the result as pairs of edges
        vector<vector<int>> ansPath;
        for (int i = 0; i < eulerPath.size() - 1; ++i) {
            ansPath.push_back({eulerPath[i], eulerPath[i + 1]});
        }

        return ansPath;
    }
};
