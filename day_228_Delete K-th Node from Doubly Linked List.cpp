/*
Delete K-th Node from Doubly Linked List
Easy
40/40
Average time to solve is 20m
Contributed by
30 upvotes
Asked in companies
Problem statement
You are given a Doubly linked list, where every node in the linked list contains two pointers, ‘next’ and ‘prev’, which point to the next node and previous node in the list respectively. All nodes have some positive integer value associated with them.



Your task is to delete the node at the ‘k’-th position.



Note:
The 'k' given will always be less than or equal to the length of the 'list'.


Example:
 Input: ‘k’ = 3, 'list' = [1, 2, 5, 4]

 Output: [1, 2, 4]

 Explanation:
 The 3rd node, which is '5', is deleted.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
5 3
12 28 35 47 59 


Sample Output 1:
12 28 47 59 


Explanation Of Sample Input 1:
The 3rd node, which is '35', is deleted.


Sample Input 2:
7 2
8 16 24 32 40 48 56 


Sample Output 2:
8 24 32 40 48 56 


Explanation Of Sample Input 2:
The 2nd node, which is '16', is deleted.


Constraints :
1 <= Length of the list <= 10^4
1 <= ‘k’ <= Length of the list, where ‘k’ is 1-indexed.

Time Limit: 1 sec


Expected Complexity :
Time Complexity : O(k)
Space Complexity : O(1)

Where, 'k' is the position of the node to be deleted in the list.
*/

/*
Approach:
1. The function deletes the k-th node (1-based index) of a doubly linked list.
2. We first traverse the list to find the k-th node by moving a pointer `KthNode` along the list and keeping a counter (`cnt`).
3. Once we reach the k-th node:
   - We handle three cases:
     - If the k-th node is the only node in the list, we return `nullptr`.
     - If the k-th node is the head (no previous node), we update the head to the next node and return it.
     - If the k-th node is the tail (no next node), we update the previous node to be the new tail.
     - For intermediate nodes, we update the previous and next pointers of adjacent nodes to skip the k-th node.
4. Finally, we free the memory of the deleted node.

Time Complexity:
- O(k): In the worst case, we need to traverse `k` nodes to find the k-th node.

Space Complexity:
- O(1): No additional space is used apart from pointers.

*/

Node* deleteNode(Node* head, int k) {
    if (!head) return nullptr;  // Edge case: Empty list.

    int cnt = 1;  // 1-based index.
    Node* KthNode = head;
    
    // Traverse to the k-th node.
    while (KthNode && cnt < k) {
        KthNode = KthNode->next;
        cnt++;
    }

    if (!KthNode) return head;  // If k-th node doesn't exist, return head unchanged.

    Node* prevNode = KthNode->prev;
    Node* nextNode = KthNode->next; 

    // Case 1: The list contains only the k-th node.
    if (!prevNode && !nextNode) {
        delete KthNode;
        return nullptr;
    }
    
    // Case 2: k-th node is the head.
    if (!prevNode) {
        nextNode->prev = nullptr;  // Remove the backward link.
        delete KthNode;
        return nextNode;  // The new head is the next node.
    }
    
    // Case 3: k-th node is the tail.
    if (!nextNode) {
        prevNode->next = nullptr;  // Update the tail.
        delete KthNode;
        return head;  // Return the original head.
    }

    // Case 4: k-th node is in the middle.
    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    // Remove links from the k-th node to isolate it.
    KthNode->next = nullptr;
    KthNode->prev = nullptr;
    
    delete KthNode;  // Free the memory of the k-th node.

    return head;
}
