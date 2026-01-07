/*
1339. Maximum Product of Splitted Binary Tree

avatar
Discuss Approach
arrow-up
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.

Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.

Note that you need to maximize the answer before taking the mod and not after taking it.

 

Example 1:


Input: root = [1,2,3,4,5,6]
Output: 110
Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)
Example 2:


Input: root = [1,null,2,3,4,null,null,5,6]
Output: 90
Explanation: Remove the red edge and get 2 binary trees with sum 15 and 6.Their product is 90 (15*6)
 

Constraints:

The number of nodes in the tree is in the range [2, 5 * 104].
1 <= Node.val <= 104
*/

/*
Approach:
---------
We are given a binary tree. We need to split the tree into two subtrees
by removing exactly one edge such that the **product of the sums of the
two resulting subtrees is maximized**.

Steps:
------
1. First DFS (findSum):
   - Convert each node’s value into the sum of its entire subtree.
   - After this step, root->val holds the total sum of the tree.

2. Second DFS (solve):
   - For every possible edge removal:
       • Consider the subtree sum on one side of the cut
       • Remaining sum = totalSum - subtreeSum
       • Compute product = subtreeSum * remainingSum
   - Track the maximum product found.

3. Return the maximum product modulo 1e9+7.
   (Important: modulus is applied only at the end to avoid precision loss.)

Intuition:
----------
Any valid split corresponds to cutting exactly one edge.
If we know the sum of every subtree, then each cut gives us:
    subtreeSum × (totalSum − subtreeSum)

So the problem reduces to evaluating this expression for all subtrees
and taking the maximum.

Time Complexity:
----------------
O(n)
- Each node is visited once in findSum
- Each node is visited once in solve

Space Complexity:
-----------------
O(h)
- Recursion stack, where h is the height of the tree
- Worst case: O(n) for a skewed tree

*/

class Solution {
    const int mod = 1e9 + 7;

public:
    // DFS to compute subtree sums
    long long findSum(TreeNode* root) {
        if (!root) return 0;

        long long leftSum  = findSum(root->left);
        long long rightSum = findSum(root->right);

        // Store subtree sum directly in node value
        root->val += leftSum + rightSum;
        return root->val;
    }

    // DFS to evaluate all possible splits
    void solve(TreeNode* root, long long totalSum, long long &maxProduct) {
        if (!root) return;

        // Consider cutting the edge to the left child
        if (root->left) {
            long long leftSubtreeSum = root->left->val;
            long long remainingSum  = totalSum - leftSubtreeSum;

            long long product = leftSubtreeSum * remainingSum;
            maxProduct = max(maxProduct, product);

            solve(root->left, totalSum, maxProduct);
        }

        // Consider cutting the edge to the right child
        if (root->right) {
            long long rightSubtreeSum = root->right->val;
            long long remainingSum   = totalSum - rightSubtreeSum;

            long long product = rightSubtreeSum * remainingSum;
            maxProduct = max(maxProduct, product);

            solve(root->right, totalSum, maxProduct);
        }
    }

    int maxProduct(TreeNode* root) {
        // Step 1: Compute total tree sum
        long long totalSum = findSum(root);

        // Step 2: Try all splits and track maximum product
        long long maxProductVal = 0;
        solve(root, totalSum, maxProductVal);

        // Step 3: Return result modulo 1e9+7
        return maxProductVal % mod;
    }
};


