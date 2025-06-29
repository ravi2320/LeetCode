/*
1498. Number of Subsequences That Satisfy the Given Sum Condition

avatar
Discuss Approach
arrow-up
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given an array of integers nums and an integer target.

Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo 109 + 7.

 

Example 1:

Input: nums = [3,5,6,7], target = 9
Output: 4
Explanation: There are 4 subsequences that satisfy the condition.
[3] -> Min value + max value <= target (3 + 3 <= 9)
[3,5] -> (3 + 5 <= 9)
[3,5,6] -> (3 + 6 <= 9)
[3,6] -> (3 + 6 <= 9)
Example 2:

Input: nums = [3,3,6,8], target = 10
Output: 6
Explanation: There are 6 subsequences that satisfy the condition. (nums can have repeated numbers).
[3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]
Example 3:

Input: nums = [2,3,3,4,6,7], target = 12
Output: 61
Explanation: There are 63 non-empty subsequences, two of them do not satisfy the condition ([6,7], [7]).
Number of valid subsequences (63 - 2 = 61).
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 106
1 <= target <= 106
*/

/*
Approach:
We are given an array `nums` and a `target`, and we must count the number of subsequences such that
the sum of the minimum and maximum element in the subsequence is less than or equal to `target`.

Steps:
1. Sort the array so that we can apply two pointers to efficiently check the min and max.
2. Use two pointers (l and r) to scan the array:
   - If nums[l] + nums[r] <= target:
     - Then, all subsequences that start with nums[l] and end anywhere between [l, r] are valid.
     - Count of such subsequences = 2^(r - l)
     - Add it to the result and move left pointer forward.
   - Else:
     - Move right pointer backward to reduce the sum.
3. Use modular exponentiation for computing powers of 2.

Intuition:
- By fixing the smallest value at the left and checking the largest at the right,
  we can efficiently count all valid subsequences using powers of 2.

Time Complexity:
- O(n log n): For sorting.
- O(n log k): For repeated calls to `power()` function with b up to `n`.

Space Complexity:
- O(log k): Recursion stack in `power()` function.
*/

class Solution {
    int mod = 1e9 + 7;

public:
    // Function to compute (a^b) % mod using recursive fast exponentiation
    long long power(int a, int b) {
        if (b == 0) return 1;

        long long half = power(a, b / 2) % mod;
        long long res = (half * half) % mod;

        if (b % 2 == 1)
            res = (res * a) % mod;

        return res;
    }

    int numSubseq(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        long long ans = 0;

        // Sort array to apply two-pointer technique
        sort(nums.begin(), nums.end());

        // Traverse using two pointers
        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                // All subsequences from nums[l] to nums[r] are valid
                long long add = power(2, r - l);
                ans = (ans + add) % mod;
                l++;
            } else {
                // Reduce the right end to make sum smaller
                r--;
            }
        }

        return (int)ans;
    }
};