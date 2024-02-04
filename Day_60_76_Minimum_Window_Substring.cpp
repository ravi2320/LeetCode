/*
76. Minimum Window Substring
Solved
Hard
Topics
Companies
Hint
Given two strings s and t of lengths m and n respectively, return the minimum window 
substring
 of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
*/

class Solution {
public:
    string minWindow(string s, string t) {
        int windowStart = 0, windowEnd = 0;
        int charCounter = t.size();
        unordered_map<char, int> mp;
        int minLen = INT_MAX;
        int minStart = 0;
        
        for(char c : t)
            mp[c]++;
        
        while(windowEnd < s.size()){
            if(mp.find(s[windowEnd]) != mp.end()){
                if(mp[s[windowEnd]] > 0)
                    charCounter--;
                mp[s[windowEnd]]--;
            }
            
            while(charCounter == 0){
                if(windowEnd - windowStart + 1 < minLen){
                    minLen = windowEnd - windowStart + 1;
                    minStart = windowStart;
                }

                if(mp.find(s[windowStart]) != mp.end()){
                    mp[s[windowStart]]++;
                    if(mp[s[windowStart]] > 0)
                        charCounter++;
                }
                
                windowStart++;
            }
            
            windowEnd++;
        }  

        return (minLen == INT_MAX) ? "" : s.substr(minStart, minLen);
    }
};
