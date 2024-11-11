/*
2601. Prime Subtraction Operation
Solved
Medium
Topics
Companies
Hint
You are given a 0-indexed integer array nums of length n.

You can perform the following operation as many times as you want:

Pick an index i that you haven’t picked before, and pick a prime p strictly less than nums[i], then subtract p from nums[i].
Return true if you can make nums a strictly increasing array using the above operation and false otherwise.

A strictly increasing array is an array whose each element is strictly greater than its preceding element.

 

Example 1:

Input: nums = [4,9,6,10]
Output: true
Explanation: In the first operation: Pick i = 0 and p = 3, and then subtract 3 from nums[0], so that nums becomes [1,9,6,10].
In the second operation: i = 1, p = 7, subtract 7 from nums[1], so nums becomes equal to [1,2,6,10].
After the second operation, nums is sorted in strictly increasing order, so the answer is true.
Example 2:

Input: nums = [6,8,11,12]
Output: true
Explanation: Initially nums is sorted in strictly increasing order, so we don't need to make any operations.
Example 3:

Input: nums = [5,8,3]
Output: false
Explanation: It can be proven that there is no way to perform operations to make nums sorted in strictly increasing order, so the answer is false.
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 1000
nums.length == n
*/

/*
Approach:
1. Generate a sieve of primes up to 1000 using the Sieve of Eratosthenes.
2. Traverse the array `nums` from right to left (starting from the second last element).
   - If `nums[i] < nums[i+1]`, skip to the next element.
   - Otherwise, try subtracting each prime (smaller than `nums[i]`) from `nums[i]` to make `nums[i] < nums[i+1]`.
   - If successful, break out of the inner loop and move to the next element.
3. If `nums[i]` is still not smaller than `nums[i+1]` after trying all primes, return `false`.
4. If we complete the loop without returning `false`, return `true`.

Time Complexity:
- Sieve generation: O(N log log N), where N = 1000.
- Checking conditions and updating `nums`: O(n * p), where `n` is the length of `nums` and `p` is the number of primes.

Space Complexity: O(N) for storing the sieve and additional O(n) space for `nums`.

*/

class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        // Generate a sieve of primes up to 1000
        vector<bool> seive(1001, 1);
        for (int i = 2; i * i <= 1000; i++) {
            if (seive[i]) {
                for (int j = i * i; j <= 1000; j += i) {
                    seive[j] = 0;
                }
            }
        }

        int n = nums.size();

        // Traverse from the second last element to the start
        for (int i = n - 2; i >= 0; i--) {
            // If current element is already less than the next, skip it
            if (nums[i] < nums[i + 1]) {
                continue;
            }

            // Try reducing nums[i] by a prime to make it less than nums[i+1]
            for (int p = 2; p < nums[i]; p++) {
                if (!seive[p]) {
                    continue;
                }

                // Check if subtracting p makes nums[i] less than nums[i+1]
                if (nums[i] - p < nums[i + 1]) {
                    nums[i] -= p;
                    break;
                }
            }

            // If nums[i] is still not less than nums[i+1], return false
            if (nums[i] >= nums[i + 1]) {
                return false;
            }
        }

        // If all conditions are met, return true
        return true;
    }
};
