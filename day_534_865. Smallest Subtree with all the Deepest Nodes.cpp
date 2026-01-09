/*
865. Smallest Subtree with all the Deepest Nodes

avatar
Discuss Approach
arrow-up
Solved
Medium
Topics
premium lock icon
Companies
Given the root of a binary tree, the depth of each node is the shortest distance to the root.

Return the smallest subtree such that it contains all the deepest nodes in the original tree.

A node is called the deepest if it has the largest depth possible among any node in the entire tree.

The subtree of a node is a tree consisting of that node, plus the set of all descendants of that node.

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation: We return the node with value 2, colored in yellow in the diagram.
The nodes coloured in blue are the deepest nodes of the tree.
Notice that nodes 5, 3 and 2 contain the deepest nodes in the tree but node 2 is the smallest subtree among them, so we return it.
Example 2:

Input: root = [1]
Output: [1]
Explanation: The root is the deepest node in the tree.
Example 3:

Input: root = [0,1,3,null,2]
Output: [2]
Explanation: The deepest node in the tree is 2, the valid subtrees are the subtrees of nodes 2, 1 and 0 but the subtree of node 2 is the smallest.
 

Constraints:

The number of nodes in the tree will be in the range [1, 500].
0 <= Node.val <= 500
The values of the nodes in the tree are unique.
*/

/*
Approach:
---------
We are given a binary tree and need to find the **smallest subtree**
that contains **all the deepest nodes**.

This can be solved in two main steps:

1️⃣ Find the maximum depth of the tree and store the depth of each node.
2️⃣ Find the Lowest Common Ancestor (LCA) of all nodes that are at this
   maximum depth.

Steps:
------
1. Perform a DFS to:
   - Compute the depth of every node
   - Track the maximum depth (`maxi`)
2. Perform another DFS to find the LCA:
   - If a node itself is at the maximum depth, return it
   - Recur on left and right subtrees
   - If both sides return non-null, current node is the LCA
   - Otherwise propagate the non-null child upward
3. The returned node is the root of the smallest subtree
   containing all deepest nodes.

Intuition:
----------
All deepest nodes lie at the same maximum depth.
The smallest subtree containing them is simply their LCA.
By knowing the depth of each node, we can detect deepest nodes
and compute their LCA in a clean recursive manner.

Time Complexity:
----------------
O(n)
- One DFS to compute depths
- One DFS to compute LCA
- Each node is visited a constant number of times

Space Complexity:
-----------------
O(n)
- Hash map for storing depths
- Recursion stack in the worst case (skewed tree)

*/

class Solution {
    int maxi = 0;  // Stores maximum depth found

public:

    // Finds the LCA of all nodes having maximum depth
    TreeNode* LCA(TreeNode* root, unordered_map<int, int> &depth) {
        if (!root)
            return nullptr;

        // If current node is at maximum depth, return it
        if (depth[root->val] == maxi)
            return root;

        TreeNode* left  = LCA(root->left, depth);
        TreeNode* right = LCA(root->right, depth);

        // If both subtrees contain deepest nodes, current node is LCA
        if (left && right)
            return root;
        else if (left)
            return left;
        else if (right)
            return right;

        return nullptr;
    }

    // Computes depth of each node and tracks maximum depth
    void findDepth(TreeNode* root, int d, unordered_map<int, int> &depth) {
        if (!root)
            return;

        maxi = max(maxi, d);
        depth[root->val] = d;

        findDepth(root->left, d + 1, depth);
        findDepth(root->right, d + 1, depth);
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        unordered_map<int, int> depth;

        // Step 1: Compute depths
        findDepth(root, 0, depth);

        // Step 2: Find LCA of all deepest nodes
        return LCA(root, depth);
    }
};
