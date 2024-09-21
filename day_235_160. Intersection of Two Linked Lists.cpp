/*
160. Intersection of Two Linked Lists
Solved
Easy
Topics
Companies
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

For example, the following two linked lists begin to intersect at node c1:


The test cases are generated such that there are no cycles anywhere in the entire linked structure.

Note that the linked lists must retain their original structure after the function returns.

Custom Judge:

The inputs to the judge are given as follows (your program is not given these inputs):

intersectVal - The value of the node where the intersection occurs. This is 0 if there is no intersected node.
listA - The first linked list.
listB - The second linked list.
skipA - The number of nodes to skip ahead in listA (starting from the head) to get to the intersected node.
skipB - The number of nodes to skip ahead in listB (starting from the head) to get to the intersected node.
The judge will then create the linked structure based on these inputs and pass the two heads, headA and headB to your program. If you correctly return the intersected node, then your solution will be accepted.

 

Example 1:


Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
- Note that the intersected node's value is not 1 because the nodes with value 1 in A and B (2nd node in A and 3rd node in B) are different node references. In other words, they point to two different locations in memory, while the nodes with value 8 in A and B (3rd node in A and 4th node in B) point to the same location in memory.
Example 2:


Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Intersected at '2'
Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.
Example 3:


Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: No intersection
Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
Explanation: The two lists do not intersect, so return null.
 

Constraints:

The number of nodes of listA is in the m.
The number of nodes of listB is in the n.
1 <= m, n <= 3 * 104
1 <= Node.val <= 105
0 <= skipA < m
0 <= skipB < n
intersectVal is 0 if listA and listB do not intersect.
intersectVal == listA[skipA] == listB[skipB] if listA and listB intersect.
 
*/

/*
 * Approach: 
 * 1. Use a hash map to store the nodes of the first linked list (headA).
 * 2. Traverse the second linked list (headB) and check if any node exists in the hash map.
 * 3. If a match is found, return that node as the intersection point.
 * 4. If no intersection is found by the end of the second list, return NULL.
 *
 * Time Complexity: O(m + n), where m and n are the lengths of the two linked lists.
 * Space Complexity: O(m), as we store nodes of the first list in the hash map.
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> mp; // Hash map to store nodes of headA
        ListNode* temp = headA;
        
        // Store all nodes of headA in the hash map
        while(temp){
            mp[temp]++;
            temp = temp->next;
        }

        temp = headB;
        // Traverse headB and check for intersection
        while(temp){
            if(mp.find(temp) != mp.end()){
                return temp; // Return the intersection node
            }
            temp = temp->next;
        }

        return NULL; // No intersection found
    }
};


/*
 * Approach:
 * 1. Calculate the lengths of both linked lists (headA and headB).
 * 2. Calculate the difference in lengths.
 * 3. Move the pointer of the longer list forward by the difference in lengths.
 * 4. Traverse both lists together until the intersection node is found.
 * 5. If no intersection is found, return NULL.
 *
 * Time Complexity: O(m + n), where m and n are the lengths of the two linked lists.
 * Space Complexity: O(1), since we're using only a few extra variables.
 */

class Solution {
public:
    // Function to find the length of the linked list
    int findLen(ListNode* head) {
        int len = 0; // Initialize length counter
        while (head) { // Traverse the list
            len++; // Increment length
            head = head->next; // Move to the next node
        }
        return len; // Return the total length
    }

    // Function to get the intersection node of two linked lists
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int len1 = findLen(headA); // Length of first list
        int len2 = findLen(headB); // Length of second list
        int diff = len1 > len2 ? len1 - len2 : len2 - len1; // Calculate difference in lengths

        // Move the pointer of the longer list forward by the length difference
        for (int i = 0; i < diff; i++) {
            if (len1 > len2) {
                headA = headA->next; // Move headA forward
            } else {
                headB = headB->next; // Move headB forward
            }
        }

        // Traverse both lists to find the intersection
        while (headA) {
            if (headA == headB) {
                return headA; // Intersection found
            }
            headA = headA->next; // Move headA forward
            headB = headB->next; // Move headB forward
        }

        return NULL; // No intersection found
    }
};

/*
 * Approach:
 * 1. Use two pointers (t1 and t2) to traverse both linked lists.
 * 2. When a pointer reaches the end of its list, redirect it to the head of the other list.
 * 3. Continue until the two pointers meet at the intersection node or both become NULL.
 * 4. If there's an intersection, they will eventually meet at that node; otherwise, they will both end up being NULL.
 *
 * Time Complexity: O(m + n), where m and n are the lengths of the two linked lists.
 * Space Complexity: O(1), since no additional data structures are used.
 */

class Solution {
public:
    // Function to get the intersection node of two linked lists
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        // If either head is NULL, return NULL
        if (!headA || !headB) return NULL;

        ListNode* t1 = headA; // Pointer for the first list
        ListNode* t2 = headB; // Pointer for the second list

        // Traverse until both pointers meet
        while (t1 != t2) {
            t1 = t1->next; // Move t1 to the next node
            t2 = t2->next; // Move t2 to the next node

            // If they meet, return the intersection node
            if (t1 == t2) return t1;

            // If t1 reaches the end, redirect it to headB
            if (!t1) t1 = headB;
            // If t2 reaches the end, redirect it to headA
            if (!t2) t2 = headA;
        }

        return t1; // Return the intersection node or NULL if there's no intersection
    }
};
