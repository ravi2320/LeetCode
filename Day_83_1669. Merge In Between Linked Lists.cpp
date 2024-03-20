/*
1669. Merge In Between Linked Lists
Solved
Medium
Topics
Companies
Hint
You are given two linked lists: list1 and list2 of sizes n and m respectively.

Remove list1's nodes from the ath node to the bth node, and put list2 in their place.

The blue edges and nodes in the following figure indicate the result:


Build the result list and return its head.

 

Example 1:


Input: list1 = [10,1,13,6,9,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
Output: [10,1,13,1000000,1000001,1000002,5]
Explanation: We remove the nodes 3 and 4 and put the entire list2 in their place. The blue edges and nodes in the above figure indicate the result.
Example 2:


Input: list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
Output: [0,1,1000000,1000001,1000002,1000003,1000004,6]
Explanation: The blue edges and nodes in the above figure indicate the result.
 

Constraints:

3 <= list1.length <= 104
1 <= a <= b < list1.length - 1
1 <= list2.length <= 104
*/

class Solution {
public:
    // Merges list2 into list1 between nodes with indices a and b
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *left = NULL;  // Pointer to the node just before the sublist to be replaced
        ListNode *right = list1;  // Pointer to the node after the sublist to be replaced

        // Traverse list1 until reaching the end of the sublist to be replaced
        for (int i = 0; i <= b; i++) {
            // If the current node is the one just before the sublist to be replaced, update left pointer
            if (i == a - 1)
                left = right;
            
            // Move the right pointer to the next node
            right = right->next;
        }

        // Connect the sublist before 'left' to list2
        left->next = list2;

        // Traverse to the end of list2
        while (left->next != NULL) {
            left = left->next;
        }

        // Connect the end of list2 to the sublist after 'right'
        left->next = right;

        // Return the modified list1
        return list1;
    }
};