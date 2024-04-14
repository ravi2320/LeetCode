/*
404. Sum of Left Leaves
Solved
Easy
Topics
Companies
Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
Example 2:

Input: root = [1]
Output: 0
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-1000 <= Node.val <= 1000
*/

// Intuition:
// We perform a depth-first traversal of the binary tree.
// At each node, we check if it's a leaf node and if it's a left child of its parent.
// If both conditions are met, we add its value to the sum.
// We recursively traverse the left and right subtrees, passing the current node and its parent to the recursive function.

// Time Complexity: O(N), where N is the number of nodes in the binary tree. We visit each node once.
// Space Complexity: O(H), where H is the height of the binary tree. This is the space required for the recursive call stack.
//                   In the worst case, the tree is unbalanced, and the height is equal to the number of nodes.
//                   In the average case or when the tree is balanced, the space complexity is O(log N), where N is the number of nodes.

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
    // Recursive function to calculate the sum of left leaves
    int solve(TreeNode* curr, TreeNode* parent) {
        // Base case: if current node is nullptr, return 0
        if (!curr)
            return 0;

        // If current node is a leaf and it's a left child of its parent, return its value
        if (!curr->left && !curr->right && parent && parent->left == curr)
            return curr->val;

        // Recursive calls for left and right subtrees
        int left = solve(curr->left, curr);
        int right = solve(curr->right, curr);

        // Return the sum of left leaves in the subtree rooted at current node
        return left + right;
    } 

    // Main function to calculate the sum of left leaves
    int sumOfLeftLeaves(TreeNode* root) {
        // Call the recursive function with root and nullptr as parent
        return solve(root, nullptr);
    }
};

// Intuition:
// We perform a depth-first traversal of the binary tree.
// At each node, we check if it's a leaf node and if it's a left child of its parent (if 'isleft' is true).
// If both conditions are met, we add its value to the sum.
// We recursively traverse the left and right subtrees, passing the current node and the boolean indicating if it's a left child to the recursive function.

// Time Complexity: O(N), where N is the number of nodes in the binary tree. We visit each node once.
// Space Complexity: O(H), where H is the height of the binary tree. This is the space required for the recursive call stack.
//                   In the worst case, the tree is unbalanced, and the height is equal to the number of nodes.
//                   In the average case or when the tree is balanced, the space complexity is O(log N), where N is the number of nodes.

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
    // Recursive function to calculate the sum of left leaves
    int solve(TreeNode* curr, bool isleft) {
        // Base case: if current node is nullptr, return 0
        if (!curr)
            return 0;

        // If current node is a leaf and it's a left child of its parent (if 'isleft' is true), return its value
        if (!curr->left && !curr->right && isleft)
            return curr->val;

        // Recursive calls for left and right subtrees
        int left = solve(curr->left, true);
        int right = solve(curr->right, false);

        // Return the sum of left leaves in the subtree rooted at current node
        return left + right;
    } 

    // Main function to calculate the sum of left leaves
    int sumOfLeftLeaves(TreeNode* root) {
        // Call the recursive function with root and false indicating it's not a left child
        return solve(root, false);   
    }
};
