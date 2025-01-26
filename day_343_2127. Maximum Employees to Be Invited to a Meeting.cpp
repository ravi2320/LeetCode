/*
2127. Maximum Employees to Be Invited to a Meeting
Solved
Hard
Topics
Companies
Hint
A company is organizing a meeting and has a list of n employees, waiting to be invited. They have arranged for a large circular table, capable of seating any number of employees.

The employees are numbered from 0 to n - 1. Each employee has a favorite person and they will attend the meeting only if they can sit next to their favorite person at the table. The favorite person of an employee is not themself.

Given a 0-indexed integer array favorite, where favorite[i] denotes the favorite person of the ith employee, return the maximum number of employees that can be invited to the meeting.

 

Example 1:


Input: favorite = [2,2,1,2]
Output: 3
Explanation:
The above figure shows how the company can invite employees 0, 1, and 2, and seat them at the round table.
All employees cannot be invited because employee 2 cannot sit beside employees 0, 1, and 3, simultaneously.
Note that the company can also invite employees 1, 2, and 3, and give them their desired seats.
The maximum number of employees that can be invited to the meeting is 3. 
Example 2:

Input: favorite = [1,2,0]
Output: 3
Explanation: 
Each employee is the favorite person of at least one other employee, and the only way the company can invite them is if they invite every employee.
The seating arrangement will be the same as that in the figure given in example 1:
- Employee 0 will sit between employees 2 and 1.
- Employee 1 will sit between employees 0 and 2.
- Employee 2 will sit between employees 1 and 0.
The maximum number of employees that can be invited to the meeting is 3.
Example 3:


Input: favorite = [3,0,1,4,1]
Output: 4
Explanation:
The above figure shows how the company will invite employees 0, 1, 3, and 4, and seat them at the round table.
Employee 2 cannot be invited because the two spots next to their favorite employee 1 are taken.
So the company leaves them out of the meeting.
The maximum number of employees that can be invited to the meeting is 4.
 

Constraints:

n == favorite.length
2 <= n <= 105
0 <= favorite[i] <= n - 1
favorite[i] != i
*/

/*
Approach:
1. Represent the problem as a directed graph where each node points to its "favorite" node.
2. Use DFS and BFS to analyze the structure of the graph:
   - Detect cycles and calculate their lengths.
   - Identify "happy cycles" (cycles of length 2) and calculate their maximum possible influence by exploring their surrounding nodes using BFS.
3. Compute the maximum of two values:
   - The longest cycle length in the graph.
   - The total size of all happy cycles plus the nodes they can indirectly influence.

Intuition:
- Each node in the graph either belongs to a cycle or is part of a chain leading into a cycle.
- For "happy cycles" (cycles of length 2), the maximum number of invitations includes all the nodes that can connect to the cycle.
- For longer cycles, the length of the cycle itself is the maximum possible number of invitations.

Time Complexity:
- Building the adjacency list: \(O(n)\), where \(n\) is the number of nodes.
- Detecting cycles: \(O(n)\) (each node is visited once).
- BFS for each "happy cycle": \(O(n)\) in the worst case.
- Overall: \(O(n)\).

Space Complexity:
- Adjacency list: \(O(n)\).
- Visited arrays and auxiliary data structures: \(O(n)\).
- Total: \(O(n)\).

*/

class Solution {
public:
    // BFS to calculate the maximum distance from a starting node.
    int BFS(int start, unordered_map<int, vector<int>>& adj, vector<bool>& visited) {
        queue<pair<int, int>> q; // Stores {current node, distance from start}.
        q.push({start, 0});
        int maxDistance = 0;

        while (!q.empty()) {
            auto [currNode, dist] = q.front();
            q.pop();

            for (int adjNode : adj[currNode]) {
                if (!visited[adjNode]) {
                    visited[adjNode] = true; // Mark the node as visited.
                    q.push({adjNode, dist + 1});
                    maxDistance = max(maxDistance, dist + 1); // Update maximum distance.
                }
            }
        }

        return maxDistance;
    }

    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        unordered_map<int, vector<int>> adj;

        // Build the graph: each node points to its "favorite" node.
        for (int i = 0; i < n; i++) {
            adj[favorite[i]].push_back(i);
        }

        int longestCycleLen = 0; // Longest cycle length.
        int happyCycleCnt = 0;  // Total size of all "happy cycles" and their influence.
        vector<bool> visited(n, false);

        // Iterate over each node to find all cycles and compute their influence.
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int currNode = i;
                int currNodeCnt = 0;
                unordered_map<int, int> nodeToStep;

                // Traverse the cycle using a modified DFS approach.
                while (!visited[currNode]) {
                    visited[currNode] = true;
                    nodeToStep[currNode] = currNodeCnt;

                    int nextNode = favorite[currNode];
                    currNodeCnt++;

                    if (nodeToStep.count(nextNode)) {
                        // Cycle detected: calculate its length.
                        int cycleLen = currNodeCnt - nodeToStep[nextNode];
                        longestCycleLen = max(longestCycleLen, cycleLen);

                        // If it's a "happy cycle" (length = 2), calculate influence.
                        if (cycleLen == 2) {
                            vector<bool> visitedNodes(n, false);
                            visitedNodes[currNode] = true;
                            visitedNodes[nextNode] = true;

                            // Add nodes in the cycle and their surrounding chains.
                            happyCycleCnt += 2 + BFS(currNode, adj, visitedNodes) + BFS(nextNode, adj, visitedNodes);
                        }
                        break;
                    }

                    currNode = nextNode;
                }
            }
        }

        return max(longestCycleLen, happyCycleCnt); // Maximum invitations possible.
    }
};