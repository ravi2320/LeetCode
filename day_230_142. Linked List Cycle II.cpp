/*
142. Linked List Cycle II
Solved
Medium
Topics
Companies
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
Example 2:


Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
Example 3:


Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
 

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
 

Follow up: Can you solve it using O(1) (i.e. constant) memory?
*/

/*
Approach:
1. We use two pointers, `slow` and `fast`, to traverse the list:
   - `slow` moves one step at a time.
   - `fast` moves two steps at a time.
2. If there is a cycle in the list, the `fast` pointer will eventually meet the `slow` pointer within the cycle.
3. Once a cycle is detected, we reset the `slow` pointer to the head of the list and move both `slow` and `fast` one step at a time until they meet again. The meeting point will be the start of the cycle.
4. If no cycle is detected, return `NULL`.

Time Complexity:
- O(n): In the worst case, both `slow` and `fast` pointers traverse the list at most twice (once to detect the cycle and again to find the start of the cycle), where `n` is the number of nodes in the list.

Space Complexity:
- O(1): We use constant extra space (two pointer variables).

*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Edge case: if the list is empty or has only one node, no cycle is possible
        if (!head || !head->next)
            return NULL;

        // Initialize slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;

        // Move through the list until fast or fast->next becomes NULL (no cycle)
        while (fast && fast->next) {
            slow = slow->next;           // Move slow pointer by one step
            fast = fast->next->next;     // Move fast pointer by two steps

            // Cycle detected if slow and fast pointers meet
            if (slow == fast) {
                // Reset slow pointer to head to find the start of the cycle
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                // The point where slow and fast meet is the start of the cycle
                return slow;
            }
        }

        // No cycle found
        return NULL;
    }
};
