/*
530. Minimum Absolute Difference in BST
Solved
Easy
Topics
Companies
Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

 

Example 1:


Input: root = [4,2,6,1,3]
Output: 1
Example 2:


Input: root = [1,0,48,null,null,12,49]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 104].
0 <= Node.val <= 105
 
*/

/**
 * Intuition:
 * We perform an in-order traversal of the binary search tree to collect the node values in ascending order.
 * During traversal, we compute the absolute difference between each adjacent pair of values and update the minimum absolute difference.
 * Finally, we return the minimum absolute difference found during traversal.
 * 
 * Time Complexity: O(N)
 * - N is the number of nodes in the binary search tree.
 * - We perform an in-order traversal of the entire tree, visiting each node once.
 * 
 * Space Complexity: O(H)
 * - H is the height of the binary search tree.
 * - The space complexity is dominated by the recursive call stack during the traversal.
 * - In the worst case, the height of the binary search tree is O(N) (unbalanced tree), resulting in O(N) space complexity.
 */

class Solution {
public:
    int minDiff = INT_MAX; // Variable to store the minimum absolute difference
    int prev = INT_MAX; // Variable to store the value of the previous node during traversal

    // Function to compute the minimum absolute difference in a binary search tree
    int getMinimumDifference(TreeNode* root) {
        if(root == NULL) 
            return minDiff; // Return the minimum absolute difference if the root is NULL

        // Traverse the left subtree
        getMinimumDifference(root->left);

        // Compute the absolute difference between the current node value and the previous node value
        if(prev != INT_MAX){
            minDiff = min(minDiff, abs(abs(root->val) - abs(prev))); // Update the minimum absolute difference
        }

        prev = root->val; // Update the previous node value

        // Traverse the right subtree
        getMinimumDifference(root->right);

        return minDiff; // Return the minimum absolute difference  
    }
};
