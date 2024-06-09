/*
974. Subarray Sums Divisible by K
Solved
Medium
Topics
Companies
Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
Example 2:

Input: nums = [5], k = 9
Output: 0
 

Constraints:

1 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
2 <= k <= 104
*/

/*
Intuition:
- The task is to count the number of subarrays whose sum is divisible by a given integer `k`.
- This can be efficiently solved using a hash map to keep track of the remainders of the cumulative sums modulo `k`.
- By leveraging the properties of modular arithmetic, we can determine if a subarray sum is divisible by `k` if the difference between two cumulative sums is a multiple of `k`.

Approach:
1. Initialize a hash map (`mp`) to store the frequency of remainders when cumulative sums are divided by `k`.
2. Initialize the cumulative sum (`sum`) and the count of valid subarrays (`cnt`).
3. Traverse through the array, updating the cumulative sum at each step.
4. Calculate the remainder (`rem`) of the cumulative sum modulo `k`.
   - Adjust the remainder to be non-negative by adding `k` if it is negative.
5. Check if this remainder has been seen before in the map:
   - If yes, it means there are subarrays ending at the current index whose sum is divisible by `k`. Increment the count by the frequency of this remainder.
   - Increment the frequency of this remainder in the map.
6. Return the count of valid subarrays.

Time Complexity: O(n)
- We traverse the array once, making the approach linear in time complexity.

Space Complexity: O(k)
- The space complexity is determined by the hash map storing at most `k` unique remainders.

*/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int cnt = 0;
        mp[0] = 1;
        int sum = 0;
        
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            int rem = sum % k;

            if (rem < 0)  // Adjust negative remainder
                rem += k;

            if (mp.find(rem) != mp.end())
                cnt += mp[rem];

            mp[rem]++;
        }

        return cnt;
    }
};
