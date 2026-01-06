/*
1161. Maximum Level Sum of a Binary Tree

avatar
Discuss Approach
arrow-up
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

 

Example 1:


Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
Example 2:

Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-105 <= Node.val <= 105
*/

/*
Approach:
---------
We are given the root of a binary tree.
Our task is to find the level (1-indexed) that has the **maximum sum of node values**.

We use **Level Order Traversal (BFS)** to process the tree level by level.

Steps:
------
1. Use a queue to perform BFS.
2. For each level:
   - Determine the number of nodes at that level.
   - Sum their values.
3. Track:
   - `maxi` → maximum level sum seen so far
   - `ans`  → level at which maximum sum occurs
4. Update `maxi` and `ans` whenever a larger level sum is found.
5. Return the level number with the maximum sum.

Intuition:
----------
Level order traversal naturally groups nodes by levels.
By summing values level-wise, we can easily identify
which level contributes the most.

Time Complexity:
----------------
O(n) — Each node is visited exactly once.

Space Complexity:
-----------------
O(n) — Queue can hold up to one full level of nodes.

*/

class Solution {
public:
    int maxLevelSum(TreeNode* root) {

        int maxi = INT_MIN;  // Stores maximum level sum
        int level = 0;       // Current level number
        int ans = 0;         // Level with maximum sum

        queue<TreeNode*> q;
        q.push(root);        // Start BFS from root

        // Level order traversal
        while (!q.empty()) {

            int n = q.size();   // Number of nodes at current level
            int sum = 0;
            level++;

            // Process all nodes of current level
            while (n--) {
                TreeNode* curr = q.front();
                q.pop();

                sum += curr->val;

                // Push children into queue
                if (curr->left)
                    q.push(curr->left);

                if (curr->right)
                    q.push(curr->right);
            }

            // Update max sum and corresponding level
            if (sum > maxi) {
                maxi = sum;
                ans = level;
            }
        }

        return ans;
    }
};
