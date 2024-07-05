/*
2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
Solved
Medium
Topics
Companies
Hint
A critical point in a linked list is defined as either a local maxima or a local minima.

A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.

A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.

Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.

Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].

 

Example 1:


Input: head = [3,1]
Output: [-1,-1]
Explanation: There are no critical points in [3,1].
Example 2:


Input: head = [5,3,1,2,5,1,2]
Output: [1,3]
Explanation: There are three critical points:
- [5,3,1,2,5,1,2]: The third node is a local minima because 1 is less than 3 and 2.
- [5,3,1,2,5,1,2]: The fifth node is a local maxima because 5 is greater than 2 and 1.
- [5,3,1,2,5,1,2]: The sixth node is a local minima because 1 is less than 5 and 2.
The minimum distance is between the fifth and the sixth node. minDistance = 6 - 5 = 1.
The maximum distance is between the third and the sixth node. maxDistance = 6 - 3 = 3.
Example 3:


Input: head = [1,3,2,2,3,2,2,2,7]
Output: [3,3]
Explanation: There are two critical points:
- [1,3,2,2,3,2,2,2,7]: The second node is a local maxima because 3 is greater than 1 and 2.
- [1,3,2,2,3,2,2,2,7]: The fifth node is a local maxima because 3 is greater than 2 and 2.
Both the minimum and maximum distances are between the second and the fifth node.
Thus, minDistance and maxDistance is 5 - 2 = 3.
Note that the last node is not considered a local maxima because it does not have a next node.
 

Constraints:

The number of nodes in the list is in the range [2, 105].
1 <= Node.val <= 105
*/

/*
 * Intuition:
 * The problem requires finding the minimum and maximum distances between critical points in a linked list.
 * Critical points are defined as nodes that are either local minima or maxima. By iterating through the list and keeping track of the positions of these points, we can calculate the required distances.
 * 
 * Time Complexity: O(n), where n is the number of nodes in the linked list. We traverse the list once.
 * Space Complexity: O(1), as we are using a constant amount of extra space.
 */

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int firstCriticalPoint = -1;  // Position of the first critical point
        int prevCriticalPoint = -1;   // Position of the previous critical point
        int minDist = INT_MAX;        // Minimum distance between critical points
        int maxDist = INT_MIN;        // Maximum distance between critical points

        ListNode *prev = head;        // Previous node
        ListNode *curr = head->next;  // Current node
        int cnt = 1;                  // Position counter

        while (curr != nullptr && curr->next != nullptr) {
            // Check if the current node is a critical point (local minima or maxima)
            if ((prev->val < curr->val && curr->next->val < curr->val) || 
                (prev->val > curr->val && curr->next->val > curr->val)) {
                
                if (firstCriticalPoint == -1) {
                    firstCriticalPoint = cnt;  // Set the first critical point position
                } else {
                    minDist = min(minDist, cnt - prevCriticalPoint);  // Update the minimum distance
                    maxDist = cnt - firstCriticalPoint;  // Update the maximum distance
                }
                prevCriticalPoint = cnt;  // Update the previous critical point position
            }
            prev = curr;  // Move to the next node
            curr = curr->next;
            cnt++;
        }

        // If no critical points were found or only one critical point was found
        if (minDist == INT_MAX) {
            return {-1, -1};
        }

        return {minDist, maxDist};  // Return the minimum and maximum distances
    }
};
