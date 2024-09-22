/*
440. K-th Smallest in Lexicographical Order
Solved
Hard
Topics
Companies
Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].

 

Example 1:

Input: n = 13, k = 2
Output: 10
Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.
Example 2:

Input: n = 1, k = 1
Output: 1
 

Constraints:

1 <= k <= n <= 109
*/

/*
 * Approach:
 * 1. The goal is to find the k-th smallest number in lexicographical order from 1 to n.
 * 2. Start with the current number as 1 and decrement k.
 * 3. Use a helper function `Count` to count how many numbers exist between the current number and the next number lexicographically.
 * 4. If the count is less than or equal to k, move to the next lexicographical number and decrement k accordingly.
 * 5. Otherwise, move downwards in the lexicographical tree by multiplying the current number by 10.
 * 6. Continue until k becomes 0, at which point the current number is the k-th smallest.
 *
 * Time Complexity: O(log(n) * log(n)), where log(n) is due to traversing through the lexicographical tree.
 * Space Complexity: O(1), since no additional space is required except for a few variables.
 */

class Solution {
public:
    // Helper function to count how many numbers are in the range [curr, next) in lexicographical order
    int Count(long curr, long next, int n) {
        int countNum = 0;

        // Count how many numbers exist between curr and next up to n
        while (curr <= n) {
            countNum += next - curr;

            curr *= 10;
            next *= 10;

            // Limit next to be within the bounds of n
            next = min(next, (long)n + 1);
        }

        return countNum;
    }

    // Function to find the k-th lexicographical number
    int findKthNumber(int n, int k) {
        int curr = 1; // Start from the first number
        k -= 1;       // Decrement k as we already have the first number

        // Loop until we find the k-th lexicographical number
        while (k > 0) {
            // Count the numbers between curr and curr + 1 lexicographically
            int cnt = Count(curr, curr + 1, n);

            // If the count is less than or equal to k, move to the next lexicographical number
            if (cnt <= k) {
                k -= cnt;
                curr++;
            }
            // Otherwise, go deeper into the lexicographical tree (move to the next digit)
            else {
                k -= 1;
                curr *= 10;
            }
        }

        return curr; // Return the k-th lexicographical number
    }
};
