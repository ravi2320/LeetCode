/*
1347. Minimum Number of Steps to Make Two Strings Anagram
Solved
Medium
Topics
Companies
Hint
You are given two strings of the same length s and t. In one step you can choose any character of t and replace it with another character.

Return the minimum number of steps to make t an anagram of s.

An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.

 

Example 1:

Input: s = "bab", t = "aba"
Output: 1
Explanation: Replace the first 'a' in t with b, t = "bba" which is anagram of s.
Example 2:

Input: s = "leetcode", t = "practice"
Output: 5
Explanation: Replace 'p', 'r', 'a', 'i' and 'c' from t with proper characters to make t anagram of s.
Example 3:

Input: s = "anagram", t = "mangaar"
Output: 0
Explanation: "anagram" and "mangaar" are anagrams. 
 

Constraints:

1 <= s.length <= 5 * 104
s.length == t.length
s and t consist of lowercase English letters only.
*/
class Solution {
public:
    int minSteps(string s, string t) {
        int res[26] = {0};
        for(char c : s) res[c - 'a']++;
        for(char c : t) res[c - 'a']--;
        int ans = 0;
        for(int i=0; i<26; i++) ans += abs(res[i]);
        return ans/2;
    }
};

class Solution {
public:
    int minSteps(string s, string t) {
        int occ[26] = {0};
        for (auto it : s) occ[it-'a'] ++;
        for (auto it : t) occ[it-'a']--;

        int res = 0;
        for (int i = 0; i < 26; i++) res += abs(occ[i]);

        return res / 2;
    }
};
