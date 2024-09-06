/*
3217. Delete Nodes From Linked List Present in Array
Solved
Medium
Topics
Companies
Hint
You are given an array of integers nums and the head of a linked list. Return the head of the modified linked list after removing all nodes from the linked list that have a value that exists in nums.

 

Example 1:

Input: nums = [1,2,3], head = [1,2,3,4,5]

Output: [4,5]

Explanation:



Remove the nodes with values 1, 2, and 3.

Example 2:

Input: nums = [1], head = [1,2,1,2,1,2]

Output: [2,2,2]

Explanation:



Remove the nodes with value 1.

Example 3:

Input: nums = [5], head = [1,2,3,4]

Output: [1,2,3,4]

Explanation:



No node has value 5.

 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105
All elements in nums are unique.
The number of nodes in the given list is in the range [1, 105].
1 <= Node.val <= 105
The input is generated such that there is at least one node in the linked list that has a value not present in nums.
*/

/*
**Problem Statement:**
- Given a linked list (`head`) and a vector of integers (`nums`), modify the list by removing all nodes from the linked list whose values are present in the vector `nums`.

**Approach:**
1. **Use Unordered Set for Fast Lookup:**
   - Store all the integers in `nums` in an unordered set `st` for quick lookup. This allows checking whether a node's value is in `nums` in constant time O(1).

2. **Remove Matching Head Nodes:**
   - While the value of the head node is present in the set `st`, update the head to the next node and delete the previous head.

3. **Traverse the Rest of the List:**
   - Traverse the list using a pointer `curr`. For each node, check if the next node’s value exists in the set `st`. If it does, bypass the next node by updating `curr->next` and delete the node.
   - If the next node's value is not in `st`, move the pointer `curr` to the next node.

4. **Return the Modified List:**
   - After processing all the nodes, return the modified linked list starting from the new head.

**Time Complexity:**
   - O(n + m), where `n` is the number of nodes in the linked list and `m` is the size of the vector `nums`. Creating the set takes O(m), and traversing the linked list takes O(n).

**Space Complexity:**
   - O(m) for storing the values from `nums` in the unordered set.

**Example Usage:**
- If `nums = {2, 4}` and the linked list is `1 -> 2 -> 3 -> 4 -> 5`, the modified linked list will be `1 -> 3 -> 5`.
*/

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Store the values from nums in an unordered set for fast lookup
        unordered_set<int> st(nums.begin(), nums.end());

        // Remove all matching head nodes
        while (head && st.count(head->val)) {
            ListNode* temp = head;
            head = head->next;
            delete(temp); // Free the memory of the removed node
        }

        // If the entire list has been removed, return nullptr
        if (!head) return nullptr;

        // Traverse the rest of the list
        ListNode* curr = head;
        while (curr && curr->next) {
            // If the next node's value is in the set, remove it
            if (st.count(curr->next->val)) {
                ListNode* temp = curr->next;
                curr->next = curr->next->next; // Bypass the next node
                delete(temp); // Free the memory of the removed node
            } else {
                curr = curr->next; // Move to the next node
            }
        }

        return head; // Return the modified head of the list
    }
};
