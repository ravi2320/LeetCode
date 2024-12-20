/*
2415. Reverse Odd Levels of Binary Tree
Solved
Medium
Topics
Companies
Hint
Given the root of a perfect binary tree, reverse the node values at each odd level of the tree.

For example, suppose the node values at level 3 are [2,1,3,4,7,11,29,18], then it should become [18,29,11,7,4,3,1,2].
Return the root of the reversed tree.

A binary tree is perfect if all parent nodes have two children and all leaves are on the same level.

The level of a node is the number of edges along the path between it and the root node.

 

Example 1:


Input: root = [2,3,5,8,13,21,34]
Output: [2,5,3,8,13,21,34]
Explanation: 
The tree has only one odd level.
The nodes at level 1 are 3, 5 respectively, which are reversed and become 5, 3.
Example 2:


Input: root = [7,13,11]
Output: [7,11,13]
Explanation: 
The nodes at level 1 are 13, 11, which are reversed and become 11, 13.
Example 3:

Input: root = [0,1,2,0,0,0,0,1,1,1,1,2,2,2,2]
Output: [0,2,1,0,0,0,0,2,2,2,2,1,1,1,1]
Explanation: 
The odd levels have non-zero values.
The nodes at level 1 were 1, 2, and are 2, 1 after the reversal.
The nodes at level 3 were 1, 1, 1, 1, 2, 2, 2, 2, and are 2, 2, 2, 2, 1, 1, 1, 1 after the reversal.
 

Constraints:

The number of nodes in the tree is in the range [1, 214].
0 <= Node.val <= 105
root is a perfect binary tree.
*/

/*
Approach:
1. Perform a level-order traversal (BFS) of the binary tree using a queue.
2. Keep track of the current level index (`level`), starting from 0.
3. Collect all nodes at each level in a `vector<TreeNode*> nodesAtLevel`.
4. If the current level is odd:
   - Reverse the values of the nodes at that level using two pointers (`left` and `right`).
5. Push the children of nodes at the current level into the queue for the next iteration.
6. Continue until all levels are processed.

Steps:
1. Use a queue for BFS.
2. At each level, collect nodes and store their children for the next level.
3. Reverse node values if the level is odd.
4. Increment the level counter and repeat.

Time Complexity:
- O(n): Each node is visited once, and reversing values at odd levels takes linear time in the worst case.

Space Complexity:
- O(w): Space used by the queue and vector, where `w` is the maximum width of the tree.

Edge Cases:
- Tree with only one node.
- Tree with no odd levels (only root).

*/

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root); // Start BFS from the root
        int level = 0; // Track current level
        
        while (!q.empty()) {
            int n = q.size(); // Number of nodes at the current level
            vector<TreeNode*> nodesAtLevel;

            // Process nodes at the current level
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                nodesAtLevel.push_back(node); // Collect nodes at this level
                
                if (node->left) q.push(node->left);   // Add left child to the queue
                if (node->right) q.push(node->right); // Add right child to the queue
            }

            // Reverse the values if the current level is odd
            if (level % 2 == 1) {
                int left = 0, right = nodesAtLevel.size() - 1;
                while (left < right) {
                    swap(nodesAtLevel[left]->val, nodesAtLevel[right]->val); // Swap values
                    left++;
                    right--;
                }
            }
            
            level++; // Increment level after processing
        }

        return root; // Return the updated tree
    }
};
