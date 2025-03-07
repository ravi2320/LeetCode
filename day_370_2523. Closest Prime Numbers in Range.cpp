/*
2523. Closest Prime Numbers in Range
Solved
Medium
Topics
Companies
Hint
Given two positive integers left and right, find the two integers num1 and num2 such that:

left <= num1 < num2 <= right .
Both num1 and num2 are prime numbers.
num2 - num1 is the minimum amongst all other pairs satisfying the above conditions.
Return the positive integer array ans = [num1, num2]. If there are multiple pairs satisfying these conditions, return the one with the smallest num1 value. If no such numbers exist, return [-1, -1].

 

Example 1:

Input: left = 10, right = 19
Output: [11,13]
Explanation: The prime numbers between 10 and 19 are 11, 13, 17, and 19.
The closest gap between any pair is 2, which can be achieved by [11,13] or [17,19].
Since 11 is smaller than 17, we return the first pair.
Example 2:

Input: left = 4, right = 6
Output: [-1,-1]
Explanation: There exists only one prime number in the given range, so the conditions cannot be satisfied.
 

Constraints:

1 <= left <= right <= 106
*/

/**
 * Approach:
 * - **Step 1**: Use the **Sieve of Eratosthenes** to precompute all primes up to `right`.
 * - **Step 2**: Iterate over the range `[left, right]` to find the closest prime pair.
 * 
 * 🔹 **Sieve of Eratosthenes**:
 *   - `sieve[i] = true` → `i` is prime.
 *   - `sieve[i] = false` → `i` is composite.
 *   - Use **O(n log log n) complexity** for prime computation.
 * 
 * 🔹 **Iterate through primes in range**:
 *   - Track the **previous prime** seen.
 *   - Update the closest pair if a new **smaller gap** is found.
 * 
 * 🔹 **Time Complexity**: `O(n log log n) + O(n) ≈ O(n)`
 * 🔹 **Space Complexity**: `O(n)` (for the `sieve` array)
 */
class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int n = right + 1;
        vector<bool> sieve(n, true);
        
        // Step 1: Sieve of Eratosthenes to mark primes
        sieve[0] = sieve[1] = false;  // 0 and 1 are not primes
        for(long long i = 2; i * i < n; i++) {
            if (sieve[i]) {
                for (long long j = i * i; j < n; j += i) {
                    sieve[j] = false;
                }
            }
        }

        // Step 2: Find closest prime pair in range [left, right]
        left = max(left, 2);
        vector<int> ans = {-1, -1};
        int prevPrime = -1;
        int minDiff = INT_MAX;

        for (int i = left; i <= right; i++) {
            if (sieve[i]) {
                if (prevPrime != -1 && i - prevPrime < minDiff) {
                    ans = {prevPrime, i};
                    minDiff = i - prevPrime;
                }
                prevPrime = i;
            }
        }

        return ans;
    }
};
