/*
515. Find Largest Value in Each Tree Row
Solved
Medium
Topics
Companies
Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

 

Example 1:


Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]
Example 2:

Input: root = [1,2,3]
Output: [1,3]
 

Constraints:

The number of nodes in the tree will be in the range [0, 104].
-231 <= Node.val <= 231 - 1
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

//Using BFS
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        
        vector<int> arr;
        if(root==NULL) return arr;
        queue<TreeNode*> q;
        int maxNode;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            maxNode = q.front()->val;
            while(n--)
            {
                TreeNode* t = q.front();
                q.pop();
                maxNode = max(maxNode, t->val);
                if(t->left != NULL)
                    q.push(t->left);
                if(t->right != NULL)
                    q.push(t->right);
            }
            arr.push_back(maxNode);
        }
        return arr;
    }
};

//Using DFS
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

    void dfs(TreeNode* root, int currHeight, vector<int> &rowMax)
    {
        if(root == NULL) return;

        if(rowMax.size() < currHeight+1)
        {
            rowMax.push_back(root->val);
        }
        if(rowMax[currHeight] < root->val)
        {
            rowMax[currHeight] = root->val;
        }
        dfs(root->left, currHeight+1, rowMax);
        dfs(root->right, currHeight+1, rowMax);
    }

    vector<int> largestValues(TreeNode* root) {
        vector<int> rowMax;
        dfs(root, 0, rowMax);
        return rowMax;
    }
};