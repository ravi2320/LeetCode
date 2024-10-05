/*
567. Permutation in String
Solved
Medium
Topics
Companies
Hint
Given two strings s1 and s2, return true if s2 contains a 
permutation
 of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 

Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.
*/

/*
Approach:
1. This function checks if the string `s1`'s permutation is present as a substring in `s2`.
2. First, we check if the length of `s1` is greater than `s2`. If so, we return `false` as a permutation can't exist in a smaller string.
3. We sort the string `s1` to make comparisons easier.
4. We then slide a window of size `n` (where `n` is the length of `s1`) over `s2`, and for each substring of `s2` of length `n`, we check if its sorted version matches the sorted `s1`.
5. If we find such a substring, we return `true`. If we go through the whole string without finding a match, we return `false`.

Time Complexity:
- Sorting `s1` takes O(N log N), where N is the length of `s1`.
- For each window in `s2`, we perform sorting, which takes O(N log N). Since there are M-N+1 windows (where M is the length of `s2`), the overall complexity becomes O((M-N+1) * N log N).
- Hence, the time complexity is O(M * N log N).

Space Complexity:
- O(N) for the sorted substring `s1` and the sliding window in `s2`.

*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();  // Length of string s1
        int m = s2.length();  // Length of string s2

        // If s1 is longer than s2, permutation is not possible
        if(n > m){
            return false;
        }

        // Sort s1 to make comparisons easier
        sort(s1.begin(), s1.end());

        // Slide a window of size `n` over `s2`
        for(int i = 0; i <= m - n; i++){
            // Extract substring of length `n` from s2
            string substr = s2.substr(i, n);

            // Sort the substring and compare with sorted `s1`
            sort(substr.begin(), substr.end());

            if(s1 == substr){
                return true;  // Found a permutation
            }
        }

        // No permutation found
        return false;
    }
};


/*
Approach:
1. The task is to find if a permutation of `s1` exists as a substring in `s2`.
2. Instead of sorting and comparing substrings (which would be inefficient), we use frequency counts of characters.
3. We maintain two frequency arrays (`s1_freq` and `s2_freq`) of size 26 (for each lowercase alphabet character).
4. First, we calculate the frequency of characters in `s1`.
5. Then, using a sliding window of size `n` (length of `s1`) on `s2`, we compare the frequency arrays for the current window in `s2` with that of `s1`.
6. If the frequency arrays match at any point, it means that a permutation of `s1` exists in `s2`, and we return `true`.
7. If no match is found by the end of the process, return `false`.

Time Complexity:
- We traverse `s2` with a sliding window, and for each position, we update and compare the frequency arrays, making this approach O(M), where M is the length of `s2`.

Space Complexity:
- The space complexity is O(1), as we use two fixed-size arrays of length 26 for character frequency.

*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();  // Length of s1
        int m = s2.length();  // Length of s2

        // If s1 is longer than s2, a permutation cannot exist
        if(n > m){
            return false;
        }

        // Frequency arrays for s1 and current window of s2
        vector<int> s1_freq(26, 0);
        vector<int> s2_freq(26, 0);

        // Populate the frequency array for s1
        for(char &x : s1){
            s1_freq[x - 'a']++;
        }

        // Sliding window over s2
        int i = 0, j = 0;
        while(j < m){
            // Add the current character to the s2 frequency array
            s2_freq[s2[j] - 'a']++;

            // When the window size exceeds the size of s1, shrink the window from the left
            while(j - i + 1 > n){
                s2_freq[s2[i] - 'a']--;  // Remove the leftmost character from the window
                i++;  // Move the left pointer of the window
            }

            // Compare the frequency arrays. If they match, return true
            if(s1_freq == s2_freq){
                return true;
            }

            // Move the right pointer of the window
            j++;
        }

        // No permutation of s1 found in s2
        return false;
    }
};
