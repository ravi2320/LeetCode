/*
1021. Remove Outermost Parentheses
Solved
Easy
Topics
Companies
Hint
A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.

For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.

Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.

Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

 

Example 1:

Input: s = "(()())(())"
Output: "()()()"
Explanation: 
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".
Example 2:

Input: s = "(()())(())(()(()))"
Output: "()()()()(())"
Explanation: 
The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".
Example 3:

Input: s = "()()"
Output: ""
Explanation: 
The input string is "()()", with primitive decomposition "()" + "()".
After removing outer parentheses of each part, this is "" + "" = "".
 

Constraints:

1 <= s.length <= 105
s[i] is either '(' or ')'.
s is a valid parentheses string.
*/

class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        int n = s.size();
        string str = "";
        for(int i=0; i<n; i++)
        {
            if(s[i] == '(')
            {
                if(st.size() >= 1)
                    str += "(";
                st.push('(');
            }
            else
            {
                if(st.size() > 1)
                    str += ")";
                st.pop();
            }
        }
        return str;
    }
};

//Optimal Code:
class Solution {
public:
    string removeOuterParentheses(string s) {
        string str = "";
        int cnt = 0;
        for(char c:s)
        {
            if(c == '(' && cnt++ > 0) str += c;
            if(c == ')' && cnt-- > 1) str += c;
        }
        return str;
    }
};