//20. Valid Parentheses https://leetcode.com/problems/valid-parentheses/description/

/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

My Solution
===========

*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i=0; i<s.size(); i++)
        {
            char ch = s[i];
            if(ch == '{' || ch == '[' || ch == '(')
                stk.push(ch);
            else
            {
                if(!stk.empty())
                {
                    if(ch == '}')
                    {
                        if(stk.top() == '{')
                            stk.pop();
                        else
                            return false;
                    }
                    else if(ch == ']')
                    {
                        if(stk.top() == '[')
                            stk.pop();
                        else
                            return false;
                    }
                    else if(ch== ')')
                    {
                        if(stk.top() == '(')
                            stk.pop();
                        else
                            return false;
                    }
                }
                else
                    return false;
            }
            
        }
        return stk.empty() ? true : false;
    }
};

//Optimal Solution
//================
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i=0; i<s.size(); i++)
        {
            char ch = s[i];
            if(ch == '{' || ch == '[' || ch == '(')
                stk.push(ch);
            else
            {
                if(stk.empty() || (ch == '}' && stk.top() != '{') || (ch == ']' && stk.top() != '[') || (ch == ')' && stk.top() != '('))
                {
                    return false;        
                }
                stk.pop();
            }            
        }
        return stk.empty();
    }
};