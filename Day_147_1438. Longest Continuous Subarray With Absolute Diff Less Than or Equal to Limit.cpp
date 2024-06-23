/*
1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
Solved
Medium
Topics
Companies
Hint
Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.

 

Example 1:

Input: nums = [8,2,4,7], limit = 4
Output: 2 
Explanation: All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4. 
Therefore, the size of the longest subarray is 2.
Example 2:

Input: nums = [10,1,2,4,7,2], limit = 5
Output: 4 
Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.
Example 3:

Input: nums = [4,2,2,2,4,4,2,2], limit = 0
Output: 3
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
0 <= limit <= 109
*/

/*
Intuition:
- We need to maintain a window [i, j] such that the absolute difference between the maximum and minimum elements in this window is <= limit.
- Use two priority queues:
  1. maxPQ to keep track of the maximum elements.
  2. minPQ to keep track of the minimum elements.
- Expand the window by moving the right pointer j.
- If the condition (max - min <= limit) is violated, shrink the window by moving the left pointer i until the condition is satisfied again.
- Keep track of the maximum window size that satisfies the condition.

Time Complexity:
- O(n log n): In the worst case, each element might be pushed and popped from the priority queues, leading to O(log n) operations for each of the n elements.

Space Complexity:
- O(n): The priority queues might store all elements in the worst case.

*/

class Solution {
public:
    typedef pair<int, int> P;
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        priority_queue<P, vector<P>> maxPQ;  // Max heap
        priority_queue<P, vector<P>, greater<P>> minPQ;  // Min heap
        int maxLen = 0;
        int i = 0;
        int j = 0;

        while (j < n) {
            maxPQ.push({nums[j], j});
            minPQ.push({nums[j], j});

            // While the current window [i, j] is invalid
            while (maxPQ.top().first - minPQ.top().first > limit) {
                // Move the left boundary of the window
                i = min(maxPQ.top().second, minPQ.top().second) + 1;

                // Remove elements outside the new window from the heaps
                while (maxPQ.top().second < i) {
                    maxPQ.pop();
                }
                while (minPQ.top().second < i) {
                    minPQ.pop();
                }
            }

            // Update the maximum length of the valid window
            maxLen = max(maxLen, j - i + 1);
            j++;
        }

        return maxLen;
    }
};
