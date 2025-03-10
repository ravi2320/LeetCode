/*
3306. Count of Substrings Containing Every Vowel and K Consonants II
Solved
Medium
Topics
Companies
Hint
You are given a string word and a non-negative integer k.

Return the total number of substrings of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once and exactly k consonants.

 

Example 1:

Input: word = "aeioqq", k = 1

Output: 0

Explanation:

There is no substring with every vowel.

Example 2:

Input: word = "aeiou", k = 0

Output: 1

Explanation:

The only substring with every vowel and zero consonants is word[0..4], which is "aeiou".

Example 3:

Input: word = "ieaouqqieaouqq", k = 1

Output: 3

Explanation:

The substrings with every vowel and one consonant are:

word[0..5], which is "ieaouq".
word[6..11], which is "qieaou".
word[7..12], which is "ieaouq".
 

Constraints:

5 <= word.length <= 2 * 105
word consists only of lowercase English letters.
0 <= k <= word.length - 5
*/

/**
 * Approach:
 * - Use **two-pointer sliding window** technique.
 * - Maintain a **frequency map for vowels** and a count of **consonants**.
 * - Expand `j` to include characters while maintaining exactly `k` consonants.
 * - Shrink `i` when consonants exceed `k`.
 * - Maintain an array `nextCons[]` to track the **next consonant position** for fast counting.
 * 
 * 🔹 **Time Complexity**: O(N) → Two-pointer traversal.
 * 🔹 **Space Complexity**: O(1) → Fixed map size (5 vowels).
 */

class Solution {
public:
    // Helper function to check if a character is a vowel
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    long long countOfSubstrings(string word, int k) {
        int n = word.length();
        unordered_map<char, int> vowelFreq;
        vector<int> nextCons(n); // Store next consonant index

        // Initialize `nextCons[]` for quick lookup of next consonant
        int lastIdx = n;
        for (int i = n - 1; i >= 0; i--) {
            nextCons[i] = lastIdx;
            if (!isVowel(word[i])) {
                lastIdx = i;
            }
        }

        int consonantCount = 0, i = 0, j = 0;
        long long result = 0;

        // Sliding window approach
        while (j < n) {
            if (isVowel(word[j])) {
                vowelFreq[word[j]]++;
            } else {
                consonantCount++;
            }

            // Shrink window if consonants exceed k
            while (i < n && consonantCount > k) {
                if (isVowel(word[i])) {
                    vowelFreq[word[i]]--;
                    if (vowelFreq[word[i]] == 0) {
                        vowelFreq.erase(word[i]);
                    }
                } else {
                    consonantCount--;
                }
                i++;
            }

            // If all vowels are present and consonants == k, count substrings
            while (i < n && vowelFreq.size() == 5 && consonantCount == k) {
                int idx = nextCons[j]; // Get next consonant index
                result += idx - j;

                if (isVowel(word[i])) {
                    vowelFreq[word[i]]--;
                    if (vowelFreq[word[i]] == 0) {
                        vowelFreq.erase(word[i]);
                    }
                } else {
                    consonantCount--;
                }
                i++;
            }

            j++;
        }

        return result;
    }
};
