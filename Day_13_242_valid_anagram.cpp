/*

242. Valid Anagram
Solved
Easy
Topics
Companies
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.

*/

class Solution {
public:
    bool isAnagram(string s, string t) {

        map<char, int> counter;

        for(int i=0; i<s.length(); i++)
            counter[s[i]]++;

        for(int i=0; i<t.length(); i++)
            counter[t[i]]--;

        for(int i=0; i<s.length(); i++)
        {
            if(counter[s[i]] != 0)
                return false;
        }
        for(int i=0; i<t.length(); i++)
        {
            if(counter[t[i]] != 0)
                return false;
        }
        return true;
    }
};