/*
2471. Minimum Number of Operations to Sort a Binary Tree by Level
Solved
Medium
Topics
Companies
Hint
You are given the root of a binary tree with unique values.

In one operation, you can choose any two nodes at the same level and swap their values.

Return the minimum number of operations needed to make the values at each level sorted in a strictly increasing order.

The level of a node is the number of edges along the path between it and the root node.

 

Example 1:


Input: root = [1,4,3,7,6,8,5,null,null,null,null,9,null,10]
Output: 3
Explanation:
- Swap 4 and 3. The 2nd level becomes [3,4].
- Swap 7 and 5. The 3rd level becomes [5,6,8,7].
- Swap 8 and 7. The 3rd level becomes [5,6,7,8].
We used 3 operations so return 3.
It can be proven that 3 is the minimum number of operations needed.
Example 2:


Input: root = [1,3,2,7,6,5,4]
Output: 3
Explanation:
- Swap 3 and 2. The 2nd level becomes [2,3].
- Swap 7 and 4. The 3rd level becomes [4,6,5,7].
- Swap 6 and 5. The 3rd level becomes [4,5,6,7].
We used 3 operations so return 3.
It can be proven that 3 is the minimum number of operations needed.
Example 3:


Input: root = [1,2,3,4,5,6]
Output: 0
Explanation: Each level is already sorted in increasing order so return 0.
 

Constraints:

The number of nodes in the tree is in the range [1, 105].
1 <= Node.val <= 105
All the values of the tree are unique.
*/

/*
Approach:
This problem aims to calculate the minimum number of operations required to make the binary tree level-wise sorted. For each level of the tree:
1. Extract the node values.
2. Compute the minimum number of swaps needed to sort the values. This is done using a helper function `minSwaps`, which uses a sorting and mapping approach to minimize swaps.
3. Sum up the swaps across all levels of the tree.

Key Components:
- `minSwaps` function:
  - Sorts the array and uses a hash map to track original indices.
  - Performs swaps to move elements to their sorted positions while counting the swaps.
- BFS traversal:
  - Traverse the tree level-by-level and extract values.
  - For each level, calculate the swaps using `minSwaps`.

Time Complexity:
1. BFS Traversal: O(n), where `n` is the total number of nodes in the tree.
2. Sorting and swaps for each level:
   - Sorting: O(k log k), where `k` is the number of nodes at the current level.
   - Swaps: O(k), in the worst case.
   - Total across all levels ≈ O(n log k), assuming balanced tree.

Space Complexity:
- BFS Queue: O(n), for storing nodes during traversal.
- Additional space for arrays and map: O(k) per level.

Edge Cases:
1. Tree with a single node.
2. Tree where all levels are already sorted.
3. Tree with uneven levels or missing children.

*/

class Solution {
public:
    // Helper function to calculate the minimum number of swaps to sort an array
    int minSwaps(vector<int> &vec) {
        vector<int> sortedVec(vec.begin(), vec.end());
        sort(sortedVec.begin(), sortedVec.end());
        unordered_map<int, int> mp;
        int n = vec.size();
        int swaps = 0;

        // Map original positions of elements
        for (int i = 0; i < n; i++) {
            mp[vec[i]] = i;
        }

        // Iterate through the array to sort it with minimum swaps
        for (int i = 0; i < n; i++) {
            if (vec[i] == sortedVec[i]) 
                continue;

            // Swap current element with its correct position
            int currIdx = mp[sortedVec[i]];
            mp[vec[i]] = currIdx;
            mp[vec[currIdx]] = i;
            swap(vec[i], vec[currIdx]);
            swaps++;
        }

        return swaps;
    }

    // Main function to calculate the minimum operations to make the tree level-wise sorted
    int minimumOperations(TreeNode* root) {
        if (!root) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int res = 0;

        // BFS traversal to process each level
        while (!q.empty()) {
            int n = q.size();
            vector<int> vec;

            // Process all nodes at the current level
            while (n--) {
                TreeNode* curr = q.front();
                q.pop();
                vec.push_back(curr->val);

                // Add left and right children to the queue
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
            }

            // Calculate swaps for the current level
            res += minSwaps(vec);
        }

        return res;
    }
};
