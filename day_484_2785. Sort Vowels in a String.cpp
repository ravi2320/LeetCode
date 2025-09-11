/*
2785. Sort Vowels in a String

avatar
Discuss Approach
arrow-up
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given a 0-indexed string s, permute s to get a new string t such that:

All consonants remain in their original places. More formally, if there is an index i with 0 <= i < s.length such that s[i] is a consonant, then t[i] = s[i].
The vowels must be sorted in the nondecreasing order of their ASCII values. More formally, for pairs of indices i, j with 0 <= i < j < s.length such that s[i] and s[j] are vowels, then t[i] must not have a higher ASCII value than t[j].
Return the resulting string.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in lowercase or uppercase. Consonants comprise all letters that are not vowels.

 

Example 1:

Input: s = "lEetcOde"
Output: "lEOtcede"
Explanation: 'E', 'O', and 'e' are the vowels in s; 'l', 't', 'c', and 'd' are all consonants. The vowels are sorted according to their ASCII values, and the consonants remain in the same places.
Example 2:

Input: s = "lYmpH"
Output: "lYmpH"
Explanation: There are no vowels in s (all characters in s are consonants), so we return "lYmpH".
 

Constraints:

1 <= s.length <= 105
s consists only of letters of the English alphabet in uppercase and lowercase.
*/

/*
Approach:
1. Traverse the string and collect all vowels (both lowercase and uppercase).
2. Sort the collected vowels alphabetically.
3. Traverse the string again, and for each vowel, replace it with the next sorted vowel.
4. Return the modified string.

Intuition:
- The consonants remain fixed in their positions.
- Only vowels need sorting, so just extract → sort → replace.
- This reduces unnecessary operations and keeps the algorithm simple.

Time Complexity:
- Collect vowels: O(n)
- Sort vowels: O(k log k), where k = number of vowels in s
- Replace vowels: O(n)
Overall: O(n + k log k), which is efficient since k ≤ n.

Space Complexity:
- Extra space for storing vowels: O(k).
- Hence, O(k) auxiliary space.

*/

class Solution {
public:
    // Helper function to check if a character is a vowel (case-insensitive)
    bool isVowel(char c) {
        return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
               c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    string sortVowels(string s) {
        // Step 1: Collect all vowels from the string
        vector<char> vowels;
        for (char c : s) {
            if (isVowel(c)) {
                vowels.push_back(c);
            }
        }

        // Step 2: Sort the vowels alphabetically
        sort(vowels.begin(), vowels.end());

        // Step 3: Replace vowels in original string with sorted vowels
        int idx = 0; // index for sorted vowels
        for (int i = 0; i < s.length(); ++i) {
            if (isVowel(s[i])) {
                s[i] = vowels[idx++];
            }
        }

        // Step 4: Return the modified string
        return s;
    }
};
