/*
102. Binary Tree Level Order Traversal
Solved
Medium
Topics
Companies
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        while(!q.empty()){
            int levelSize = q.size();
            vector<int> temp;

            for(int i=0; i<levelSize; i++){
                TreeNode* front = q.front();
                q.pop();
                temp.push_back(front->val);

                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            ans.push_back(temp);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


class Solution {
public:
    void helper(TreeNode* root, int level, vector<vector<int>> &ans){
        if(root == NULL) return;

        if(level >= ans.size()){
            ans.push_back({});
        }
        ans[level].push_back(root->val);
        helper(root->left, level+1, ans);
        helper(root->right, level+1, ans);
    } 
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        helper(root, 0, ans);
        return ans;
    }
};