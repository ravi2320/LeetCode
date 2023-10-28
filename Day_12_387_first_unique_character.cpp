/*

387. First Unique Character in a String
Solved
Easy
Topics
Companies
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

Example 1:

Input: s = "leetcode"
Output: 0
Example 2:

Input: s = "loveleetcode"
Output: 2
Example 3:

Input: s = "aabb"
Output: -1
 

Constraints:

1 <= s.length <= 105
s consists of only lowercase English letters.



class Solution {
public:
    int firstUniqChar(string s) {

        unordered_map<char, int> counter;
       for(int i=0; i<s.size(); i++)
       {
           char ch = s[i];
           counter[ch]++;
       }

       for(int i=0; i<s.size(); i++)
       {
           if(counter[s[i]] == 1)
               return i;
       }
       return -1;
    }
};

*/

class Solution {
public:
    int firstUniqChar(string s) {

       for(int i=0; i<s.size(); i++)
       {
           int found = 0;
           for(int j=0; j<s.size(); j++)
           {
               if(s[i]==s[j] && i!=j)
               {
                   found = 1;
                   break;
               }
           }
           if(found == 0)
            return i;
       } 
       return -1;
    }
};