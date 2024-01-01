/*
1160. Find Words That Can Be Formed by Characters
Solved
Easy
Topics
Companies
Hint
You are given an array of strings words and a string chars.

A string is good if it can be formed by characters from chars (each character can only be used once).

Return the sum of lengths of all good strings in words.

 

Example 1:

Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation: The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
Example 2:

Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation: The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
 

Constraints:

1 <= words.length <= 1000
1 <= words[i].length, chars.length <= 100
words[i] and chars consist of lowercase English letters.
*/

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> count(26, 0);
        for(char c:chars)
        {
            count[c - 'a']++;
        }

        int ans = 0;
        for(string str:words)
        {
            if(canForm(str, count))
                ans += str.length();
        }
        return ans;
    }

    bool canForm(string &str, vector<int> &count)
    {
        vector<int> cnt(26, 0);
        for(char ch:str)
        {
            int x = ch - 'a';
            cnt[x]++;

            if(cnt[x] > count[x])
                return false;
        }
        return true;
    }
};