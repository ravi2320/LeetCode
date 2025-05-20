/*
3355. Zero Array Transformation I
Solved
Medium
Topics
Companies
Hint
You are given an integer array nums of length n and a 2D array queries, where queries[i] = [li, ri].

For each queries[i]:

Select a subset of indices within the range [li, ri] in nums.
Decrement the values at the selected indices by 1.
A Zero Array is an array where all elements are equal to 0.

Return true if it is possible to transform nums into a Zero Array after processing all the queries sequentially, otherwise return false.

 

Example 1:

Input: nums = [1,0,1], queries = [[0,2]]

Output: true

Explanation:

For i = 0:
Select the subset of indices as [0, 2] and decrement the values at these indices by 1.
The array will become [0, 0, 0], which is a Zero Array.
Example 2:

Input: nums = [4,3,2,1], queries = [[1,3],[0,2]]

Output: false

Explanation:

For i = 0:
Select the subset of indices as [1, 2, 3] and decrement the values at these indices by 1.
The array will become [4, 2, 1, 0].
For i = 1:
Select the subset of indices as [0, 1, 2] and decrement the values at these indices by 1.
The array will become [3, 1, 0, 0], which is not a Zero Array.
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 105
1 <= queries.length <= 105
queries[i].length == 2
0 <= li <= ri < nums.length
*/

/*
Approach:
- Each query allows us to decrement all elements from index `start` to `end` by 1.
- We simulate all queries using a difference array `diffArr`.
- For each query [start, end], we do:
    diffArr[start] += 1
    diffArr[end + 1] -= 1 (if in bounds)
- Then, accumulate the effect of operations and compare with the original array.
- At each index, ensure that the total decrement operations available (sum)
  is at least equal to nums[i]; otherwise, return false.

Time Complexity: O(n + q), where n = nums.size() and q = queries.size()
Space Complexity: O(n)
*/

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diffArr(n, 0);  // Difference array to track range increments

        // Apply all queries as +1 at start and -1 at end+1 in difference array
        for (auto& query : queries) {
            int start = query[0];
            int end = query[1];

            diffArr[start] += 1;
            if (end + 1 < n) {
                diffArr[end + 1] -= 1;
            }
        }

        // Accumulate the effects of all operations and compare with nums
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += diffArr[i];  // Current number of operations at index i

            if (sum < nums[i]) {
                return false;  // Not enough operations to reduce nums[i] to zero
            }
        }

        return true;  // All elements can be reduced to zero
    }
};
