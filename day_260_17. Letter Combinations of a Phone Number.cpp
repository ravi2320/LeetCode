/*
17. Letter Combinations of a Phone Number
Solved
Medium
Topics
Companies
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].

*/

/*
Approach:
- The problem is solved using backtracking to generate all possible combinations of letters corresponding to a given sequence of digits.
- We use a map (`unordered_map<char, string>`) to store the mapping of each digit to its corresponding letters.
- The function `solve` performs the backtracking. It processes each digit, appends each possible letter to the current string, and recurses for the next digit.
- Once all digits are processed (when `idx` equals `digits.size()`), the current combination is added to the result.
- The base case for the recursion occurs when all digits have been processed.

Time Complexity:
- O(4^n), where `n` is the length of the input `digits` string. Each digit maps to 3 or 4 possible letters, and we explore every possible combination.
- The worst case is when every digit maps to 4 letters (e.g., '7' or '9'), resulting in O(4^n) combinations.

Space Complexity:
- O(n) for the recursion stack, where `n` is the length of the input string. Additionally, the space used by the result vector is proportional to the number of valid combinations, which is O(4^n).

*/

class Solution {
public:
    // Helper function for recursive backtracking
    void solve(int idx, string &digits, string &curr, vector<string> &res, unordered_map<char, string> &mp) {
        // Base case: if we've processed all digits, add the current combination to result
        if (idx == digits.size()) {
            res.push_back(curr);
            return;
        }

        // Get the letters corresponding to the current digit
        string str = mp[digits[idx]];

        // Try each letter and recursively solve for the next digit
        for (int i = 0; i < str.length(); i++) {
            curr.push_back(str[i]);  // Add letter to current combination
            solve(idx + 1, digits, curr, res, mp);  // Recurse for the next digit
            curr.pop_back();  // Backtrack by removing the last added letter
        }
    }

    // Main function to generate letter combinations
    vector<string> letterCombinations(string digits) {
        // Edge case: if the input is empty, return an empty result
        if (digits.size() == 0) return {};

        // Mapping of digits to corresponding letters
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        string curr = "";  // Temporary string to store current combination
        vector<string> res;  // Result vector to store all possible combinations

        // Start backtracking from the first digit
        solve(0, digits, curr, res, mp);

        return res;  // Return the final result
    }
};
