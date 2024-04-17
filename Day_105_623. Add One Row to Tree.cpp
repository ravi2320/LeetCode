/*
623. Add One Row to Tree
Solved
Medium
Topics
Companies
Given the root of a binary tree and two integers val and depth, add a row of nodes with value val at the given depth depth.

Note that the root node is at depth 1.

The adding rule is:

Given the integer depth, for each not null tree node cur at the depth depth - 1, create two tree nodes with value val as cur's left subtree root and right subtree root.
cur's original left subtree should be the left subtree of the new left subtree root.
cur's original right subtree should be the right subtree of the new right subtree root.
If depth == 1 that means there is no depth depth - 1 at all, then create a tree node with value val as the new root of the whole original tree, and the original tree is the new root's left subtree.
 

Example 1:


Input: root = [4,2,6,3,1,5], val = 1, depth = 2
Output: [4,1,1,2,null,null,6,3,1,5]
Example 2:


Input: root = [4,2,null,3,1], val = 1, depth = 3
Output: [4,2,null,1,1,3,null,null,1]
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
The depth of the tree is in the range [1, 104].
-100 <= Node.val <= 100
-105 <= val <= 105
1 <= depth <= the depth of tree + 1
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    string res = "";

    // Depth First Search (DFS) function to traverse the binary tree
    void dfs(TreeNode* root, string curr){
        // Base case: if root is NULL, return
        if(root == NULL)
            return;

        // Add the current node's value to the current path string
        // Convert the integer value to a character ('a' corresponds to 0, 'b' to 1, and so on)
        curr = char(root->val + 'a') + curr;

        // If it's a leaf node, compare the current path string with the result
        if(!root->left && !root->right)
        {
            // If the result string is empty or the current path is smaller lexically
            if(res == "" || res > curr)
            {
                // Update the result string with the current path
                res = curr;
            }
            return;
        }

        // Recursively traverse the left and right subtrees
        dfs(root->left, curr);
        dfs(root->right, curr);
    }

    // Main function to find the lexicographically smallest string
    string smallestFromLeaf(TreeNode* root) {
        // Call the DFS function with the root and an empty string as the current path
        dfs(root, "");
        // Return the result string
        return res;
    }
};
