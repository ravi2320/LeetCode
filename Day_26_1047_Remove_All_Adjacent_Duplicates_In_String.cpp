/*
1047. Remove All Adjacent Duplicates In String
Solved
Easy
Topics
Companies
Hint
You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

 

Example 1:

Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
Example 2:

Input: s = "azxxzy"
Output: "ay"
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(char c:s)
        {
            if(!st.empty() && c == st.top())
                st.pop();
            else
                st.push(c);
        }
        string str = "";
        while(!st.empty())
        {
            str.push_back(st.top());
            st.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};
*/

class Solution {
public:
    string removeDuplicates(string s) {
        string str = "";
        for(char c:s)
        {
            if(str.size() && c == str.back())
                str.pop_back();
            else
                str.push_back(c);
        }
        return str;
    }
};