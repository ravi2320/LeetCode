/*
2807. Insert Greatest Common Divisors in Linked List
Solved
Medium
Topics
Companies
Given the head of a linked list head, in which each node contains an integer value.

Between every pair of adjacent nodes, insert a new node with a value equal to the greatest common divisor of them.

Return the linked list after insertion.

The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.

 

Example 1:


Input: head = [18,6,10,3]
Output: [18,6,6,2,10,1,3]
Explanation: The 1st diagram denotes the initial linked list and the 2nd diagram denotes the linked list after inserting the new nodes (nodes in blue are the inserted nodes).
- We insert the greatest common divisor of 18 and 6 = 6 between the 1st and the 2nd nodes.
- We insert the greatest common divisor of 6 and 10 = 2 between the 2nd and the 3rd nodes.
- We insert the greatest common divisor of 10 and 3 = 1 between the 3rd and the 4th nodes.
There are no more adjacent nodes, so we return the linked list.
Example 2:


Input: head = [7]
Output: [7]
Explanation: The 1st diagram denotes the initial linked list and the 2nd diagram denotes the linked list after inserting the new nodes.
There are no pairs of adjacent nodes, so we return the initial linked list.
 

Constraints:

The number of nodes in the list is in the range [1, 5000].
1 <= Node.val <= 1000
*/

/*
Approach:
1. Iterate through the given singly-linked list using two pointers: `currNode` (current node) and `nextNode` (next node).
2. For each consecutive pair of nodes, calculate the Greatest Common Divisor (GCD) of their values.
3. Create a new node with the GCD value and insert it between `currNode` and `nextNode`.
4. Move the pointers forward and repeat the process until the end of the list is reached.

Time Complexity:
- O(n): We traverse the linked list once and compute the GCD for each pair of consecutive nodes (where n is the number of nodes in the list).

Space Complexity:
- O(1): We only use a constant amount of extra space to store pointers and GCD values (excluding the space for newly added nodes).

*/

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        // Initialize pointers to traverse the list
        ListNode* currNode = head;       // Points to the current node
        ListNode* nextNode = head->next; // Points to the next node

        // Traverse the list until nextNode is null
        while (nextNode) {
            // Calculate GCD of current and next node values
            int GCD = __gcd(currNode->val, nextNode->val);

            // Create a new node with the GCD value
            ListNode* gcdNode = new ListNode(GCD);

            // Insert the GCD node between currNode and nextNode
            currNode->next = gcdNode;
            gcdNode->next = nextNode;

            // Move the pointers to the next pair of nodes
            currNode = nextNode;
            nextNode = nextNode->next;
        }

        // Return the modified linked list head
        return head;
    }
};
