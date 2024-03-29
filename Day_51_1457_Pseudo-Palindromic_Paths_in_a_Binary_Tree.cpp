/*
1457. Pseudo-Palindromic Paths in a Binary Tree
Solved
Medium
Topics
Companies
Hint
Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be pseudo-palindromic if at least one permutation of the node values in the path is a palindrome.

Return the number of pseudo-palindromic paths going from the root node to leaf nodes.

 

Example 1:



Input: root = [2,3,1,3,1,null,1]
Output: 2 
Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the red path [2,3,3], the green path [2,1,1], and the path [2,3,1]. Among these paths only red path and green path are pseudo-palindromic paths since the red path [2,3,3] can be rearranged in [3,2,3] (palindrome) and the green path [2,1,1] can be rearranged in [1,2,1] (palindrome).
Example 2:



Input: root = [2,1,1,1,3,null,null,null,null,null,1]
Output: 1 
Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the green path [2,1,1], the path [2,1,3,1], and the path [2,1]. Among these paths only the green path is pseudo-palindromic since [2,1,1] can be rearranged in [1,2,1] (palindrome).
Example 3:

Input: root = [9]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [1, 105].
1 <= Node.val <= 9
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
    int result = 0; 
    void solve(TreeNode* root, vector<int>& count){
        if(root == NULL) return;

        count[root->val]++;
        if(root->left == NULL && root->right == NULL){
            int oddFreq = 0;
            for(int i=1; i<=9; i++){
                if(count[i] % 2 != 0)
                    oddFreq++;
            }
            if(oddFreq <= 1)
                result++;
        }

        solve(root->left, count);
        solve(root->right, count);
        count[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> count(10, 0);
        solve(root, count);
        return result;
    }
};

class Solution {
public:
    int result = 0; 
    void solve(TreeNode* root, int count){
        if(root == NULL) return;

        count = (count ^ (1 << root->val));
        if(root->left == NULL && root->right == NULL){
            if((count & count-1) == 0)
                result++;
        }

        solve(root->left, count);
        solve(root->right, count);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        solve(root, 0);
        return result;
    }
};