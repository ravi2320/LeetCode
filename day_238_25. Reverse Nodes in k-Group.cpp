/*
25. Reverse Nodes in k-Group
Solved
Hard
Topics
Companies
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000
 
*/

/*
 * Approach:
 * 1. This solution reverses nodes in a linked list in groups of `k`. The key idea is to reverse each group of `k` nodes individually.
 * 2. First, we find the `kth` node in each group. If the group contains fewer than `k` nodes, we stop and link the remaining nodes as is.
 * 3. We reverse the nodes between the current position and the `kth` node and adjust the pointers to maintain the list's structure.
 * 
 * Time Complexity: O(n), where `n` is the number of nodes in the linked list. Each node is visited at most twice.
 * 
 * Space Complexity: O(1), since the algorithm only uses a few pointers and doesn't need additional space proportional to the input size.
 */

class Solution {
public:
    // Helper function to reverse a segment of the linked list
    ListNode* reverse(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* prev = NULL;   // Initialize the previous node as NULL
        ListNode* curr = head;   // Start with the current node as the head
        while(curr) {
            ListNode* next = curr->next;  // Temporarily store the next node
            curr->next = prev;            // Reverse the current node's pointer
            prev = curr;                  // Move prev to the current node
            curr = next;                  // Move curr to the next node
        }

        return prev;  // Return the new head after reversing
    }

    // Helper function to find the k-th node from the current node
    ListNode* getKthNode(ListNode* temp, int k) {
        k -= 1;  // Since the first node is already the 1st, reduce `k` by 1
        while(temp && k--) {
            temp = temp->next;  // Move to the next node
        }
        return temp;  // Return the k-th node (or NULL if the group is smaller than `k`)
    }

    // Function to reverse nodes in k groups
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;     // Initialize temp pointer to traverse the list
        ListNode* prevNode = NULL; // Initialize the previous node to NULL

        // Process each group of k nodes
        while(temp) {
            ListNode* kthNode = getKthNode(temp, k);  // Find the k-th node in the current group

            // If the group has less than k nodes, no need to reverse
            if(!kthNode) {
                if(prevNode) prevNode->next = temp;  // Link the last segment
                break;
            }

            ListNode* nextNode = kthNode->next;  // Temporarily store the next node after the k-th node
            kthNode->next = NULL;                // Detach the k-th node to reverse the current segment
            reverse(temp);                       // Reverse the current segment

            // Adjust the head and previous node pointers after reversing
            if(temp == head) {
                head = kthNode;  // If this is the first group, update the head to the new head
            } else {
                prevNode->next = kthNode;  // Link the previous segment to the reversed segment
            }

            prevNode = temp;  // Move prevNode to the original head of the segment (which is now the tail)
            temp = nextNode;  // Move temp to the next segment to continue the process
        }

        return head;  // Return the new head of the list after reversing in k groups
    }
};
