/*
2220. Minimum Bit Flips to Convert Number
Solved
Easy
Topics
Companies
Hint
A bit flip of a number x is choosing a bit in the binary representation of x and flipping it from either 0 to 1 or 1 to 0.

For example, for x = 7, the binary representation is 111 and we may choose any bit (including any leading zeros not shown) and flip it. We can flip the first bit from the right to get 110, flip the second bit from the right to get 101, flip the fifth bit from the right (a leading zero) to get 10111, etc.
Given two integers start and goal, return the minimum number of bit flips to convert start to goal.

 

Example 1:

Input: start = 10, goal = 7
Output: 3
Explanation: The binary representation of 10 and 7 are 1010 and 0111 respectively. We can convert 10 to 7 in 3 steps:
- Flip the first bit from the right: 1010 -> 1011.
- Flip the third bit from the right: 1011 -> 1111.
- Flip the fourth bit from the right: 1111 -> 0111.
It can be shown we cannot convert 10 to 7 in less than 3 steps. Hence, we return 3.
Example 2:

Input: start = 3, goal = 4
Output: 3
Explanation: The binary representation of 3 and 4 are 011 and 100 respectively. We can convert 3 to 4 in 3 steps:
- Flip the first bit from the right: 011 -> 010.
- Flip the second bit from the right: 010 -> 000.
- Flip the third bit from the right: 000 -> 100.
It can be shown we cannot convert 3 to 4 in less than 3 steps. Hence, we return 3.
 

Constraints:

0 <= start, goal <= 109
*/

/*
Approach:
1. The key observation is that a bit needs to be flipped if it's different between `start` and `goal`. 
   - The XOR operation (`^`) between `start` and `goal` produces a number where the bits set to `1` indicate the positions where the two numbers differ.
2. To count the number of differing bits, we count how many `1`s are present in the result of `start ^ goal`.
3. This can be done by checking each bit of the XOR result, either by using a loop to check each bit or by continuously dividing the result by 2 and counting the remainder (which checks the least significant bit).

Time Complexity:
- O(1): Since we are dealing with 32-bit integers, the loop will run a fixed number of times (at most 32 times).

Space Complexity:
- O(1): No extra space beyond a few variables is used.

*/

class Solution {
public:
    int minBitFlips(int start, int goal) {
        // XOR to find differing bits between start and goal
        int ans = start ^ goal;

        // Count the number of differing bits
        int cnt = 0;

        // Iterate while ans is greater than 0
        while (ans > 0) {
            // Check if the least significant bit is 1 (i.e., a bit flip is needed)
            if (ans % 2)
                cnt++;  // Increment the flip count
            
            ans /= 2;  // Right shift by dividing by 2 to check the next bit
        }

        // Return the total number of bit flips required
        return cnt;
    }
};
