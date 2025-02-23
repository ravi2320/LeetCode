/*
889. Construct Binary Tree from Preorder and Postorder Traversal
Solved
Medium
Topics
Companies
Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.

If there exist multiple answers, you can return any of them.

 

Example 1:


Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]
Example 2:

Input: preorder = [1], postorder = [1]
Output: [1]
 

Constraints:

1 <= preorder.length <= 30
1 <= preorder[i] <= preorder.length
All the values of preorder are unique.
postorder.length == preorder.length
1 <= postorder[i] <= postorder.length
All the values of postorder are unique.
It is guaranteed that preorder and postorder are the preorder traversal and postorder traversal of the same binary tree.
*/

/**
 * Approach:
 * - **Recursive Tree Construction using Preorder & Postorder**:
 *   - The **first element in preorder** is the **root**.
 *   - The **second element in preorder** is the root of the **left subtree**.
 *   - Find this element in **postorder**, which helps determine the **left subtree size**.
 *   - Recursively construct **left and right subtrees** using updated indices.
 *
 * Intuition:
 * - Preorder gives **root → left → right** order.
 * - Postorder gives **left → right → root** order.
 * - Using the second element of **preorder**, we find the left subtree in **postorder**.
 *
 * Time Complexity:
 * - **O(N)** → Each node is visited once, and postorder search takes **O(N)** in the worst case.
 *
 * Space Complexity:
 * - **O(N)** for recursive stack (in worst case, a skewed tree).
 */

class Solution {
public:
    // Recursive function to construct the binary tree
    TreeNode* solve(int preStart, int postStart, int preEnd, vector<int> &preorder, vector<int> &postorder) {
        if (preStart > preEnd) return nullptr; // Base case
        
        // Create root node from preorder
        TreeNode* root = new TreeNode(preorder[preStart]);
        if (preStart == preEnd) return root; // Single node case
        
        // Find the left subtree root in postorder
        int nextNode = preorder[preStart + 1]; // Left subtree root (next in preorder)
        int j = postStart;
        while (postorder[j] != nextNode) j++; // Find its index in postorder
        
        int num = j - postStart + 1; // Number of nodes in left subtree

        // Recursive calls to build left and right subtrees
        root->left = solve(preStart + 1, postStart, preStart + num, preorder, postorder);
        root->right = solve(preStart + num + 1, j + 1, preEnd, preorder, postorder);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        return solve(0, 0, n - 1, preorder, postorder);
    }
};

/**
 * Approach:
 * - **Recursive Tree Construction with Hash Map Optimization**:
 *   - The **first element in preorder** is the **root**.
 *   - The **second element in preorder** is the root of the **left subtree**.
 *   - Use a **hash map (unordered_map)** to store the index of each value in **postorder**, 
 *     reducing the time complexity of lookups from **O(N)** to **O(1)**.
 *   - Recursively construct **left and right subtrees** using updated indices.
 *
 * Intuition:
 * - Preorder gives **root → left → right** order.
 * - Postorder gives **left → right → root** order.
 * - The second element of **preorder** helps determine the left subtree in **postorder**.
 * - Using a **hash map**, we avoid unnecessary linear searches in postorder.
 *
 * Time Complexity:
 * - **O(N)** → Each node is processed once.
 *
 * Space Complexity:
 * - **O(N)** for the recursive stack (worst-case, skewed tree).
 * - **O(N)** extra space for the hash map.
 */

class Solution {
public:
    // Recursive function to construct the binary tree
    TreeNode* solve(int preStart, int postStart, int preEnd, vector<int> &preorder, vector<int> &postorder, unordered_map<int, int> &mp) {
        if (preStart > preEnd) return nullptr; // Base case
        
        // Create root node from preorder
        TreeNode* root = new TreeNode(preorder[preStart]);
        if (preStart == preEnd) return root; // Single node case

        // Find the left subtree root index in postorder using hash map
        int nextNode = preorder[preStart + 1]; // Left subtree root (next in preorder)
        int j = mp[nextNode]; // O(1) lookup instead of O(N) search

        int num = j - postStart + 1; // Number of nodes in left subtree

        // Recursive calls to build left and right subtrees
        root->left = solve(preStart + 1, postStart, preStart + num, preorder, postorder, mp);
        root->right = solve(preStart + num + 1, j + 1, preEnd, preorder, postorder, mp);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        unordered_map<int, int> mp; // Hash map for postorder indices

        // Store index of each value in postorder
        for (int i = 0; i < n; i++) {
            mp[postorder[i]] = i;
        }

        return solve(0, 0, n - 1, preorder, postorder, mp);
    }
};