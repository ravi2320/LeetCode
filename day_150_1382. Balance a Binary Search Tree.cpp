/*
1382. Balance a Binary Search Tree
Solved
Medium
Topics
Companies
Hint
Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

 

Example 1:


Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
Example 2:


Input: root = [2,1,3]
Output: [2,1,3]
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
1 <= Node.val <= 105
*/

/**
 * Intuition:
 * - To balance a BST, we can perform an in-order traversal to extract the elements in sorted order.
 * - We then construct a balanced BST from the sorted list by recursively selecting the middle element as the root.

 * Time Complexity: O(n)
 * - In-order traversal takes O(n) time to visit all nodes.
 * - Constructing the balanced BST from the sorted list also takes O(n) time.

 * Space Complexity: O(n)
 * - We store the elements of the tree in a vector, which requires O(n) space.

 */
class Solution {
public:
    // Helper function to perform in-order traversal and store values in a vector
    void inorder(TreeNode* root, vector<int>& vec) {
        if (!root) return;
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    } 

    // Helper function to construct a balanced BST from a sorted vector
    TreeNode* construct(int left, int right, vector<int>& vec) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;

        TreeNode* root = new TreeNode(vec[mid]);
        root->left = construct(left, mid - 1, vec);
        root->right = construct(mid + 1, right, vec);

        return root;
    }

    // Function to balance a BST
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vec;

        // Perform in-order traversal to get sorted elements
        inorder(root, vec);

        // Construct and return the balanced BST
        return construct(0, vec.size() - 1, vec);
    }
};
