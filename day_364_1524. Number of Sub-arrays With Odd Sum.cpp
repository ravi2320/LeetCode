/*
1524. Number of Sub-arrays With Odd Sum
Solved
Medium
Topics
Companies
Hint
Given an array of integers arr, return the number of subarrays with an odd sum.

Since the answer can be very large, return it modulo 109 + 7.

 

Example 1:

Input: arr = [1,3,5]
Output: 4
Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
All sub-arrays sum are [1,4,9,3,8,5].
Odd sums are [1,9,3,5] so the answer is 4.
Example 2:

Input: arr = [2,4,6]
Output: 0
Explanation: All subarrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
All sub-arrays sum are [2,6,12,4,10,6].
All sub-arrays have even sum and the answer is 0.
Example 3:

Input: arr = [1,2,3,4,5,6,7]
Output: 16
 

Constraints:

1 <= arr.length <= 105
1 <= arr[i] <= 100
*/

/**
 * Approach:
 * - Compute the **prefix sum** while iterating through the array.
 * - Track the **count of even and odd prefix sums**:
 *   - If a prefix sum is **even**, it can form an odd subarray with a previous **odd prefix sum**.
 *   - If a prefix sum is **odd**, it can form an odd subarray with a previous **even prefix sum**.
 * - We maintain two counters:
 *   - **even**: Counts the number of even prefix sums (initialize to 1 for empty sum).
 *   - **odd**: Counts the number of odd prefix sums.
 * - For each prefix sum:
 *   - If **even**, add the number of **odd** prefix sums seen so far.
 *   - If **odd**, add the number of **even** prefix sums seen so far.
 *
 * 🔹 **Time Complexity**: **O(N)** (Single pass)
 * 🔹 **Space Complexity**: **O(1)** (No extra space used except a few variables)
 */

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int sum = 0, cnt = 0, M = 1e9+7;
        int even = 1, odd = 0; // Even initialized to 1 to handle full odd subarrays

        for(int i = 0; i < n; i++){
            sum += arr[i]; // Update running prefix sum
            
            if (sum % 2 == 0) { 
                cnt = (cnt + odd) % M; // Even sum can form an odd subarray with previous odd sums
                even++; // Increment even count
            } else {
                cnt = (cnt + even) % M; // Odd sum can form an odd subarray with previous even sums
                odd++; // Increment odd count
            }
        }

        return cnt;
    }
};