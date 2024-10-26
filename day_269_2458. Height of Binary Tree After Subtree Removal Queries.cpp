/*
2458. Height of Binary Tree After Subtree Removal Queries
Solved
Hard
Topics
Companies
Hint
You are given the root of a binary tree with n nodes. Each node is assigned a unique value from 1 to n. You are also given an array queries of size m.

You have to perform m independent queries on the tree where in the ith query you do the following:

Remove the subtree rooted at the node with the value queries[i] from the tree. It is guaranteed that queries[i] will not be equal to the value of the root.
Return an array answer of size m where answer[i] is the height of the tree after performing the ith query.

Note:

The queries are independent, so the tree returns to its initial state after each query.
The height of a tree is the number of edges in the longest simple path from the root to some node in the tree.
 

Example 1:


Input: root = [1,3,4,2,null,6,5,null,null,null,null,null,7], queries = [4]
Output: [2]
Explanation: The diagram above shows the tree after removing the subtree rooted at node with value 4.
The height of the tree is 2 (The path 1 -> 3 -> 2).
Example 2:


Input: root = [5,8,9,2,1,3,7,4,6], queries = [3,2,4,8]
Output: [3,2,3,2]
Explanation: We have the following queries:
- Removing the subtree rooted at node with value 3. The height of the tree becomes 3 (The path 5 -> 8 -> 2 -> 4).
- Removing the subtree rooted at node with value 2. The height of the tree becomes 2 (The path 5 -> 8 -> 1).
- Removing the subtree rooted at node with value 4. The height of the tree becomes 3 (The path 5 -> 8 -> 2 -> 6).
- Removing the subtree rooted at node with value 8. The height of the tree becomes 2 (The path 5 -> 9 -> 3).
 

Constraints:

The number of nodes in the tree is n.
2 <= n <= 105
1 <= Node.val <= n
All the values in the tree are unique.
m == queries.length
1 <= m <= min(n, 104)
1 <= queries[i] <= n
queries[i] != root.val
*/

/*
Approach:
1. **Tree Traversal and Height Calculation**:
   - Use a recursive `findHeight` function to calculate the height of each node and populate arrays for each level:
     - `level[]`: Tracks the level of each node.
     - `levelMaxHt[]` and `levelSecMaxHt[]`: Track the maximum and second maximum heights at each level.
     - `height[]`: Stores the height of each node.
   - During the traversal:
     - For each node at level `l`, update `levelMaxHt[l]` and `levelSecMaxHt[l]` based on the node's height.
  
2. **Answering Queries**:
   - For each query node, calculate the effective height of the tree if this node and its subtree are removed.
   - If the queried node contributes to the maximum height at its level, the second maximum height at that level is used.
   - Store the result for each query.

Time Complexity: O(n + q), where `n` is the number of nodes in the tree and `q` is the number of queries.
Space Complexity: O(n), where `n` is the number of nodes, for arrays to store levels and heights.

*/

class Solution {
    // Arrays to store level, height, max height, and second max height at each level
    int level[1000001];
    int levelMaxHt[1000001];
    int levelSecMaxHt[1000001];
    int height[1000001];
public:
    // Recursive function to find the height of each node and track max heights at each level
    int findHeight(TreeNode* root, int l) {
        if (!root) return 0;

        level[root->val] = l;

        // Recursively find height of left and right subtree, then calculate node's height
        height[root->val] = max(findHeight(root->left, l + 1), findHeight(root->right, l + 1)) + 1;

        // Update maximum and second maximum heights for the level
        if (levelMaxHt[l] < height[root->val]) {
            levelSecMaxHt[l] = levelMaxHt[l];
            levelMaxHt[l] = height[root->val];
        } else if (levelSecMaxHt[l] < height[root->val]) {
            levelSecMaxHt[l] = height[root->val];
        }

        return height[root->val];
    }

    // Function to process queries and return results
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        // Initialize level max heights by calculating heights of all nodes
        findHeight(root, 0);

        vector<int> result;

        for (int &node : queries) {
            int L = level[node];

            // Calculate the result for the query based on max and second max heights at the level
            int tempRes = L + (levelMaxHt[L] == height[node] ? levelSecMaxHt[L] : levelMaxHt[L]) - 1;

            result.push_back(tempRes);
        }

        return result;
    }
};
