/*
1611. Minimum One Bit Operations to Make Integers Zero

avatar
Discuss Approach
arrow-up
Solved
Hard
Topics
premium lock icon
Companies
Hint
Given an integer n, you must transform it into 0 using the following operations any number of times:

Change the rightmost (0th) bit in the binary representation of n.
Change the ith bit in the binary representation of n if the (i-1)th bit is set to 1 and the (i-2)th through 0th bits are set to 0.
Return the minimum number of operations to transform n into 0.

 

Example 1:

Input: n = 3
Output: 2
Explanation: The binary representation of 3 is "11".
"11" -> "01" with the 2nd operation since the 0th bit is 1.
"01" -> "00" with the 1st operation.
Example 2:

Input: n = 6
Output: 4
Explanation: The binary representation of 6 is "110".
"110" -> "010" with the 2nd operation since the 1st bit is 1 and 0th through 0th bits are 0.
"010" -> "011" with the 1st operation.
"011" -> "001" with the 2nd operation since the 0th bit is 1.
"001" -> "000" with the 1st operation.
 

Constraints:

0 <= n <= 109
*/

/*
Intuition:
- The goal of the problem is to determine the minimum number of "1 bit operations" required to transform the number `n` to 0.
- A "1 bit operation" allows you to flip a single bit (0 -> 1 or 1 -> 0).
- We need to exploit the pattern that emerges when considering flipping bits in binary numbers and the nature of binary operations.

Approach:
- Use a precomputed `function[i]` array where `function[i]` stores the minimum number of operations needed to flip all bits from the 0th to the ith bit (this is derived from the properties of binary numbers).
- For each bit of `n`, depending on whether it is 0 or 1, we update the result based on the alternating nature of bit flipping (flipping a 1 to 0 requires an operation, and vice versa).
- Start from the highest bit to the lowest bit to minimize the number of operations.

Time Complexity:
- The time complexity is O(1) since the solution always iterates over a fixed number of 32 bits (the maximum number of bits in an integer).
- Thus, the loop that processes the bits takes constant time.

Space Complexity:
- The space complexity is O(1) because the only additional space used is the `function` array, which has a fixed size of 32.
*/

class Solution {
public:
    int minimumOneBitOperations(int n) {
        // Base case: If n is 0, no operations are needed.
        if(n == 0)
            return 0;
        
        // Precompute the function array where function[i] gives the 
        // minimum number of operations to flip all bits up to the ith bit.
        vector<long long> function(32, 0);
        function[0] = 1;  // For the 0th bit, the minimum operation is 1.
        
        // Fill in the function array based on the binary pattern.
        for(int i = 1; i <= 31; i++) {
            function[i] = 2 * function[i - 1] + 1;  // Derived from the nature of bit flipping.
        }
        
        int result = 0;  // To store the minimum operations required.
        int sign = 1;    // Sign will alternate as we go through the bits.

        // Process each bit from the 30th down to the 0th (from most significant to least significant).
        for(int i = 30; i >= 0; i--) {
            // Check if the ith bit is set (1) or not (0).
            int ith_bit = ((1 << i) & n);
            
            if(ith_bit == 0) {
                continue;  // If the ith bit is not set, move to the next bit.
            }
            
            // If the sign is positive, add the number of operations for this bit,
            // else subtract the number of operations.
            if(sign > 0)
                result += function[i];
            else
                result -= function[i];
            
            // Alternate the sign for the next bit.
            sign *= -1;
        }
        
        return result;  // Return the minimum operations needed to make n zero.
    }
};
