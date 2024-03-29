/*
647. Palindromic Substrings
Solved
Medium
Topics
Companies
Hint
Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.
*/

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> isPalindrome(n, vector<int>(n, 0));
        int ans = 0;
        for(int i = n-1; i > -1; i--){
            for(int j = i; j < n; j++){
                if(i == j){
                    isPalindrome[i][j] = 1;
                    ans++;
                }
                else{
                    if(s[i] == s[j] and (i == j-1 or isPalindrome[i+1][j-1] == 1)){
                        isPalindrome[i][j] = 1;
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};