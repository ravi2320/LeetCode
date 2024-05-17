/*
1325. Delete Leaves With a Given Value
Solved
Medium
Topics
Companies
Hint
Given a binary tree root and an integer target, delete all the leaf nodes with value target.

Note that once you delete a leaf node with value target, if its parent node becomes a leaf node and has the value target, it should also be deleted (you need to continue doing that until you cannot).

 

Example 1:



Input: root = [1,2,3,2,null,2,4], target = 2
Output: [1,null,3,null,4]
Explanation: Leaf nodes in green with value (target = 2) are removed (Picture in left). 
After removing, new nodes become leaf nodes with value (target = 2) (Picture in center).
Example 2:



Input: root = [1,3,3,3,2], target = 3
Output: [1,3,null,null,2]
Example 3:



Input: root = [1,2,null,2,null,2], target = 2
Output: [1]
Explanation: Leaf nodes in green with value (target = 2) are removed at each step.
 

Constraints:

The number of nodes in the tree is in the range [1, 3000].
1 <= Node.val, target <= 1000
*/

// Intuition:
// - We use a recursive approach to traverse the binary tree.
// - At each node, we recursively remove leaf nodes with the given target value.
// - If a leaf node is encountered with the target value, we return NULL, indicating its removal from the tree.
// - Otherwise, we return the current node after potentially removing its children.

// Time Complexity: O(N), where N is the number of nodes in the binary tree.
// - Each node is visited once in the recursive traversal.
// - Therefore, the time complexity is linear with respect to the number of nodes in the tree.

// Space Complexity: O(H), where H is the height of the binary tree.
// - The space complexity is determined by the recursive call stack during the traversal.
// - In the worst case, the height of the binary tree could be equal to the number of nodes, leading to O(N) space complexity.
// - In the best case of a balanced binary tree, the space complexity is O(log N).

class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        // Base case: If the current node is NULL, return NULL
        if (root == nullptr)
            return nullptr;

        // Recursively remove leaf nodes with the target value from the left and right subtrees
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);

        // Check if the current node is a leaf node with the target value
        if (!root->left && !root->right && root->val == target) {
            // If so, return NULL to remove it from the tree
            return nullptr;
        }

        // Otherwise, return the current node
        return root;
    }
};
