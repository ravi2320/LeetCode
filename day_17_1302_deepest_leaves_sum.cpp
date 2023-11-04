/*

1302. Deepest Leaves Sum
Solved
Medium
Topics
Companies
Hint
Given the root of a binary tree, return the sum of values of its deepest leaves.
 

Example 1:


Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15
Example 2:

Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 19
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
1 <= Node.val <= 100

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
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        queue<TreeNode*> q;

        if(root == NULL) return 0;

        q.push(root);
        while(!q.empty())
        {
            queue<TreeNode*> temp;
            sum = 0;
            while(!q.empty())
            {
                TreeNode* front = q.front();
                q.pop();
                sum += front->val;
                if(front->left != NULL) temp.push(front->left);
                if(front->right != NULL) temp.push(front->right);
            }
            q = temp;
        }
        return sum;
    }
};