/*
2641. Cousins in Binary Tree II
Solved
Medium
Topics
Companies
Hint
Given the root of a binary tree, replace the value of each node in the tree with the sum of all its cousins' values.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Return the root of the modified tree.

Note that the depth of a node is the number of edges in the path from the root node to it.

 

Example 1:


Input: root = [5,4,9,1,10,null,7]
Output: [0,0,0,7,7,null,11]
Explanation: The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
- Node with value 5 does not have any cousins so its sum is 0.
- Node with value 4 does not have any cousins so its sum is 0.
- Node with value 9 does not have any cousins so its sum is 0.
- Node with value 1 has a cousin with value 7 so its sum is 7.
- Node with value 10 has a cousin with value 7 so its sum is 7.
- Node with value 7 has cousins with values 1 and 10 so its sum is 11.
Example 2:


Input: root = [3,1,2]
Output: [0,0,0]
Explanation: The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
- Node with value 3 does not have any cousins so its sum is 0.
- Node with value 1 does not have any cousins so its sum is 0.
- Node with value 2 does not have any cousins so its sum is 0.
 

Constraints:

The number of nodes in the tree is in the range [1, 105].
1 <= Node.val <= 104
*/

/*
Approach:
- This problem is about updating the value of each node in the tree such that its new value is the sum of all node values at the same level except for its own children.
- First, we calculate the sum of node values at each level of the tree and store it in `levelSum`.
- Then, we traverse the tree again and for each node, subtract the sum of its children from the `levelSum` of its level to determine its new value.
- The root node is set to 0 after all updates.
- We use a queue for level-order traversal (BFS).

Time Complexity: O(n), where 'n' is the number of nodes in the tree. We traverse the tree twice.
Space Complexity: O(n), for storing the queue and level sums.
*/

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        // Vector to store the sum of node values at each level
        vector<long long> levelSum;
        queue<TreeNode*> q;
        q.push(root);

        // First pass: calculate the sum of values at each level
        while (!q.empty()) {
            int n = q.size();
            long long sum = 0;
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Add the left and right child values to the sum
                if (node->left) {
                    q.push(node->left);
                    sum += node->left->val;
                }
                if (node->right) {
                    q.push(node->right);
                    sum += node->right->val;
                }
            }
            levelSum.push_back(sum); // Store the level sum
        }

        // Second pass: update node values
        q.push(root);
        int idx = 0; // To keep track of the current level
        while (!q.empty()) {
            int n = q.size();

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                long long childSum = 0;  // Calculate the sum of this node's children
                if (node->left) {
                    childSum += node->left->val;
                }
                if (node->right) {
                    childSum += node->right->val;
                }

                // Update the left child value
                if (node->left) {
                    node->left->val = levelSum[idx] - childSum;
                    q.push(node->left);
                }

                // Update the right child value
                if (node->right) {
                    node->right->val = levelSum[idx] - childSum;
                    q.push(node->right);
                }
            }
            idx++; // Move to the next level
        }

        // Set root value to 0
        root->val = 0;

        return root; // Return the updated tree
    }
};


/*
Approach:
- The goal is to replace each node's value with the difference between the sum of node values at its level and the sum of its children's values.
- We use a queue for a level-order traversal (BFS) to process the tree.
- For each node, we calculate the sum of its children and update its value.
- The children's values are then updated with this calculated sum, and we move to the next level.

Time Complexity: O(n), where 'n' is the number of nodes in the tree, since we visit each node exactly once.
Space Complexity: O(n), for the queue used in the BFS traversal.
*/

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return root;  // If tree is empty, return null

        queue<TreeNode*> q;  // Queue for BFS
        q.push(root);
        int levelSum = root->val;  // Initialize the level sum with the root's value

        // BFS traversal
        while (!q.empty()) {
            int n = q.size();  // Get the number of nodes at the current level
            int nextLevelSum = 0;  // Initialize sum for the next level

            // Process all nodes at the current level
            while (n--) {
                TreeNode* node = q.front();
                q.pop();

                // Update the current node's value
                node->val = levelSum - node->val;

                // Calculate the sum of the children
                int childSum = (node->left ? node->left->val : 0);
                childSum += (node->right ? node->right->val : 0);

                // Push the left child to the queue and update its value
                if (node->left) {
                    node->left->val = childSum;
                    q.push(node->left);
                }

                // Push the right child to the queue and update its value
                if (node->right) {
                    node->right->val = childSum;
                    q.push(node->right);
                }

                // Update the next level's total sum
                nextLevelSum += childSum;
            }

            // Move to the next level
            levelSum = nextLevelSum;
        }

        return root;  // Return the modified tree
    }
};
