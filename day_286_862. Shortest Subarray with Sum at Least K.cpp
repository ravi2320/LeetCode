/*
862. Shortest Subarray with Sum at Least K
Solved
Hard
Topics
Companies
Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1], k = 1
Output: 1
Example 2:

Input: nums = [1,2], k = 4
Output: -1
Example 3:

Input: nums = [2,-1,2], k = 3
Output: 3
 

Constraints:

1 <= nums.length <= 105
-105 <= nums[i] <= 105
1 <= k <= 109
*/

/*
Approach:
1. Use a **cumulative sum** array to maintain running totals of the `nums` array.
   - This helps in quickly calculating the sum of any subarray using the difference between two cumulative sums.
2. Utilize a **deque** to maintain indices of the cumulative sum array in a way that helps find the shortest subarray sum greater than or equal to `k`.
   - Keep the deque sorted by values of cumulative sums.
   - Iterate through `nums` to calculate the cumulative sums and use the deque to find the shortest subarray meeting the condition.
   - Update the `res` variable to store the minimum length found.
3. Edge case: If no valid subarray is found, return `-1`.

Time Complexity:
- O(n) — Each element is processed at most twice (once for entering and once for leaving the deque).

Space Complexity:
- O(n) — Storage for the cumulative sum array and deque.

*/

class Solution {
public:
    // Function to find the length of the shortest subarray with sum >= k
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> cumulativeSum(n, 0); // Stores the cumulative sum
        deque<int> deq; // Deque to keep track of indices in a sorted manner
        int res = INT_MAX; // Variable to store the result (minimum length)

        // Iterate over the array
        for (int j = 0; j < n; ++j) {
            // Calculate the cumulative sum
            if (j == 0) {
                cumulativeSum[j] = nums[j];
            } else {
                cumulativeSum[j] = cumulativeSum[j - 1] + nums[j];
            }

            // If the current cumulative sum itself is >= k, update result
            if (cumulativeSum[j] >= k) {
                res = min(res, j + 1);
            }

            // Check for subarrays ending at index `j` with a sum >= k
            while (!deq.empty() && cumulativeSum[j] - cumulativeSum[deq.front()] >= k) {
                res = min(res, j - deq.front());
                deq.pop_front();
            }

            // Maintain the deque in a sorted order for cumulative sums
            while (!deq.empty() && cumulativeSum[j] <= cumulativeSum[deq.back()]) {
                deq.pop_back();
            }

            // Add the current index to the deque
            deq.push_back(j);
        }

        // If no valid subarray found, return -1
        return res == INT_MAX ? -1 : res;
    }
};
