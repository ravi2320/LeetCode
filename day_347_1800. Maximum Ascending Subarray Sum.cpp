/*
1800. Maximum Ascending Subarray Sum
Solved
Easy
Topics
Companies
Hint
Given an array of positive integers nums, return the maximum possible sum of an ascending subarray in nums.

A subarray is defined as a contiguous sequence of numbers in an array.

A subarray [numsl, numsl+1, ..., numsr-1, numsr] is ascending if for all i where l <= i < r, numsi  < numsi+1. Note that a subarray of size 1 is ascending.

 

Example 1:

Input: nums = [10,20,30,5,10,50]
Output: 65
Explanation: [5,10,50] is the ascending subarray with the maximum sum of 65.
Example 2:

Input: nums = [10,20,30,40,50]
Output: 150
Explanation: [10,20,30,40,50] is the ascending subarray with the maximum sum of 150.
Example 3:

Input: nums = [12,17,15,13,10,11,12]
Output: 33
Explanation: [10,11,12] is the ascending subarray with the maximum sum of 33.
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
*/

/*
Approach:
1. The **diameter of a binary tree** is the length of the longest path between any two nodes in the tree. 
   - This path may or may not pass through the root.
   - The diameter is measured in terms of the number of edges.

2. For each node, we calculate:
   - The **height of the left subtree**.
   - The **height of the right subtree**.
   - The **diameter at the current node** = left height + right height.
   - We keep track of the maximum diameter found during the traversal.

3. We use a helper function `solve()` that:
   - Returns the height of the subtree rooted at the current node.
   - Updates the maximum diameter (`res`) during the traversal.

Intuition:
- The key insight is that the longest path (diameter) will always be the sum of the heights of the left and right subtrees at some node in the tree.

Time Complexity:
- **O(N)** where N is the number of nodes in the binary tree. Each node is visited exactly once.

Space Complexity:
- **O(H)** where H is the height of the binary tree due to the recursion stack.
  - In the worst case (skewed tree), it can be **O(N)**.
  - In the best case (balanced tree), it is **O(log N)**.
*/

class Solution {
public:
    // Helper function to calculate the height of the tree and update the diameter
    int solve(Node* root, int &res) {
        if (!root) {
            return 0;  // Base case: height of an empty subtree is 0
        }
        
        // Recursively calculate the height of the left and right subtrees
        int left = solve(root->left, res);
        int right = solve(root->right, res);
        
        // Update the diameter (maximum path length) at the current node
        res = max(res, left + right);
        
        // Return the height of the current subtree
        return 1 + max(left, right);
    }

    // Function to calculate the diameter of the binary tree
    int diameter(Node* root) {
        if (!root) {
            return 0;  // Edge case: empty tree has a diameter of 0
        }
        
        int res = 0;  // To store the maximum diameter found during traversal
        
        solve(root, res);  // Start the DFS traversal to calculate the diameter
        
        return res;  // The diameter is the longest path found
    }
};