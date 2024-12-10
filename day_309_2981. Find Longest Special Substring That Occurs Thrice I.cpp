/*
2981. Find Longest Special Substring That Occurs Thrice I
Solved
Medium
Topics
Companies
Hint
You are given a string s that consists of lowercase English letters.

A string is called special if it is made up of only a single character. For example, the string "abc" is not special, whereas the strings "ddd", "zz", and "f" are special.

Return the length of the longest special substring of s which occurs at least thrice, or -1 if no special substring occurs at least thrice.

A substring is a contiguous non-empty sequence of characters within a string.

 

Example 1:

Input: s = "aaaa"
Output: 2
Explanation: The longest special substring which occurs thrice is "aa": substrings "aaaa", "aaaa", and "aaaa".
It can be shown that the maximum length achievable is 2.
Example 2:

Input: s = "abcdef"
Output: -1
Explanation: There exists no special substring which occurs at least thrice. Hence return -1.
Example 3:

Input: s = "abcaba"
Output: 1
Explanation: The longest special substring which occurs thrice is "a": substrings "abcaba", "abcaba", and "abcaba".
It can be shown that the maximum length achievable is 1.
 

Constraints:

3 <= s.length <= 50
s consists of only lowercase English letters.
*/

/*
Approach:
1. Use a sliding window to find substrings with all identical characters.
2. For every substring, calculate its frequency of occurrence.
3. Return the length of the longest substring that appears at least 3 times.

Steps:
- Traverse the string and create substrings with consecutive identical characters.
- Count their occurrences using a hash map (`unordered_map`).
- Check all substrings for the condition of appearing at least 3 times and return the maximum length.

Optimizations:
- Avoid creating all substrings explicitly; only store substrings with identical characters.
- Break early when characters differ to avoid unnecessary computation.

Time Complexity:
- O(n^2): Outer loop runs for each character, inner loop creates substrings.
- Map operations are O(1) amortized.

Space Complexity:
- O(n^2): Due to storage of substrings in the hash map.

Edge Cases:
- String is empty.
- String contains no substring meeting the criteria.

*/

class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string, int> mp; // Map to store substring frequency
        int n = s.length();

        for (int i = 0; i < n; i++) {
            string str = "";
            for (int j = i; j < n; j++) {
                if (str.empty() || s[j] == str.back()) {
                    // Extend the substring
                    str.push_back(s[j]);
                    mp[str]++;
                } else {
                    // Break on encountering a different character
                    break;
                }
            }
        }

        int res = 0; // Store the maximum length found
        for (auto &itr : mp) {
            // Check if substring occurs at least 3 times and is the longest
            if (itr.second >= 3 && itr.first.length() > res) {
                res = itr.first.length();
            }
        }

        return res == 0 ? -1 : res; // Return -1 if no valid substring found
    }
};


/*
Approach:
1. Iterate through the string to identify contiguous substrings of identical characters.
2. Use a `map` to store the count of each character and its consecutive occurrence count.
3. Return the maximum length of a substring that appears at least 3 times.

Steps:
- Traverse the string and identify substrings where all characters are the same.
- Count occurrences of substrings using a map with `char` and `count` as keys.
- Check the map for substrings that appear at least 3 times and record the maximum length.

Optimizations:
- Break the inner loop early when encountering a different character.
- Use a map to avoid storing full substrings and instead store `char` and length pairs.

Time Complexity:
- O(n^2): Outer loop runs for each character, inner loop checks consecutive identical characters.
- Map operations are O(log k), where k is the number of distinct keys.

Space Complexity:
- O(k): Space used by the map, where k is the number of distinct `(char, count)` pairs.

Edge Cases:
- String is empty.
- String contains no substring meeting the criteria.

*/

class Solution {
public:
    int maximumLength(string s) {
        map<pair<char, int>, int> mp; // Map to store frequency of each (character, count) pair
        int n = s.length();

        // Iterate through the string
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            int cnt = 0;

            // Count consecutive characters
            for (int j = i; j < n; j++) {
                if (s[j] == ch) {
                    cnt++; // Increment count for the same character
                    mp[{ch, cnt}]++; // Increment frequency of this (char, count) pair
                } else {
                    break; // Stop counting on encountering a different character
                }
            }
        }

        int res = 0; // Variable to store the maximum length found
        for (auto &itr : mp) {
            // Check if the substring appears at least 3 times and is the longest
            if (itr.second >= 3 && itr.first.second > res) {
                res = itr.first.second;
            }
        }

        return res == 0 ? -1 : res; // Return -1 if no valid substring found
    }
};
