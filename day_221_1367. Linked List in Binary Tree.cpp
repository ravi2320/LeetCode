/*
1367. Linked List in Binary Tree
Solved
Medium
Topics
Companies
Hint
Given a binary tree root and a linked list with head as the first node. 

Return True if all the elements in the linked list starting from the head correspond to some downward path connected in the binary tree otherwise return False.

In this context downward path means a path that starts at some node and goes downwards.

 

Example 1:



Input: head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true
Explanation: Nodes in blue form a subpath in the binary Tree.  
Example 2:



Input: head = [1,4,2,6], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true
Example 3:

Input: head = [1,4,2,6,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: false
Explanation: There is no path in the binary tree that contains all the elements of the linked list from head.
 

Constraints:

The number of nodes in the tree will be in the range [1, 2500].
The number of nodes in the list will be in the range [1, 100].
1 <= Node.val <= 100 for each node in the linked list and binary tree.
*/

/*
**Problem Statement:**
- The task is to determine if there exists a downward path in a binary tree whose nodes' values match the sequence in a linked list.

**Approach:**
1. **Check Function:**
   - This function checks if a linked list can be matched with a path starting from the current node of the binary tree.
   - It compares the values of the linked list nodes with the tree nodes.
   - If a mismatch occurs at any point, the function returns `false`.
   - If the linked list ends (`head == NULL`), the function returns `true` because it means all the linked list values have been matched successfully.

2. **Recursive Tree Traversal:**
   - We recursively traverse the binary tree using a helper function `isSubPath`, which checks if there is a matching path starting from the current root or any of its children (left or right).
   - For each tree node, we invoke the `check` function to determine if the current tree node and its children can match the linked list.

**Time Complexity:**
   - O(N * M), where `N` is the number of nodes in the binary tree and `M` is the length of the linked list.
   - For each node of the tree, we may need to check if the linked list matches a path starting from that node.

**Space Complexity:**
   - O(M) for the recursion stack if a valid path is found, where `M` is the length of the linked list (for recursive calls along a valid path).

**Example Usage:**
   - A linked list `{4 -> 2 -> 8}` and a binary tree where such a path exists will return `true`.

**Edge Cases:**
   - If the linked list is empty, the function should return `true`.
   - If the binary tree is empty, the function should return `false`.

*/

class Solution {
public:
    // Helper function to check if a linked list can be matched starting from the current tree node
    bool check(ListNode* head, TreeNode* root) {
        // If the linked list is exhausted, the match is successful
        if (head == NULL) return true;
        
        // If the tree is exhausted or values do not match, return false
        if (root == NULL || head->val != root->val) return false;
        
        // Recursively check left or right subtree to see if further nodes in the list match
        return check(head->next, root->left) || check(head->next, root->right);
    }

    // Main function to determine if the linked list is a subpath in the binary tree
    bool isSubPath(ListNode* head, TreeNode* root) {
        // If the tree is exhausted and no match was found, return false
        if (root == NULL) return false;
        
        // Check the current tree node, or explore left and right subtrees
        return check(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
