/*
151. Reverse Words in a String
Solved
Medium
Topics
Companies
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.
*/

/*
Intuition:
- We need to reverse the order of words in a string.
- Split the string into words and store them in a stack.
- Pop the words from the stack to reverse the order and construct the result string.

Time Complexity:
- O(n): We traverse the string once to split the words and once to construct the result.

Space Complexity:
- O(n): We use a stack to store the words and an additional result string.
*/

class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        string temp = "";
        stack<string> st;
        
        // Split the string into words and push them onto the stack
        for (char ch : s) {
            if (ch == ' ') {
                if (temp.length() == 0) continue;
                st.push(temp);
                temp = "";
            } else {
                temp += ch;
            }
        }
        
        // Push the last word onto the stack
        if (temp.length()) {
            st.push(temp);
        }
        
        // Pop the words from the stack to reverse the order
        while (!st.empty()) {
            string tmp = st.top();
            st.pop();
            if (st.empty()) {
                res += tmp;
            } else {
                res += tmp + " ";
            }
        }
        
        return res;
    }
};
