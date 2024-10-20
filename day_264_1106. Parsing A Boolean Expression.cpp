/*
1106. Parsing A Boolean Expression
Solved
Hard
Topics
Companies
Hint
A boolean expression is an expression that evaluates to either true or false. It can be in one of the following shapes:

't' that evaluates to true.
'f' that evaluates to false.
'!(subExpr)' that evaluates to the logical NOT of the inner expression subExpr.
'&(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical AND of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
'|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
Given a string expression that represents a boolean expression, return the evaluation of that expression.

It is guaranteed that the given expression is valid and follows the given rules.

 

Example 1:

Input: expression = "&(|(f))"
Output: false
Explanation: 
First, evaluate |(f) --> f. The expression is now "&(f)".
Then, evaluate &(f) --> f. The expression is now "f".
Finally, return false.
Example 2:

Input: expression = "|(f,f,f,t)"
Output: true
Explanation: The evaluation of (false OR false OR false OR true) is true.
Example 3:

Input: expression = "!(&(f,t))"
Output: true
Explanation: 
First, evaluate &(f,t) --> (false AND true) --> false --> f. The expression is now "!(f)".
Then, evaluate !(f) --> NOT false --> true. We return true.
 

Constraints:

1 <= expression.length <= 2 * 104
expression[i] is one following characters: '(', ')', '&', '|', '!', 't', 'f', and ','.
*/

/*
Approach:
- The problem is to parse a boolean expression consisting of three operators:
  1. `!` (NOT): Inverts the value of the boolean.
  2. `&` (AND): Returns true if all values are true, otherwise false.
  3. `|` (OR): Returns true if at least one value is true, otherwise false.
  
- The expression consists of characters 't' (true), 'f' (false), and the operators with parentheses to define precedence.

- The main idea is to use a stack to process the expression:
  1. Push every character to the stack until a closing parenthesis `)` is encountered.
  2. Once `)` is found, pop the values between `(` and `)` and apply the corresponding operator (`!`, `&`, or `|`).
  3. Push the result back onto the stack and continue until the expression is fully evaluated.
  4. At the end, the stack will contain either 't' or 'f', which represents the final result of the expression.

Time Complexity:
- O(n), where n is the length of the input string. Each character is processed exactly once by pushing and popping from the stack, making the solution linear in time.

Space Complexity:
- O(n), where n is the number of characters in the input string. The stack may hold up to all characters in the worst case.

*/

class Solution {
public:
    // Helper function to evaluate the operation on the list of boolean values
    char solve(char &op, vector<char> &values) {

        // NOT operator: invert the single boolean value
        if(op == '!') {
            return values[0] == 't' ? 'f' : 't';
        }

        // AND operator: return 'f' if any value is 'f', otherwise return 't'
        if(op == '&') {
            for(char &x : values) {
                if(x == 'f') {
                    return 'f';
                }
            }
            return 't';
        }

        // OR operator: return 't' if any value is 't', otherwise return 'f'
        if(op == '|') {
            for(char &x : values) {
                if(x == 't') {
                    return 't';
                }
            }
            return 'f';
        }

        return 't';  // default case, though should never be reached
    }

    bool parseBoolExpr(string expression) {
        // Stack to store the characters and operators during parsing
        stack<char> st;

        // Traverse through each character in the expression
        for(char &ch : expression) {

            // Skip commas as they are just separators
            if(ch == ',') continue;

            // When encountering a closing parenthesis ')'
            if(ch == ')') {
                vector<char> values;

                // Pop values until reaching the opening parenthesis '('
                while(st.top() != '(') {
                    values.push_back(st.top());
                    st.pop();
                }

                st.pop();  // Pop the opening parenthesis '('
                char op = st.top();  // Get the operator (!, &, |)
                st.pop();

                // Evaluate the operation using the helper function and push the result back to stack
                st.push(solve(op, values));
            } else {
                // Push any other characters (including operators) to the stack
                st.push(ch);
            }
        }

        // The final result will be at the top of the stack ('t' for true, 'f' for false)
        return st.top() == 't';
    }
};