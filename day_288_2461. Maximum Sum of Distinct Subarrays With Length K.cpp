/*
2461. Maximum Sum of Distinct Subarrays With Length K
Solved
Medium
Topics
Companies
Hint
You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

The length of the subarray is k, and
All the elements of the subarray are distinct.
Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,5,4,2,9,9,9], k = 3
Output: 15
Explanation: The subarrays of nums with length 3 are:
- [1,5,4] which meets the requirements and has a sum of 10.
- [5,4,2] which meets the requirements and has a sum of 11.
- [4,2,9] which meets the requirements and has a sum of 15.
- [2,9,9] which does not meet the requirements because the element 9 is repeated.
- [9,9,9] which does not meet the requirements because the element 9 is repeated.
We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions
Example 2:

Input: nums = [4,4,4], k = 3
Output: 0
Explanation: The subarrays of nums with length 3 are:
- [4,4,4] which does not meet the requirements because the element 4 is repeated.
We return 0 because no subarrays meet the conditions.
 

Constraints:

1 <= k <= nums.length <= 105
1 <= nums[i] <= 105
*/

/*
Approach:
1. We are given an integer vector `nums` and a size `k`. The task is to find the maximum sum of a subarray of length `k` that does not contain any duplicate elements.
2. Use a sliding window approach with a hashmap to keep track of elements in the current window.
3. Maintain a running sum of the elements in the window and update the result when a valid subarray of size `k` is found.

Steps:
1. Initialize pointers `i` and `j` for the sliding window, where `i` marks the start and `j` marks the end.
2. Use an unordered map `mp` to keep track of the frequency and the last occurrence index of each element.
3. If a duplicate is found while expanding the window (`j`), shrink the window from the left (`i`) to remove the duplicate and update the running sum.
4. If the window size exceeds `k`, shrink the window from the left.
5. Update the result when a valid window of size `k` is found.

Time Complexity:
- O(n) — Each element is processed at most twice (once for adding to the window and once for removing).

Space Complexity:
- O(k) — To store the elements in the sliding window and their indices in the map.

*/

class Solution {
public:
    // Function to find the maximum sum of subarray of size k with unique elements
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0, res = 0;  // `sum` is the current window sum, `res` is the maximum found sum
        int j = 0, i = 0;  // `j` is the end of the window, `i` is the start of the window
        unordered_map<int, int> mp;  // Map to store the last occurrence of each element

        // Iterate over the array with the end of the window `j`
        while (j < n) {
            // If the current element is already in the window, adjust the start of the window
            if (mp.find(nums[j]) != mp.end()) {
                int m = mp[nums[j]];
                // Remove elements from the start until the duplicate is excluded
                for (int k = i; k <= m; k++) {
                    sum -= nums[k];
                    mp.erase(nums[k]);
                }
                // Update the start of the window
                i = m + 1;
            }

            // Include the current element in the window
            mp[nums[j]] = j;
            sum += nums[j];

            // If the window size exceeds `k`, shrink it from the left
            while (j - i + 1 > k) {
                sum -= nums[i];
                mp.erase(nums[i++]);
            }

            // If the window size is exactly `k`, update the result
            if (j - i + 1 == k) {
                res = max(res, sum);
            }

            // Expand the window
            j++;
        }

        return res;
    }
};