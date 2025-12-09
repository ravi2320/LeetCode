/*
3583. Count Special Triplets

avatar
Discuss Approach
arrow-up
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given an integer array nums.

A special triplet is defined as a triplet of indices (i, j, k) such that:

0 <= i < j < k < n, where n = nums.length
nums[i] == nums[j] * 2
nums[k] == nums[j] * 2
Return the total number of special triplets in the array.

Since the answer may be large, return it modulo 109 + 7.

 

Example 1:

Input: nums = [6,3,6]

Output: 1

Explanation:

The only special triplet is (i, j, k) = (0, 1, 2), where:

nums[0] = 6, nums[1] = 3, nums[2] = 6
nums[0] = nums[1] * 2 = 3 * 2 = 6
nums[2] = nums[1] * 2 = 3 * 2 = 6
Example 2:

Input: nums = [0,1,0,0]

Output: 1

Explanation:

The only special triplet is (i, j, k) = (0, 2, 3), where:

nums[0] = 0, nums[2] = 0, nums[3] = 0
nums[0] = nums[2] * 2 = 0 * 2 = 0
nums[3] = nums[2] * 2 = 0 * 2 = 0
Example 3:

Input: nums = [8,4,2,8,4]

Output: 2

Explanation:

There are exactly two special triplets:

(i, j, k) = (0, 1, 3)
nums[0] = 8, nums[1] = 4, nums[3] = 8
nums[0] = nums[1] * 2 = 4 * 2 = 8
nums[3] = nums[1] * 2 = 4 * 2 = 8
(i, j, k) = (1, 2, 4)
nums[1] = 4, nums[2] = 2, nums[4] = 4
nums[1] = nums[2] * 2 = 2 * 2 = 4
nums[4] = nums[2] * 2 = 2 * 2 = 4
 

Constraints:

3 <= n == nums.length <= 105
0 <= nums[i] <= 105
*/

/*
Approach:
---------
We want to count the number of "special triplets" (i, j, k) such that:
    nums[i] + nums[k] = 2 * nums[j]
This means nums[j] is the arithmetic mean of nums[i] and nums[k].

We process nums[] from left to right:
- rightMap stores frequencies of upcoming elements (right side of j)
- leftMap stores frequencies of already seen elements (left side of j)

For each index j:
    - Remove nums[j] from rightMap (since it becomes the middle point)
    - We want:
          nums[i] + nums[k] = 2 * nums[j]
      →  nums[i] = 2*nums[j] - nums[k]

But this can be efficiently counted by symmetry:
    Count how many nums[i] on the left equal 2*nums[j]
    Count how many nums[k] on the right equal 2*nums[j]

Then:
    validTriplets += leftMap[2*nums[j]] * rightMap[2*nums[j]]

We add these counts modulo 1e9+7.

Intuition:
----------
The key is recognizing that nums[j] must be the middle of an arithmetic progression.
Instead of checking all i < j < k (O(n³)), we maintain frequency maps for left and right.
This reduces the work to O(n).

Time Complexity:
----------------
O(n)  — Each number is processed once.

Space Complexity:
-----------------
O(n)  — For the frequency maps.

*/

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> leftMap, rightMap;
        int mod = 1e9 + 7;

        // Populate rightMap with counts of all numbers initially
        for (int &num : nums) {
            rightMap[num]++;
        }

        long long ans = 0;

        // Iterate considering each number as nums[j]
        for (int &num : nums) {
            
            // Move current number from right side to middle
            rightMap[num]--;

            // Count how many nums[i] = 2 * nums[j] on the LEFT
            int left = leftMap[num * 2];

            // Count how many nums[k] = 2 * nums[j] on the RIGHT
            int right = rightMap[num * 2];

            // Add product of valid left and right matches
            ans = (ans + 1LL * left * right) % mod;

            // Now include the current number into left side
            leftMap[num]++;
        }

        return ans;
    }
};
