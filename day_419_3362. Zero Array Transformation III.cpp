/*
3362. Zero Array Transformation III
Solved
Medium
Topics
Companies
Hint
You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri].

Each queries[i] represents the following action on nums:

Decrement the value at each index in the range [li, ri] in nums by at most 1.
The amount by which the value is decremented can be chosen independently for each index.
A Zero Array is an array with all its elements equal to 0.

Return the maximum number of elements that can be removed from queries, such that nums can still be converted to a zero array using the remaining queries. If it is not possible to convert nums to a zero array, return -1.

 

Example 1:

Input: nums = [2,0,2], queries = [[0,2],[0,2],[1,1]]

Output: 1

Explanation:

After removing queries[2], nums can still be converted to a zero array.

Using queries[0], decrement nums[0] and nums[2] by 1 and nums[1] by 0.
Using queries[1], decrement nums[0] and nums[2] by 1 and nums[1] by 0.
Example 2:

Input: nums = [1,1,1,1], queries = [[1,3],[0,2],[1,3],[1,2]]

Output: 2

Explanation:

We can remove queries[2] and queries[3].

Example 3:

Input: nums = [1,2,3,4], queries = [[0,3]]

Output: -1

Explanation:

nums cannot be converted to a zero array even after using all the queries.

 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 105
1 <= queries.length <= 105
queries[i].length == 2
0 <= li <= ri < nums.length
*/

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();               // Length of the nums array
        int Q = queries.size();            // Number of queries

        // MaxHeap to store end times of currently available queries
        priority_queue<int> maxHeap;

        // MinHeap to manage the expiry (past) queries (end time ≤ current index)
        priority_queue<int, vector<int>, greater<int>> past;

        // Sort queries by their starting time
        sort(queries.begin(), queries.end());

        int j = 0;               // Pointer to iterate over queries
        int usedCnt = 0;         // Count of queries used

        for (int i = 0; i < n; i++) {

            // Add all queries that start at time i to the maxHeap
            while (j < Q && queries[j][0] == i) {
                maxHeap.push(queries[j][1]);  // Push end time
                j++;
            }

            // Reduce required tasks at index i based on expired tasks (already counted)
            nums[i] -= past.size();

            // Try to satisfy current nums[i] using available queries from maxHeap
            while (nums[i] > 0 && !maxHeap.empty() && maxHeap.top() >= i) {
                int ending = maxHeap.top();  // Take query with latest end
                maxHeap.pop();
                past.push(ending);           // Move it to used list
                usedCnt++;                   // Count this query as used
                nums[i]--;                   // One task done
            }

            // If unable to satisfy all required tasks at index i, return -1
            if (nums[i] > 0) return -1;

            // Clean up past heap by removing expired queries (end < current time)
            while (!past.empty() && past.top() <= i) {
                past.pop();
            }
        }

        // Return number of queries that were not used
        return Q - usedCnt;
    }
};
