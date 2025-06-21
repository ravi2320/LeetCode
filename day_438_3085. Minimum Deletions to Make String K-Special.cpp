/*
3085. Minimum Deletions to Make String K-Special

avatar
Discuss Approach
arrow-up
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given a string word and an integer k.

We consider word to be k-special if |freq(word[i]) - freq(word[j])| <= k for all indices i and j in the string.

Here, freq(x) denotes the frequency of the character x in word, and |y| denotes the absolute value of y.

Return the minimum number of characters you need to delete to make word k-special.

 

Example 1:

Input: word = "aabcaba", k = 0

Output: 3

Explanation: We can make word 0-special by deleting 2 occurrences of "a" and 1 occurrence of "c". Therefore, word becomes equal to "baba" where freq('a') == freq('b') == 2.

Example 2:

Input: word = "dabdcbdcdcd", k = 2

Output: 2

Explanation: We can make word 2-special by deleting 1 occurrence of "a" and 1 occurrence of "d". Therefore, word becomes equal to "bdcbdcdcd" where freq('b') == 2, freq('c') == 3, and freq('d') == 4.

Example 3:

Input: word = "aaabaaa", k = 2

Output: 1

Explanation: We can make word 2-special by deleting 1 occurrence of "b". Therefore, word becomes equal to "aaaaaa" where each letter's frequency is now uniformly 6.

 

Constraints:

1 <= word.length <= 105
0 <= k <= 105
word consists only of lowercase English letters.
*/

/*
Approach:
We are given a string `word` and an integer `k`. Our goal is to delete the minimum number of characters such that
**the frequency difference between any two characters does not exceed `k`.**

Steps:
1. Count the frequency of each character using a vector of size 26.
2. Iterate over all possible base frequencies `freq[i]` (assuming `i` is the target frequency to normalize towards).
3. For each other character `j`:
   - If `freq[j] < freq[i]`, we delete all `freq[j]` characters (as they are too small to fit in range).
   - If `freq[j] > freq[i] + k`, we reduce their count by deleting `freq[j] - (freq[i] + k)` characters.
4. Track the minimum total deletions required among all choices of base frequency.

Intuition:
We are trying all possible base frequencies and figuring out how many deletions it takes to make all other
characters fall within `[freq[i], freq[i] + k]`.

Time Complexity: O(26 × 26) = O(1)
- Fixed constant loop over 26 characters, independent of input size

Space Complexity: O(1)
- Only a fixed-size array of 26 used for frequency count
*/

class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);  // Frequency of each character

        // Step 1: Count character frequencies
        for (char &x : word) {
            freq[x - 'a']++;
        }

        int minDelChar = INT_MAX;

        // Step 2: Try each character's frequency as base
        for (int i = 0; i < 26; i++) {
            int delChar = 0;

            for (int j = 0; j < 26; j++) {
                if (i == j) continue;

                // Case 1: If character freq is already less, delete all
                if (freq[j] < freq[i]) {
                    delChar += freq[j];
                }
                // Case 2: If freq exceeds freq[i] + k, delete extras
                else if (freq[j] - freq[i] > k) {
                    delChar += freq[j] - freq[i] - k;
                }
            }

            // Update minimum deletions across all base frequencies
            minDelChar = min(minDelChar, delChar);
        }

        return minDelChar;
    }
};

/*
Approach:
We aim to minimize the number of deletions such that for every character in the string `word`, 
the frequency difference between any two characters is at most `k`.

Optimized Strategy:
1. Count the frequency of each character.
2. Sort the frequencies in ascending order.
3. For each frequency `freq[i]`, assume it's the minimum base frequency.
   - Any frequency smaller than `freq[i]` will be completely deleted (accumulated via a prefix sum).
   - Any frequency `freq[j]` such that `freq[j] > freq[i] + k` will be reduced to `freq[i] + k`.
4. Track the minimum total deletions across all such choices.

Intuition:
We fix one frequency as the baseline and adjust other frequencies above the allowable range down to within `k`,
and delete smaller ones completely. Sorting allows efficient calculation of prefix sums and comparisons.

Time Complexity: O(26 log 26) ≈ O(1)
- Frequency count: O(n)
- Sorting: O(26 log 26)
- Two nested loops over 26 chars: O(26²)

Space Complexity: O(1)
- Constant-sized frequency array of 26
*/

class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);

        // Step 1: Count character frequencies
        for (char &x : word) {
            freq[x - 'a']++;
        }

        // Step 2: Sort the frequencies
        sort(freq.begin(), freq.end());

        int minDelChar = INT_MAX;
        int cumulativeSum = 0;  // Tracks sum of frequencies before current index

        // Step 3: Try each frequency as the baseline
        for (int i = 0; i < 26; i++) {
            int delChar = cumulativeSum;  // Delete all characters with frequency < freq[i]

            // Step 4: Reduce characters with freq > freq[i] + k
            for (int j = 25; j > i; j--) {
                if (freq[j] - freq[i] <= k) {
                    break;  // Already within allowable range
                }
                delChar += freq[j] - freq[i] - k;  // Reduce freq[j] to freq[i] + k
            }

            cumulativeSum += freq[i];  // Accumulate deletions for next iteration
            minDelChar = min(minDelChar, delChar);  // Track minimum deletions
        }

        return minDelChar;
    }
};
