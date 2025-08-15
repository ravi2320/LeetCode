/*
342. Power of Four

avatar
Discuss Approach
arrow-up
Solved
Easy
Topics
premium lock icon
Companies
Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four, if there exists an integer x such that n == 4x.

 

Example 1:

Input: n = 16
Output: true
Example 2:

Input: n = 5
Output: false
Example 3:

Input: n = 1
Output: true
 

Constraints:

-231 <= n <= 231 - 1
*/

/*
Approach:
1. First, handle invalid cases (n <= 0) by returning false immediately, since powers of four are positive integers.
2. Repeatedly divide n by 4 as long as it is divisible by 4.
3. If at any point n is not divisible by 4 (n % 4 != 0) before reaching 1, return false.
4. If we reduce n to exactly 1, it means n was a power of four.

Intuition:
A power of four always has the form 4^k where k ≥ 0.
By continuously dividing by 4, we check if n can be reduced to 1 without a remainder at any step.
If any step gives a remainder, n is not a power of four.

Time Complexity:
O(log₄ n) → Each division by 4 reduces n significantly.
Space Complexity:
O(1) → No extra space used apart from variables.
*/

class Solution {
public:
    bool isPowerOfFour(int n) {
        // Powers of four must be positive integers
        if (n <= 0) {
            return false;
        }

        // Keep dividing by 4 while possible
        while (n > 1) {
            // If n is not divisible by 4, it cannot be a power of four
            if (n % 4 != 0) {
                return false;
            }
            // Divide by 4 to check the next factor
            n /= 4;
        }

        // If reduced to exactly 1, it is a power of four
        return n == 1;
    }
};

/*
Approach:
1. First, handle edge cases: if n is less than or equal to 0, it's not a power of four.
2. Use bit manipulation to check if n has exactly one bit set (i.e., power of two).
3. Iterate over each bit position (0 to 31):
   - If a bit is set, increment the count and check if the bit position is even.
4. Ensure:
   - Only one bit is set (count == 1)
   - That bit is at an even position → valid power of four.

Intuition:
A number is a power of four if:
1. It's a power of two (only one '1' bit in binary representation).
2. The position of that bit is even (0-based index).
For example:
    4 → binary 00000100 → bit at position 2 (even) → true
    16 → binary 00010000 → bit at position 4 (even) → true

Time Complexity:
O(1) → Fixed loop of 32 iterations regardless of n.
Space Complexity:
O(1) → Constant extra space.
*/

class Solution {
public:
    bool isPowerOfFour(int n) {
        // If n is non-positive, it cannot be a power of four
        if (n <= 0) {
            return false;
        }

        bool isEven = false; // Tracks if the set bit is in an even position
        int cnt = 0;         // Counts the number of set bits

        // Check each bit position from 0 to 31
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) { // If bit at position i is set
                cnt++;          // Increment set bit count
                if (i % 2 == 0) // Check if position is even
                    isEven = true;
            }

            // More than one set bit means not a power of two, hence not power of four
            if (cnt > 1) return false;
        }

        // Valid if exactly one set bit and it's in an even position
        return isEven;
    }
};
