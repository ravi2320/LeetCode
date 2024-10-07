/*
22. Generate Parentheses
Solved
Medium
Topics
Companies
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/

/*
Approach:
1. **Backtracking**:
   - We generate all possible combinations of `n` pairs of parentheses.
   - For each combination, we check if it is a valid combination of parentheses using a stack.
   - If the combination is valid, we add it to the result.

2. **Base Case**:
   - Once the length of the current string becomes `2 * n` (since each valid combination will contain `n` opening and `n` closing parentheses), we check if the combination is valid.

3. **Recursive Case**:
   - At each recursive step, we either add an opening `'('` or a closing `')'` to the current string and recurse further until the string length becomes `2 * n`.

4. **Optimization**:
   - We can prune invalid combinations early by ensuring the number of closing parentheses does not exceed the number of opening ones during recursion. This ensures that we don't need to validate using a stack.

Time Complexity:
- The time complexity is **O(2^2n)** because we are generating all possible combinations of `2n` characters (either `'('` or `')'`).
- For each combination, validating the parentheses is O(n), so overall complexity is O(2^2n * n) in this approach.

Space Complexity:
- The space complexity is O(n) for the recursion stack and O(2^2n) for storing the results.

*/

class Solution {
    vector<string> res;  // Vector to store the result of valid combinations
public:
    // Function to check if a parenthesis string is valid
    bool isValidParenthesis(string &curr) {
        stack<char> st;
        for (char &ch : curr) {
            if (ch == '(') 
                st.push(ch);  // Push opening parenthesis onto stack
            else if (!st.empty() && ch == ')' && st.top() == '(')
                st.pop();  // If matching pair, pop from stack
            else
                return false;  // Invalid if no matching pair
        }
        return st.empty();  // Valid if stack is empty at the end
    }

    // Recursive function to generate all combinations
    void solve(string &curr, int n) {
        // If we have a combination of length 2*n
        if (curr.length() == 2 * n) {
            if (isValidParenthesis(curr)) {  // Check if the combination is valid
                res.push_back(curr);  // Add valid combination to result
            }
            return;
        }

        // Add opening parenthesis '(' and recurse
        curr.push_back('(');
        solve(curr, n);
        curr.pop_back();

        // Add closing parenthesis ')' and recurse
        curr.push_back(')');
        solve(curr, n);
        curr.pop_back();
    }

    // Function to generate all valid parenthesis combinations
    vector<string> generateParenthesis(int n) {
        string curr;  // Current string to generate combinations
        solve(curr, n);  // Start the recursion
        return res;  // Return the result vector
    }
};


/*
Approach:
1. **Backtracking with open and close counters**:
   - We generate all possible valid combinations of `n` pairs of parentheses without needing to validate each one afterward.
   - We keep track of two counters, `open` (number of `'('` added) and `close` (number of `')'` added). This ensures that at any point, the number of closing parentheses does not exceed the number of opening parentheses.

2. **Base Case**:
   - When the length of the current string `curr` reaches `2 * n`, we add it to the result list.

3. **Recursive Case**:
   - Add `'('` to `curr` if the number of opening parentheses used is less than `n`.
   - Add `')'` to `curr` if the number of closing parentheses used is less than the number of opening parentheses used.

Time Complexity:
- The time complexity is **O(4^n / √n)**. This is due to the fact that we only generate valid combinations (a Catalan number grows exponentially), so we avoid checking all 2^(2n) possibilities.

Space Complexity:
- The space complexity is **O(n)** due to the depth of the recursion stack.

*/

class Solution {
    vector<string> res;  // Vector to store the result of valid combinations
public:
    // Recursive function to generate valid parentheses
    void solve(string &curr, int n, int open, int close) {
        // Base case: when the current string has 2*n characters
        if (curr.length() == 2 * n) {
            res.push_back(curr);  // Add valid combination to result
            return;
        }

        // Add opening parenthesis '(' if we haven't used all n open parentheses
        if (open < n) {
            curr.push_back('(');  // Add '(' to current string
            solve(curr, n, open + 1, close);  // Recur with incremented open counter
            curr.pop_back();  // Backtrack by removing last character
        }

        // Add closing parenthesis ')' if the number of close is less than open
        if (close < open) {
            curr.push_back(')');  // Add ')' to current string
            solve(curr, n, open, close + 1);  // Recur with incremented close counter
            curr.pop_back();  // Backtrack by removing last character
        }
    }

    // Function to generate all valid parenthesis combinations
    vector<string> generateParenthesis(int n) {
        string curr;  // String to store the current combination
        int open = 0, close = 0;  // Counters for open and close parentheses

        solve(curr, n, open, close);  // Start the recursive backtracking

        return res;  // Return the result vector
    }
};
