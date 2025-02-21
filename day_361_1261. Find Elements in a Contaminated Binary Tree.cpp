/*
1261. Find Elements in a Contaminated Binary Tree
Solved
Medium
Topics
Companies
Hint
Given a binary tree with the following rules:

root.val == 0
For any treeNode:
If treeNode.val has a value x and treeNode.left != null, then treeNode.left.val == 2 * x + 1
If treeNode.val has a value x and treeNode.right != null, then treeNode.right.val == 2 * x + 2
Now the binary tree is contaminated, which means all treeNode.val have been changed to -1.

Implement the FindElements class:

FindElements(TreeNode* root) Initializes the object with a contaminated binary tree and recovers it.
bool find(int target) Returns true if the target value exists in the recovered binary tree.
 

Example 1:


Input
["FindElements","find","find"]
[[[-1,null,-1]],[1],[2]]
Output
[null,false,true]
Explanation
FindElements findElements = new FindElements([-1,null,-1]); 
findElements.find(1); // return False 
findElements.find(2); // return True 
Example 2:


Input
["FindElements","find","find","find"]
[[[-1,-1,-1,-1,-1]],[1],[3],[5]]
Output
[null,true,true,false]
Explanation
FindElements findElements = new FindElements([-1,-1,-1,-1,-1]);
findElements.find(1); // return True
findElements.find(3); // return True
findElements.find(5); // return False
Example 3:


Input
["FindElements","find","find","find","find"]
[[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]
Output
[null,true,false,false,true]
Explanation
FindElements findElements = new FindElements([-1,null,-1,-1,null,-1]);
findElements.find(2); // return True
findElements.find(3); // return False
findElements.find(4); // return False
findElements.find(5); // return True
 

Constraints:

TreeNode.val == -1
The height of the binary tree is less than or equal to 20
The total number of nodes is between [1, 104]
Total calls of find() is between [1, 104]
0 <= target <= 106
*/

/**
 * Approach:
 * - **Recover the tree** by assigning values based on the given rules:
 *   - Root starts as `0`.
 *   - Left child = `2 * parent + 1`
 *   - Right child = `2 * parent + 2`
 * - Store all node values in an **unordered_set** for **O(1) search**.
 *
 * Intuition:
 * - Since the tree was **contaminated**, we reconstruct it by **traversing DFS**.
 * - The unordered set **allows constant-time lookup** for any target.
 *
 * Time Complexity:
 * - **Tree Recovery (DFS)** → **O(N)**
 * - **Find Operation** → **O(1)**
 *
 * Space Complexity:
 * - **O(N)** (Stores all elements in the set).
 */

class FindElements {
    unordered_set<int> st; // Stores all recovered values
public:
    // DFS to recover tree values
    void dfs(TreeNode* root, int x) {
        if (!root) return;

        root->val = x;
        st.insert(x);

        dfs(root->left, 2 * x + 1);
        dfs(root->right, 2 * x + 2);
    }

    // Constructor: Recovers tree from contaminated state
    FindElements(TreeNode* root) {
        st.clear();
        dfs(root, 0);
    }

    // Checks if the target exists in the tree
    bool find(int target) {
        return st.count(target);
    }
};