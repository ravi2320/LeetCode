/*
2181. Merge Nodes in Between Zeros
Solved
Medium
Topics
Companies
Hint
You are given the head of a linked list, which contains a series of integers separated by 0's. The beginning and end of the linked list will have Node.val == 0.

For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. The modified list should not contain any 0's.

Return the head of the modified linked list.

 

Example 1:


Input: head = [0,3,1,0,4,5,2,0]
Output: [4,11]
Explanation: 
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 3 + 1 = 4.
- The sum of the nodes marked in red: 4 + 5 + 2 = 11.
Example 2:


Input: head = [0,1,0,3,0,2,2,0]
Output: [1,3,4]
Explanation: 
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 1 = 1.
- The sum of the nodes marked in red: 3 = 3.
- The sum of the nodes marked in yellow: 2 + 2 = 4.
 

Constraints:

The number of nodes in the list is in the range [3, 2 * 105].
0 <= Node.val <= 1000
There are no two consecutive nodes with Node.val == 0.
The beginning and end of the linked list have Node.val == 0.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Intuition:
// The problem is to merge nodes between two zero nodes and store the sum in the place of the first zero node, removing the intermediate nodes.
// We traverse the list, accumulating values until we encounter a zero, at which point we store the sum and reset the sum counter.

// Time Complexity: O(n), where n is the number of nodes in the linked list. We traverse each node exactly once.
// Space Complexity: O(1), as we use only a constant amount of extra space for pointers and counters.

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head;         // Pointer to traverse the list
        ListNode* zeroNode = head;     // Pointer to the current zero node
        ListNode* zeroNodePrev = head; // Pointer to the previous zero node
        int sum = 0;                   // Sum of values between zero nodes

        while(temp){
            if(temp->val == 0 && sum != 0){
                zeroNode->val = sum;    // Update the zero node with the sum
                zeroNode->next = temp;  // Move zero node's next to current zero node
                zeroNodePrev = zeroNode;// Update zeroNodePrev
                zeroNode = zeroNode->next;// Move zeroNode to the next node
                sum = 0;                // Reset sum for next segment
            } else {
                sum += temp->val;       // Accumulate values
            }
            temp = temp->next;          // Move to the next node
        }
        
        zeroNodePrev->next = NULL;      // Terminate the list after last zero node
        
        return head;
    }
};
