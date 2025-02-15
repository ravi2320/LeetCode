/*
2698. Find the Punishment Number of an Integer
Solved
Medium
Topics
Companies
Hint
Given a positive integer n, return the punishment number of n.

The punishment number of n is defined as the sum of the squares of all integers i such that:

1 <= i <= n
The decimal representation of i * i can be partitioned into contiguous substrings such that the sum of the integer values of these substrings equals i.
 

Example 1:

Input: n = 10
Output: 182
Explanation: There are exactly 3 integers i in the range [1, 10] that satisfy the conditions in the statement:
- 1 since 1 * 1 = 1
- 9 since 9 * 9 = 81 and 81 can be partitioned into 8 and 1 with a sum equal to 8 + 1 == 9.
- 10 since 10 * 10 = 100 and 100 can be partitioned into 10 and 0 with a sum equal to 10 + 0 == 10.
Hence, the punishment number of 10 is 1 + 81 + 100 = 182
Example 2:

Input: n = 37
Output: 1478
Explanation: There are exactly 4 integers i in the range [1, 37] that satisfy the conditions in the statement:
- 1 since 1 * 1 = 1. 
- 9 since 9 * 9 = 81 and 81 can be partitioned into 8 + 1. 
- 10 since 10 * 10 = 100 and 100 can be partitioned into 10 + 0. 
- 36 since 36 * 36 = 1296 and 1296 can be partitioned into 1 + 29 + 6.
Hence, the punishment number of 37 is 1 + 81 + 100 + 1296 = 1478
 

Constraints:

1 <= n <= 1000
*/

class Solution {
public:
    /**
     * Approach:
     * - The problem requires checking if the square of a number can be partitioned into substrings 
     *   that sum up to the original number.
     * - We use a recursive function `check()` with memoization (`t` array) to explore all valid 
     *   partitions of the square number.
     * - If a valid partition exists, we add the square to the total punishment number.
     * 
     * Intuition:
     * - We recursively try to form valid partitions of the square of each number.
     * - Using memoization, we store results of overlapping subproblems to optimize performance.
     * 
     * Time Complexity:
     * - `punishmentNumber(n)`: O(N * M^2) where N is the input number and M is the length of 
     *   the squared number (since we generate partitions).
     * - `check()`: O(M^2) in the worst case for each number.
     * 
     * Space Complexity:
     * - O(N * M) for the memoization table.
     */

    bool check(int i, int currsum, string s, int num, vector<vector<int>>& t) {
        if (i == s.length()) {
            return currsum == num;  // If end of string reached, check if sum matches `num`
        }
        if (currsum > num) 
            return false;  // If sum exceeds `num`, return false

        if (t[i][currsum] != -1) 
            return t[i][currsum];  // Return stored result if subproblem already solved

        bool possible = false;
        for (int j = i; j < s.length(); j++) {
            string currentString = s.substr(i, j - i + 1);  // Extract substring
            int addend = stoi(currentString);  // Convert substring to integer

            possible = possible || check(j + 1, currsum + addend, s, num, t);
            if (possible) return true;  // If a valid partition is found, return true
        }

        return t[i][currsum] = possible;  // Store result in memoization table
    }

    int punishmentNumber(int n) {
        int punishmentNum = 0;
        for (int num = 1; num <= n; num++) {
            int squareNum = num * num;  // Compute square of `num`
            string s = to_string(squareNum);  // Convert to string for partitioning

            vector<vector<int>> t(s.size(), vector<int>(num + 1, -1));  // Memoization table

            if (check(0, 0, s, num, t)) {
                punishmentNum += squareNum;  // Add to result if valid partition exists
            }
        }
        return punishmentNum;
    }
};