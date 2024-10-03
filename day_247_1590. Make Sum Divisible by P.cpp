/*
1590. Make Sum Divisible by P
Solved
Medium
Topics
Companies
Hint
Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that the sum of the remaining elements is divisible by p. It is not allowed to remove the whole array.

Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.

A subarray is defined as a contiguous block of elements in the array.

 

Example 1:

Input: nums = [3,1,4,2], p = 6
Output: 1
Explanation: The sum of the elements in nums is 10, which is not divisible by 6. We can remove the subarray [4], and the sum of the remaining elements is 6, which is divisible by 6.
Example 2:

Input: nums = [6,3,5,2], p = 9
Output: 2
Explanation: We cannot remove a single element to get a sum divisible by 9. The best way is to remove the subarray [5,2], leaving us with [6,3] with sum 9.
Example 3:

Input: nums = [1,2,3], p = 3
Output: 0
Explanation: Here the sum is 6. which is already divisible by 3. Thus we do not need to remove anything.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= p <= 109
*/

/*
Approach:
- This problem is about finding the smallest subarray that, when removed, makes the sum of the remaining array elements divisible by `p`.
- First, calculate the total sum of the array modulo `p`. The goal is to find the smallest subarray whose sum modulo `p` is equal to the remainder of the total sum (`SUM % p`).
- To efficiently track subarray sums, use a prefix sum array and a hash map (`mp`) that maps prefix sum remainders to their indices.
- For each element, calculate the current prefix sum, and then check if a previously seen prefix sum exists such that removing the subarray between the current index and that previous index gives the desired remainder.
- The hash map helps track the indices of these remainders to quickly find the smallest subarray.

Time Complexity:
- O(n), where n is the size of the input array. We only traverse the array once and perform constant time operations for each element (modulo, map lookups, and insertions).

Space Complexity:
- O(n), due to the space used by the hash map to store prefix sums.

*/

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int SUM = 0;

        // Step 1: Calculate the total sum of the array modulo p
        for(int &x : nums) {
            SUM = (SUM + x) % p;
        }

        int target = SUM % p;  // The remainder that needs to be removed to make the sum divisible by p

        // If the sum is already divisible by p, return 0 (no need to remove any subarray)
        if(target == 0) {
            return 0;
        }

        unordered_map<int, int> mp;  // Hash map to store prefix sums and their indices
        int curr = 0;  // Variable to store the current prefix sum
        mp[curr] = -1;  // Initialize map with a dummy index for the base case (empty prefix)

        int result = n;  // Initialize result with n (maximum subarray length)

        // Step 2: Traverse the array and compute the prefix sums
        for(int j = 0; j < n; j++) {
            curr = (curr + nums[j]) % p;  // Update current prefix sum modulo p

            int remain = (curr - target + p) % p;  // Compute the required remainder

            // Step 3: Check if the required remainder exists in the map
            if(mp.find(remain) != mp.end()) {
                result = min(result, j - mp[remain]);  // Update the result with the minimum subarray length
            }

            // Step 4: Update the hash map with the current prefix sum
            mp[curr] = j;
        }

        // If no valid subarray is found, return -1
        return result == n ? -1 : result;
    }
};
