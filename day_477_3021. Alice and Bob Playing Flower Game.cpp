/*
3021. Alice and Bob Playing Flower Game
Solved

avatar
Discuss Approach
arrow-up
Medium
Topics
premium lock icon
Companies
Hint
Alice and Bob are playing a turn-based game on a field, with two lanes of flowers between them. There are x flowers in the first lane between Alice and Bob, and y flowers in the second lane between them.



The game proceeds as follows:

Alice takes the first turn.
In each turn, a player must choose either one of the lane and pick one flower from that side.
At the end of the turn, if there are no flowers left at all in either lane, the current player captures their opponent and wins the game.
Given two integers, n and m, the task is to compute the number of possible pairs (x, y) that satisfy the conditions:

Alice must win the game according to the described rules.
The number of flowers x in the first lane must be in the range [1,n].
The number of flowers y in the second lane must be in the range [1,m].
Return the number of possible pairs (x, y) that satisfy the conditions mentioned in the statement.

 

Example 1:

Input: n = 3, m = 2
Output: 3
Explanation: The following pairs satisfy conditions described in the statement: (1,2), (3,2), (2,1).
Example 2:

Input: n = 1, m = 1
Output: 0
Explanation: No pairs satisfy the conditions described in the statement.
 

Constraints:

1 <= n, m <= 105
*/

/*
Approach:
---------
We are given two numbers `n` and `m` representing counts of flowers of two types.  
The game rule: one player picks from the `n` flowers, the other from the `m` flowers.  
The player who ends up with an *odd total* wins.  
So, we need to count the number of possible ways pairs `(i, j)` can be chosen such that:
  - i is odd and j is even, OR
  - i is even and j is odd.

Mathematically:
  - Count odd numbers in [1..n] = (n+1)/2
  - Count even numbers in [1..n] = n/2
  - Count odd numbers in [1..m] = (m+1)/2
  - Count even numbers in [1..m] = m/2

Total valid pairs = (odd_n * even_m) + (even_n * odd_m)

Intuition:
----------
The game is essentially reduced to counting odd-even pairs.  
Since odd + even = odd, only these pairs matter.  
We compute the count of odd/even numbers in both sets and multiply to get total valid winning pairs.

Time Complexity:
----------------
O(1) → Only arithmetic operations are performed.  

Space Complexity:
-----------------
O(1) → No extra space used.
*/

class Solution {
public:
    long long flowerGame(int n, int m) {
        // Count of odd numbers in [1..n]
        long long oddN = (n + 1) / 2;
        // Count of even numbers in [1..n]
        long long evenN = n / 2;
        
        // Count of odd numbers in [1..m]
        long long oddM = (m + 1) / 2;
        // Count of even numbers in [1..m]
        long long evenM = m / 2;

        // Valid pairs: (odd_n * even_m) + (even_n * odd_m)
        return oddN * evenM + evenN * oddM;
    }
};
