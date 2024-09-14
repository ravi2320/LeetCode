/*
 Delete Last Node of a Doubly Linked List
Easy
40/40
Average time to solve is 20m
Contributed by
43 upvotes
Problem statement
A doubly-linked list is a data structure that consists of sequentially linked nodes, and the nodes have reference to both the previous and the next nodes in the sequence of nodes.



Given a doubly-linked list, delete the node at the end of the doubly linked list.



Note:
You need not print anything. You’re given the head of the linked list, just return the head of the modified list.


Example:
Input: Linked List:  4 <-> 10 <-> 3 <-> 5 <-> 20

Output: Modified Linked List: 4 <-> 10 <-> 3 <-> 5

Explanation: The last node having ‘data’ = 20 is removed from the linked list.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
5
4 10 3 5 20


Sample Output 1:
4 10 3 5 NULL


Explanation Of Sample Input 1 :
The last node having ‘data’ = 20 is removed from the linked list.


Sample Input 2 :
1
5


Sample Output 2 :
NULL


Explanation Of Sample Input 2 :
The linked list has only one node, so the modified linked list is empty.


Expected time complexity :
The expected time complexity is O(N).


Constraints:
1 <= ‘N’ <= 100000
1 <= Data of a node in linked list <= 10^9

Time limit: 1 second
*/

/*
Approach:
1. If the list is empty or has only one node, return nullptr.
2. Otherwise, traverse to the last node.
3. Update the `next` pointer of the second last node to `nullptr` and delete the last node.

Time Complexity:
- O(n): We traverse to the end of the list.

Space Complexity:
- O(1): No extra space is used except for temporary pointers.
*/

Node* deleteLastNode(Node* head) {
    // Case 1: If the list is empty, return nullptr.
    if (!head) return nullptr;

    // Case 2: If there's only one node in the list.
    if (!head->next) {
        delete head; // Delete the only node.
        return nullptr; // List becomes empty.
    }

    // Case 3: Traverse to the last node.
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }

    // Update the second last node's `next` pointer to `nullptr`.
    temp->prev->next = nullptr;

    // Disconnect the last node and delete it.
    temp->prev = nullptr;
    delete temp;

    // Return the head of the list.
    return head;
}
