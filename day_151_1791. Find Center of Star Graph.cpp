/*
1791. Find Center of Star Graph
Solved
Easy
Topics
Companies
Hint
There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly n - 1 edges that connect the center node with every other node.

You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi. Return the center of the given star graph.

 

Example 1:


Input: edges = [[1,2],[2,3],[4,2]]
Output: 2
Explanation: As shown in the figure above, node 2 is connected to every other node, so 2 is the center.
Example 2:

Input: edges = [[1,2],[5,1],[1,3],[1,4]]
Output: 1
 

Constraints:

3 <= n <= 105
edges.length == n - 1
edges[i].length == 2
1 <= ui, vi <= n
ui != vi
The given edges represent a valid star graph.
*/

/**
 * Intuition:
 * - The problem involves finding the center node of a star graph. In a star graph, one node (the center) is connected to all other nodes.
 * - Given the edges of the star graph, we need to determine which node is the center.
 * - Since the center node is connected to every other node, it must appear in the first two edges.

 * Time Complexity: O(1)
 * - The solution examines only the first two edges to determine the center node, making the time complexity constant.

 * Space Complexity: O(1)
 * - The solution uses a constant amount of extra space.

 * @param edges: a list of edges representing the star graph
 * @return: the value of the center node
 */

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // Check if the first node of the first edge is the center
        if ((edges[0][0] == edges[1][0]) || (edges[0][0] == edges[1][1])) 
            return edges[0][0];
        
        // Otherwise, the second node of the first edge is the center
        return edges[0][1];
    }
};
