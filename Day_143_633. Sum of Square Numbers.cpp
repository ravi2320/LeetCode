/*
633. Sum of Square Numbers
Solved
Medium
Topics
Companies
Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

 

Example 1:

Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5
Example 2:

Input: c = 3
Output: false
 

Constraints:

0 <= c <= 231 - 1
*/

/*
Intuition:
- We need to determine if a number `c` can be expressed as the sum of two square numbers.
- This can be achieved by using a two-pointer approach where one pointer starts from 0 (smallest square number) and the other starts from the largest possible square number less than or equal to the square root of `c`.

Approach:
1. Initialize two pointers: `left` starting at 0 and `right` starting at the largest integer whose square is less than or equal to `c`.
2. Calculate the sum of squares of the numbers at `left` and `right`.
3. If the sum is equal to `c`, return true.
4. If the sum is less than `c`, increment `left` to increase the sum.
5. If the sum is greater than `c`, decrement `right` to decrease the sum.
6. Repeat the process until `left` exceeds `right`.

Time Complexity:
- O(sqrt(c)), since in the worst case, we check each pair of (left, right) until they meet.

Space Complexity:
- O(1), as we are only using a constant amount of extra space.

*/

class Solution {
public:
    bool judgeSquareSum(int c) {
        long left = 0;
        long right = sqrt(c);

        while (left <= right) {
            long sum = left * left + right * right;
            
            if (sum == c)
                return true;
            else if (sum < c)
                left++;
            else
                right--;
        }

        return false;
    }
};
