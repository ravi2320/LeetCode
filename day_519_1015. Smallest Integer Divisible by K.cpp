/*
1015. Smallest Integer Divisible by K

Given a positive integer k, you need to find the length of the smallest positive integer n such that n is divisible by k, and n only contains the digit 1.

Return the length of n. If there is no such n, return -1.

Note: n may not fit in a 64-bit signed integer.

 

Example 1:

Input: k = 1
Output: 1
Explanation: The smallest answer is n = 1, which has length 1.
Example 2:

Input: k = 2
Output: -1
Explanation: There is no such positive integer n divisible by 2.
Example 3:

Input: k = 3
Output: 3
Explanation: The smallest answer is n = 111, which has length 3.
 

Constraints:

1 <= k <= 105
*/

/*
Approach:
---------
We want the smallest positive integer made only of digit '1' (like 1, 11, 111, ...) 
that is divisible by k. Instead of generating full numbers (which grow very big), 
we track only the remainder when dividing by k.

Key idea:
- Start with num = 1 (which represents the repunit "1")
- Repeatedly generate the next repunit using: num = (num % k) * 10 + 1
- Stop when remainder becomes 0 → meaning the number formed is divisible by k
- Count how many digits (all '1') were used.

Why modulus works:
- We only need the remainder to check divisibility.
- Using modulus prevents the integer from overflowing.

Important constraint:
- If k is divisible by 2 or 5, no repunit (111...1) will ever be divisible by k.

Intuition:
-----------
Repunit numbers grow like:
1 → 11 → 111 → 1111 → ...
Instead of storing these huge numbers, we only store the remainder.  
This ensures numbers stay small while still determining divisibility.  
Once the remainder becomes 0, we found the smallest repunit divisible by k.

Time Complexity:
----------------
O(k)  
• In the worst case, we must generate at most k different remainders  
  (Pigeonhole Principle: After k steps, remainder must repeat).  
• Thus the loop runs at most k times.

Space Complexity:
-----------------
O(1)  
• Only using a few integer variables, no extra storage.

*/

class Solution {
public:
    int smallestRepunitDivByK(int k) {

        // If k is divisible by 2 or 5, no number made of only '1' digits can divide it.
        if (k % 2 == 0 || k % 5 == 0)
            return -1;

        int num = 1;   // Represents the current remainder of the repunit
        int cnt = 1;   // Number of digits (all '1') used in the repunit

        // Loop until the remainder becomes zero
        while (num % k != 0) {
            // Generate next repunit remainder
            // Example: remainder R for number X becomes (R * 10 + 1)
            num = (num % k) * 10 + 1;

            cnt++;  // Increase digit count
        }

        return cnt;  // Found the smallest repunit divisible by k
    }
};
