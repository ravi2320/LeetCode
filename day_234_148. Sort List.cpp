/*
148. Sort List
Solved
Medium
Topics
Companies
Given the head of a linked list, return the list after sorting it in ascending order.

 

Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105
*/

/*
Approach:
1. **Extract values**:
   - Traverse through the linked list and store the values in a vector.
   
2. **Sort the vector**:
   - Use the built-in `sort()` function to sort the values in ascending order.

3. **Rebuild the list**:
   - Traverse through the linked list again, updating each node with the sorted values.

Time Complexity:
- **O(n log n)**: 
  - Extracting values takes O(n), where `n` is the number of nodes in the linked list.
  - Sorting the vector takes O(n log n).
  - Rebuilding the list with sorted values takes O(n).
  - Overall, the time complexity is dominated by the sorting step, making it O(n log n).

Space Complexity:
- **O(n)**: 
  - We use an additional vector to store the values of the linked list, which takes O(n) space.

*/

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // If the list is empty or contains only one element, return it as is
        if (!head || !head->next)
            return head;

        // Step 1: Extract the values from the linked list into a vector
        vector<int> arr;
        ListNode* temp = head;
        while (temp) {
            arr.push_back(temp->val);  // Add each node's value to the vector
            temp = temp->next;
        }

        // Step 2: Sort the vector of values
        sort(arr.begin(), arr.end());

        // Step 3: Rebuild the linked list with the sorted values
        temp = head;
        int i = 0;
        while (temp) {
            temp->val = arr[i++];  // Assign the sorted values back to the nodes
            temp = temp->next;
        }

        return head;  // Return the head of the sorted linked list
    }
};

/*
Approach:
1. **Divide the list into two halves**:
   - Use the slow and fast pointer technique to find the middle of the linked list.
   - Split the linked list into two parts: `left` and `right`.

2. **Sort both halves recursively**:
   - Recursively apply the sorting process to both halves.

3. **Merge the sorted halves**:
   - Use the merge function to merge two sorted linked lists.

This approach is based on **Merge Sort**, which works well for linked lists.

Time Complexity:
- **O(n log n)**:
  - Finding the middle of the list takes O(n).
  - Recursively sorting both halves takes O(log n) recursion depth.
  - Merging the two sorted halves takes O(n).
  - Overall time complexity is O(n log n).

Space Complexity:
- **O(log n)** (due to recursion stack):
  - The space complexity is O(log n) because of the recursion depth in the merge sort.
  - No extra space is used beyond the recursion stack.

*/

class Solution {
public:
    // Function to find the middle node of the linked list
    ListNode* findMiddle(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        // Use slow and fast pointers to find the middle
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow; // Return the node just before the middle node
    }

    // Function to merge two sorted linked lists
    ListNode* mergeTwoSortedLL(ListNode* left, ListNode* right) {
        // Create a dummy node to simplify merging process
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        // Merge the two sorted lists by comparing nodes
        while (left && right) {
            if (left->val <= right->val) {
                temp->next = left; // Add the smaller node to the merged list
                left = left->next; // Move to the next node in the left list
            } else {
                temp->next = right; // Add the smaller node to the merged list
                right = right->next; // Move to the next node in the right list
            }
            temp = temp->next; // Move the merged list pointer
        }

        // If there are remaining nodes in either list, append them
        if (left) {
            temp->next = left;
        } else {
            temp->next = right;
        }

        return dummy->next; // Return the head of the merged list
    }

    // Function to sort the linked list using merge sort
    ListNode* sortList(ListNode* head) {
        // Base case: if the list is empty or has one node, it's already sorted
        if (!head || !head->next) return head;

        // Find the middle of the list to divide it into two halves
        ListNode* middle = findMiddle(head);

        // Split the list into left and right halves
        ListNode* right = middle->next;
        middle->next = NULL;
        ListNode* left = head;

        // Recursively sort both halves
        left = sortList(left);
        right = sortList(right);

        // Merge the two sorted halves and return the sorted list
        return mergeTwoSortedLL(left, right);
    }
};
