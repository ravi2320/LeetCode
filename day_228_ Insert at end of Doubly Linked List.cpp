/*
 Insert at end of Doubly Linked List
Easy
40/40
Average time to solve is 20m
Contributed by
60 upvotes
Asked in company
Problem statement
A doubly-linked list is a data structure that consists of sequentially linked nodes, and the nodes have reference to both the previous and the next nodes in the sequence of nodes.



Given a doubly-linked list and a value ‘k’, insert a node having value ‘k’ at the end of the doubly linked list.



Note:
You need not print anything. You’re given the head of the linked list. Return the head of the modified list.


Example:
Input: Linked List: 4 <-> 10 <-> 3 <-> 5 and ‘k’ = 20

Output: Modified Linked List: 4 <-> 10 <-> 3 <-> 5 <-> 20

Explanation: A new node having value ‘k’ = 20 is inserted at the end of the linked list.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
4
4 10 3 5
20


Sample Output 1:
4 10 3 5 20


Explanation Of Sample Input 1 :
A new node having value ‘k’ = 20 is inserted at the end of the linked list.


Sample Input 2 :
0

5


Sample Output 2 :
5


Explanation Of Sample Input 2 :
The linked list was empty. So the new node is the only node in the modified linked list.


Expected time complexity:
The expected time complexity is O(N).


Constraints:
0 <= ‘N’ <= 100000
1 <= Value in linked list <= 10^9
1 <= ‘k’ <= 10^9

Time limit: 1 second
*/

/*
Approach:
1. If the list is empty, we create a new node and return it as the head.
2. If the list is non-empty, we traverse to the last node.
3. We create a new node, set its `prev` pointer to the current tail, and update the `next` pointer of the tail.

Time Complexity:
- O(n): We traverse to the end of the list.

Space Complexity:
- O(1): No extra space is used except for the new node.
*/

Node* insertAtTail(Node* head, int k) {
    // Case: If the list is empty, return the new node as the head.
    if (!head) return new Node(k);

    // Traverse to the last node (tail).
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }

    // Create the new node and adjust pointers.
    Node* newNode = new Node(k);
    temp->next = newNode;
    newNode->prev = temp;

    // Return the head of the list (unchanged).
    return head;
}
