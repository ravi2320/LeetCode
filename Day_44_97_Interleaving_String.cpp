/*
97. Interleaving String
Solved
Medium
Topics
Companies
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where s and t are divided into n and m 
substrings
 respectively, such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

 

Example 1:


Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Explanation: One way to obtain s3 is:
Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
Since s3 can be obtained by interleaving s1 and s2, we return true.
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Explanation: Notice how it is impossible to interleave s2 with any other string to obtain s3.
Example 3:

Input: s1 = "", s2 = "", s3 = ""
Output: true
 

Constraints:

0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1, s2, and s3 consist of lowercase English letters.
*/

//Time Complexity O(n3) Space Complexity = O(n3)
class Solution {
public:
    int f(string s1, string s2, string s3, int i, int j, int k, vector<vector<vector<int>>> &dp){
        if(i+j > k) return false;
        if(k == s3.size()) return true;

        if(dp[i][j][k] != -1) return dp[i][j][k];

         bool success = false;
         if(s1[i] == s3[k]){
             bool val = f(s1, s2, s3, i+1, j, k+1, dp);
             if(val) success = true;
         }

         if(s2[j] == s3[k]){
             bool val = f(s1, s2, s3, i, j+1, k+1, dp);
             if(val) success = true;
         }

         dp[i][j][k] = (success ? 1:0);
         return success;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() > s3.size()) return false;
        vector<vector<vector<int>>> dp(101, vector<vector<int>>(101, vector<int>(201, -1)));
        return f(s1, s2, s3, 0, 0, 0, dp);
    }
};

//Time Complexity O(n2) Space Complexity = O(n2)
class Solution {
public:

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;

        bool dp[101][101];
        dp[0][0] = true;
        for(int i=1; i<= s1.size(); i++){
            if(s1[i-1] != s3[i-1])
                dp[i][0] = false;
            else
                dp[i][0] = dp[i-1][0];
        }

        for(int i=1; i<= s2.size(); i++){
            if(s2[i-1] != s3[i-1])
                dp[0][i] = false;
            else
                dp[0][i] = dp[0][i-1];
        }

        for(int i=1; i<=s1.size(); i++){
            for(int j=1; j<=s2.size(); j++){
                if(s1[i-1] == s3[i+j-1] && dp[i-1][j])
                    dp[i][j] = true;
                else if(s2[j-1] == s3[i+j-1] && dp[i][j-1])
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
            }
        }
        return dp[s1.size()][s2.size()];
    }
};