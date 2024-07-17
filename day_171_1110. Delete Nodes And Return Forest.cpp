/*
1110. Delete Nodes And Return Forest
Solved
Medium
Topics
Companies
Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest. You may return the result in any order.

 

Example 1:


Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]
Example 2:

Input: root = [1,2,4,null,3], to_delete = [3]
Output: [[1,2,4]]
 

Constraints:

The number of nodes in the given tree is at most 1000.
Each node has a distinct value between 1 and 1000.
to_delete.length <= 1000
to_delete contains distinct values between 1 and 1000.
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
    // Intuition:
    // - The goal is to delete the nodes with values in `to_delete` from the tree and return the forest (remaining trees).
    // - We use a helper function to traverse the tree and handle the deletion.
    // - When a node to be deleted is found, its children become new roots in the resulting forest.
    // - We use a set to quickly check if a node needs to be deleted.

    // Time Complexity: O(N)
    // - We traverse each node of the tree exactly once, where N is the number of nodes in the tree.

    // Space Complexity: O(N)
    // - We use additional space for the set to store nodes to be deleted and for the recursion stack.

    // Helper function to delete nodes and form the forest
    TreeNode* deleteHelper(TreeNode* root, unordered_set<int> &st, vector<TreeNode*> &res) {
        if (!root)
            return NULL;

        // Recur for the left and right subtrees
        root->left = deleteHelper(root->left, st, res);
        root->right = deleteHelper(root->right, st, res);

        // If the current node needs to be deleted
        if (st.find(root->val) != st.end()) {
            // If the left child exists, add it to the result forest
            if (root->left) {
                res.push_back(root->left);
            }
            // If the right child exists, add it to the result forest
            if (root->right) {
                res.push_back(root->right);
            }
            // Return NULL to delete the current node
            return NULL;
        }

        // Return the current node if it is not deleted
        return root;
    }

    // Main function to delete nodes and return the forest
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        unordered_set<int> st;

        // Insert all nodes to be deleted into the set
        for (int &n : to_delete) {
            st.insert(n);
        }

        // Call the helper function to delete nodes
        deleteHelper(root, st, res);

        // If the root is not deleted, add it to the result forest
        if (st.find(root->val) == st.end()) {
            res.push_back(root);
        }

        return res;
    }
};
