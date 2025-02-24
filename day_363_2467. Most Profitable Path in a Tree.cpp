/*
2467. Most Profitable Path in a Tree
Solved
Medium
Topics
Companies
Hint
There is an undirected tree with n nodes labeled from 0 to n - 1, rooted at node 0. You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

At every node i, there is a gate. You are also given an array of even integers amount, where amount[i] represents:

the price needed to open the gate at node i, if amount[i] is negative, or,
the cash reward obtained on opening the gate at node i, otherwise.
The game goes on as follows:

Initially, Alice is at node 0 and Bob is at node bob.
At every second, Alice and Bob each move to an adjacent node. Alice moves towards some leaf node, while Bob moves towards node 0.
For every node along their path, Alice and Bob either spend money to open the gate at that node, or accept the reward. Note that:
If the gate is already open, no price will be required, nor will there be any cash reward.
If Alice and Bob reach the node simultaneously, they share the price/reward for opening the gate there. In other words, if the price to open the gate is c, then both Alice and Bob pay c / 2 each. Similarly, if the reward at the gate is c, both of them receive c / 2 each.
If Alice reaches a leaf node, she stops moving. Similarly, if Bob reaches node 0, he stops moving. Note that these events are independent of each other.
Return the maximum net income Alice can have if she travels towards the optimal leaf node.

 

Example 1:


Input: edges = [[0,1],[1,2],[1,3],[3,4]], bob = 3, amount = [-2,4,2,-4,6]
Output: 6
Explanation: 
The above diagram represents the given tree. The game goes as follows:
- Alice is initially on node 0, Bob on node 3. They open the gates of their respective nodes.
  Alice's net income is now -2.
- Both Alice and Bob move to node 1. 
  Since they reach here simultaneously, they open the gate together and share the reward.
  Alice's net income becomes -2 + (4 / 2) = 0.
- Alice moves on to node 3. Since Bob already opened its gate, Alice's income remains unchanged.
  Bob moves on to node 0, and stops moving.
- Alice moves on to node 4 and opens the gate there. Her net income becomes 0 + 6 = 6.
Now, neither Alice nor Bob can make any further moves, and the game ends.
It is not possible for Alice to get a higher net income.
Example 2:


Input: edges = [[0,1]], bob = 1, amount = [-7280,2350]
Output: -7280
Explanation: 
Alice follows the path 0->1 whereas Bob follows the path 1->0.
Thus, Alice opens the gate at node 0 only. Hence, her net income is -7280. 
 

Constraints:

2 <= n <= 105
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
ai != bi
edges represents a valid tree.
1 <= bob < n
amount.length == n
amount[i] is an even integer in the range [-104, 104].
*/

/**
 * Approach:
 * - Construct an **adjacency list** to represent the **tree**.
 * - Perform **DFS for Bob** to track the **earliest time Bob reaches each node**.
 * - Perform **DFS for Alice** to calculate the **maximum profit Alice can collect**.
 * 
 * Intuition:
 * - **Bob's DFS** finds the **shortest path** from Bob's starting position to the root (0) 
 *   and stores the time Bob reaches each node.
 * - **Alice's DFS** traverses the tree and calculates Alice’s earnings while comparing
 *   with Bob’s timing:
 *   - If Alice reaches a node **before** Bob → Alice takes the full amount.
 *   - If Alice reaches **at the same time** as Bob → Alice takes **half** the amount.
 *   - If Bob arrives **before Alice** → Alice gets **nothing**.
 * - Alice's DFS explores all **leaf nodes** to maximize profit.
 *
 * Time Complexity:
 * - **O(N)** → Both DFS traversals run in linear time.
 *
 * Space Complexity:
 * - **O(N)** → Adjacency list, visited array, and Bob's map all use linear space.
 */

class Solution {
public:
    /**
     * DFS for Bob:
     * - Tracks the earliest time Bob reaches each node.
     * - Uses a map `bobMap` to store {node -> time}.
     * - If a path to the root (0) is found, keep those times; otherwise, erase it.
     */
    bool DFSBob(int curr, int t, unordered_map<int, vector<int>> &adj, 
                vector<bool> &visited, unordered_map<int, int> &bobMap) {
        visited[curr] = true;
        bobMap[curr] = t;

        if (curr == 0) return true;  // Reached the root

        for (int &ngbr : adj[curr]) {
            if (!visited[ngbr]) {
                if (DFSBob(ngbr, t + 1, adj, visited, bobMap)) {
                    return true;
                }
            }
        }

        bobMap.erase(curr);  // If this path doesn't lead to root, remove from Bob's path.
        return false;
    }

    /**
     * DFS for Alice:
     * - Traverses the tree, tracking Alice's income.
     * - Alice gets:
     *   - **Full amount** if she reaches earlier.
     *   - **Half amount** if she and Bob reach at the same time.
     *   - **Nothing** if Bob reached earlier.
     * - If Alice reaches a leaf node, update the maximum possible income.
     */
    void DFSAlice(int curr, int t, int income, int &aliceIncome, 
                  unordered_map<int, vector<int>> &adj, vector<bool> &visited, 
                  unordered_map<int, int> &bobMap, vector<int> &amount) {
        visited[curr] = true;

        // Calculate Alice's income based on Bob's arrival time
        if (bobMap.find(curr) == bobMap.end() || t < bobMap[curr]) {
            income += amount[curr];  // Alice takes full amount
        } else if (t == bobMap[curr]) {
            income += amount[curr] / 2;  // Alice takes half amount
        }

        // If current node is a leaf (except root), update Alice's max income
        if (adj[curr].size() == 1 && curr != 0) {
            aliceIncome = max(aliceIncome, income);
        }

        // Explore next nodes
        for (int &ngbr : adj[curr]) {
            if (!visited[ngbr]) {
                DFSAlice(ngbr, t + 1, income, aliceIncome, adj, visited, bobMap, amount);
            }
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        unordered_map<int, vector<int>> adj;

        // Build adjacency list
        for (vector<int> &edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 1: DFS to track Bob's earliest arrival time at each node
        int time = 0;
        vector<bool> visited(n, false);
        unordered_map<int, int> bobMap;
        DFSBob(bob, time, adj, visited, bobMap);

        // Step 2: DFS to compute Alice's maximum possible income
        int aliceIncome = INT_MIN;
        visited.assign(n, false);
        DFSAlice(0, 0, 0, aliceIncome, adj, visited, bobMap, amount);

        return aliceIncome;
    }
};