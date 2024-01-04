/*
49. Group Anagrams
Solved
Medium
Topics
Companies
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;
        unordered_map<string, vector<int>> mp;
        for(int i=0; i<strs.size(); i++)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            mp[s].push_back(i);
        }

        for(auto a:mp)
        {
            vector<string> v;
            for(auto b:a.second) v.push_back(strs[b]);
            ans.push_back(v);
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<string> sorted;
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for(string s : strs)
        {
            sort(s.begin(), s.end());
            sorted.push_back(s);
        }
        for(int i=0; i<strs.size(); i++)
            mp[sorted[i]].push_back(strs[i]);

        for(auto m : mp)
            ans.push_back(m.second);
        return ans;
    }
};