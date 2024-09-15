/*
206. Reverse Linked List
Solved
Easy
Topics
Companies
Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
 

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

/*
Approach:
1. Use a stack to store the values of the nodes as we traverse the list.
2. Traverse the list again, and for each node, replace its value with the top value from the stack.
3. Pop the stack after each assignment to maintain the reversed order of values.

Time Complexity:
- O(n): We traverse the list twice where `n` is the number of nodes.

Space Complexity:
- O(n): We use extra space for the stack, which stores all the node values.
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Initialize a stack to hold node values
        stack<int> st;
        ListNode* temp = head;
        
        // Traverse the list and push node values onto the stack
        while(temp){
            st.push(temp->val);
            temp = temp->next;
        }

        // Traverse the list again and pop values from the stack to reverse the list
        temp = head;
        while(temp){
            temp->val = st.top(); // Assign the top value from the stack to the node
            st.pop();            // Remove the top value from the stack
            temp = temp->next;  // Move to the next node
        }

        return head;
    }
};



/*
Approach:
1. Initialize three pointers: `prev` (nullptr), `curr` (head), and `next` (nullptr).
2. Iterate through the list:
   - Save the next node (`next = curr->next`).
   - Reverse the current node's pointer (`curr->next = prev`).
   - Move `prev` and `curr` forward.
3. After the loop, `prev` will point to the new head of the reversed list.

Time Complexity:
- O(n): We traverse the list once where `n` is the number of nodes.

Space Complexity:
- O(1): We use a constant amount of extra space for the pointers.
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Initialize pointers
        ListNode* prev = nullptr; // This will eventually become the new head
        ListNode* curr = head;    // Pointer to the current node
        ListNode* next = nullptr; // Temporary pointer to store the next node
        
        // Iterate through the list
        while (curr != nullptr) {
            next = curr->next; // Save the next node
            curr->next = prev; // Reverse the link
            prev = curr;       // Move prev forward
            curr = next;       // Move curr forward
        }
        
        // At the end of the loop, prev is the new head
        return prev;
    }
};


/*
Approach:
1. Use recursion to reverse the linked list.
2. The base case is when the list is empty or has only one node; in this case, return the head.
3. Recursively reverse the rest of the list (`head->next`).
4. Adjust the pointers to reverse the current node's link:
   - Set `head->next->next` to `head`.
   - Set `head->next` to `nullptr` to mark the end of the reversed portion.
5. Return the new head of the reversed list.

Time Complexity:
- O(n): Each node is processed exactly once.

Space Complexity:
- O(n): The space complexity is O(n) due to the recursion stack, where `n` is the number of nodes in the list.
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Base case: if the list is empty or has only one node
        if (!head || !head->next) return head;

        // Recursively reverse the rest of the list
        ListNode* newHead = reverseList(head->next);

        // Adjust pointers to reverse the current node's link
        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;

        return newHead;
    }
};
