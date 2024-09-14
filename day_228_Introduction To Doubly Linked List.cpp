/*
Introduction To Doubly Linked List
Easy
40/40
Average time to solve is 10m
Contributed by
64 upvotes
Problem statement
You are given an array ‘Arr’ of size ‘N’ consisting of positive integers.



Your task is to make a doubly linked list from the array and return the head of the linked list.



Here, the head of the doubly linked list is the first element of the array, and the tail of the doubly linked list is the last element.



Note:
A doubly linked list is one in which it is possible to access the next and the previous nodes from a node in the linked list (if they exist).


Example:
Input: ‘N’ = 4, ‘Arr’ = [4, 2, 5, 1]

Output: 4 2 5 1

Explanation: Doubly Linked List for the array ‘Arr’ = [4, 2, 5, 1] is 4 <-> 2 <-> 5 <-> 1.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
4
4 2 5 1
Sample Output 1 :
4 2 5 1
Explanation Of Sample Input 1:
Input: ‘N’ = 4, ‘Arr’ = [4, 2, 5, 1]

Output: 4 2 5 1

Explanation: 
Doubly Linked List for the array ‘Arr’ = [4, 2, 5, 1] is 4 <-> 2 <-> 5 <-> 1.
Sample Input 2:
5
4 3 2 1 5
Sample Output 2:
4 3 2 1 5
Explanation Of Sample Input 2:
Input: ‘N’ = 5, ‘Arr’ = [4, 3, 2, 1, 5]

Output: 4 3 2 1 5

Explanation: 
Doubly Linked List for the array ‘Arr’ = [4, 3, 2, 1, 5] is 4 <-> 3 <-> 2 <-> 1 <-> 5.


Expected Time Complexity:
Try solving this in O(N).


Constraints:
1 <= 'N' <= 10^4
1 <= 'Arr[i]' <= 10^5

Time Limit: 1 sec
*/

/*
Approach:
1. We need to construct a doubly linked list (DLL) from a given array `arr` of integers.
2. Each node in the doubly linked list contains three parts: 
   - `data` to store the value,
   - `next` to point to the next node,
   - `prev` to point to the previous node.
3. We create the first node (`head`) using the first element of the array.
4. For each subsequent element in the array, a new node is created and linked to the previous node using the `next` and `prev` pointers.

Time Complexity:
- O(n): We traverse the array once and construct the doubly linked list.

Space Complexity:
- O(n): We create n nodes, one for each element in the array.

*/

Node* constructDLL(vector<int>& arr) {
    // Handle edge case where the array is empty.
    if (arr.empty()) return nullptr;

    // Create the head node using the first element of the array.
    Node* head = new Node(arr[0]);
    Node* curr = head;

    int n = arr.size();  // Get the size of the array.

    // Loop through the rest of the array and construct the DLL.
    for(int i = 1; i < n; i++) {
        // Create a new node for each element and link it with the previous node.
        curr->next = new Node(arr[i], nullptr, curr);
        curr = curr->next;  // Move the current pointer to the newly created node.
    }

    return head;  // Return the head of the constructed doubly linked list.
}
