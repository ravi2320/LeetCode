/*
1544. Make The String Great
Solved
Easy
Topics
Companies
Hint
Given a string s of lower and upper case English letters.

A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:

0 <= i <= s.length - 2
s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.
To make the string good, you can choose two adjacent characters that make the string bad and remove them. You can keep doing this until the string becomes good.

Return the string after making it good. The answer is guaranteed to be unique under the given constraints.

Notice that an empty string is also good.

 

Example 1:

Input: s = "leEeetcode"
Output: "leetcode"
Explanation: In the first step, either you choose i = 1 or i = 2, both will result "leEeetcode" to be reduced to "leetcode".
Example 2:

Input: s = "abBAcC"
Output: ""
Explanation: We have many possible scenarios, and all lead to the same answer. For example:
"abBAcC" --> "aAcC" --> "cC" --> ""
"abBAcC" --> "abBA" --> "aA" --> ""
Example 3:

Input: s = "s"
Output: "s"
 

Constraints:

1 <= s.length <= 100
s contains only lower and upper case English letters.
*/

/* 
Intuition:
- We iterate through each character in the string.
- If the current character is equal to the previous character in case-insensitive manner and their ASCII difference is 32 (indicating uppercase-lowercase pair), we remove the last character from the result string.
- Otherwise, we append the current character to the result string.
- The resulting string will be the final answer.

Time Complexity: O(n), where n is the length of the input string.
- We iterate through each character in the string once.

Space Complexity: O(n) for the result string.
- The space complexity is linear with respect to the length of the input string as we store the resulting string.
*/

class Solution {
public:
    string makeGood(string s) 
    {
        string res;
        for (char c : s) {
            if (!res.empty() && (toupper(c) == toupper(res.back())) && (c - res.back() != 0)) {
                res.pop_back();
            } else {
                res.push_back(c);
            }
        }
        
        return res;
    }
};
