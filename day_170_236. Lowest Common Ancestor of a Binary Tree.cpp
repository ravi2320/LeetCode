/*
236. Lowest Common Ancestor of a Binary Tree
Solved
Medium
Topics
Companies
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the tree.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // Intuition:
    // - To find the lowest common ancestor (LCA) of two nodes `p` and `q` in a binary tree, we can use a recursive approach.
    // - We start from the root and recursively search for `p` and `q` in the left and right subtrees.
    // - If both `p` and `q` are found in different subtrees, the current node is their LCA.
    // - If both are found in the same subtree, we continue searching in that subtree.
    // - If we reach a node that matches either `p` or `q`, we return that node.

    // Time Complexity: O(N)
    // - In the worst case, we visit all the nodes in the binary tree, which takes O(N) time.

    // Space Complexity: O(H)
    // - The recursion stack can go as deep as the height of the tree, which is O(H).

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if the current node is NULL, return NULL
        if (!root) return NULL;

        // If the current node is either p or q, return the current node
        if (root == p || root == q)
            return root;

        // Recursively search for LCA in the left and right subtrees
        TreeNode *leftN = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightN = lowestCommonAncestor(root->right, p, q);
        
        // If both leftN and rightN are non-NULL, the current node is the LCA
        if (leftN && rightN)
            return root;

        // If only leftN is non-NULL, return leftN
        if (leftN)
            return leftN;

        // If only rightN is non-NULL, return rightN
        return rightN;
    }
};
