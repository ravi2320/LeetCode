/*
2929. Distribute Candies Among Children II
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given two positive integers n and limit.

Return the total number of ways to distribute n candies among 3 children such that no child gets more than limit candies.

 

Example 1:

Input: n = 5, limit = 2
Output: 3
Explanation: There are 3 ways to distribute 5 candies such that no child gets more than 2 candies: (1, 2, 2), (2, 1, 2) and (2, 2, 1).
Example 2:

Input: n = 3, limit = 3
Output: 10
Explanation: There are 10 ways to distribute 3 candies such that no child gets more than 3 candies: (0, 0, 3), (0, 1, 2), (0, 2, 1), (0, 3, 0), (1, 0, 2), (1, 1, 1), (1, 2, 0), (2, 0, 1), (2, 1, 0) and (3, 0, 0).
 

Constraints:

1 <= n <= 106
1 <= limit <= 106
*/

/*
Approach:
- We need to distribute 'n' candies among 3 children, where each child can receive at most 'limit' candies.
- Let the number of candies given to the first child be `i` (0 ≤ i ≤ limit), but constrained so that the remaining
  candies (n - i) can be split between the other two children without exceeding the limit for each.
- For each valid `i`, calculate the number of ways to split (n - i) between child 2 and 3 where each gets ≤ limit.

Intuition:
- This is an integer partition problem with upper bounds.
- For each valid value of first child's candies, we compute the valid range for the second child.
- The third child’s count is automatically determined as (n - i - j), so we only need to make sure
  all three stay within the [0, limit] range.

Time Complexity: O(limit)
- We loop from max(0, n - 2*limit) to min(n, limit), so the loop runs at most 'limit + 1' times.

Space Complexity: O(1)
- Only constant variables are used.
*/

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        // Minimum value child 1 can take such that remaining can be valid for other two
        int minCh1 = max(0, n - 2 * limit);
        // Maximum value child 1 can take based on limit and total candies
        int maxCh1 = min(n, limit);

        long long ways = 0;

        // Loop through all valid values for first child
        for(int i = minCh1; i <= maxCh1; i++) {
            int remaining = n - i; // Candies left for child 2 and 3

            // Minimum and maximum valid candies child 2 can get
            int minCh2 = max(0, remaining - limit);
            int maxCh2 = min(remaining, limit);

            // Count the number of valid integer values child 2 can take
            ways += maxCh2 - minCh2 + 1;
        }

        return ways;
    }
};
