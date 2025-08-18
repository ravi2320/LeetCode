/*
679. 24 Game

avatar
Discuss Approach
arrow-up
Solved
Hard
Topics
premium lock icon
Companies
You are given an integer array cards of length 4. You have four cards, each containing a number in the range [1, 9]. You should arrange the numbers on these cards in a mathematical expression using the operators ['+', '-', '*', '/'] and the parentheses '(' and ')' to get the value 24.

You are restricted with the following rules:

The division operator '/' represents real division, not integer division.
For example, 4 / (1 - 2 / 3) = 4 / (1 / 3) = 12.
Every operation done is between two numbers. In particular, we cannot use '-' as a unary operator.
For example, if cards = [1, 1, 1, 1], the expression "-1 - 1 - 1 - 1" is not allowed.
You cannot concatenate numbers together
For example, if cards = [1, 2, 1, 2], the expression "12 + 12" is not valid.
Return true if you can get such expression that evaluates to 24, and false otherwise.

 

Example 1:

Input: cards = [4,1,8,7]
Output: true
Explanation: (8-4) * (7-1) = 24
Example 2:

Input: cards = [1,2,1,2]
Output: false
 

Constraints:

cards.length == 4
1 <= cards[i] <= 9
*/

/*
Approach:
---------
We need to determine if four numbers can be combined using +, -, *, and / 
to form the number 24. This is a backtracking problem where:
1. We repeatedly pick two numbers, apply all possible operations, and 
   replace them with the result.
2. We recurse until only one number remains.
3. If that number is approximately 24 (within an epsilon tolerance), 
   return true.

Intuition:
----------
- The game requires testing all possible combinations of operations and 
  number pairings.
- Using recursion and backtracking, we simulate all arithmetic possibilities.
- Since the number of cards is small (fixed at 4), brute-force with pruning 
  is feasible.

Time Complexity:
----------------
- There are 4 numbers → choose 2 numbers → apply ~6 operations.
- Then recurse with 3 numbers, and so on.
- Roughly O(n! * k^n), but since n = 4 is fixed, the complexity is manageable.
- Effectively, the runtime is constant and bounded.

Space Complexity:
-----------------
- O(n) for recursion depth and storing intermediate results.
- Here, O(4) = O(1).

*/

class Solution {
    double epsilon = 0.1;  // tolerance for floating point comparison
public:
    // Recursive function to check if numbers can form 24
    bool solve(vector<double> &cards) {
        // Base case: if only one number remains, check if it's ~24
        if (cards.size() == 1) {
            return abs(cards[0] - 24) <= epsilon;
        }

        // Try all pairs of numbers
        for (int i = 0; i < cards.size(); i++) {
            for (int j = 0; j < cards.size(); j++) {
                if (i == j) continue;  // avoid using the same card twice

                // Store remaining numbers (excluding i and j)
                vector<double> temp;
                for (int k = 0; k < cards.size(); k++) {
                    if (k == i || k == j) continue;
                    temp.push_back(cards[k]);
                }

                double a = cards[i], b = cards[j];

                // Generate all possible results from a and b
                vector<double> possibleValues = {a + b, a - b, b - a, a * b};

                // Handle division only if denominator ≠ 0
                if (abs(b) > 0.0) possibleValues.push_back(a / b);
                if (abs(a) > 0.0) possibleValues.push_back(b / a);

                // Try each possible value recursively
                for (double val : possibleValues) {
                    temp.push_back(val);       // choose this operation result
                    if (solve(temp)) return true;  // check if it leads to 24
                    temp.pop_back();           // backtrack
                }
            }
        }

        return false; // No valid operation sequence found
    }

    bool judgePoint24(vector<int>& cards) {
        // Convert integers to double for precision in division
        vector<double> doubleCards;
        for (int &card : cards) {
            doubleCards.push_back(1.0 * card);
        }
        return solve(doubleCards);
    }
};
