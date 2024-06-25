/*
1038. Binary Search Tree to Greater Sum Tree
Solved
Medium
Topics
Companies
Hint
Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
Example 2:

Input: root = [0,null,1]
Output: [1,null,1]
 

Constraints:

The number of nodes in the tree is in the range [1, 100].
0 <= Node.val <= 100
All the values in the tree are unique.
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

 * Intuition:
 * - The task is to transform the BST into a Greater Sum Tree (GST) where each node's value is updated to the sum of all values greater than or equal to it in the original tree.
 * - This can be achieved using a reverse in-order traversal (right-root-left), which processes nodes in descending order.
 * - As we traverse the tree, we keep a running sum of all the values encountered and update each node's value to this running sum.

 * Time Complexity: O(n)
 * - We visit each node exactly once during the traversal, making the time complexity linear in terms of the number of nodes in the tree.

 * Space Complexity: O(h)
 * - The space complexity is proportional to the height of the tree due to the recursion stack. In the worst case, this can be O(n) for a skewed tree, but it is O(log n) for a balanced tree.

 */
class Solution {
public:
    void solve(TreeNode* root, int &sum) {
        if (!root) {
            return;
        }

        // Traverse the right subtree first
        solve(root->right, sum);

        // Update the running sum and the node's value
        sum += root->val;
        root->val = sum;

        // Traverse the left subtree
        solve(root->left, sum);
    }

    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        solve(root, sum);
        return root;
    }
};
