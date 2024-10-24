/*
951. Flip Equivalent Binary Trees
Solved
Medium
Topics
Companies
For a binary tree T, we can define a flip operation as follows: choose any node, and swap the left and right child subtrees.

A binary tree X is flip equivalent to a binary tree Y if and only if we can make X equal to Y after some number of flip operations.

Given the roots of two binary trees root1 and root2, return true if the two trees are flip equivalent or false otherwise.

 

Example 1:

Flipped Trees Diagram
Input: root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 = [1,3,2,null,6,4,5,null,null,null,null,8,7]
Output: true
Explanation: We flipped at nodes with values 1, 3, and 5.
Example 2:

Input: root1 = [], root2 = []
Output: true
Example 3:

Input: root1 = [], root2 = [1]
Output: false
 

Constraints:

The number of nodes in each tree is in the range [0, 100].
Each tree will have unique node values in the range [0, 99].
*/

/*
Approach:
- The function checks whether two binary trees are *flip equivalent*. Two trees are flip equivalent if one can be transformed into the other by swapping the left and right children of some of their nodes.
- The base cases check whether both nodes are null (indicating equivalence), or if only one is null or their values differ (indicating non-equivalence).
- The main logic checks for two possible cases:
  1. The left subtrees of both trees are equivalent, and the right subtrees of both trees are equivalent.
  2. The left subtree of one tree is equivalent to the right subtree of the other tree, and vice versa (flip case).

Time Complexity: O(n), where n is the number of nodes in the smaller tree. We visit each node once.
Space Complexity: O(h), where h is the height of the tree (due to the recursion stack).
*/

class Solution {
public:
    // Function to determine if two trees are flip equivalent
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // If both nodes are null, they are equivalent
        if (!root1 && !root2)
            return true;
        // If only one node is null, they are not equivalent
        if (!root1 || !root2)
            return false;
        // If values differ, they are not equivalent
        if (root1->val != root2->val)
            return false;

        // Check for both normal equivalence and flipped equivalence
        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
               (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
    }
};