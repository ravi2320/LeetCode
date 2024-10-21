/*
1593. Split a String Into the Max Number of Unique Substrings
Solved
Medium
Topics
Companies
Hint
Given a string s, return the maximum number of unique substrings that the given string can be split into.

You can split string s into any list of non-empty substrings, where the concatenation of the substrings forms the original string. However, you must split the substrings such that all of them are unique.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: s = "ababccc"
Output: 5
Explanation: One way to split maximally is ['a', 'b', 'ab', 'c', 'cc']. Splitting like ['a', 'b', 'a', 'b', 'c', 'cc'] is not valid as you have 'a' and 'b' multiple times.
Example 2:

Input: s = "aba"
Output: 2
Explanation: One way to split maximally is ['a', 'ba'].
Example 3:

Input: s = "aa"
Output: 1
Explanation: It is impossible to split the string any further.
 

Constraints:

1 <= s.length <= 16

s contains only lower case English letters.
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
