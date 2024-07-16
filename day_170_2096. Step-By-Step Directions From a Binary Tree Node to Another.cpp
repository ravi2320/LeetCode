/*
2096. Step-By-Step Directions From a Binary Tree Node to Another
Solved
Medium
Topics
Companies
Hint
You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.

Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:

'L' means to go from a node to its left child node.
'R' means to go from a node to its right child node.
'U' means to go from a node to its parent node.
Return the step-by-step directions of the shortest path from node s to node t.

 

Example 1:


Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
Output: "UURL"
Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.
Example 2:


Input: root = [2,1], startValue = 2, destValue = 1
Output: "L"
Explanation: The shortest path is: 2 → 1.
 

Constraints:

The number of nodes in the tree is n.
2 <= n <= 105
1 <= Node.val <= n
All the values in the tree are unique.
1 <= startValue, destValue <= n
startValue != destValue
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
    TreeNode* getLowestCommonAncestor(TreeNode* root, int p, int q){

        if(!root)
            return NULL;

        if(root->val == p || root->val == q)
            return root;

        TreeNode* leftN = getLowestCommonAncestor(root->left, p, q);
        TreeNode* rightN = getLowestCommonAncestor(root->right, p, q);
        
        if(leftN && rightN)
            return root;

        if(leftN)
            return leftN;

        return rightN;
    }

    bool findPath(TreeNode *root, int target, string &res){
        
        if(!root)
            return false;

        if(root->val == target)
            return true;

        res.push_back('L');
        if(findPath(root->left, target, res)){
            return true;
        }
        res.pop_back();

        res.push_back('R');
        if(findPath(root->right, target, res)){
            return true;
        }
        res.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        TreeNode* LCA = getLowestCommonAncestor(root, startValue, destValue);

        string lcaTOsrc = "";
        string lcaTOdest = "";/**
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
    // - To find directions from `startValue` to `destValue` in a binary tree, we can trace the path from the root to each of these nodes.
    // - Once we have the paths, we can determine the point where the paths diverge.
    // - The final directions from `startValue` to `destValue` can be formed by moving up to the divergence point and then down to `destValue`.

    // Time Complexity: O(N)
    // - Finding the path from the root to `startValue` and `destValue` takes O(N) time each.
    // - Comparing the paths to find the divergence point takes O(H) time, where H is the height of the tree.
    // - Overall time complexity is O(N).

    // Space Complexity: O(H)
    // - The recursion stack for the path finding functions has a maximum depth of H, where H is the height of the tree.
    // - The space required for the path strings is O(H) in the worst case.

    bool getPath(TreeNode* root, int target, string &path) {
        // Base case: if root is NULL
        if (!root)
            return false;

        // If the current node is the target
        if (root->val == target)
            return true;

        // Recur on the left subtree
        path.push_back('L');
        if (getPath(root->left, target, path)) {
            return true;
        }
        path.pop_back();

        // Recur on the right subtree
        path.push_back('R');
        if (getPath(root->right, target, path)) {
            return true;
        }
        path.pop_back();

        // If the target is not found
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        // Find the path from root to startValue
        string srcPath = "";
        getPath(root, startValue, srcPath);

        // Find the path from root to destValue
        string destPath = "";
        getPath(root, destValue, destPath);

        // Find the divergence point
        int i = 0;
        while (i < srcPath.length() && i < destPath.length() && srcPath[i] == destPath[i]) {
            i++;
        }

        // Create the result string
        string result = "";
        for (int j = i; j < srcPath.length(); j++) {
            result.push_back('U'); // Move up from startValue to the divergence point
        }
        result += destPath.substr(i); // Append the path from the divergence point to destValue

        return result;
    }
};


        findPath(LCA, startValue, lcaTOsrc);
        findPath(LCA, destValue, lcaTOdest);

        string result = "";
        for(char &ch : lcaTOsrc){
            result.push_back('U');
        }

        result += lcaTOdest;

        return result;
    }
};

