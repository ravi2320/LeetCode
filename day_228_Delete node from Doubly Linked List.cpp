/*
Delete node from Doubly Linked List
Easy
40/40
Average time to solve is 10m
Contributed by
15 upvotes
Asked in companies
Problem statement
There exists a doubly linked list with nodes containing integer values. You are given a specified node of the list which you have to delete.



Note:

The node to be deleted is guaranteed not to be the head of the list.
EXAMPLE:
Input :
List = 1 <-> 2 <-> 3 <-> 4
Node = '3', its position k = 3

Output:
1 <-> 2 <-> 4

Explanation:
The 3rd node, which is '3', has been deleted.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
6 4
51 54 23 31 74 65 
Sample Output 1:
51 54 23 74 65 
Explanation Of Sample Input 1 :
The 4th node, which is '31' has been deleted.
Sample Input 2 :
8 3
24 76 65 54 40 58 68 61 
Sample Output 2 :
24 76 54 40 58 68 61 
Constraints :
1 <= 'n' <= 10^4
2 <= ‘k’ <= Length of the list, where ‘k’ is 1-indexed.
1 <= 'a[i]' <= 10^5 where a[i] are the values in list.

Time Limit: 1 sec
Expected Complexity :
Time Complexity : O(1)
Space Complexity : O(1)
*/

/*
Approach:
1. The function deletes the given node from a doubly linked list.
2. We check if the node is the head or the tail and update the adjacent nodes accordingly.
3. We safely handle the removal by updating both the `next` and `prev` pointers of the adjacent nodes.
4. After removing the node from the list, we free its memory.

Time Complexity:
- O(1): The deletion process only involves updating pointers and freeing memory.

Space Complexity:
- O(1): No additional space is used apart from pointers.
*/

void deleteNode(Node* node) {
    if (!node) return;  // Edge case: Null node.

    Node* prevNode = node->prev;
    Node* nextNode = node->next;

    // If there is a previous node, update its `next` pointer.
    if (prevNode) {
        prevNode->next = nextNode;
    }

    // If there is a next node, update its `prev` pointer.
    if (nextNode) {
        nextNode->prev = prevNode;
    }

    // Remove links to isolate the node (optional for clarity).
    node->next = nullptr;
    node->prev = nullptr;

    // Delete the node.
    delete node;
}
