/*
2593. Find Score of an Array After Marking All Elements
Solved
Medium
Topics
Companies
Hint
You are given an array nums consisting of positive integers.

Starting with score = 0, apply the following algorithm:

Choose the smallest integer of the array that is not marked. If there is a tie, choose the one with the smallest index.
Add the value of the chosen integer to score.
Mark the chosen element and its two adjacent elements if they exist.
Repeat until all the array elements are marked.
Return the score you get after applying the above algorithm.

 

Example 1:

Input: nums = [2,1,3,4,5,2]
Output: 7
Explanation: We mark the elements as follows:
- 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,1,3,4,5,2].
- 2 is the smallest unmarked element, so we mark it and its left adjacent element: [2,1,3,4,5,2].
- 4 is the only remaining unmarked element, so we mark it: [2,1,3,4,5,2].
Our score is 1 + 2 + 4 = 7.
Example 2:

Input: nums = [2,3,5,1,3,2]
Output: 5
Explanation: We mark the elements as follows:
- 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,3,5,1,3,2].
- 2 is the smallest unmarked element, since there are two of them, we choose the left-most one, so we mark the one at index 0 and its right adjacent element: [2,3,5,1,3,2].
- 2 is the only remaining unmarked element, so we mark it: [2,3,5,1,3,2].
Our score is 1 + 2 + 2 = 5.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 106
*/

/*
Approach:
1. Use a priority queue (min-heap) to process the elements in ascending order of their values.
2. Each element is paired with its index in the array for efficient identification during processing.
3. Mark an element and its adjacent neighbors as "visited" once it contributes to the score, ensuring they are not considered again.
4. Iterate through the priority queue:
   - If the current element is not visited, add its value to the score and mark it and its adjacent neighbors as visited.
5. Continue until all elements in the queue are processed.

Steps:
- Initialize a min-heap with pairs containing array values and their indices.
- Use a `visited` array to track whether an element or its neighbors have been processed.
- Iterate through the heap, updating the score and marking indices as visited.

Time Complexity:
- O(n log n): Building the heap takes O(n), and processing all elements involves O(n log n) for heap operations.

Space Complexity:
- O(n): Space for the heap and the `visited` array.

Edge Cases:
- Single-element array.
- Array with all equal elements.
- Empty array (result is `0`).

*/

class Solution {
    typedef pair<int, int> P; // Define pair type for simplicity
public:
    long long findScore(vector<int>& nums) {
        priority_queue<P, vector<P>, greater<P>> pq; // Min-heap to store {value, index}
        int n = nums.size();
        vector<int> visited(n, 0); // Track visited indices

        // Push all elements with their indices into the min-heap
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        long long ans = 0; // Variable to store the final score

        // Process elements from the heap
        while (!pq.empty()) {
            P front = pq.top();
            pq.pop();

            // If the current element is not visited, update the score
            if (!visited[front.second]) {
                ans += front.first; // Add the element value to the score
                int idx = front.second;

                // Mark the current element and its neighbors as visited
                visited[idx] = true;
                if (idx > 0) visited[idx - 1] = true;
                if (idx < n - 1) visited[idx + 1] = true;
            }
        }

        return ans; // Return the calculated score
    }
};
