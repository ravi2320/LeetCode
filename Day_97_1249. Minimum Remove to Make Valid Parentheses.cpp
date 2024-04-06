/*
1249. Minimum Remove to Make Valid Parentheses
Solved
Medium
Topics
Companies
Hint
Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
 

Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
Example 2:

Input: s = "a)b(c)d"
Output: "ab(c)d"
Example 3:

Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.
 

Constraints:

1 <= s.length <= 105
s[i] is either'(' , ')', or lowercase English letter.
*/


/* 
Intuition:
- We use a stack to keep track of indices of opening parentheses '(' encountered in the string.
- Whenever we encounter a closing parenthesis ')', we pop the top index from the stack, indicating that the opening parenthesis at that index has been matched.
- After iterating through the string, we have the indices of unmatched opening parentheses left in the stack.
- We then create a set to store these indices for constant time lookup.
- Finally, we iterate through the original string again, appending characters to the result string if their index is not in the set of unmatched opening parentheses.
- The resulting string will be the final answer.

Time Complexity: O(n), where n is the length of the input string.
- We iterate through the string twice: once to process parentheses and once to construct the result string.

Space Complexity: O(n) for the stack and set.
- The space complexity is linear with respect to the length of the input string.
*/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;

        // Process the string to find unmatched opening parentheses
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                st.push(i);
            else if (s[i] == ')') {
                if (!st.empty())
                    st.pop();
                else
                    s[i] = '*'; // Mark invalid closing parentheses
            }
        }

        unordered_set<int> set1;

        // Store indices of unmatched opening parentheses in a set
        while (!st.empty()) {
            set1.insert(st.top());
            st.pop();
        }

        string res = "";

        // Construct the resulting string without invalid parentheses
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' && set1.count(i)) // Skip unmatched opening parentheses
                continue;
            if (s[i] != '*') // Append valid characters to the result string
                res += s[i];
        }

        return res;
    }
};


/*
Intuition:
- We iterate through the string from left to right and maintain a count of open parentheses.
- If we encounter a lowercase letter, we add it directly to the result string.
- If we encounter an opening parenthesis '(', we add it to the result and increment the count of open parentheses.
- If we encounter a closing parenthesis ')' and there are still open parentheses, we add it to the result and decrement the count of open parentheses.
- After processing from left to right, we repeat the process from right to left to handle excess closing parentheses.
- Finally, we reverse the result string to obtain the correct order.

Time Complexity: O(n), where n is the length of the input string.
- We iterate through the string twice, once from left to right and once from right to left.

Space Complexity: O(n) for the result string.
- The space complexity is linear with respect to the length of the input string.
*/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string result = "";
        int open = 0;

        // Process the string from left to right
        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                result.push_back(c);
            } else if (c == '(') {
                result.push_back(c);
                open++;
            } else if (open > 0) {
                result.push_back(c);
                open--;
            }
        }

        // Final processing from right to left
        int n = result.length();
        string final_result = "";
        int close = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (result[i] >= 'a' && result[i] <= 'z') {
                final_result.push_back(result[i]);
            } else if (result[i] == ')') {
                final_result.push_back(result[i]);
                close++;
            } else if (close > 0) {
                final_result.push_back(result[i]);
                close--;
            }
        }

        reverse(final_result.begin(), final_result.end()); // Reverse the result string
        return final_result;
    }
};


/*
Intuition:
- We iterate through the string from left to right and maintain a count of open parentheses.
- If we encounter an opening parenthesis '(', we increment the count and add it to the temporary string.
- If we encounter a closing parenthesis ')' and there are still open parentheses, we decrement the count and add it to the temporary string.
- Otherwise, if it's a valid character (not a parenthesis), we add it to the temporary string.
- After processing from left to right, we iterate through the temporary string from right to left.
- If there are still unmatched open parentheses, we remove them.
- Finally, we reverse the result string to obtain the correct order.

Time Complexity: O(n), where n is the length of the input string.
- We iterate through the string twice, once from left to right and once from right to left.

Space Complexity: O(n) for the temporary and result strings.
- The space complexity is linear with respect to the length of the input string.
*/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string temp = "";
        int open = 0;

        // Process the string from left to right
        for (char c : s) {
            if (c == '(') {
                open++;
                temp.push_back(c);
            } else if (c == ')' && open > 0) {
                open--;
                temp.push_back(c);
            } else if (isalpha(c)) {
                temp.push_back(c); // Add valid characters to the temporary string
            }
        }

        // Final processing from right to left
        int n = temp.length();
        string res = "";
        for (int i = n - 1; i >= 0; i--) {
            if (open && temp[i] == '(') {
                open--;
            } else {
                res.push_back(temp[i]); // Add valid characters to the result string
            }
        }

        reverse(res.begin(), res.end()); // Reverse the result string
        return res;
    }
};

