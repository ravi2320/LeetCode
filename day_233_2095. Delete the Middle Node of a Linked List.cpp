/*
2095. Delete the Middle Node of a Linked List
Solved
Medium
Topics
Companies
Hint
You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.
 

Example 1:


Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
Explanation:
The above figure represents the given linked list. The indices of the nodes are written below.
Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
We return the new list after removing this node. 
Example 2:


Input: head = [1,2,3,4]
Output: [1,2,4]
Explanation:
The above figure represents the given linked list.
For n = 4, node 2 with value 3 is the middle node, which is marked in red.
Example 3:


Input: head = [2,1]
Output: [2]
Explanation:
The above figure represents the given linked list.
For n = 2, node 1 with value 1 is the middle node, which is marked in red.
Node 0 with value 2 is the only node remaining after removing node 1.
 

Constraints:

The number of nodes in the list is in the range [1, 105].
1 <= Node.val <= 105
*/


/*
Approach:
1. **Two Passes Approach**:
   - In the first pass, traverse the linked list to calculate its length.
   - In the second pass, traverse again until reaching the node just before the middle node, then delete the middle node.
2. **Edge Case**:
   - If the list contains only one node, return `NULL` because the only node needs to be deleted.
   
Time Complexity:
- **O(L)**, where `L` is the length of the linked list. We traverse the list twice, once to calculate the length and once to delete the middle node.

Space Complexity:
- **O(1)**: We only use a few pointers and a variable to store the length, so the space usage is constant.

*/

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // If the list has only one node or is empty, return NULL
        if(!head || !head->next)
            return NULL;

        // Step 1: Calculate the length of the list
        int len = 0;
        ListNode* temp = head;
        while(temp) {
            len++;
            temp = temp->next;
        }

        // Step 2: Find the middle node (index len / 2)
        len /= 2;  // Middle node index
        temp = head;
        while(len != 1) {  // Traverse to the node just before the middle node
            temp = temp->next;
            len--;
        }

        // Step 3: Delete the middle node
        ListNode* delNode = temp->next;  // Middle node to delete
        temp->next = temp->next->next;   // Skip over the middle node
        delete delNode;  // Free the memory

        return head;  // Return the modified list
    }
};



/*
Approach:
1. **Two Pointer Technique (Slow and Fast pointers)**:
   - Use two pointers: `slow` and `fast`.
   - Move the `slow` pointer one step at a time and the `fast` pointer two steps at a time.
   - When `fast` reaches the end of the list, the `slow` pointer will be at the middle of the list.
2. **Edge Case**:
   - If the list has only one node or is empty, return `NULL` because the only node needs to be deleted.
   
Time Complexity:
- **O(L)**, where `L` is the length of the linked list. We traverse the list once.

Space Complexity:
- **O(1)**: Only a few pointers (`slow`, `fast`, and `delNode`) are used, so the space usage is constant.

*/

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // If there's only one node or the list is empty, return NULL
        if(!head || !head->next)
            return NULL;

        // Initialize slow and fast pointers
        ListNode* slow = head;  // Slow pointer
        ListNode* fast = head;  // Fast pointer
        
        // Move fast two steps and slow one step until fast reaches the end
        fast = fast->next->next;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow is now pointing to the node before the middle node
        ListNode* delNode = slow->next;  // Middle node to delete
        slow->next = slow->next->next;   // Remove middle node by skipping it
        delete delNode;  // Free the memory

        return head;  // Return the modified list
    }
};
