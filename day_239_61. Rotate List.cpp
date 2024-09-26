/*
61. Rotate List
Solved
Medium
Topics
Companies
Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109
*/

/*
 * Approach:
 * 1. Find the length of the linked list and connect the last node to the head, forming a circular linked list.
 * 2. Calculate the effective rotations needed using `k = k % len` since rotating `len` times results in the same list.
 * 3. Find the new head by moving `len - k` steps from the start.
 * 4. Break the circular link to form the new rotated list.
 * 
 * Time Complexity: O(N), where N is the number of nodes in the list, as we traverse the list a few times.
 * Space Complexity: O(1), no additional space is used apart from pointers.
 */

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // If the list is empty or has only one node, or no rotation is needed
        if(!head || !head->next) return head;
        
        int len = 1;  // Initialize length to 1 to include the head

        ListNode* temp = head;
        // Calculate the length of the linked list
        while(temp->next){
            len++;
            temp = temp->next;
        }

        // Calculate effective rotations needed
        k = k % len;
        // If k is 0, the list remains the same
        if(k == 0) return head;

        len -= k;  // Adjust len to find the new head
        temp->next = head;  // Connect the last node to the head to form a circular list

        // Move to the node just before the new head
        for(int i = 0; i < len; i++){
            temp = temp->next;
        }

        head = temp->next;  // Set the new head
        temp->next = NULL;  // Break the circular link to finalize the list

        return head;  // Return the new head of the rotated list
    }
};
