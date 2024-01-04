/*
516. Longest Palindromic Subsequence
Solved
Medium
Topics
Companies
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 

Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> hash(n, vector<int>(n));

        for(int len=1; len<=n; len++){
            for(int start=0; start<=n-len; start++){
                int end = start + len-1;
                
                if(start == end)
                {
                    hash[start][end] = 1;
                }else if(s[start] == s[end]){
                    hash[start][end] = 2 + hash[start+1][end-1];
                }else{
                    hash[start][end] = max(hash[start+1][end], hash[start][end-1]);
                }
            }
        }
        return hash[0][n-1];
    }
};