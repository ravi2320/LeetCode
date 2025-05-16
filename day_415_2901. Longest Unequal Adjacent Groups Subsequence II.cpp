/*
2901. Longest Unequal Adjacent Groups Subsequence II
Solved
Medium
Topics
Companies
Hint
You are given a string array words, and an array groups, both arrays having length n.

The hamming distance between two strings of equal length is the number of positions at which the corresponding characters are different.

You need to select the longest subsequence from an array of indices [0, 1, ..., n - 1], such that for the subsequence denoted as [i0, i1, ..., ik-1] having length k, the following holds:

For adjacent indices in the subsequence, their corresponding groups are unequal, i.e., groups[ij] != groups[ij+1], for each j where 0 < j + 1 < k.
words[ij] and words[ij+1] are equal in length, and the hamming distance between them is 1, where 0 < j + 1 < k, for all indices in the subsequence.
Return a string array containing the words corresponding to the indices (in order) in the selected subsequence. If there are multiple answers, return any of them.

Note: strings in words may be unequal in length.

 

Example 1:

Input: words = ["bab","dab","cab"], groups = [1,2,2]

Output: ["bab","cab"]

Explanation: A subsequence that can be selected is [0,2].

groups[0] != groups[2]
words[0].length == words[2].length, and the hamming distance between them is 1.
So, a valid answer is [words[0],words[2]] = ["bab","cab"].

Another subsequence that can be selected is [0,1].

groups[0] != groups[1]
words[0].length == words[1].length, and the hamming distance between them is 1.
So, another valid answer is [words[0],words[1]] = ["bab","dab"].

It can be shown that the length of the longest subsequence of indices that satisfies the conditions is 2.

Example 2:

Input: words = ["a","b","c","d"], groups = [1,2,3,4]

Output: ["a","b","c","d"]

Explanation: We can select the subsequence [0,1,2,3].

It satisfies both conditions.

Hence, the answer is [words[0],words[1],words[2],words[3]] = ["a","b","c","d"].

It has the longest length among all subsequences of indices that satisfy the conditions.

Hence, it is the only answer.

 

Constraints:

1 <= n == words.length == groups.length <= 1000
1 <= words[i].length <= 10
1 <= groups[i] <= n
words consists of distinct strings.
words[i] consists of lowercase English letters.
*/

/*
Approach:
- We are given a list of words and their group identifiers (0 or 1).
- We aim to find the **longest subsequence** where:
    1. The groups alternate (i.e., no two consecutive words are from the same group).
    2. Each pair of consecutive words in the subsequence must have a **Hamming distance of exactly 1** (same length, only one differing character).

Intuition:
- Treat each word as a node and create a graph edge to a later word if it satisfies the above two constraints.
- Use dynamic programming (`dp[i]`) to store the length of the longest valid subsequence ending at `i`.
- `parent[i]` is used to reconstruct the actual subsequence via backtracking.

Time Complexity:
- O(n^2 * L), where:
    - `n` is number of words,
    - `L` is the max length of the words (used in Hamming comparison).

Space Complexity:
- O(n) for `dp` and `parent` arrays.

*/

class Solution {
public:
    // Helper function to check if Hamming Distance == 1
    bool CheckHammingDiffOne(string &word1, string &word2) {
        int diff = 0;
        for (int i = 0; i < word1.length(); i++) {
            if (word1[i] != word2[i]) {
                diff++;
                if (diff > 1)
                    return false;
            }
        }
        return diff == 1;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();

        vector<int> dp(n, 1);        // dp[i] = length of longest subsequence ending at i
        vector<int> parent(n, -1);   // parent[i] = previous index in the path

        int longestSub = 1;
        int longestSubIdx = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (groups[i] != groups[j] &&                        // groups alternate
                    words[i].length() == words[j].length() &&       // same length
                    CheckHammingDiffOne(words[i], words[j])) {      // Hamming distance = 1

                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;

                        // Update global max length and index
                        if (dp[i] > longestSub) {
                            longestSub = dp[i];
                            longestSubIdx = i;
                        }
                    }
                }
            }
        }

        // Reconstruct the longest subsequence
        vector<string> res;
        while (longestSubIdx != -1) {
            res.push_back(words[longestSubIdx]);
            longestSubIdx = parent[longestSubIdx];
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
