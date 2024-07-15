/*
2196. Create Binary Tree From Descriptions
Solved
Medium
Topics
Companies
Hint
You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

If isLefti == 1, then childi is the left child of parenti.
If isLefti == 0, then childi is the right child of parenti.
Construct the binary tree described by descriptions and return its root.

The test cases will be generated such that the binary tree is valid.

 

Example 1:


Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
Output: [50,20,80,15,17,19]
Explanation: The root node is the node with value 50 since it has no parent.
The resulting binary tree is shown in the diagram.
Example 2:


Input: descriptions = [[1,2,1],[2,3,0],[3,4,1]]
Output: [1,2,null,null,3,4]
Explanation: The root node is the node with value 1 since it has no parent.
The resulting binary tree is shown in the diagram.
 

Constraints:

1 <= descriptions.length <= 104
descriptions[i].length == 3
1 <= parenti, childi <= 105
0 <= isLefti <= 1
The binary tree described by descriptions is valid.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr, right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Intuition:
// - Use a hashmap to create or retrieve TreeNode objects for parents and children.
// - Use a set to track all child nodes to identify the root node (the only node that is not a child).
// - Time Complexity: O(n), where n is the number of descriptions. We iterate through the descriptions twice.
// - Space Complexity: O(n). We use extra space for the hashmap and set.

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // HashMap to store nodes
        unordered_map<int, TreeNode*> mp;
        // Set to track all child nodes
        unordered_set<int> childSet;

        // Iterate through descriptions to create nodes and link them
        for(vector<int>& vec : descriptions) {
            int parent = vec[0];
            int child = vec[1];
            int isLeft = vec[2];

            // Create parent node if not present in hashmap
            if(mp.find(parent) == mp.end()) {
                mp[parent] = new TreeNode(parent);
            }

            // Create child node if not present in hashmap
            if(mp.find(child) == mp.end()) {
                mp[child] = new TreeNode(child);
            }

            // Link child to parent as left or right child
            if(isLeft) {
                mp[parent]->left = mp[child];
            } else {
                mp[parent]->right = mp[child];
            }

            // Add child to the set
            childSet.insert(child);
        }

        // Identify the root node (the one that is not a child)
        for(vector<int>& vec : descriptions) {
            int parent = vec[0];
            if(childSet.find(parent) == childSet.end()) {
                return mp[parent];
            }
        }

        return nullptr; // Return null if no root is found (shouldn't happen with valid input)
    }
};
