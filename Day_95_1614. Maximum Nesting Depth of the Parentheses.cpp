/*
1614. Maximum Nesting Depth of the Parentheses
Solved
Easy
Topics
Companies
Hint
A string is a valid parentheses string (denoted VPS) if it meets one of the following:

It is an empty string "", or a single character not equal to "(" or ")",
It can be written as AB (A concatenated with B), where A and B are VPS's, or
It can be written as (A), where A is a VPS.
We can similarly define the nesting depth depth(S) of any VPS S as follows:

depth("") = 0
depth(C) = 0, where C is a string with a single character not equal to "(" or ")".
depth(A + B) = max(depth(A), depth(B)), where A and B are VPS's.
depth("(" + A + ")") = 1 + depth(A), where A is a VPS.
For example, "", "()()", and "()(()())" are VPS's (with nesting depths 0, 1, and 2), and ")(" and "(()" are not VPS's.

Given a VPS represented as string s, return the nesting depth of s.

 

Example 1:

Input: s = "(1+(2*3)+((8)/4))+1"
Output: 3
Explanation: Digit 8 is inside of 3 nested parentheses in the string.
Example 2:

Input: s = "(1)+((2))+(((3)))"
Output: 3
 

Constraints:

1 <= s.length <= 100
s consists of digits 0-9 and characters '+', '-', '*', '/', '(', and ')'.
It is guaranteed that parentheses expression s is a VPS.
*/

/**
 * Intuition:
 * - We can use a stack to keep track of the opening parentheses '(' encountered.
 * - For each '(' encountered, push it onto the stack.
 * - For each ')' encountered, pop an opening parenthesis from the stack, indicating a valid pair.
 * - The maximum depth of nested parentheses corresponds to the maximum size of the stack during the traversal.
 * 
 * Time Complexity: O(n), where n is the length of the input string 's'.
 * - We iterate through each character in the string once.
 * 
 * Space Complexity: O(n), where n is the length of the input string 's'.
 * - In the worst case, the stack can hold all the opening parentheses.
 * - Thus, the space required is linearly proportional to the length of the input string.
 */

class Solution {
public:
    int maxDepth(string s) {
        stack<char> st; // Stack to keep track of opening parentheses
        int res = 0; // Variable to store the maximum depth
        
        // Process the string to find the maximum depth
        for (char ch : s) {
            if (ch == '(')
                st.push('('); // Push '(' onto the stack for each opening parenthesis encountered
            else if (ch == ')')
                st.pop(); // Pop an opening parenthesis from the stack for each closing parenthesis encountered

            // Update the maximum depth with the current size of the stack
            res = max(res, static_cast<int>(st.size()));
        }

        return res; // Return the maximum depth
    }
};



/**
 * Intuition:
 * - We maintain a count of opening and closing parentheses encountered while traversing the string.
 * - Increment the count when an opening parenthesis '(' is encountered and decrement it when a closing parenthesis ')' is encountered.
 * - The maximum depth of nested parentheses corresponds to the maximum count of opening parentheses encountered at any point during the traversal.
 * 
 * Time Complexity: O(n), where n is the length of the input string 's'.
 * - We iterate through each character in the string once.
 * 
 * Space Complexity: O(1)
 * - We use only constant space for integer variables 'countBracket' and 'res', independent of the input size.
 */

class Solution {
public:
    int maxDepth(string s) {
        int countBracket = 0; // Variable to keep track of the count of opening parentheses
        int res = 0; // Variable to store the maximum depth
        
        // Traverse the string to find the maximum depth
        for (char ch : s) {
            if (ch == '(')
                countBracket++; // Increment count for each opening parenthesis encountered
            else if (ch == ')')
                countBracket--; // Decrement count for each closing parenthesis encountered

            // Update the maximum depth with the current count of opening parentheses
            res = max(res, countBracket);
        }

        return res; // Return the maximum depth
    }
};