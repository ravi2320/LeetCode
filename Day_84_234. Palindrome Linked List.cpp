/*
234. Palindrome Linked List
Solved
Easy
Topics
Companies
Given the head of a singly linked list, return true if it is a 
palindrome
 or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?
*/

//Approach 1: TC-O(n), SC-O(n)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        while(head != NULL){
            arr.push_back(head->val);
            head = head->next;
        }
        
        int i = 0, j = arr.size()-1;
        while(i <= j){
            if(arr[i] == arr[j]){
                i++;
                j--;
            }
            else
                return false;
        }
        return true;
    }
};


//Approach 2: TC-O(n), SC-O(n)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/**
 * Intuition:
 * 
 * To determine if a linked list is a palindrome, we can follow these steps:
 * 1. Use two pointers, slow and fast, to find the middle of the list. While advancing fast two nodes at a time, slow moves one node at a time. When fast reaches the end of the list, slow points to the middle node or the first node of the second half of the list.
 * 2. While finding the middle, also reverse the first half of the list. This can be achieved by using a third pointer, prev, to keep track of the node before slow.
 * 3. After finding the middle and reversing the first half, disconnect the first half from the second half by setting prev->next to NULL.
 * 4. Reverse the second half of the list using the reverseLL function.
 * 5. Compare the values of nodes in the reversed second half with the nodes in the first half of the list. If at any point, a mismatch is found, return false indicating that the list is not a palindrome. Otherwise, return true.
 */

class Solution {
public:
    ListNode* reverseLL(ListNode* head){
        if(!head || !head->next)
            return head;

        ListNode* tail = NULL;
        while(head){
            ListNode* next = head->next;
            head->next = tail;
            tail = head;
            head = next;
        }
        return tail;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        // Move slow to the middle and reverse the first half of the list
        while (fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        
        // Disconnect the first half from the second half
        prev->next = NULL;

        // Reverse the second half of the list
        ListNode* tail = reverseLL(slow);

        // Compare the reversed second half with the first half
        while (tail && head) {
            if (tail->val != head->val) {
                return false;
            }
            tail = tail->next;
            head = head->next;
        }

        return true;
    }
};


//Approach 3: TC-O(n) SC-O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/**
 * Intuition:
 * 
 * To determine if a linked list is a palindrome, we can follow these steps:
 * 1. Use two pointers, slow and fast, to find the middle of the list. While advancing fast two nodes at a time, slow moves one node at a time. When fast reaches the end of the list, slow points to the middle node or the first node of the second half of the list.
 * 2. While finding the middle, also reverse the first half of the list. This can be achieved by using a third pointer, prev, to keep track of the node before slow.
 * 3. After finding the middle and reversing the first half, disconnect the first half from the second half by setting prev->next to NULL.
 * 4. Reverse the second half of the list using the reverseLL function.
 * 5. Compare the values of nodes in the reversed second half with the nodes in the first half of the list. If at any point, a mismatch is found, return false indicating that the list is not a palindrome. Otherwise, return true.
 */

class Solution {
public:

    bool isPalindrome(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        // Move slow to the middle and reverse the first half of the list
        while (fast && fast->next) {
            fast = fast->next->next;

            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        
        if(fast != NULL)
            slow = slow->next;

        // Compare the reversed second half with the first half
        while (prev && slow) {
            if (prev->val != slow->val) {
                return false;
            }
            prev = prev->next;
            slow = slow->next;
        }

        return true;
    }
};


//Approach 4: without modyfying input using recusion TC-O(n), SC-O(1)

/**
 * Intuition:
 * 
 * To determine if a linked list is a palindrome, we can use a recursive approach as follows:
 * 1. Traverse the linked list recursively until reaching the end (base case). During the traversal, maintain a pointer to the current node (curr).
 * 2. At each recursive call, compare the value of the current node (head) with the corresponding node from the end of the list (curr). If they do not match, return false, indicating that the list is not a palindrome.
 * 3. If the values match, move the curr pointer to the next node.
 * 4. Continue the recursive calls until reaching the end of the list. If all comparisons are successful, return true, indicating that the list is a palindrome.
 */

class Solution {
public:
    ListNode* curr; // Pointer to the current node during recursion

    // Recursive function to check if the linked list is a palindrome
    bool recur(ListNode* head) {
        // Base case: when the end of the list is reached
        if (head == nullptr)
            return true;
        
        // Recursive call to traverse to the end of the list
        bool ans = recur(head->next);

        // Compare the value of the current node with the corresponding node from the end
        if (head->val != curr->val)
            return false;

        // Move the curr pointer to the next node
        curr = curr->next;

        return ans; // Return the result of the recursive call
    }

    // Function to check if the linked list is a palindrome
    bool isPalindrome(ListNode* head) {
        curr = head; // Initialize the curr pointer to the head of the list
        return recur(head); // Start the recursive traversal
    }
};