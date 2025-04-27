/*
3392. Count Subarrays of Length Three With a Condition
Solved
Easy
Topics
Companies
Hint
Given an integer array nums, return the number of subarrays of length 3 such that the sum of the first and third numbers equals exactly half of the second number.

 

Example 1:

Input: nums = [1,2,1,4,1]

Output: 1

Explanation:

Only the subarray [1,4,1] contains exactly 3 elements where the sum of the first and third numbers equals half the middle number.

Example 2:

Input: nums = [1,1,1]

Output: 0

Explanation:

[1,1,1] is the only subarray of length 3. However, its first and third numbers do not add to half the middle number.

 

Constraints:

3 <= nums.length <= 100
-100 <= nums[i] <= 100
*/

/*
Intuition:
We are asked to count the number of *good* subarrays of size 3.
A subarray of size 3 is good if (nums[i] + nums[i+2]) * 2 == nums[i+1].

Approach:
- Loop through the array from index 0 to n-3 (because we need groups of 3 elements).
- For each triplet (i, i+1, i+2):
    - Check if the given condition holds.
    - If yes, increment the result count.
- Return the final count.

Time Complexity: O(N)
- We scan each element once (excluding the last two).

Space Complexity: O(1)
- Only a few integer variables used.
*/

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int res = 0;

        // Iterate over triplets
        for (int i = 0; i < n - 2; i++) {
            if ((nums[i] + nums[i + 2]) * 2 == nums[i + 1]) {
                res++;
            }
        }

        return res;
    }
};