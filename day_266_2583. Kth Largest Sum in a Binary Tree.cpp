/*
2583. Kth Largest Sum in a Binary Tree
Solved
Medium
Topics
Companies
Hint
You are given the root of a binary tree and a positive integer k.

The level sum in the tree is the sum of the values of the nodes that are on the same level.

Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer than k levels in the tree, return -1.

Note that two nodes are on the same level if they have the same distance from the root.

 

Example 1:


Input: root = [5,8,9,2,1,3,7,4,6], k = 2
Output: 13
Explanation: The level sums are the following:
- Level 1: 5.
- Level 2: 8 + 9 = 17.
- Level 3: 2 + 1 + 3 + 7 = 13.
- Level 4: 4 + 6 = 10.
The 2nd largest level sum is 13.
Example 2:


Input: root = [1,2,null,3], k = 1
Output: 3
Explanation: The largest level sum is 3.
 

Constraints:

The number of nodes in the tree is n.
2 <= n <= 105
1 <= Node.val <= 106
1 <= k <= n
*/

/*
Approach:
- The goal is to find the `k`th largest level sum in a binary tree.
- We perform a level-order traversal (BFS) to compute the sum of nodes at each level.
- We use a min-heap (priority queue) of size `k` to keep track of the `k` largest sums encountered.
- If the size of the heap exceeds `k`, we pop the smallest element, ensuring that only the `k` largest sums remain in the heap.
- At the end, the root of the heap will contain the `k`th largest sum, if such a sum exists.

Key Steps:
1. Use a queue (`q`) to perform BFS, where each iteration processes all nodes at the current level.
2. For each level, calculate the sum of node values.
3. Push each level sum into the min-heap (`pq`).
4. If the heap size exceeds `k`, pop the smallest element to maintain only the `k` largest sums.
5. If there are fewer than `k` levels, return `-1`. Otherwise, return the root of the heap (`pq.top()`), which holds the `k`th largest sum.

Time Complexity:
- O(n log k), where `n` is the total number of nodes and `k` is the desired rank. Each level sum is pushed into the heap, and maintaining the heap takes `O(log k)` time.

Space Complexity:
- O(k + n), where `k` is the size of the heap and `n` is the maximum number of nodes in the queue at any point (the largest level in the tree).

*/

class Solution {
public:
    // Function to find the kth largest sum of levels in a binary tree
    long long kthLargestLevelSum(TreeNode* root, int k) {
        // Min-heap to store the k largest level sums
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        // Queue for level-order traversal (BFS)
        queue<TreeNode*> q;
        q.push(root);
        
        // Perform level-order traversal to calculate level sums
        while (!q.empty()) {
            int n = q.size(); // Number of nodes at the current level
            long long sum = 0; // Sum of the current level

            // Process all nodes at the current level
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front(); // Get the front node in the queue
                q.pop();
                sum += node->val; // Add node's value to the level sum

                // Add left and right children to the queue
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            // Push the level sum into the min-heap
            pq.push(sum);

            // If heap size exceeds k, remove the smallest element
            if (pq.size() > k) pq.pop();
        }

        // If there are fewer than k levels, return -1
        return pq.size() < k ? -1 : pq.top();
    }
};
