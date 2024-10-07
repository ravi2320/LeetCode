/*
2696. Minimum String Length After Removing Substrings
Solved
Easy
Topics
Companies
Hint
You are given a string s consisting only of uppercase English letters.

You can apply some operations to this string where, in one operation, you can remove any occurrence of one of the substrings "AB" or "CD" from s.

Return the minimum possible length of the resulting string that you can obtain.

Note that the string concatenates after removing the substring and could produce new "AB" or "CD" substrings.

 

Example 1:

Input: s = "ABFCACDB"
Output: 2
Explanation: We can do the following operations:
- Remove the substring "ABFCACDB", so s = "FCACDB".
- Remove the substring "FCACDB", so s = "FCAB".
- Remove the substring "FCAB", so s = "FC".
So the resulting length of the string is 2.
It can be shown that it is the minimum length that we can obtain.
Example 2:

Input: s = "ACBBD"
Output: 5
Explanation: We cannot do any operations on the string so the length remains the same.
 

Constraints:

1 <= s.length <= 100
s consists only of uppercase English letters.
*/

/*
Approach:
1. We are tasked with reducing the string `s` by removing specific consecutive pairs: 
   - "AB" → can be removed.
   - "CD" → can be removed.
2. We use a stack to process the string one character at a time:
   - If the top of the stack and the current character form a removable pair ("AB" or "CD"), we pop the stack.
   - Otherwise, we push the current character onto the stack.
3. In the end, the size of the stack will represent the length of the reduced string.

Time Complexity:
- **O(n)**, where `n` is the length of the string. We process each character once.

Space Complexity:
- **O(n)**, in the worst case, the stack may contain all characters if no pairs are removed.

*/

class Solution {
public:
    // Function to find the minimum length of the string after removal of "AB" and "CD" pairs
    int minLength(string s) {
        // Stack to help process the string
        stack<char> st;

        // Iterate over each character in the string
        for(char &ch : s) {
            // Check if the top of the stack and current character form a removable pair
            if(!st.empty() && ((ch == 'B' && st.top() == 'A') || (ch == 'D' && st.top() == 'C'))) {
                st.pop();  // Remove the pair
            } 
            else {
                st.push(ch);  // Push the current character if no pair is formed
            }
        }

        // The size of the stack represents the reduced string's length
        return st.size();
    }
};