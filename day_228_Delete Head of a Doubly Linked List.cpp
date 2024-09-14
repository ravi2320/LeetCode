/*
Delete Head of a Doubly Linked List
Easy
40/40
Average time to solve is 10m
Contributed by
16 upvotes
Asked in company
Problem statement
You are given a doubly-linked list of length ’n’ .



Your task is to delete the head of a doubly-linked list.



Note:
A doubly-linked list is a data structure that consists of sequentially linked records, and the nodes have reference to both the previous and the next nodes in the sequence of nodes.
For Example:-
Input: 5 <-> 8 <-> 3 <-> 7 <-> 9

Output: 8 <-> 3 <-> 7 <-> 9

Explanation: The head of the given list is at 5. After deletion of head, new list is 8 <-> 3 <-> 7 <-> 9.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:-
4
3 1 8 7
Sample Output 1:-
1 8 7
Explanation of sample input 1:-
Given list: 3 <-> 1 <-> 8 <-> 7
Head of the given list is at 3. 
After deletion, updated list is 1 <-> 8 <->7
Sample Input 2:-
3
1 3 5
Sample Output 2:-
3 5
Constraints:-
1 <= ‘n’ <= 10^5
1 <= 'data' <= 10^9

where 'data' is the values of node in a doubly linked list.
Time Limit: 1 sec
*/

/*
Approach:
1. The function deletes the head node of a doubly linked list.
2. If the list is empty (`head` is `nullptr`) or contains only one node, we return `nullptr` as the new head.
3. Otherwise, we:
   - Store the current head in a temporary pointer (`temp`).
   - Move the head to the next node (`head = head->next`).
   - Update the new head's `prev` pointer to `nullptr` (to remove the backward link).
   - Delete the old head using the `delete` keyword to free memory.

Time Complexity:
- O(1): The function performs constant time operations for deleting the head.

Space Complexity:
- O(1): No additional space is used apart from a temporary pointer.

*/

Node* deleteHead(Node* head) {
    // If the list is empty or contains only one node, return nullptr.
    if (!head || !head->next) 
        return nullptr;

    Node* temp = head;  // Store the current head.
    head = head->next;  // Move the head to the next node.
    head->prev = nullptr;  // Set the previous pointer of the new head to nullptr.
    
    delete temp;  // Delete the old head to free memory.

    return head;  // Return the new head.
}
