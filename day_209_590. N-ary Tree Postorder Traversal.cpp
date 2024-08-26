/*
590. N-ary Tree Postorder Traversal
Solved
Easy
Topics
Companies
Given the root of an n-ary tree, return the postorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)

 

Example 1:


Input: root = [1,null,3,2,4,null,5,6]
Output: [5,6,3,2,4,1]
Example 2:


Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [2,6,14,11,7,3,12,8,4,13,9,10,5,1]
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
0 <= Node.val <= 104
The height of the n-ary tree is less than or equal to 1000.
 
*/

/*
Intuition:
The problem involves performing a postorder traversal on an N-ary tree, where each node can have multiple children. In a postorder traversal, the process is to first visit all the children of a node and then visit the node itself. This ensures that all the descendant nodes are processed before their parent node.

Approach:
1. **Recursive Traversal**:
   - Start from the root node and recursively visit each child node using a helper function.
   - After all children of a node have been processed, add the value of the current node to the result list.
2. **Base Case**:
   - If the current node is `nullptr`, return immediately as there is nothing to process.
3. **Final Result**:
   - The result vector will contain the nodes' values in postorder sequence.

Time Complexity:
- The time complexity is O(N), where N is the total number of nodes in the tree. This is because each node is visited exactly once.

Space Complexity:
- The space complexity is O(N) in the worst case due to the recursion stack, especially if the tree is skewed. The additional space for storing the result is also O(N).

*/

class Solution {
public:
    // Helper function to perform the postorder traversal recursively
    void solve(Node *root, vector<int> &ans) {
        if (!root) return;

        // Recursively traverse all the children
        for (int i = 0; i < root->children.size(); i++) {
            solve(root->children[i], ans);
        }
        
        // Process the current node after all children
        ans.push_back(root->val);
    }

    // Function to perform postorder traversal on the N-ary tree
    vector<int> postorder(Node* root) {
        vector<int> ans;

        // If the root is null, return an empty result
        if (!root) return ans;

        // Call the helper function to fill the result in postorder
        solve(root, ans);

        return ans;
    }
};
