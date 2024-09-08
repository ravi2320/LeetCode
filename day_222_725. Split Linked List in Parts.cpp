/*
725. Split Linked List in Parts
Solved
Medium
Topics
Companies
Hint
Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.

Return an array of the k parts.

 

Example 1:


Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].
Example 2:


Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
Output: [[1,2,3,4],[5,6,7],[8,9,10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.
 

Constraints:

The number of nodes in the list is in the range [0, 1000].
0 <= Node.val <= 1000
1 <= k <= 50
*/

Approach:

Calculate length: Determine the total length of the linked list.
Calculate bucket size: Determine the number of nodes per bucket (rounded down).
Allocate buckets: Create a vector of k buckets to store the partitioned lists.
Iterate through linked list:
Assign the current node to the current bucket.
Move to the next node based on the bucket size and extra nodes.
If necessary, break the link between the current bucket and the remaining nodes.
Return buckets: Return the vector of partitioned lists.
Time Complexity: O(n) where n is the length of the linked list.
Space Complexity: O(k) where k is the number of parts to split the list into.

Code with Comments:

C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x),   
 next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k)   
 {
        // Calculate the length of the linked list
        int len = 0;
        ListNode* temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }

        // Create a vector to store the partitioned lists
        vector<ListNode*> ans(k, NULL);

        // Handle the case of an empty linked list
        if (len == 0) return ans;

        // Calculate the number of nodes per bucket and extra nodes
        int eachBucketNode = len / k;
        int extraNode = len % k;

        // Iterate through the linked list and partition it into buckets
        ListNode* curr = head;
        ListNode* prev = NULL;
        for (int i = 0; i < k; i++) {
            // Assign the current node to the current bucket
            ans[i] = curr;

            // Move to the next node based on the bucket size and extra nodes
            for (int j = 0; j < eachBucketNode + (extraNode > 0 ? 1 : 0); j++) {
                prev = curr;
                curr = curr->next;
            }

            // Break the link between the current bucket and the remaining nodes
            prev->next = NULL;
            extraNode--;
        }

        return ans;
    }
};