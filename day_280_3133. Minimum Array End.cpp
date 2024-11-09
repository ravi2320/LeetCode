/*
3133. Minimum Array End
Solved
Medium
Topics
Companies
Hint
You are given two integers n and x. You have to construct an array of positive integers nums of size n where for every 0 <= i < n - 1, nums[i + 1] is greater than nums[i], and the result of the bitwise AND operation between all elements of nums is x.

Return the minimum possible value of nums[n - 1].

 

Example 1:

Input: n = 3, x = 4

Output: 6

Explanation:

nums can be [4,5,6] and its last element is 6.

Example 2:

Input: n = 2, x = 7

Output: 15

Explanation:

nums can be [7,15] and its last element is 15.

 

Constraints:

1 <= n, x <= 108
*/

/*
Approach:
1. Start with `num` initialized to `x`.
2. For each of the next `n-1` steps:
   - Increment `num` by 1, then perform a bitwise OR with `x` to set any bit in `num` that is set in `x`.
3. This loop constructs the final number by ensuring that each subsequent increment includes all bits set in `x`.
4. Return the final value of `num`.

Time Complexity: O(n), where n is the number of iterations.
Space Complexity: O(1), as we use a constant amount of additional space.

*/

class Solution {
public:
    long long minEnd(int n, int x) {
        long long num = x;
        for (int i = 1; i < n; i++) {
            num = (num + 1) | x;  // Increment and OR with x
        }
        return num;
    }
};
