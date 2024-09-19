/*
241. Different Ways to Add Parentheses
Solved
Medium
Topics
Companies
Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.

The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 104.

 

Example 1:

Input: expression = "2-1-1"
Output: [0,2]
Explanation:
((2-1)-1) = 0 
(2-(1-1)) = 2
Example 2:

Input: expression = "2*3-4*5"
Output: [-34,-14,-10,-10,10]
Explanation:
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
 

Constraints:

1 <= expression.length <= 20
expression consists of digits and the operator '+', '-', and '*'.
All the integer values in the input expression are in the range [0, 99].
The integer values in the input expression do not have a leading '-' or '+' denoting the sign.
*/

/*
Approach:
1. **Recursive Splitting**: The problem is divided into smaller subproblems by splitting the expression at each operator ('+', '-', '*'). 
2. **Recursion on Subexpressions**: For each split, recursively compute all possible results for the left and right parts of the expression.
3. **Combine Results**: For each pair of results from the left and right parts, apply the operator to get all possible outcomes for the current subexpression.
4. **Base Case**: If the string doesn't contain any operators, it is treated as a number, and the result is returned.

Time Complexity:
- In the worst case, the time complexity is **O(Catalan(n))**, where `n` is the number of operators. The number of ways to parenthesize an expression is given by the nth Catalan number, and for each pair of subexpressions, the results are combined.
- The Catalan number grows exponentially, so the time complexity is **O(4^n / n^(3/2))**.

Space Complexity:
- **O(n!)**: The recursion stack may grow as deep as the number of ways to split the expression, leading to a factorial space complexity.

*/

class Solution {
public:
    // Helper function to recursively solve sub-expressions
    vector<int> solve(string expr) {
        int n = expr.size();
        vector<int> res;

        // Iterate through the expression
        for(int i = 0; i < n; i++) {
            // Check if the current character is an operator
            if(expr[i] == '+' || expr[i] == '-' || expr[i] == '*') {
                // Recursively solve the left and right parts of the expression
                vector<int> left_res = solve(expr.substr(0, i));
                vector<int> right_res = solve(expr.substr(i+1));

                // Combine the results from both parts based on the operator
                for(int &x : left_res) {
                    for(int &y : right_res) {
                        if(expr[i] == '+') {
                            res.push_back(x + y); // Apply addition
                        }
                        else if(expr[i] == '-') {
                            res.push_back(x - y); // Apply subtraction
                        }
                        else {
                            res.push_back(x * y); // Apply multiplication
                        }
                    }
                }
            }
        }

        // If the result vector is empty, it means this is a number, not an expression
        if(res.empty()) {
            res.push_back(stoi(expr)); // Convert the string to an integer
        }

        return res; // Return the list of all possible results
    }

    // Main function to compute all possible results from different ways of parenthesizing the expression
    vector<int> diffWaysToCompute(string expr) {
        return solve(expr); // Call the helper function
    }
};
