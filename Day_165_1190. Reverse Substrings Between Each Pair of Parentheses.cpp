/*
1190. Reverse Substrings Between Each Pair of Parentheses
Solved
Medium
Topics
Companies
Hint
You are given a string s that consists of lower case English letters and brackets.

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should not contain any brackets.

 

Example 1:

Input: s = "(abcd)"
Output: "dcba"
Example 2:

Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.
Example 3:

Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.
 

Constraints:

1 <= s.length <= 2000
s only contains lower case English characters and parentheses.
It is guaranteed that all parentheses are balanced.
*/

/*
 * Intuition:
 * To reverse substrings within each pair of parentheses in the string `s`, we can use a stack to keep track of the positions of '('.
 * When we encounter a ')', we reverse the substring from the last '(' position to the current position.
 * This approach ensures that the nested parentheses are handled correctly.
 *
 * Time Complexity: O(n^2) in the worst case, where n is the length of the string, due to the potential repeated reversal of substrings.
 * Space Complexity: O(n), where n is the length of the string, for the stack and the resulting string.
 */

class Solution {
public:
    string reverseParentheses(string s) {
        string res = "";
        stack<int> st;

        for (char ch : s) {
            if (ch >= 'a' && ch <= 'z') {
                res += ch;
            } else if (ch == '(') {
                st.push(res.length());
            } else {
                int l = st.top();
                st.pop();
                reverse(res.begin() + l, res.end());
            }
        }

        return res;
    }
};


/*
 * Intuition:
 * To reverse substrings within each pair of parentheses in the string `s`, we can use a stack to identify the matching pairs of parentheses.
 * Once we know the pairs, we can traverse the string, reversing directions as needed when encountering parentheses.
 *
 * Time Complexity: O(n), where n is the length of the string, due to the single traversal for determining pairs and another for building the result.
 * Space Complexity: O(n), where n is the length of the string, for the stack and the `door` vector.
 */

class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();

        stack<int> st;
        vector<int> door(n);

        // Identify matching pairs of parentheses
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int j = st.top();
                st.pop();
                door[i] = j;
                door[j] = i;
            }
        }

        int flag = 1;
        string res = "";
        
        // Traverse the string, reversing directions as needed
        for (int i = 0; i < n; i += flag) {
            if (s[i] == '(' || s[i] == ')') {
                flag = -flag;
                i = door[i];
            } else {
                res.push_back(s[i]);
            }
        }

        return res;
    }
};
