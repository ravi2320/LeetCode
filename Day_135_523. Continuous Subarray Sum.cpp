/*
523. Continuous Subarray Sum
Solved
Medium
Topics
Companies
Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

A good subarray is a subarray where:

its length is at least two, and
the sum of the elements of the subarray is a multiple of k.
Note that:

A subarray is a contiguous part of the array.
An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.
 

Example 1:

Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
Example 2:

Input: nums = [23,2,6,4,7], k = 6
Output: true
Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.
Example 3:

Input: nums = [23,2,6,4,7], k = 13
Output: false
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109
0 <= sum(nums[i]) <= 231 - 1
1 <= k <= 231 - 1
*/

/*
Intuition:
- The problem is to check if there exists a subarray of size at least 2 whose sum is a multiple of a given integer `k`.
- The idea is to use the prefix sum technique and modulus operation to efficiently determine the existence of such a subarray.

Approach:
1. Use an unordered map to store the remainder of the prefix sum when divided by `k` and the corresponding index.
2. Initialize the map with a key-value pair `0: -1` to handle the case where the subarray starts from index 0.
3. Traverse the array, calculate the running prefix sum, and compute the remainder when divided by `k`.
4. If this remainder has been seen before, it means there is a subarray with a sum that is a multiple of `k`. Check if the length of this subarray is at least 2.
5. If the remainder has not been seen before, store it in the map with the current index.
6. If the conditions are met, return true. If the loop ends without meeting the conditions, return false.

Time Complexity: O(n)
- The loop runs for `n` elements, and each operation inside the loop is O(1) on average due to the unordered map operations.

Space Complexity: O(min(n, k))
- The space used by the map is proportional to the minimum of `n` and `k` due to the pigeonhole principle.

*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = -1;  // Initialize to handle the case where the subarray starts from index 0

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int rem = sum % k;

            // If the remainder is negative, adjust it to be within the range [0, k-1]
            if (rem < 0) {
                rem += k;
            }

            if (mp.find(rem) != mp.end()) {
                if (i - mp[rem] >= 2) {  // Ensure the subarray length is at least 2
                    return true;
                }
            } else {
                mp[rem] = i;  // Store the index of the first occurrence of the remainder
            }
        }

        return false;
    }
};
