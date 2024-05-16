/*
2331. Evaluate Boolean Binary Tree
Solved
Easy
Topics
Companies
Hint
You are given the root of a full binary tree with the following properties:

Leaf nodes have either the value 0 or 1, where 0 represents False and 1 represents True.
Non-leaf nodes have either the value 2 or 3, where 2 represents the boolean OR and 3 represents the boolean AND.
The evaluation of a node is as follows:

If the node is a leaf node, the evaluation is the value of the node, i.e. True or False.
Otherwise, evaluate the node's two children and apply the boolean operation of its value with the children's evaluations.
Return the boolean result of evaluating the root node.

A full binary tree is a binary tree where each node has either 0 or 2 children.

A leaf node is a node that has zero children.

 

Example 1:


Input: root = [2,1,3,null,null,0,1]
Output: true
Explanation: The above diagram illustrates the evaluation process.
The AND node evaluates to False AND True = False.
The OR node evaluates to True OR False = True.
The root node evaluates to True, so we return true.
Example 2:

Input: root = [0]
Output: false
Explanation: The root node is a leaf node and it evaluates to false, so we return false.
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
0 <= Node.val <= 3
Every node has either 0 or 2 children.
Leaf nodes have a value of 0 or 1.
Non-leaf nodes have a value of 2 or 3.
*/

// Intuition:
// - We recursively evaluate each node in the binary tree.
// - If the node is a leaf node (i.e., it has no children), we return its boolean value.
// - If the node is an internal node, we recursively evaluate its left and right children.
// - Depending on the value of the current node, we perform either a logical OR or a logical AND operation on the results obtained from its children.
// - Finally, we return the result obtained after evaluating the entire tree.

// Time Complexity: O(N), where N is the number of nodes in the binary tree.
// - We visit each node of the tree once in the recursive evaluation process.
// - Therefore, the time complexity is linear with respect to the number of nodes in the tree.
// Space Complexity: O(H), where H is the height of the binary tree.
// - The space complexity is determined by the recursive call stack during the depth-first traversal of the tree.
// - In the worst case, where the tree is skewed (i.e., it resembles a linked list), the height of the tree is equal to the number of nodes, resulting in linear space complexity.
// - In the average case, where the tree is balanced, the space complexity is proportional to the height of the tree.
// - Overall, the space complexity is determined by the height of the tree.
#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        // Base case: If the root is a leaf node, return its boolean value
        if (!root->left && !root->right)
            return root->val;

        // Recursive evaluation of left and right subtrees
        bool a = evaluateTree(root->left);
        bool b = evaluateTree(root->right);

        // Logical operation based on the value of the current node
        if (root->val == 2)
            return a | b; // Logical OR operation
        else
            return a & b; // Logical AND operation
    }
};
