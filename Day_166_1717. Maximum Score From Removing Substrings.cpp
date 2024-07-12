/*
1717. Maximum Score From Removing Substrings
Solved
Medium
Topics
Companies
Hint
You are given a string s and two integers x and y. You can perform two types of operations any number of times.

Remove substring "ab" and gain x points.
For example, when removing "ab" from "cabxbae" it becomes "cxbae".
Remove substring "ba" and gain y points.
For example, when removing "ba" from "cabxbae" it becomes "cabxe".
Return the maximum points you can gain after applying the above operations on s.

 

Example 1:

Input: s = "cdbcbbaaabab", x = 4, y = 5
Output: 19
Explanation:
- Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
- Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
- Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
- Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
Total score = 5 + 4 + 5 + 5 = 19.
Example 2:

Input: s = "aabbaaxybbaabb", x = 5, y = 4
Output: 20
 

Constraints:

1 <= s.length <= 105
1 <= x, y <= 104
s consists of lowercase English letters.
*/

/*
 * Intuition:
 * To maximize the gain from removing "ab" and "ba" substrings, we use a stack to simulate the removal process.
 * We process the string twice: first to remove the more valuable substring, then the less valuable substring.
 *
 * Time Complexity: O(n), where n is the length of the string s.
 * Space Complexity: O(n), used by the stack.
 */

class Solution {
public:
    string removedSubStr(string &s, string matchStr) {
        stack<char> st;

        for (char ch : s) {
            if (!st.empty() && ch == matchStr[1] && st.top() == matchStr[0]) {
                st.pop();
            } else {
                st.push(ch);
            }
        }

        string temp = "";
        while (!st.empty()) {
            temp += st.top();
            st.pop();
        }

        reverse(temp.begin(), temp.end());
        return temp;
    }

    int maximumGain(string s, int x, int y) {
        int n = s.length();
        int score = 0;

        string maxStr = (x > y) ? "ab" : "ba";
        string minStr = (x < y) ? "ab" : "ba";

        // First Pass: Remove the more valuable substring first
        string temp_first = removedSubStr(s, maxStr);
        int L = temp_first.length();
        int charRemoved = n - L;
        score += (charRemoved / 2) * max(x, y);

        // Second Pass: Remove the less valuable substring
        string temp_second = removedSubStr(temp_first, minStr);
        charRemoved = L - temp_second.length();
        score += (charRemoved / 2) * min(x, y);

        return score;
    }
};


/*
 * Intuition:
 * To maximize the gain from removing "ab" and "ba" substrings, we use a two-pass approach:
 * - First, remove the more valuable substring using a two-pointer method.
 * - Then, remove the less valuable substring from the resulting string.
 *
 * Time Complexity: O(n), where n is the length of the string s.
 * Space Complexity: O(1), in-place modification of the string.
 */

class Solution {
public:
    string removedSubStr1(string &s, string matchStr){
        int i = 0; // i is for writing purpose

        for(int j = 0; j < s.length(); j++){ // j is for reading each character
            s[i] = s[j]; // write at s[i] whichever s[j] reads
            i++;

            if(i >= 2 && s[i-2] == matchStr[0] && s[i-1] == matchStr[1]){
                i -= 2; // remove the matched substring
            }
        }
    
        s.erase(s.begin() + i, s.end()); // erase the remaining part of the string after i
        return s;
    }

    int maximumGain(string s, int x, int y) {
        int n = s.length();
        int score = 0;

        string maxStr = (x > y) ? "ab" : "ba";
        string minStr = (x < y) ? "ab" : "ba";

        // First pass: remove the more valuable substring
        string temp_first = removedSubStr1(s, maxStr);
        int L = temp_first.length();
        int charRemoved = n - L;
        score += (charRemoved / 2) * max(x, y);

        // Second pass: remove the less valuable substring
        string temp_second = removedSubStr1(temp_first, minStr);
        charRemoved = L - temp_second.length();
        score += (charRemoved / 2) * min(x, y);

        return score;
    }
};
